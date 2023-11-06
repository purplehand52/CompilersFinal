%{
   #define YYSTYPE struct st
   #include<stdio.h>
   #include<stdlib.h>
   #include "st.h"

   extern FILE* yyin,*fp2;
   extern int line;
   FILE * fp;

   int yylex();
   void yyerror();

   int classical_registers,quantum_registers,iterations;
   int * classical_states,classical_index=0,quantum_index=0;
   struct Quantum* quantum_states;

   struct List* head = NULL,*head2=NULL;
   struct BlockTable* BlockSymbolTable = NULL;
   struct GateTable* GateSymbolTable = NULL;
%}

%start prgm
%token ID
%token  NUMBER ITERS NEG
%token SET STATES REGISTERS QUANTUM CLASSICAL
%token MAIN_BEGIN MAIN_END OUTPUT_BEGIN OUTPUT_END INIT_BEGIN INIT_END
%token GATE BLOCK ARROW IN  
%token MEASURE CONDITION OTHERWISE BARRIER
%token FOR FOR_LEX FOR_ZIP
%token COMP TRUE FALSE EQUALITY AND OR
%token WHILE
%token ADD SUB DOT STD_DEV VAR AVG CONDENSE SUM
%token COUT QOUT
%token INT UINT FLOAT COMPLEX STRING MATRIX STATE BOOL IMAG LIST
%token  DEC EXP
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

prgm                    : init_section main_section output_section {fprintf(fp,"\nParsing successful!\n");printBlockTable();printGateTable(&GateSymbolTable);}
                        ;

// sequence has been enforced for the initializations and definitions in the init section
init_section            :  '\\' INIT_BEGIN {fprintf(fp,"\nInit section begins\n\n");} mandatory_init set_states block_defn_section gate_defn_section '\\' INIT_END {fprintf(fp,"\nInit section ends\n");}
                        ;   

main_section            :  '\\'  MAIN_BEGIN {fprintf(fp,"\nMain section begins\n\n");} main_stmt_list '\\' MAIN_END {fprintf(fp,"\nMain section ends\n");}
                        ;

output_section          :  '\\' OUTPUT_BEGIN {fprintf(fp,"\nOutput section begins\n\n");} out_main '\\' OUTPUT_END {fprintf(fp,"\nOutput section ends\n");}
                        ;


/* ..............
    INIT SECTION 
   ..............
*/
mandatory_init          :  '#' REGISTERS QUANTUM '=' NUMBER '#' REGISTERS CLASSICAL '=' NUMBER '#' ITERS '=' NUMBER {  fprintf(fp,"Register and iteration initialization section\n");classical_registers = $10.num;quantum_registers = $5.num;iterations = $14.num;}
                        ;

// can only one type of states be set?
set_states              :   set_quantum_states set_classical_states 
                        |   set_classical_states set_quantum_states 
                        |   set_quantum_states                      
                        |   set_classical_states                    
                        |
                        ;

set_quantum_states      :   '#' SET QUANTUM STATES ARROW quantum_state_list {fprintf(fp,"Setting initial state of quantum registers\n");}
                        ;

set_classical_states    :   '#' SET CLASSICAL STATES ARROW classical_state_list {fprintf(fp,"Setting initial state of classical registers\n");}
                        ;

quantum_state_list      :   quantum_state_list ',' state_const       {if(quantum_index == quantum_registers){yyerror();return;}quantum_states[quantum_index++] = $3.q;}
                        |   state_const   {quantum_states = (struct Quantum*)malloc(sizeof(struct Quantum)*quantum_registers);quantum_states[quantum_index++] = $1.q;}
                        ;

classical_state_list    :   classical_state_list ',' classical_state  {if(classical_index == classical_registers){yyerror();return;}classical_states[classical_index++] = $3.num;}
                        |   classical_state {classical_states = (int *)malloc(sizeof(int)*classical_registers);classical_states[classical_index++] = $1.num;}
                        ;

classical_state         :   NUMBER  {$$.num = $1.num;}
                        ;


gate_defn_section       :  {fprintf(fp,"Gate definition section begins\n");} gate_defn_list {fprintf(fp,"Gate definition section ends\n");}
                        |
                        ;

gate_defn_list          :   gate_defn_list gate_defn
                        |   gate_defn
                        ;

gate_defn               :   GATE ID '=' rhs {fprintf(fp,"Gate definition\n");}   {insertInGateTable(&GateSymbolTable,$2.str,$4.rows,$4.cols);}
                        ;

rhs                     :   '[' tuple_list ']'  {$$.rows = $2.rows;$$.cols = $2.cols;}
                        |   '{' tuple_list2 '}'

tuple_list              : tuple_list ',' '[' id_list ']' {if($1.cols != $4.cols){yyerror();return;}int temp; temp = $1.rows + 1;$$.rows = temp;$$.cols = $1.cols;}
                        | '[' id_list ']'                {$$.rows = 1;$$.cols = $2.cols;}

