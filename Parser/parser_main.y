%{
   #include<stdio.h>
   #include<stdlib.h>
   extern FILE* yyin,*fp2;

   int yylex();
   void yyerror();
%}

%start prgm
%token REGISTERS QUANTUM CLASSICAL NUMBER ITERS SET STATES
%token MAIN_BEGIN MAIN_END OUTPUT_BEGIN OUTPUT_END INIT_BEGIN INIT_END
%token GATE ID BLOCK ARROW IN  
%token MEASURE CONDITION OTHERWISE BARRIER
%token FOR FOR_LEX FOR_ZIP
%token COMP TRUE FALSE EQUALITY AND OR
%token WHILE
%token ADD SUB DOT STD_DEV VAR AVG CONDENSE SUM
%token COUT QOUT
%token INT UINT FLOAT COMPLEX STRING MATRIX STATE BOOL IMAG LIST
%token NEG DEC EXP
%token SAVE ECHO RETURN

%left '+' '-'
%left '*' '/' '%'
%left '@'
%left COMP
%left EQUALITY
%left '&'
%left '^'
%left '|'
%left '!'
%left AND
%left OR

%%

prgm                    : init_section main_section output_section {printf("Done\n");}
                        ;

// sequence has been enforced for the initializations and definitions in the init section
init_section            :  '\\' INIT_BEGIN mandatory_init set_states block_defns_list gate_defn_section '\\' INIT_END {printf("init done\n");}
                        ;   

main_section            : '\\'  MAIN_BEGIN main_stmt_list '\\' MAIN_END
                        | '\\' MAIN_BEGIN '\\' MAIN_END
                        ;

output_section          : '\\' OUTPUT_BEGIN out_main '\\' OUTPUT_END


/* ..............
    INIT SECTION 
   ..............
*/
mandatory_init          :  '#' REGISTERS QUANTUM '=' NUMBER '#' REGISTERS CLASSICAL '=' NUMBER '#' ITERS '=' NUMBER
                        ;

// can only one type of states be set?
set_states              :   set_quantum_states set_states
                        |   set_classical_states set_states
                        |
                        ;

set_quantum_states      :   '#' SET QUANTUM STATES ARROW quantum_state_list
                        ;

set_classical_states    :   '#' SET CLASSICAL STATES ARROW classical_state_list
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

variable                : var
                        | '(' var ',' var ')'

var                     : NUMBER
                        | ID
                        | NEG
                        | DEC

block_defns_list        :   block_defns_list block_defn
                        |   /* epsilon */
                        ;

block_defn              : BLOCK block_id params target_params '[' block_body ']'
                        ;

params                  :  ID                                   /* parantheses maybe ignored for single ID */
                        | '(' param_id_list ')'
                        ;

param_id_list           : param_id_list ',' ID
                        | ID
                        ;

target_params           : /* epsilon */                          /* optional */
                        | ARROW ID  
                        | ARROW '(' target_param_list ')'
                        ;

target_param_list       :   target_param_list ',' ID
                        |   ID
                        ;

block_body              : 
                        | stmts block_body
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

main_stmt               : stmts
                        | barrier_stmt

stmts                   : call_stmt
                        | measure_stmt
                        | condition_stmt
                        | for_stmt
                        | for_lex_stmt
                        | for_zip_stmt
                        | while_stmt
                        ;

register                : NUMBER  /* check non negative*/
                        | ID
                        ;


/* separate rules for gate calls and block calls because same syntax means different things for both */
call_stmt               : classic_control GATE quantum_control ARROW register
                        | classic_control block_id quantum_control ARROW target
                        | GATE quantum_control ARROW register
                        | block_id quantum_control ARROW target
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
                | arithmetic_expr '%' arithmetic_expr
                | ID
                | NUMBER
                ;

expr            : expr COMP expr
                | expr EQUALITY expr
                | expr AND expr
                | expr OR expr
                | expr '^' expr
                | expr '&' expr
                | expr '|' expr
                | '(' expr ')'
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

// /* ................ 
//     OUTPUT SECTION 
//    ................
// */

/* Datatypes */
out_id                  : ID | COUT | QOUT ;

prim_type               : INT 
                        | UINT
                        | FLOAT
                        | COMPLEX
                        | STRING
                        | MATRIX
                        | STATE
                        | BOOL
                        ;

list_type               : LIST '<' prim_type '>'
                        ;

