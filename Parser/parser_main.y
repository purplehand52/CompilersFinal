%{
   #define YYSTYPE struct st
   #include<stdio.h>
   #include<stdbool.h>
   #include<stdlib.h>
   #include "st.h"

   #define HELLO printf("HELLO\n");

   extern FILE* yyin,*fp2;
   extern int line;
   FILE * fp;
// comment
   int yylex();
   void yyerror();

   int classical_registers,quantum_registers,iterations,temp_type;
   int * classical_states,classical_index=0,quantum_index=0;
   struct Quantum* quantum_states;
   int isInBlock=0;
   int outputLevel = 0;
   bool isInOutput = false;
   bool isDeclaration = false;

   struct List* head = NULL;
   struct List* id_list = NULL;
   struct BlockTable* BlockSymbolTable = NULL;
   struct GateTable* GateSymbolTable = NULL;

   /* Output Section */
   struct OutputSymbolEntry* OutputSymbolTable = NULL;

   bool firstLetterCapital(char *str);
   struct OutputSymbolEntry* getOutputSymbolEntry(struct OutputSymbolEntry** Head, char* id, int level, int findFlag); // declaration
   bool inList(struct List** Head, char* data);
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

prgm                    : init_section main_section output_section {fprintf(fp,"\nParsing successful!\n");}
                        ;

// sequence has been enforced for the initializations and definitions in the init section
init_section            :  '\\' INIT_BEGIN {fprintf(fp,"\nInit section begins\n\n");} mandatory_init set_states block_defn_section gate_defn_section '\\' INIT_END {fprintf(fp,"\nInit section ends\n");}
                        ;   

main_section            :  '\\'  MAIN_BEGIN {fprintf(fp,"\nMain section begins\n\n");} main_stmt_list '\\' MAIN_END {fprintf(fp,"\nMain section ends\n");}
                        ;

output_section          :  '\\' OUTPUT_BEGIN {fprintf(fp,"\nOutput section begins\n\n"); isInOutput = true; outputLevel = 1;} out_main  '\\' OUTPUT_END {fprintf(fp,"\nOutput section ends\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel);}
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
                        | ARROW target_param_list
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

register                : NUMBER  {if($1.num < 0){yyerror(); return;} $$.num = $1.num;$$.flag=0;}/* check non negative*/
                        | ID      {if(isInBlock){insertInList(&id_list,$1.str);}$$.flag = 1;}
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


measure_stmt            : MEASURE ':' register ARROW register {if((!$3.flag && ($3.num < 0 || $3.num >= quantum_registers)) || (!$5.flag && ($5.num < 0 || $5.num >= classical_registers))){yyerror(); return;}} /* check if register1 and register2 are in bounds */
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

var_list                : var_list ',' ID    {if(isInOutput){if(getOutputSymbolEntry(&OutputSymbolTable,$3.str,outputLevel + 1,0) != NULL){yyerror(); return;} else insertInOutputTable(&OutputSymbolTable,$2.str,outputLevel + 1, Int,true,0,0,true);} else if(!inList(&head,$3.str)){insertInList(&head,$3.str);} else {yyerror(); return;} $$.num = 1 + $1.num;}
                        | ID                 {if(isInOutput){if(getOutputSymbolEntry(&OutputSymbolTable,$1.str,outputLevel + 1,0) != NULL){yyerror(); return;} else insertInOutputTable(&OutputSymbolTable,$1.str,outputLevel + 1, Int,true,0,0,true);} else if(!inList(&head,$1.str)){insertInList(&head,$1.str);} else {yyerror(); return;} $$.num = 1;}
                        ;

for_stmt                : FOR ID {if(!inList(&head,$2.str)){insertInList(&head,$2.str);} else {yyerror(); return;}} IN '(' range ')' '{' main_stmt_list '}' {removeTopKFromList(&head,1);}
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
out_id                  : ID {$$.out_flag = 0; $$.str = $1.str;}
                        | COUT {$$.out_flag = 1; $$.type = Int; $$.prim = false; $$.dim = (1 << classical_registers); $$.rows = 0;}
                        | QOUT {$$.out_flag = 2; $$.type = State; $$.prim = false; $$.dim = quantum_registers; $$.rows = 0;}
                        ;

prim_type               : INT       {$$.type = Int; $$.prim = true;}
                        | UINT      {$$.type = Uint; $$.prim = true;}
                        | FLOAT     {$$.type = Float; $$.prim = true;}
                        | COMPLEX   {$$.type = Complex; $$.prim = true;}
                        | STRING    {$$.type = String; $$.prim = true;}
                        | MATRIX    {$$.type = Matrix; $$.prim = true;}
                        | STATE     {$$.type = State; $$.prim = true;}
                        | BOOL      {$$.type = Bool; $$.prim = true;}
                        ;

list_type               : LIST '[' prim_type ']' {$$.type = $3.type; $$.prim = false;}
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

matrix_const            : '[' row_list ']'         {if($2.rows == $2.cols) {$$.rows = $2.rows;} else {yyerror(); return;}}
                        ;

row_list                : row_list ',' row         {$$.rows = $1.rows + 1; if($1.cols == $3.cols) {$$.cols = $1.cols;} else {yyerror(); return;}}
                        | row                      {$$.rows = 1; $$.cols = $1.cols;}
                        ;

row                     : '[' comps ']'            {$$.cols = $2.cols;}
                        ;

comps                   : comps ',' compatible_const  {$$.cols = $1.cols + 1;}
                        | compatible_const            {$$.cols = 1;}
                        ;

compatible_const        : complex_const
                        | num
                        ;

state_const             : '{' temp ',' temp '}'    {$$.q.first = $2.cpx; $$.q.second = $4.cpx;}
                        ;

temp                    : complex_const   {$$.cpx = $1.cpx;}
                        | num             {$$.cpx.real = $1.real; $$.cpx.imag = 0;}
                        ;

prim_const              : bool_const      {$$.type = Bool;}
                        | complex_const   {$$.type = Complex;}
                        | matrix_const    {$$.type = Matrix; $$.rows = $1.rows;}
                        | state_const     {$$.type = State;}
                        | NUMBER          {$$.type = Uint;}
                        | NEG             {$$.type = Int;}
                        | DEC             {$$.type = Float;}
                        | EXP             {$$.type = Float;}
                        | STRING          {$$.type = String;}
                        ;

vec_const               : '[' vec_list ']'        {$$.dim = $2.dim; $$.type = $2.type; if($$.type == Matrix) {$$.rows = $2.rows;} else {$$.rows = 0;} }
                        ;

vec_list                : vec_list ',' prim_const {temp_type = compatibleCheck($1.type, $3.type); if(temp_type != -1) {$$.type = temp_type;} else {yyerror(); return;} $$.dim = $1.dim + 1; if($$.type == Matrix){ if($1.rows != $3.rows){yyerror();return;}else{$$.rows = $1.rows;} }}
                        | prim_const              {$$.type = $1.type; $$.dim = 1; if($$.type == Matrix) {$$.rows = $1.rows;}}
                        ;

/* Calls : Must Define Dimensions */
calls                   : ADD '(' out_rhs ',' out_rhs ')'   /* List (uint, int, float, complex, matrix, string??) */ {temp_type = compatibleCheckAdv($5.type, $3.type, $5.prim, $3.prim, $5.dim, $3.dim); printf("%d\n", temp_type); if((!$3.prim) && (temp_type>= 0) && ((temp_type<=COMPATIBLE) || temp_type==Matrix /*|| temp_type==String*/)) {$$.prim = false; $$.type = temp_type; $$.dim = $3.dim;} else {yyerror(); return;}}
                        | SUB '(' out_rhs ',' out_rhs ')'   /* List (uint, int, float, complex, matrix) */           {temp_type = compatibleCheckAdv($5.type, $3.type, $5.prim, $3.prim, $5.dim, $3.dim); if((!$3.prim) && (temp_type>= 0) && ((temp_type<=COMPATIBLE) || temp_type==Matrix)) {$$.prim = false; $$.type = temp_type; $$.dim = $3.dim;} else {yyerror(); return;}}      
                        | DOT '(' out_rhs ',' out_rhs ')'   /* List (uint, int, float, complex) List(Comp*Mat)*/     {temp_type = compatibleCheckAdv($5.type, $3.type, $5.prim, $3.prim, $5.dim, $3.dim); if((!$3.prim) && (temp_type>= 0) && (temp_type<=COMPATIBLE)) {$$.prim = true; $$.type = temp_type; $$.dim = $3.dim;} else if ((!$3.prim) && (!$5.prim) && ($3.type<=COMPATIBLE) && ($5.type==Matrix)) {$$.prim = true; $$.type = Matrix; $$.dim = 0;} else yyerror();}        
                        | STD_DEV '(' out_rhs ')'           /* List (uint, int) */                                   {if((!$3.prim) && (($3.type==Uint) || ($3.type==Int) || ($3.type==Float))) {$$.prim = true; $$.type = $3.type; $$.dim = $3.dim;} else {yyerror(); return;}}   
                        | VAR '(' out_rhs ')'               /* List (uint, int) */                                   {if((!$3.prim) && (($3.type==Uint) || ($3.type==Int) || ($3.type==Float))) {$$.prim = true; $$.type = $3.type; $$.dim = $3.dim;} else {yyerror(); return;}}
                        | CONDENSE '(' out_rhs ',' NUMBER ')'     /* List (uint, int)  with reduction */             {if((!$3.prim) && (($3.type==Uint) || ($3.type==Int))) {$$.prim = false; $$.type = $3.type; $$.dim = condenser($3.dim, 1);} else {yyerror(); return;}}
                        | CONDENSE '(' out_rhs ',' '(' uint_list ')' ')'   /* List (uint, int) with reduction */     {if((!$3.prim) && (($3.type==Uint) || ($3.type==Int))) {$$.prim = false; $$.type = $3.type; $$.dim = condenser($3.dim, $6.cond_count);} else {yyerror(); return;}}
                        | SUM '(' out_rhs ')'               /* List (uint, int, float, complex, matrix, string??) */ {if((!$3.prim) && (($3.type<=COMPATIBLE) || $3.type==Matrix /*|| temp_type==String*/)) {$$.prim = true; $$.type = $3.type; $$.dim = 0;} else {yyerror(); return;}}
                        | AVG '(' out_rhs ')'               /* List (uint, int, float, complex, matrix) */           {if((!$3.prim) && (($3.type<=COMPATIBLE) || $3.type==Matrix)) {$$.prim = true; $$.type = $3.type; $$.dim = 0;} else {yyerror(); return;}}
                        /*| REAL */
                        /*| IMAG */
                        ;


uint_list               : uint_list ',' out_rhs  {if($1.type <= Int) {$$.cond_count = $1.cond_count + 1;} else {yyerror(); return;}}
                        | out_rhs                {if($1.type <= Int) {$$.cond_count = 1;} else {yyerror(); return;}}
                        ;

/* Expressions :*/
out_rhs                 : prim_const                                             {$$.prim = true; $$.type = $1.type;}
                        | vec_const                                              {$$.prim = false; $$.dim = $1.dim; $$.type = $1.type; if($$.type == Matrix) {$$.rows = $1.rows;} else {$$.rows = 0;}}
                        | out_id                                                 {if($$.out_flag == 0){struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,$1.str,outputLevel,0); if(sample != NULL){$$.prim = sample->primitive; $$.type = sample->type; if($$.type == Matrix){$$.rows = sample->matrix_dim;} if(!$$.prim){$$.dim = sample->dim;}} else{yyerror(); return;}} else if($$.out_flag == 1){$$.type = Int; $$.prim = false; $$.dim = (1 << classical_registers); $$.rows = 0;} else{$$.type = State; $$.prim = false; $$.dim = quantum_registers; $$.rows = 0;}}
                        | out_id '[' out_rhs ']'                                 {if($$.out_flag == 0){struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,$1.str,outputLevel,0); if(sample != NULL){if($3.type <= Uint){if(sample->primitive) {if(sample->type==State) {$$.type = Complex; $$.prim = true;} else {yyerror(); return;}} else {$$.type = sample->type; $$.prim = true;}} else {yyerror(); return;}} else{yyerror(); return;}} else if($$.out_flag == 1){$$.type = Uint; $$.prim = true;} else{$$.type = State; $$.prim = true;}}
                        | out_id '[' out_rhs ']' '[' out_rhs ']'                 {if($$.out_flag == 0){struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,$1.str,outputLevel,0); if(sample != NULL){if(($3.type <= Uint) && ($5.type <= Uint)) {if(sample->type) {if(sample->type==Matrix) {$$.type = Complex; $$.prim = true;} else {yyerror(); return;}} else if(sample->type==State) {$$.type = Complex; $$.prim = true;} else {yyerror(); return;}}} else{yyerror(); return;}} else if($$.out_flag == 1){yyerror(); return;} else{$$.type = Complex; $$.prim = true;}}
                        | out_id '[' out_rhs ']' '[' out_rhs ']' '[' out_rhs ']' {if($$.out_flag == 0){struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,$1.str,outputLevel,0); if(sample != NULL){if(($3.type <= Uint) && ($5.type <= Uint) && ($7.type <= Uint)) {if(sample->primitive) {yyerror(); return;} else if(sample->type==Matrix) {$$.type = Complex; $$.prim = true;} else {yyerror(); return;}}} else{yyerror(); return;}} else{yyerror(); return;}}
                        | calls                                                  {$$.prim = $1.prim; $$.type = $1.type; if($1.type == Matrix){$$.rows = $1.rows;} if(!$$.prim){$$.dim = $1.dim;} printf("%d %d\n", $$.prim, $$.type);}
                        | '(' out_rhs ')'                                        {$$.type = $2.type;}
                        | '!' out_rhs                                            {if($2.type==Bool && $2.prim) {$$.prim = true; $$.type = Bool;} else {yyerror(); return;}  }                         
                        | out_rhs AND out_rhs                                    {if($1.type==Bool && $1.prim && $3.type==Bool && $3.prim)  {$$.prim = true; $$.type = Bool;} else {yyerror(); return;} }
                        | out_rhs OR out_rhs    /* works for bools */            {if($1.type==Bool && $1.prim && $3.type==Bool && $3.prim)  {$$.prim = true; $$.type = Bool;} else {yyerror(); return;} }
                        | out_rhs COMP out_rhs  /* Check compatible */           {temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); if(temp_type != -1 && temp_type < COMPARABLE) {$$.prim = true; $$.type = Bool;} else {yyerror(); return;}  }
                        | out_rhs EQUALITY out_rhs                               {temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); if(temp_type != -1 && temp_type < COMPARABLE) {$$.prim = true; $$.type = Bool;} else {yyerror(); return;}  }
                        | out_rhs '*' out_rhs   /* Works for uint, int, float, complex, string-multiplication, complex*Matrix */                                  {temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); if($1.prim && (temp_type <= Complex && temp_type >= 0)) {$$.prim = true; $$.type = temp_type;} else if($1.prim && $3.prim && $1.type<=Complex && $3.type==Matrix) {$$.prim = true; $$.type = Matrix;} else if (($1.prim && $3.prim) && (($1.type == String && $3.type == Uint) || ($3.type == String && $1.type == Uint))) {$$.prim = true; $$.type = String;} else {yyerror(); return;}}
                        | out_rhs '/' out_rhs   /* Works for uint, int, float, complex */                                                                         {temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); if($1.prim && (temp_type <= Complex && temp_type >= 0)) {$$.prim = true; $$.type = temp_type;} else {yyerror(); return;}}
                        | out_rhs '+' out_rhs   /* Works for uint, int, float, complex, matrix, list (uint, int, float, complex, matrix), string-concatenate */   {temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); if(temp_type == Matrix || (temp_type <= Complex && temp_type >= 0)) {$$.prim = $1.prim; $$.type = temp_type; if(temp_type == Matrix) {$$.rows=$1.rows;} $$.dim=$1.dim;} else if (($1.prim==true) && ($1.type == String)) {$$.prim = true; $$.type = String;} else {yyerror(); return;}}
                        | out_rhs '-' out_rhs   /* Works for uint, int, float, complex, matrix, list (uint, int, float, complex, matrix) */                       {temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); if(temp_type == Matrix || (temp_type <= Complex && temp_type >= 0)) {$$.prim = $1.prim; $$.type = temp_type; if(temp_type == Matrix) {$$.rows=$1.rows;} $$.dim=$1.dim;} else {yyerror(); return;} }
                        | out_rhs '@' out_rhs   /*Works for matrix, list (uint, int, float, complex); list(complex)*list(matrix)*/                                {temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); /*printf("%d\n", temp_type);*/ if($1.prim && temp_type == Matrix) {if($1.rows == $3.rows) {$$.prim = true; $$.type = temp_type; $$.rows = $1.rows;} else {yyerror(); return;}} else if(!$1.prim && (temp_type <= COMPATIBLE) && (temp_type >= 0)) {$$.prim = true; $$.type = temp_type; $$.dim = 0;} else if ($1.type<=COMPATIBLE && $3.type==Matrix) {$$.prim = true; $$.type = Matrix; $$.dim = 0;} else {yyerror(); return;}}
                        //| matrix_const '@' matrix_const     {if($1.rows == $3.rows){$$.type == Matrix; $$.rows == $1.rows; $$.prim = true;} else{yyerror();return;}}
                        //| vec_const '@' vec_const           {temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); if(temp_type <= COMPATIBLE) {$$.type = temp_type; $$.prim = true;} else if($1.type == Complex && $3.type == Matrix) {$$.type = Matrix; $$.prim = true; $$.rows = $3.rows;}}
                        | out_rhs '&' out_rhs   /* Works for uint, int, list(uint, int)*/                                                                         {temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); if(temp_type <= Int) {$$.prim = $1.prim; $$.type = temp_type;} else {yyerror(); return;}}
                        | out_rhs '^' out_rhs   /* Works for uint, int, list(uint, int)*/                                                                         {temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); if(temp_type <= Int) {$$.prim = $1.prim; $$.type = temp_type;} else {yyerror(); return;}}
                        | out_rhs '|' out_rhs   /* Works for uint, int, list(uint, int) */                                                                        {temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); if(temp_type <= Int) {$$.prim = $1.prim; $$.type = temp_type;} else {yyerror(); return;}}
                        ;