tuple_list2              : tuple_list2 ',' '(' id_list ')'
                        | '(' id_list ')'

id_list                 : id_list ',' temp   {$$.cols += 1;}
                        | temp               {$$.cols = 1;}


block_defn_section      :  {fprintf(fp,"Block definition section begins\n");} block_defns_list {fprintf(fp,"Block definition section ends\n");}
                        ;

block_defns_list        : block_defn block_defns_list 
                        |   /* epsilon */
                        ;

block_defn              : BLOCK block_id params target_params '[' block_body ']' {fprintf(fp,"Block definition\n");insertInBlockTable(&BlockSymbolTable,$2.str,head,head2);head = NULL;head2=NULL;}
                        ;

params                  :  ID                   {insertInList(&head,$1.str);}                  /* parantheses maybe ignored for single ID */
                        | '(' param_id_list ')' 
                        ;

param_id_list           : ID ',' param_id_list  {insertInList(&head,$1.str);}
                        | ID                    {insertInList(&head,$1.str);}
                        ;

target_params           : /* epsilon */                          /* optional */
                        | ARROW ID               {insertInList(&head2,$2.str);}
                        | ARROW '(' target_param_list ')'
                        ;

target_param_list       :   ID ',' target_param_list  {insertInList(&head2,$1.str);}
                        |   ID                        {insertInList(&head2,$1.str);}
                        ;

block_body              : 
                        | stmts block_body
                        ;

block_id                : ID      {$$ = $1;}/* check first letter capital here */
                        ;

/* ................
     MAIN SECTION 
   ................ 
*/

main_stmt_list          : main_stmt_list main_stmt
                        |
                        ;

main_stmt               : stmts
                        | barrier_stmt    {fprintf(fp,"barrier statement\n");}

stmts                   : call_stmt       
                        | measure_stmt    {fprintf(fp,"Measure statement\n");}
                        | {fprintf(fp,"Conditional statement begin\n");} condition_stmt {fprintf(fp,"Conditional statement end\n");}
                        | for_stmt        {fprintf(fp,"For statement\n");}
                        | for_lex_stmt    {fprintf(fp,"For - Lex statement\n");}
                        | for_zip_stmt    {fprintf(fp,"For - Zip statement\n");}
                        | while_stmt      {fprintf(fp,"while statement\n");}
                        ;

register                : NUMBER  /* check non negative*/
                        | ID
                        ;


/* separate rules for gate calls and block calls because same syntax means different things for both */
call_stmt               : classic_control GATE quantum_control ARROW register {fprintf(fp,"Pre - defined Gate call statement\n");}
                        | classic_control ID quantum_control ARROW register   {fprintf(fp,"user - defined Gate call statement\n");}
                        | GATE quantum_control ARROW register                 {fprintf(fp,"Pre - defined Gate call statement\n");}
                        | ID quantum_control ARROW register                   {fprintf(fp,"User - defined Gate call statement\n");}
                        | classic_control block_id parameters optional        {fprintf(fp,"Block call statement\n");}
                        | block_id parameters optional                        {fprintf(fp,"Block call statement\n");}
                        ;

parameters              : register
                        | '(' register_list ')'
                        ;

optional                : 
                        | ARROW target
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

arithmetic_expr         : arithmetic_expr '+' arithmetic_expr
                        | arithmetic_expr '-' arithmetic_expr
                        | arithmetic_expr '*' arithmetic_expr
                        | arithmetic_expr '/' arithmetic_expr
                        | arithmetic_expr '%' arithmetic_expr
                        | ID
                        | NUMBER
                        ;

expr                    : expr COMP expr
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

list_type               : LIST '[' prim_type ']'
                        ;

/* data_type               : prim_type
                        | list_type
                        ; */

bool_const              : TRUE
                        | FALSE
                        ;

num                     : DEC       {$$.real = $1.real;}
                        | NEG       {$$.real = $1.real;}
                        | EXP       {$$.real = $1.real;}
                        | NUMBER    {$$.real = $1.num;}
                        
complex_const           : '(' num ',' num ')'      {$$.cpx.real = $2.real; $$.cpx.imag = $4.real;}
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

state_const             : '{' temp ',' temp '}'    {$$.q.first = $2.cpx; $$.q.second = $4.cpx;}
                        ;

temp                    : complex_const   {$$.cpx = $1.cpx;}
                        | num             {$$.cpx.real = $1.real; $$.cpx.imag = 0;}
                        ;

prim_const              : bool_const
                        | complex_const
                        | matrix_const
                        | state_const
                        | NUMBER
                        | NEG
                        | DEC
                        | EXP
                        | STRING
                        ;

vec_const               : '[' vec_list ']'
                        ;

vec_list                : vec_list ',' prim_const
                        | prim_const
                        ;

