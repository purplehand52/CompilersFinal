%token REGISTERS, QUANTUM, CLASSICAL, NUMBER, ITERS,SET, STATES
%token MAIN_BEGIN, MAIN_END,OUTPUT_BEGIN,OUTPUT_END,INIT_BEGIN, INIT_END
%token GATE, ID, BLOCK, ARROW, IN, 
%token MEASURE, CONDITION, OTHERWISE, BARRIER
%token FOR, FOR_LEX, FOR_ZIP


%%

prgm                    : init_section main_section output_section
                        ;

// sequence has been enforced for the initializations and definitions in the init section
init_section            :   INIT_BEGIN  mandatory_init set_states block_defns_list gate_defn_list INIT_END
                        ;   

main_section            :   MAIN_BEGIN main_stmt_list MAIN_END
                        ;

output_section          : OUTPUT_BEGIN OUTPUT_END


/* ..............
    INIT SECTION 
   ..............
*/
mandatory_init          :   '#' REGISTERS QUANTUM '=' NUMBER '#' REGISTERS CLASSICAL '=' NUMBER '#' ITERS '=' NUMBER
                        ;

// can only one type of states be set?
set_states              :   set_quantum_states set_classical_states
                        |   set_quantum_states
                        |   set_classical_states
                        |
                        ;

set_quantum_states      :   '#' SET QUANTUM STATES '=' quantum_state_list
                        ;

set_classical_states    :   '#' SET CLASSICAL STATES '=' classical_state_list
                        ;

quantum_state_list      :   quantum_state_list ',' quantum_state
                        |   quantum_state
                        ;

classical_state_list    :   classical_state_list ',' classical_state
                        |   classical_state
                        ;

quantum_state           :   '(' NUMBER ',' NUMBER ')'
                        ;

classical_state         :   NUMBER
                        ;

gate_defn_list          :   gate_defn_list gate_defn
                        |   gate_defn
                        |
                        ;

gate_defn               :   GATE ID '=' rhs
                        ;

rhs                     :   '[' tuple_list ']'
                        |   '{' tuple_list2 '}'

tuple_list              : tuple_list ',' '[' id_list ']'
                        | '[' id_list ']'

tuple_list2              : tuple_list2 ',' '(' id_list ')'
                        | '(' id_list ')'

id_list                 : id_list ',' variable
                        | variable

variable                : ID
                        | '(' ID ',' ID ')'

block_defns_list        :   block_defns_list block_defn
                        |   block_defn
                        |
                        ;

block_defn              :   BLOCK block_id '('control_param_list ')' param_list '[' block_body ']'
                        ;

param_list : 
           | ARROW '(' param_id_list ')'

param_id_list : param_id_list ',' ID
              | ID
              ;

control_param_list      :   control_param_list ',' ID
                        |   ID
                        ;

// $ circuit statement calls $
block_body              :   main_stmt_list
                        ;

block_id                : ID      /* check first letter capital here */
                        ;

/* ................
     MAIN SECTION 
   ................ 
*/

main_stmt_list          : main_stmt_list main_stmt
                        | main_stmt
                        ;

main_stmt               : call_stmt
                        | measure_stmt
                        | condition_stmt
                        | for_stmt
                        | for_lex_stmt
                        | for_zip_stmt
                        | barrier_stmt
                        ;

register                : NUMBER  /* check non negative*/
                        | ID
                        ;

/* separate rules for gate calls and block calls because same syntax means different things for both */
call_stmt               : classic_control call_id ARROW quantum_control register
                        | classic_control block_id ':' '(' register_list ')' 
                        | classic_control block_id ':' '(' register_list ')' ARROW '(' register_list ')'
                        ;

call_id                 : GATE 
                        | ID
                        ;

register_list           : register_list ',' register
                        | register
                        ;

classic_control         : /* epsilon */
                        | register '?'
                        | '(' register_list ')' '?'
                        ;

quantum_control         : /* epsilon */
                        | ':' register
                        | ':' '(' register_list ')'
                        ;

measure_stmt            : MEASURE ':' register ARROW register
                        ;

barrier_stmt            : '\\' BARRIER
                        ;

condition_stmt          : CONDITION '(' expr ')' '{' main_stmt_list '}'
                        | CONDITION '(' expr ')' '{' main_stmt_list '}' OTHERWISE '{' main_stmt_list '}'
                        ;
expr :
/* negative numbers? */
value                   : NUMBER
                        | ID
                        ;

range                   : value ':' value
                        | value ':' value ':' value
                        ;

range_list              : range_list ',' range
                        | range
                        ;

var_list                : var_list ',' ID
                        | ID
                        ;

for_stmt                : FOR ID IN '(' range ')' '{' main_stmt_list '}'
                        ;

for_lex_stmt            : FOR_LEX '(' var_list ')'  IN '(' range_list ')' '{' main_stmt_list '}'
                        ;

for_zip_stmt            : FOR_ZIP '(' var_list ')'  IN '(' range_list ')' '{' main_stmt_list '}'
                        ;


/* ................ 
    OUTPUT SECTION 
   ................
*/