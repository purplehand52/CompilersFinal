%token NUMBER
%token GATE, ID
%token MEASURE, CONDITION, OTHERWISE, BARRIER
%token FOR, FOR_LEX, FOR_ZIP

%%

// sequence has been enforced for the initializations and definitions in the init section
init_section            :   INIT_BEGIN  mandatory_init set_states block_defn_list gate_defn_list INIT_END
                        ;

mandatory_init          :   '#' REGISTERS_QUANTUM '=' NUMBER '#' REGISTERS_CLASSICAL '=' NUMBER '#' ITERS '=' NUMBER
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

block_defns_list        :   block_defn_list block_defn
                        |   block_defn
                        |
                        ;

gate_defn_list          :   gate_defn_list gate_defn
                        |   gate_defn
                        |
                        ;

block_defn              :   BLOCK block_id control_param_list param_list '[' block_body ']'
                        ;

control_param_list      : /* epsilon */
                        | ID ARROW
                        | '(' register_id_list ')' ARROW
                        ;

param_list              : ID
                        | '(' register_id_list ')'
                        ;

register_id_list        :   register_id_list ',' ID
                        |   ID
                        ;

// $ circuit statement calls $
block_body              :   main_stmt_list
                        ;

gate_defn               :   GATE ID '=' rhs
                        ;

// need more clarity on what the rhs could be and what each possibility means
rhs                     :   


block_id                : ID      /* check first letter capital here */
                        ;

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

call_stmt               : classic_control GATE ':' quantum_control register
                        | classic_control block_id ':' quantum_control register
                        | classic_control block_id ':' quantum_control '(' register_list ')'
                        ;

register_list           : register_list ',' register
                        | register
                        ;

classic_control         : /* epsilon */
                        | register '?'
                        | '(' register_list ')' '?'
                        ;

quantum_control         : /* epsilon */
                        | register ARROW
                        | '(' register_list ')' ARROW
                        ;

measure_stmt            : MEASURE ':' register ARROW register
                        ;

barrier_stmt            : '\\' BARRIER
                        ;

condition_stmt          : CONDITION '(' expr ')' '{' main_stmt_list '}'
                        | CONDITION '(' expr ')' '{' main_stmt_list '}' OTHERWISE '{' main_stmt_list '}'
                        ;

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