/* Calls */
calls                   : ADD '(' out_rhs ',' out_rhs ')'
                        | SUB '(' out_rhs ',' out_rhs ')'
                        | DOT '(' out_rhs ',' out_rhs ')'
                        | STD_DEV '(' out_rhs ')'
                        | VAR '(' out_rhs ')'
                        | CONDENSE '(' out_rhs ',' NUMBER ')'
                        | CONDENSE '(' out_rhs ',' '(' uint_list ')' ')'
                        | SUM '(' out_rhs ')'
                        | AVG '(' out_rhs ')'
                        ;


uint_list               : uint_list ',' NUMBER
                        | NUMBER
                        ;

/* Expressions */
out_rhs                 : prim_const
                        | out_id
                        | out_id '[' NUMBER ']'
                        | out_id '[' NUMBER ']' '[' NUMBER ']' 
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
out_expr                : ID '=' out_rhs              {fprintf(fp,"expression statement\n");}
                        ;

decl                    : prim_type out_expr          {fprintf(fp,"Primitive datatype declaration statement\n");}
                        | list_type ID '=' vec_const  {fprintf(fp,"List datatype declaration statement\n");}
                        | list_type ID '=' calls      {fprintf(fp,"List datatype declaration statement\n");}
                        ;

/* Echo Statement */
echo_stmt               : ECHO '(' echo_list ')'      {fprintf(fp,"Echo statement\n");}
                        ;

echo_list               : echo_list ',' out_rhs
                        | out_rhs
                        ;

/* Save Statement */
save_stmt               : '\\' SAVE STRING            {fprintf(fp,"Save statement\n");}
                        ;

/* Control Statement */
out_control             : {fprintf(fp,"Output section conditional statement begins\n");} out_cond_stmt {fprintf(fp,"Output section conditional statement ends\n");}               
                        | out_for_stmt                {fprintf(fp,"For statement in output section\n");}
                        | out_for_lex_stmt            {fprintf(fp,"For - lex statement in output section\n");}
                        | out_for_zip_stmt            {fprintf(fp,"For - zip statement in output section\n");}
                        | out_while_stmt              {fprintf(fp,"while statement in output section\n");}
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
                        | 
                        ;

out_stmt                : out_control
                        | save_stmt
                        | echo_stmt
                        | out_expr
                        | decl
                        ;
%%

void insertInList(struct List** Head,char * data){
   struct List* newNode = (struct List*)malloc(sizeof(struct List));
   newNode->id = (char *)malloc(sizeof(char)*strlen(data));
   for(int i=0;i<strlen(data);i++){
      newNode->id[i] = data[i];
   }
   if(*Head == NULL){
      newNode->next = NULL;
   }
   else{
      newNode->next = *Head;
   }
   *Head = newNode;
}

void printList(struct List** head){
   struct List* temp = *head;
   while(temp!=NULL){
      printf("%s ",temp->id);
      temp = temp->next;
   }
   printf("\n");
}

void insertInBlockTable(struct BlockTable** Head,char * data,struct List* params,struct List* target_params){
   struct BlockTable* newNode = (struct BlockTable*)malloc(sizeof(struct BlockTable));
   newNode->id = (char *)malloc(sizeof(char)*strlen(data));
   for(int i=0;i<strlen(data);i++){
      newNode->id[i] = data[i];
   }
   newNode->params = params;
   newNode->target_params = target_params;
   if(*Head == NULL){
      newNode->next = NULL;
   }
   else{
      newNode->next = *Head;
   }
   *Head = newNode;
}

void printBlockTable(){
   struct BlockTable* temp = BlockSymbolTable;
   int x=1;
   while(temp != NULL){
      printf("%d. \n",x++);
      printf("%s \n",temp->id);
      printList(&(temp->params));
      printList(&(temp->target_params));
      temp = temp->next;
   }
}

void insertInGateTable(struct GateTable ** Head,char * data,int rows,int cols){
   struct GateTable* newNode = (struct GateTable*)malloc(sizeof(struct GateTable));
   newNode->id = (char *)malloc(sizeof(char)*strlen(data));
   for(int i=0;i<strlen(data);i++){
      newNode->id[i] = data[i];
   }
   newNode->rows = rows;
   newNode->cols = cols;
   if(*Head == NULL){
      newNode->next = NULL;
   }
   else{
      newNode->next = *Head;
   }
   *Head = newNode;
}

void printGateTable(struct GateTable ** GateSymbolTable){
   struct GateTable* temp = *GateSymbolTable;
   while(temp != NULL){
      printf("%s ",temp->id);
      printf("%d %d\n",temp->rows,temp->cols);
      temp = temp->next;
   }
}

int main(int argc,char* argv[])
{
  yyin = fopen(argv[1],"r");
  fp2 = fopen("tokens.txt","w");
  fp = fopen("output.parsed","w");
  yyparse();

  return 0;
}

void yyerror(){
   fprintf(fp,"Syntax error at line %d\n",line);
}