/* Expressions */
out_expr                : ID '=' out_rhs              {fprintf(fp,"expression statement\n"); if(isDeclaration){$$.type = $3.type; $$.str = $1.str; $$.prim = $3.prim; if(!$3.prim){$$.dim = $3.dim;} if($3.type == Matrix){$$.rows = $3.rows;} } else {struct OutputSymbolEntry* entry = getOutputSymbolEntry(&OutputSymbolTable,$1.str,outputLevel,1); if(entry->type != $3.type){yyerror(); return;}}}
                        ;

decl                    : prim_type out_expr          {fprintf(fp,"Primitive datatype declaration statement\n"); if( ($2.prim==false) || (($1.type < COMPATIBLE) && ($1.type < $2.type)) || (($1.type >= COMPATIBLE) && ($1.type != $2.type)) || getOutputSymbolEntry(&OutputSymbolTable,$2.str,outputLevel,0) != NULL){yyerror(); return;} else {if($2.type == Matrix) {insertInOutputTable(&OutputSymbolTable,$2.str,outputLevel,$2.type,true,$2.rows,0,false);} else {insertInOutputTable(&OutputSymbolTable,$2.str,outputLevel,$2.type,true,0,0,false);}}}
                        //| list_type ID '=' vec_const  {fprintf(fp,"List datatype declaration statement\n"); if((($1.type < COMPATIBLE) && ($1.type < $4.type)) || (($1.type >= COMPATIBLE) && ($1.type != $4.type)) || getOutputSymbolEntry(&OutputSymbolTable,$2.str,outputLevel,0) != NULL){yyerror(); return;} else insertInOutputTable(&OutputSymbolTable,$2.str,outputLevel,$1.type,false,$4.rows,$4.dim,false);}
                        | list_type out_expr          {fprintf(fp,"List datatype declaration statement\n"); if( ($2.prim==true) || (($1.type < COMPATIBLE) && ($1.type < $2.type)) || (($1.type >= COMPATIBLE) && ($1.type != $2.type)) || getOutputSymbolEntry(&OutputSymbolTable,$2.str,outputLevel,0) != NULL){yyerror(); return;} else {if($2.type == Matrix) {insertInOutputTable(&OutputSymbolTable,$2.str,outputLevel,$1.type,false,$2.rows,$2.dim,false);} else {insertInOutputTable(&OutputSymbolTable,$2.str,outputLevel,$1.type,false,0,$2.dim,false);}}}
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

