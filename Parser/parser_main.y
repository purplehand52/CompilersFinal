%{
   #define YYSTYPE struct st
   #include<stdio.h>
   #include<stdbool.h>
   #include<stdlib.h>
   #include "st.h"

   extern FILE* yyin,*fp2;
   extern int line;
   FILE * fp;

   int yylex();
   void yyerror();

   int classical_registers,quantum_registers,iterations,temp_type;
   int * classical_states,classical_index=0,quantum_index=0;
   struct Quantum* quantum_states;
   int isInBlock=0;

   struct List* head = NULL;
   struct List* id_list = NULL;
   struct BlockTable* BlockSymbolTable = NULL;
   struct GateTable* GateSymbolTable = NULL;

   /* Output Section */
   struct OutputSymbolEntry* OutputSymbolTable = NULL;
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

prgm                    : init_section main_section output_section {fprintf(fp,"\nParsing successful!\n");printBlockTable();}
                        ;

// sequence has been enforced for the initializations and definitions in the init section
init_section            :  '\\' INIT_BEGIN {fprintf(fp,"\nInit section begins\n\n");} mandatory_init set_states block_defn_section gate_defn_section '\\' INIT_END {fprintf(fp,"\nInit section ends\n");}
                        ;   

main_section            :  '\\'  MAIN_BEGIN {fprintf(fp,"\nMain section begins\n\n");} main_stmt_list '\\' MAIN_END {fprintf(fp,"\nMain section ends\n");}
                        ;

output_section          :  '\\' OUTPUT_BEGIN {fprintf(fp,"\nOutput section begins\n\n");} out_main '\\' OUTPUT_END {fprintf(fp,"\nOutput section ends\n"); $1.level = 1}
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

block_defn              : BLOCK block_id params target_params {insertInBlockTable(&BlockSymbolTable,$2.str,$3.num,head);head = NULL;isInBlock = 1;}'[' block_body ']' {fprintf(fp,"Block definition\n");if(!BlockSemanticCheck($2.str)){yyerror();return;}id_list = NULL;isInBlock = 0;}
                        ;

params                  :  ID                   {insertInList(&head,$1.str);$$.num = 1;}                  /* parantheses maybe ignored for single ID */
                        | '(' param_id_list ')' {$$.num = $2.num;}
                        ;

param_id_list           : ID ',' param_id_list  {insertInList(&head,$1.str);$$.num = 1 + $3.num;}
                        | ID                    {insertInList(&head,$1.str);$$.num = 1;}
                        ;

target_params           : /* epsilon */                          /* optional */
                        | ARROW '(' target_param_list ')'
                        ;

target_param_list       :   ID ',' target_param_list  
                        |   ID                        
                        ;

block_body              : 
                        | stmts block_body
                        ;

block_id                : ID      {if(!firstLetterCapital($1.str)){yyerror(); return;} $$.str = $1.str;}/* check first letter capital here */
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

register                : NUMBER  {if($1.num < 0){yyerror(); return;} $$.num = $1.num;}/* check non negative*/
                        | ID      {if(isInBlock){insertInList(&id_list,$1.str);}}
                        ;


/* separate rules for gate calls and block calls because same syntax means different things for both */
call_stmt               : classic_control GATE quantum_control ARROW register {fprintf(fp,"Pre - defined Gate call statement\n");}
                        | classic_control ID quantum_control ARROW register   {fprintf(fp,"user - defined Gate call statement\n");}
                        | GATE quantum_control ARROW register                 {fprintf(fp,"Pre - defined Gate call statement\n");}
                        | ID quantum_control ARROW register                   {fprintf(fp,"User - defined Gate call statement\n");}
                        | classic_control block_id parameters optional        {fprintf(fp,"Block call statement\n");if(!isInBlock){if(!BlockCallSemanticCheck($2.str,$3.num)){yyerror();return;}}}
                        | block_id parameters optional                        {fprintf(fp,"Block call statement\n");if(!isInBlock){if(!BlockCallSemanticCheck($1.str,$2.num)){yyerror();return;}}}
                        ;

parameters              : register                 {$$.num = 1;}
                        | '(' register_list ')'    {$$.num = $2.num;}
                        ;

optional                : 
                        | ARROW target
                        ;

register_list           : register_list ',' register  {$$.num = 1 + $1.num;}
                        | register                    {$$.num = 1;}
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


measure_stmt            : MEASURE ':' register ARROW register {if(($3.num < 0 || $3.num >= quantum_registers) || ($5.num < 0 || $5.num >= classical_registers)){yyerror(); return;}} /* check if register1 and register2 are in bounds */
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

range_list              : range_list ',' range     {$$.num = 1 + $1.num;}
                        | range                    {$$.num = 1;}
                        ;

var_list                : var_list ',' ID    {if(!inList(&head,$3.str)){insertInList(&head,$3.str)} else {yyerror(); return;} $$.num = 1 + $1.num;}
                        | ID                 {if(!inList(&head,$1.str)){insertInList(&head,$1.str)} else {yyerror(); return;} $$.num = 1;}
                        ;

for_stmt                : FOR ID {if(!inList(&head,$2.str)){insertInList(&head,$2.str)} else {yyerror(); return;}} IN '(' range ')' '{' main_stmt_list '}' {removeTopKFromList(&head,1);}
                        ;

for_lex_stmt            : FOR_LEX '(' var_list ')' IN '(' range_list ')' {if($3.num != $7.num){yyerror(); return;}} '{' main_stmt_list '}' {removeTopKFromList(&head,$3.num);}
                        ;

for_zip_stmt            : FOR_ZIP '(' var_list ')' IN '(' range_list ')' {if($3.num != $7.num){yyerror(); return;}} '{' main_stmt_list '}' {removeTopKFromList(&head,$3.num);}
                        ;

while_stmt              : WHILE '(' expr ')' '{' main_stmt_list '}'
                        ;

// /* ................ 
//     OUTPUT SECTION 
//    ................
// */

/* Datatypes */
out_id                  : ID | COUT | QOUT ;

prim_type               : INT       {$$.type = INT;}
                        | UINT      {$$.type = UINT;}
                        | FLOAT     {$$.type = FLOAT;}
                        | COMPLEX   {$$.type = COMPLEX;}
                        | STRING    {$$.type = STRING;}
                        | MATRIX    {$$.type = MATRIX;}
                        | STATE     {$$.type = STATE;}
                        | BOOL      {$$.type = BOOL;}
                        ;

list_type               : LIST '[' prim_type ']' {$$.type = $3.type;}
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

matrix_const            : '[' row_list ']'         {$$.rows = $2.rows; $$.columns = $2.columns;}
                        ;

row_list                : row_list ',' row         {$$.rows = $1.rows + 1; if($1.columns == $3.columns) $$.columns = $1.columns else yyerror();}
                        | row                      {$$.rows = 1; $$.columns = $1.columns;}
                        ;

row                     : '[' comps ']'            {$$.columns = $2.columns;}
                        ;

comps                   : comps ',' complex_const  {$$.columns = $1.columns + 1;}
                        | complex_const            {$$.columns = 1;}
                        ;

state_const             : '{' temp ',' temp '}'    {$$.q.first = $2.cpx; $$.q.second = $4.cpx;}
                        ;

temp                    : complex_const   {$$.cpx = $1.cpx;}
                        | num             {$$.cpx.real = $1.real; $$.cpx.imag = 0;}
                        ;

prim_const              : bool_const {$$.type = Bool;}
                        | complex_const {$$.type = Complex;}
                        | matrix_const {$$.type = Matrix;}
                        | state_const {$$.type = State;}
                        | NUMBER {$$.type = Uint;}
                        | NEG {$$.type = Int;}
                        | DEC {$$.type = Float;}
                        | EXP {$$.type = Float;}
                        | STRING {$$.type = String;}
                        ;

vec_const               : '[' vec_list ']'        {$$.dim = $2.dim; $$.type = $2.type;}
                        ;

vec_list                : vec_list ',' prim_const {temp_type = compatibleCheck($1.type, $3.type); if(temp_type != -1) $$.type = temp_type else yyerror(); $$.dim = $1.dim + 1;}
                        | prim_const              {$$.type = $1.type; $$.dim = 1;}
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

/* Expressions : Needs to be modified !!!! (Will do after class)*/
out_rhs                 : prim_const                                             {$$.type = $1.type;}
                        | out_id                                                 {$$.type = $1.type;}
                        | out_id '[' NUMBER ']'
                        | out_id '[' NUMBER ']' '[' NUMBER ']'
                        | out_id '[' NUMBER ']' '[' NUMBER ']' '[' NUMBER ']' 
                        | calls
                        | '(' out_rhs ')'                                        {$$.type = $2.type;}
                        | '!' out_rhs                                             
                        | out_rhs AND out_rhs
                        | out_rhs OR out_rhs
                        | out_rhs COMP out_rhs
                        | out_rhs EQUALITY out_rhs
                        | out_rhs '*' out_rhs                                    {temp_type = compatibleCheck($1.type, $3.type); if((temp_type >= Int) && (temp_type < COMPATIBLE)) $$.type = temp_type else yyerror();}
                        | out_rhs '/' out_rhs                                    {temp_type = compatibleCheck($1.type, $3.type); if((temp_type >= Int) && (temp_type < COMPATIBLE)) $$.type = temp_type else yyerror();}
                        | out_rhs '+' out_rhs                                    {temp_type = compatibleCheck($1.type, $3.type); if((temp_type >= Int) && (temp_type < COMPATIBLE)) $$.type = temp_type else yyerror();}
                        | out_rhs '-' out_rhs                                    {temp_type = compatibleCheck($1.type, $3.type); if((temp_type >= Int) && (temp_type < COMPATIBLE)) $$.type = temp_type else yyerror();}
                        | out_rhs '@' out_rhs                                    {temp_type = compatibleCheck($1.type, $3.type); if((temp_type >= Int) && (temp_type < COMPATIBLE)) $$.type = temp_type else yyerror();}
                        | out_rhs '&' out_rhs                                    {temp_type = compatibleCheck($1.type, $3.type); if((temp_type >= Int) && (temp_type < COMPATIBLE)) $$.type = temp_type else yyerror();}
                        | out_rhs '^' out_rhs                                    {temp_type = compatibleCheck($1.type, $3.type); if((temp_type >= Int) && (temp_type < COMPATIBLE)) $$.type = temp_type else yyerror();}
                        | out_rhs '|' out_rhs                                    {temp_type = compatibleCheck($1.type, $3.type); if((temp_type >= Int) && (temp_type < COMPATIBLE)) $$.type = temp_type else yyerror();}
                        ;

/* Expressions */
out_expr                : ID '=' out_rhs              {fprintf(fp,"expression statement\n"); insertInOutputTable(&OutputSymbolTable,$1.str,$$.type,/* complete these arguments */,$$.level);}
                        ;

decl                    : prim_type out_expr          {fprintf(fp,"Primitive datatype declaration statement\n"); $2.type = $1.type;}
                        | list_type ID '=' vec_const  {fprintf(fp,"List datatype declaration statement\n"); insertInOutputTable(&OutputSymbolTable,$2.str,$1.type,/* complete these arguments */,$$.level);}
                        | list_type ID '=' calls      {fprintf(fp,"List datatype declaration statement\n"); insertInOutputTable(&OutputSymbolTable,$2.str,$1.type,/* complete these arguments */,$$.level);}
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
out_control             : {fprintf(fp,"Output section conditional statement begins\n");} out_cond_stmt {fprintf(fp,"Output section conditional statement ends\n"); $1.type = $$.type + 1;}
                        | out_for_stmt                {fprintf(fp,"For statement in output section\n"); $1.type = $$.type;}
                        | out_for_lex_stmt            {fprintf(fp,"For - lex statement in output section\n"); $1.type = $$.type;}
                        | out_for_zip_stmt            {fprintf(fp,"For - zip statement in output section\n"); $1.type = $$.type;}
                        | out_while_stmt              {fprintf(fp,"while statement in output section\n"); $1.type = $$.type;}
                        ;

out_cond_stmt           : CONDITION '(' out_rhs ')' '{' out_main {$6.type = $$.type + 1;} '}' out_other_list out_other_final
                        ;

out_other_list          : out_other_list OTHERWISE '(' out_rhs ')' '{' out_main '}'
                        | /* epsilon */
                        ;

out_other_final         : OTHERWISE '{' out_main '}'
                        | /* epsilon */
                        ;

out_for_stmt            : FOR ID IN '(' range ')' '{' out_main {$8.type = $$.type + 1;} '}'
                        ;

out_for_lex_stmt        : FOR_LEX '(' var_list ')'  IN '(' range_list ')' '{' out_main {$10.type = $$.type + 1;} '}'
                        ;

out_for_zip_stmt        : FOR_ZIP '(' var_list ')'  IN '(' range_list ')' '{' out_main {$10.type = $$.type + 1;}'}'
                        ;

out_while_stmt          : WHILE '(' expr ')' '{' out_main {$6.type = $$.type + 1;} '}'
                        ;


/* Output Statement */
out_main                : out_main out_stmt           {$1.level = $$.level; $2.level = $$.level}
                        | 
                        ;

// TODO: structure
out_stmt                : out_control                 {$1.level = $$.level;}
                        | save_stmt
                        | echo_stmt
                        | out_expr                    {$1.level = $$.level;}
                        | decl                        {$1.level = $$.level;}
                        ;
%%

bool firstLetterCapital(char *str) {
   return (str[0] >= 65 && str[0] <= 90);
}

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

void removeTopKFromList(struct List** Head, int k) {
   if(*Head == NULL) return false;

   struct List* temp = *Head;
   while(k--) {
      struct List* toDelete = temp;
      temp = temp->next;
      free(toDelete);
   }
   *Head = temp;
}

bool inList(struct List** Head, char* data) {
   if(*Head == NULL) return false;

   struct List* temp = *Head;
   while(temp != NULL) {
      if(strcmp(temp->id, data) == 0) return true;
      temp = temp->next;
   }
   return false;
}

void printList(struct List** Head){
   struct List* temp = *Head;
   while(temp!=NULL){
      printf("%s ",temp->id);
      temp = temp->next;
   }
   printf("\n");
}

void insertInBlockTable(struct BlockTable** Head,char * data,int len,struct List* params){
   struct BlockTable* newNode = (struct BlockTable*)malloc(sizeof(struct BlockTable));
   newNode->id = (char *)malloc(sizeof(char)*strlen(data));
   for(int i=0;i<strlen(data);i++){
      newNode->id[i] = data[i];
   }
   newNode->params = params;
   newNode->len = len;
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
   while(temp != NULL){
      printf("%s \n",temp->id);
      printList(&(temp->params));
      printf("%d\n\n",temp->len);
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

/* Output Section */
void insertInOutputTable(struct OutputSymbolEntry** Head, char* id, int type, bool primitive, int dim, int level){
   /* New Entry */
   struct OutputSymbolEntry* newNode = (struct OutputSymbolEntry*)malloc(sizeof(struct OutputSymbolEntry));
   
   /* ID */
   newNode->id = (char *)malloc(sizeof(char)*strlen(id));
   for(int i=0;i<strlen(id);i++){
      newNode->id[i] = data[i];
   }

   /* Type */
   newNode->type = type;
   
   /* Primitive */
   newNode->primitive = primitive;

   /* Dimensions  */
   newNode->dim = dim;

   /* Scope Level */
   newNode->level = level;

   /* Append */
   if(*Head == NULL){
      newNode->next = NULL;
   }
   else{
      newNode->next = *Head;
   }
   *Head = newNode;
}

void printOutputTable(struct OutputSymbolEntry ** OutputSymbolTable){
   struct OutputSymbolEntry* temp = *OutputSymbolTable;
   while(temp != NULL){
      printf("%s ",temp->id);
      printf("%d %d %d\n",temp->id, temp->primitive, temp->dim);
      /* Check for scopes here! */
      temp = temp->next;
   }
}

int compatibleCheck(int t1, int t2)
{
   if(t1 == t2) return t1;
   else if((t1 < COMPATIBLE) && (t1 > t2)) return t1;
   else if((t2 < COMPATIBLE) && (t2 > t1)) return t2;
   else -1;
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
   printf("Error\n");
   fprintf(fp,"Syntax error at line %d\n",line);
}