/* data_type               : prim_type
                        | list_type
                        ; */

bool_const              : TRUE
                        | FALSE
                        ;

uint_const              : NUMBER
                        ;

nint_const               : NEG
                        /* | NUMBER */
                        ;

float_const             : DEC
                        | EXP
                        ;

complex_const           : '(' float_const ',' float_const ')'
                        /* | float_const '+' float_const IMAG
                        | float_const '-' float_const IMAG */
                        ;

string_const            : STRING
                        ;

matrix_const            : '[' row_list ']'
                        ;

row_list                : row_list ',' row 
                        | row
                        ;

row                     : '[' comps ']'
                        ;

comps                   : comps ',' complex_const
                        | complex_const
                        ;

state_const             : '{' complex_const ',' complex_const '}'
                        ;

prim_const              : bool_const
                        | uint_const
                        | nint_const
                        | float_const
                        | complex_const
                        | string_const
                        | matrix_const
                        | state_const
                        ;

vec_const               : '<' vec_list '>'
                        ;

vec_list                : vec_list ',' prim_const
                        | prim_const
                        ;

/* Calls */
calls                   : ADD '(' ID ',' ID ')'
                        | SUB '(' ID ',' ID ')'
                        | DOT '(' ID ',' ID ')'
                        | STD_DEV '(' ID ')'
                        | VAR '(' ID ')'
                        | CONDENSE '(' ID ',' uint_const ')'
                        | CONDENSE '(' ID ',' '(' uint_list ')' ')'
                        | SUM '(' ID ')'
                        | AVG '(' ID ')'
                        ;

uint_list               : uint_list ',' uint_const
                        | uint_const
                        ;

/* Expressions */
out_rhs                 : prim_const
                        | out_id
                        | out_id '[' uint_const ']'
                        | out_id '[' uint_const ']' '[' uint_const ']' 
                        | calls
                        | '(' out_rhs ')'
                        | '!' out_rhs
                        | out_rhs AND out_rhs
                        | out_rhs OR out_rhs
                        | out_rhs COMP out_rhs
                        | out_rhs EQUALITY out_rhs
                        | out_rhs '*' out_rhs
                        | out_rhs '/' out_rhs
                        | out_rhs '+' out_rhs
                        | out_rhs '-' out_rhs
                        | out_rhs '@' out_rhs
                        | out_rhs '&' out_rhs
                        | out_rhs '^' out_rhs
                        | out_rhs '|' out_rhs
                        ;

/* Expressions */
out_expr                : ID '=' out_rhs;

decl                    : prim_type out_expr 
                        | list_type ID '=' vec_const
                        ;

/* Echo Statement */
echo_stmt               : ECHO '(' echo_list ')'
                        ;

echo_list               : echo_list ',' out_rhs
                        | out_rhs
                        ;

/* Save Statement */
save_stmt               : '\\' SAVE ID
                        ;

/* Control Statement */
out_control             : out_cond_stmt
                        | out_for_stmt
                        | out_for_lex_stmt
                        | out_for_zip_stmt
                        | out_while_stmt
                        ;

out_cond_stmt           : CONDITION '(' out_rhs ')' '{' out_main '}' out_other_list out_other_final
                        ;

out_other_list          : out_other_list OTHERWISE '(' out_rhs ')' '{' out_main '}'
                        | /* epsilon */
                        ;

out_other_final         : OTHERWISE '{' out_main '}'
                        | /* epsilon */
                        ;

out_for_stmt            : FOR ID IN '(' range ')' '{' out_main '}'
                        ;

out_for_lex_stmt        : FOR_LEX '(' var_list ')'  IN '(' range_list ')' '{' out_main '}'
                        ;

out_for_zip_stmt        : FOR_ZIP '(' var_list ')'  IN '(' range_list ')' '{' out_main '}'
                        ;

out_while_stmt          : WHILE '(' expr ')' '{' out_main '}'
                        ;


/* Output Statement */
out_main                : out_main out_stmt
                        | out_stmt
                        ;

out_stmt                : out_control
                        | save_stmt
                        | echo_stmt
                        | out_expr
                        | decl
                        ;
%%

int main()
{
  yyin = fopen("in.txt","r");
  fp2 = fopen("tokens.txt","w");
  yyparse();

  return 0;
}

void yyerror(){
   printf("Invalid syntax");
}