out_cond_stmt           : CONDITION '(' out_rhs ')' '{' {outputLevel++;} out_main '}' out_other_list out_other_final {outputLevel--;}
                        ;

out_other_list          : out_other_list OTHERWISE '(' out_rhs ')' '{' out_main '}'
                        | /* epsilon */
                        ;

out_other_final         : OTHERWISE '{' out_main '}'
                        | /* epsilon */
                        ;

out_for_stmt            : FOR ID {if(getOutputSymbolEntry(&OutputSymbolTable,$2.str,outputLevel + 1,0) != NULL){yyerror(); return;} else insertInOutputTable(&OutputSymbolTable,$2.str,outputLevel + 1,Int,true,0,0,true);} IN '(' range ')' '{' {outputLevel++;} out_main '}' {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
                        ;

out_for_lex_stmt        : FOR_LEX '(' var_list ')'  IN '(' range_list ')' {if($3.num != $7.num){yyerror(); return;}} '{' {outputLevel++;} out_main '}' {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
                        ;

out_for_zip_stmt        : FOR_ZIP '(' var_list ')'  IN '(' range_list ')' {if($3.num != $7.num){yyerror(); return;}} '{' {outputLevel++;} out_main '}' {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
                        ;

out_while_stmt          : WHILE '(' expr ')' '{' {outputLevel++;} out_main '}' {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
                        ;


/* Output Statement */
out_main                : out_main out_stmt
                        |
                        ;

out_stmt                : out_control
                        | save_stmt
                        | echo_stmt
                        | {isDeclaration = false;} out_expr
                        | {isDeclaration = true;} decl
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

int BlockSemanticCheck(char *block_id){
   struct BlockTable * temp = BlockSymbolTable;
   while(temp != NULL){
      if(strcmp(temp->id,block_id) == 0){
         break;
      }
      temp = temp->next;
   }

   struct List* temp2 = temp->params;
   struct List* temp4 = id_list;

   while(temp4 != NULL){
      int x=0;
      while(temp2 != NULL){
         if(strcmp(temp4->id,temp2->id) == 0) {
            x = 1;
            break;
         }
         temp2 = temp2->next;
      }
      if(!x) {return 0;}
      temp2 = temp->params;
      temp4 = temp4->next;
   }
   return 1;
}

int BlockCallSemanticCheck(char *block_id,int num_params){
   struct BlockTable* temp = BlockSymbolTable;
   while(temp != NULL){
      if(strcmp(temp->id,block_id) == 0){
         break;
      }
      temp = temp->next;
   }
   if(temp == NULL || num_params != temp->len) return 0;
   return 1;
}

/* Output Section */

/* insert symtab entry at some scope level */
void insertInOutputTable(struct OutputSymbolEntry** Head, char* id, int level, int type, bool primitive, int matrix_dim, int dim, bool isLoopId){
   /* New Entry */
   struct OutputSymbolEntry* newNode = (struct OutputSymbolEntry*)malloc(sizeof(struct OutputSymbolEntry));

   /* ID */
   newNode->id = (char *)malloc(sizeof(char)*strlen(id));
   for(int i=0;i<strlen(id);i++){
      newNode->id[i] = id[i];
   }

   /* Type */
   newNode->type = type;
   
   /* Primitive */
   newNode->primitive = primitive;

   /* Dimensions of Matrix in a list*/
   newNode->matrix_dim = matrix_dim;

   /* Dimensions */
   newNode->dim = dim;

   /* Scope Level */
   newNode->level = level;

   /* is the identifier a loop identifier? */
   newNode->isLoopId = isLoopId;

   /* Append */
   newNode->prev = *Head;  // covers NULL case already

   *Head = newNode;
}


/* returns matching entry from outmost scope, NULL if not found */
struct OutputSymbolEntry* getOutputSymbolEntry(struct OutputSymbolEntry** Head, char* id, int level, int findFlag){
    struct OutputSymbolEntry* symbolEntry = *Head;
    while(symbolEntry != NULL){
        if(strcmp(id, symbolEntry->id) == 0 && (symbolEntry->level == level || findFlag)) { /* found an exisitng entry that doesn't permit declaration of same identifier */
            break;  // found entry
        }
        symbolEntry = symbolEntry->prev;
    }
    // symtabEntry will be none if no entry is found (including when symtab is empty)
    return (struct OutputSymbolEntry*) symbolEntry;      
}

/* removes all entries from given outermost level */
void exitOutputSymbolScope(struct OutputSymbolEntry** Head, int level){
    struct OutputSymbolEntry* symbolEntry = *Head;
    if(symbolEntry == NULL) {return;}
    struct OutputSymbolEntry* prevEntry;

    while(symbolEntry != NULL && symbolEntry->level == level){
        prevEntry = symbolEntry->prev;
        free(symbolEntry->id);
        free(symbolEntry);
        symbolEntry = prevEntry;
    }
    *Head = symbolEntry; //update by reference
    return;
}


void printOutputTable(struct OutputSymbolEntry ** OutputSymbolTable){
   struct OutputSymbolEntry* temp = *OutputSymbolTable;
   while(temp != NULL){
      printf("%s ",temp->id);
      printf("%d %d %d %d\n",temp->id, temp->level, temp->primitive, temp->dim);
      /* Check for scopes here! */
      temp = temp->prev;
   }
}


int compatibleCheck(int t1, int t2)
{
   if(t1 == t2) return t1;
   else if((t1 < COMPATIBLE) && (t1 > t2)) return t1;
   else if((t2 < COMPATIBLE) && (t2 > t1)) return t2;
   else return -1;
}

int compatibleCheckAdv(int t1, int t2, int p1, int p2, int d1, int d2)
{
   /* Primitive ? */
   if(p1 == p2)
   {  
      /* Dimension Check (if necessary) */
      if(!p1 && (d1 != d2)) return -1;
      /* Compatibility */
      if(t1 == t2) return t1;
      else if((t1 < COMPATIBLE) && (t1 > t2)) return t1;
      else if((t2 < COMPATIBLE) && (t2 > t1)) return t2;
   }
   else return -1;
}

/* Condenser Helpers */
int condenser(int size, int lim)
{
   int upper = 1;
   while(upper < size) upper = upper << 1;
   return (upper >> lim);
}

/*void cond_init(int** arr_ptr, int n)
{
   int* temp = (int*)malloc(1*sizeof(int));
   temp[0] = n;
   *arr_ptr = temp; 
}

void cond_push(int** arr_ptr, int n, int count)
{
   int* temp = (int*)realloc(*arr_ptr, (count+1)*sizeof(int));
   temp[count] = n;
   *arr_ptr = temp;
}

int cond_chk(int* arr_ptr, int n, int count)
{
   for(int i = 0; i < count; i++) if(arr_ptr[i] == n) return 1;
   return 0;
}*/

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