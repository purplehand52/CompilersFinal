%start prgm
%token REGISTERS QUANTUM CLASSICAL NUMBER ITERS SET STATES
%token MAIN_BEGIN MAIN_END OUTPUT_BEGIN OUTPUT_END INIT_BEGIN INIT_END
%token GATE ID BLOCK ARROW IN  
%token MEASURE CONDITION OTHERWISE BARRIER
%token FOR FOR_LEX FOR_ZIP
%token COMP TRUE FALSE EQUALITY AND OR
%token WHILE

%left '+' '-'
%left '*' '/' '%'
%left COMP
%left EQUALITY
%left '&'
%left '^'
%left '|'
%left AND
%left OR

%%

prgm                    : init_section main_section output_section
                        ;

// sequence has been enforced for the initializations and definitions in the init section
init_section            :   INIT_BEGIN  mandatory_init set_states block_defns_list gate_defn_section INIT_END
                        ;   

main_section            :   MAIN_BEGIN main_stmt_list MAIN_END
                        |   MAIN_BEGIN MAIN_END
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


gate_defn_section       :   gate_defn_list
                        |
                        ;

gate_defn_list          :   gate_defn_list gate_defn
                        |   gate_defn
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
                        |   /* epsilon */
                        ;

block_defn              : BLOCK block_id control_params ARROW params '[' block_body ']'
                        ;

params                  :  ID                                   /* parantheses maybe ignored for single ID */
                        | '(' param_id_list ')'
                        ;

param_id_list           : param_id_list ',' ID
                        | ID
                        ;

control_params          : /* epsilon */                          /* optional */
                        | ':' ID  
                        | ':' '(' control_param_list ')'
                        ;

control_param_list      :   control_param_list ',' ID
                        |   ID
                        ;

// $ circuit statement calls $
block_body              :
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
                        | while_stmt
                        ;

register                : NUMBER  /* check non negative*/
                        | ID
                        ;

/* separate rules for gate calls and block calls because same syntax means different things for both */
call_stmt               : classic_control GATE quantum_control ARROW register
                        | classic_control block_id quantum_control ARROW target
                        ;

register_list           : register_list ',' register
                        | register
                        ;

classic_control         : register '?'                         /* removing epsilon rule resolved all conflicts */
                        | '(' register_list ')' '?'
                        ;

quantum_control         : /* epsilon */                         /* optional */
                        | ':' register
                        | ':' '(' register_list ')'
                        ;

target                  : register                              /* blocks allow multiple targets */
                        | '(' register_list ')' 
                        ;

/* can use for not, product etc 
register_expr           : register
                        | '!' register
                        ;

register_expr_list      : register_expr_list ',' register_expr
                        | register_expr
                        ;
*/


measure_stmt            : MEASURE ':' register ARROW register
                        ;

barrier_stmt            : '\\' BARRIER
                        ;

condition_stmt          : CONDITION '(' expr ')' '{' main_stmt_list '}' otherwise_list otherwise_final
                        ;

otherwise_list          : otherwise_list OTHERWISE '(' expr ')' '{' main_stmt_list '}'
                        | /* epsilon */
                        ;

otherwise_final         : OTHERWISE '{' main_stmt_list '}'
                        | /* epsilon */
                        ;

arithmetic_expr : arithmetic_expr '+' arithmetic_expr
                | arithmetic_expr '-' arithmetic_expr
                | arithmetic_expr '*' arithmetic_expr
                | arithmetic_expr '/' arithmetic_expr
                | '(' arithmetic_expr ')'
                | ID
                ;

expr            : expr COMP expr
                | expr EQUALITY expr
                | expr AND expr
                | expr OR expr
                | expr '^' expr
                | expr '&' expr
                | expr '|' expr
                | arithmetic_expr
                | TRUE
                | FALSE
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

while_stmt              : WHILE '(' expr ')' '{' main_stmt_list '}'
                        ;

/* ................ 
    OUTPUT SECTION 
   ................
*/