%{
   #define YYSTYPE struct st
   #include<stdio.h>
   #include<stdbool.h>
   #include<stdlib.h>
   #include "st.h"

   #define HELLO printf("HELLO\n");

   extern FILE* yyin,*fp2;
   extern int line;
   FILE * fp,*out;
// comment
   int yylex();
   void yyerror(char* str);
   char * IntToString(int num);
   void printForLex(int num, int usage);
   void printForZip(int num, int usage);

   int classical_registers,quantum_registers,iterations,temp_type,indent;
   int * classical_states,classical_index=0,quantum_index=0;
   int isInBlock=0;
   int outputLevel = 0;
   bool isInOutput = false;
   bool isDeclaration = false;
   int isFirst = 1;

   struct List* head = NULL;
   struct List* id_list = NULL;
   struct List2* range_list = NULL;
   struct List3* cpx_list = NULL;
   struct List3* curr = NULL;
   struct List3* cpx_head = NULL;
   struct BlockTable* BlockSymbolTable = NULL;
   struct GateTable* GateSymbolTable = NULL;
   struct Complex* gateList = NULL;

   /* Output Section */
   struct OutputSymbolEntry* OutputSymbolTable = NULL;

   bool firstLetterCapital(char *str);
   struct OutputSymbolEntry* getOutputSymbolEntry(struct OutputSymbolEntry** Head, char* id, int level, int findFlag); // declaration
   void exitOutputSymbolScope(struct OutputSymbolEntry** Head, int level);
   int insertInGateTable(struct GateTable ** Head,char * data,struct cpx* arr);
   int insertInBlockTable(struct BlockTable** Head,char * data,int len,struct List* params);
   void insertInOutputTable(struct OutputSymbolEntry** Head, char* id, int level, int type, bool primitive, int matrix_dim, int dim, bool isLoopId);
   int BlockCallSemanticCheck(char *block_id,int num_params);
   int BlockSemanticCheck(char *block_id);
   void insertInList(struct List** Head,char * data);
   bool inList(struct List** Head, char* data);
   void removeTopKFromList(struct List** Head, int k);
   int compatibleCheck(int t1, int t2);
   int compatibleCheckAdv(int t1, int t2, int p1, int p2, int d1, int d2);
   int condenser(int size, int lim);
   int InBlock(struct BlockTable** Head,char * data,int len);
   void assignString(char* str1, char* str2);
   void printOutputTable(struct OutputSymbolEntry ** OutputSymbolTable);
%}

%start prgm
%token ID
%token NUMBER ITERS NEG
%token SET STATES REGISTERS QUANTUM CLASSICAL
%token MAIN_BEGIN MAIN_END OUTPUT_BEGIN OUTPUT_END INIT_BEGIN INIT_END
%token GATE BLOCK ARROW IN GATE_DEF
%token MEASURE CONDITION OTHERWISE BARRIER
%token FOR FOR_LEX FOR_ZIP
%token COMP TRUE FALSE EQUALITY AND OR
%token WHILE
%token ADD SUB DOT STD_DEV VAR AVG CONDENSE SUM
%token COUT
%token INT UINT FLOAT COMPLEX STRING MATRIX STATE BOOL IMAG LIST
%token DEC EXP
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

prgm                    : { fprintf(out,"#include<iostream>\n"
                                        "#include<vector>\n"
                                        "#include\"complex.h\"\n"
                                        "#include\"matrix.h\"\n"
                                        "#include\"type.h\"\n"
                                        "#include\"state.h\"\n"
                                        "#include\"list_func.h\"\n"
                                        "#include<math.h>\n\n"
                                        "using namespace std;\n\n");

                            fprintf(out,"Matrix X = Matrix(2);\n"
                                          "Matrix Y = Matrix(2);\n"
                                          "Matrix Z = Matrix(2);\n"
                                          "Matrix H = Matrix(2);\n"
                                          "int initializeGate(Matrix x,Complex a,Complex b,Complex c,Complex d){\n"
                                                "\tx.set_entry(0,0,a);\n"
                                                "\tx.set_entry(0,1,b);\n"
                                                "\tx.set_entry(1,0,c);\n"
                                                "\tx.set_entry(1,1,d);\n"
                                                "\tif(x.is_unitary()) return 1;\n"
                                                "\treturn 0;\n"
                                          "}\n\n"
                                    );

                            struct GateTable* temp = GateSymbolTable;
                            while(temp != NULL){
                                 fprintf(out,"if(!initializeGate(%s,Complex(%f,%f),Complex(%f,%f),Complex(%f,%f),Complex(%f,%f))) return 0;\n",
                                 temp->id,temp->arr[0].real,temp->arr[0].imag,temp->arr[1].real,temp->arr[1].imag,temp->arr[2].real,temp->arr[2].imag,temp->arr[3].real,temp->arr[3].imag);
                                 temp = temp->next;
                            }

                          } 
                          init_section
                          {
                              fprintf(out,"\nint main(){\nfor(int i=0; i<quantum_registers; i++) {quantum_register_dict[i] = i;}\n");
                              fprintf(out,"initializeGate(X,Complex(0,0),Complex(1,0),Complex(1,0),Complex(0,0));\n");
                              fprintf(out,"initializeGate(Y,Complex(0,0),Complex(0,-1),Complex(0,1),Complex(0,0));\n");
                              fprintf(out,"initializeGate(Z,Complex(1,0),Complex(0,0),Complex(0,0),Complex(-1,0));\n");
                              fprintf(out,"initializeGate(H,Complex(1/sqrt(2),0),Complex(1/sqrt(2),0),Complex(1/sqrt(2),0),Complex(-1/sqrt(2),0));\n");
                              fprintf(out,"FILE *result = fopen(\"result.csv\",\"w\");\n");
                              fprintf(out,"for(int iters=0;iters < num_iterations;iters++){\n");
                              fprintf(out,"q_output = StateVec(%d, q);\n"
                                          "for(int i=0;i<%d;i++){\n"
                                             "\t\tc_output[i] = c_output_original[i];\n"
                                          "}\n"
                                          "for(int i=0;i<%d;i++){\n"
                                             "\t\tquantum_register_dict[i] = i;\n"
                                          "}\n"
                                          "quantum_registers = quantum_registers_original;\n"
                                          "op = Matrix(1 << quantum_registers);\n",
                                          quantum_registers, classical_registers,quantum_registers
                                     );
                          }
                          main_section 
                           {
                              fprintf(out,"for(int i=0;i<classical_registers;i++){\n"
                                          "c_master[i] += c_output[i];\n"
                                          "}\n"
                                     );
                              fprintf(out,"fprintf(result,\"Iteration #%%d:\\n\",iters+1);\n");
                              fprintf(out,"fprintf(result,\"Classical Outputs: \");");
                              fprintf(out,"for(int i=0;i<%d-1;i++){\n"
                                             "\t\tfprintf(result,\"%%d, \",c_output[i]);\n"
                                          "}\n",classical_registers);
                              fprintf(out,"if(quantum_registers != 0) {\n");
                              fprintf(out,"fprintf(result,\"Quantum Outputs: \");");
                              fprintf(out,"for(int i=0;i< (1 << quantum_registers) ;i++){\n"
                                             "\t\tfprintf(result,\"(%%f, %%f), \",q_output.get_value(i).get_real(),q_output.get_value(i).get_imag());\n"
                                          "}\n"
                                          "fprintf(result,\"\\n\\n\");");
                              fprintf(out,"} else continue;");
                              //fprintf(out,"fprintf(result,\"(%%f, %%f)\",q_output.get_value(%d-1).get_real(),q_output.get_value(%d-1).get_imag());",quantum_registers,quantum_registers);
                              
                              fprintf(out,"}\n");
                              fprintf(out,"fclose(result);\n");
                           }
                          output_section 
                          {fprintf(out,"}\n");fprintf(fp,"\nParsing successful!\n");}
                        ;

// sequence has been enforced for the initializations and definitions in the init section
init_section            :  '\\' INIT_BEGIN {fprintf(fp,"\nInit section begins\n\n");} mandatory_init set_states block_defn_section gate_defn_section '\\' INIT_END {fprintf(fp,"\nInit section ends\n");$$.str = $5.str;}
                        ;   

main_section            :  '\\'  MAIN_BEGIN {fprintf(fp,"\nMain section begins\n\n");} main_stmt_list '\\' MAIN_END {fprintf(fp,"\nMain section ends\n");}
                        ;

output_section          :  '\\' OUTPUT_BEGIN {fprintf(fp,"\nOutput section begins\n\n"); isInOutput = true; outputLevel = 1;} out_main  '\\' OUTPUT_END {fprintf(fp,"\nOutput section ends\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel);}
                        ;


/* ..............
    INIT SECTION 
   ..............
*/
mandatory_init          :  '#' REGISTERS QUANTUM '=' NUMBER '#' REGISTERS CLASSICAL '=' NUMBER '#' ITERS '=' NUMBER {  fprintf(fp,"Register and iteration initialization section\n");
                                                                                                                        classical_registers = $10.num;
                                                                                                                        quantum_registers = $5.num;
                                                                                                                        iterations = $14.num;

                                                                                                                        fprintf(out,"int num_iterations = %d;\n", iterations);
                                                                                                                        fprintf(out,"int quantum_registers = %d;\n", quantum_registers);
                                                                                                                        fprintf(out,"int quantum_registers_original = %d;\n", quantum_registers);
                                                                                                                        fprintf(out,"int classical_registers = %d;\n\n", classical_registers);
                                                                                                                        fprintf(out,"int quantum_register_dict[%d];\n", quantum_registers);
                                                                                                                        fprintf(out,"Matrix op = Matrix(1<<quantum_registers)\n;");
                                                                                                                        fprintf(out, "int quantum_register_map(int i){\n");
                                                                                                                        fprintf(out, "if( (i>= %d) || (i<0) || (quantum_register_dict[i] == -1))\n", quantum_registers);           
                                                                                                                        fprintf(out, "{throw std::runtime_error(\"Semantic Error: Invalid quantum register access\");}\n");
                                                                                                                        fprintf(out, "return quantum_register_dict[i];\n}\n");                                                                                                                     }
                        ;

// can only one type of states be set?
set_states              :   set_quantum_states set_classical_states { fprintf(out,$1.str);fprintf(out,$2.str);}
                        |   set_classical_states                    {fprintf(out,$1.str);fprintf(out,"StateVec q_output = StateVec(%d);\nStateVec q_output_original = StateVec(%d);\n",
                                                                     quantum_registers);}
                        |   set_classical_states set_quantum_states { fprintf(out,$1.str);fprintf(out,$2.str);}
                        |   set_quantum_states                      {fprintf(out,"int c_output[%d]={ 0 };\nint c_output_original[%d]={ 0 };\nvector<unsigned int> c_master(%d, 0);\n",classical_registers,classical_registers);}
                        |   { fprintf(out,"int c_output[%d]={ 0 };\nint c_output_original[%d]={ 0 };\nvector<unsigned int> c_master(%d, 0);\n",classical_registers,classical_registers);
                              fprintf(out,"StateVec q_output = StateVec(%d);\nStateVec q_output_original = StateVec(%d);\n",quantum_registers,quantum_registers);
                            }
                        ;

set_quantum_states      :   '#' SET QUANTUM STATES ARROW quantum_state_list { fprintf(fp,"Setting initial state of quantum registers\n");
                                                                              $$.str = (char *)malloc(sizeof(char)*(strlen($6.str)*2+300));
snprintf($$.str,strlen($6.str)*2+300,"struct Quantum q[%d] = {%s};\nStateVec q_output_original = StateVec(%d,q);\nStateVec q_output = StateVec(%d,q);\n", quantum_registers,$6.str, quantum_registers,quantum_registers);
                                                                            }
                        ;

set_classical_states    :   '#' SET CLASSICAL STATES ARROW classical_state_list {   fprintf(fp,"Setting initial state of classical registers\n");
                                                                                    $$.str = (char *)malloc(sizeof(char)*(strlen($6.str)*2+200));
                                                                                    snprintf($$.str,strlen($6.str)*2+200,"int c_output[%d] = {%s};\nint c_output_original[%d] = {%s};\nvector<unsigned int> c_master(%d, 0);\n", classical_registers,$6.str, classical_registers,$6.str,classical_registers);
                                                                                }
                        ;

quantum_state_list      :   quantum_state_list ',' state_const       {  if(quantum_index == quantum_registers){
                                                                           yyerror("semantic error: quantum registers out of bounds");
                                                                           return 1;
                                                                        }  
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+110+2));
                                                                        snprintf($$.str,strlen($1.str)+110+2,"%s,Quantum(Complex(%f,%f),Complex(%f,%f))",$1.str,$3.q.first.real,$3.q.first.imag,$3.q.second.real,$3.q.second.imag);
                                                                        quantum_index++;
                                                                     }
                        |   state_const                              {  
                                                                        $$.str = (char *)malloc(sizeof(char)*110);
                                                                        snprintf($$.str,110,"Quantum(Complex(%f,%f),Complex(%f,%f))",$1.q.first.real,$1.q.first.imag,$1.q.second.real,$1.q.second.imag);
                                                                        quantum_index = 1;
                                                                     }
                        ;

classical_state_list    :   classical_state_list ',' classical_state { if(classical_index == classical_registers){
                                                                           yyerror("semantic error: classical registers out of bounds");
                                                                           return 1;
                                                                        }
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+20+2));
                                                                        snprintf($$.str,strlen($1.str)+20+2,"%s,%d",$1.str,$3.num);
                                                                        classical_index++;
                                                                     }
                        |   classical_state                          {  $$.str = (char *)malloc(sizeof(char)*20);
                                                                        snprintf($$.str,20,"%d",$1.num);
                                                                        classical_index  = 1;
                                                                     }
                        ;

classical_state         :   NUMBER                                   {$$.num = $1.num;}
                        ;


gate_defn_section       :  {fprintf(fp,"Gate definition section begins\n");} gate_defn_list {fprintf(fp,"Gate definition section ends\n");}
                        |
                        ;

gate_defn_list          :   gate_defn_list gate_defn
                        |   gate_defn
                        ;

gate_defn               :   GATE_DEF ID '=' rhs  { fprintf(fp,"Gate definition\n");
                                                   struct cpx arr[4];
                                                   for(int i=0;i<4;i++){
                                                      arr[i].real = $4.gates[i].real;
                                                      arr[i].imag = $4.gates[i].imag;
                                                   }
                                                   if(!insertInGateTable(&GateSymbolTable,$2.str,arr)){
                                                      yyerror("semantic error: gate definition requires square matrix");
                                                      return 1;
                                                   }
                                                   fprintf(out,"Matrix %s = Matrix(%d);\n", $2.str, 2);
                                                 }
                        ;

rhs                     :   '[' '[' temp ',' temp ']' ',' '[' temp ',' temp ']' ']'  {
                                                                                       $$.gates[0] = $3.cpx;
                                                                                       $$.gates[1] = $5.cpx;   
                                                                                       $$.gates[2] = $9.cpx;
                                                                                       $$.gates[3] = $11.cpx;
                                                                                     }
                        |   '{' tuple_list2 '}'


tuple_list2              : tuple_list2 ',' '(' id_list ')'
                        | '(' id_list ')'

id_list                 : id_list ',' temp   {$$.cols += 1;}
                        | temp               {$$.cols = 1;}


block_defn_section      :  {fprintf(fp,"Block definition section begins\n");} block_defns_list {fprintf(fp,"Block definition section ends\n");}
                        ;

block_defns_list        : block_defn block_defns_list 
                        |   /* epsilon */
                        ;

block_defn              : BLOCK block_id params target_params  {  if(!insertInBlockTable(&BlockSymbolTable,$2.str,$3.num,head)){
                                                                     yyerror("semantic error: incorrect block definition");
                                                                     return 1;
                                                                  }

                                                                  fprintf(out,"Matrix %s(", $2.str);
                                                                  
                                                                  if(head!=NULL){
                                                                  struct List* temp = head;
                                                                     while(temp->next!=NULL){
                                                                        fprintf(out, "int %s, ",temp->id);
                                                                        temp = temp->next;
                                                                     }   
                                                                     fprintf(out, "int %s",temp->id);
                                                                  }

                                                                  fprintf(out,"){\n");

                                                                  //free($2.str);
                                                                  head = NULL;
                                                                  isInBlock = 1;
                                                               }
                           '[' block_body ']'                  {  fprintf(fp,"Block definition\n");
                                                                  if(!BlockSemanticCheck($2.str)){
                                                                     yyerror("semantic error: incorrect block definition");
                                                                     return 1;
                                                                  }
                                                                  id_list = NULL;
                                                                  isInBlock = 0;
                                                                  fprintf(out, "return op;\n}\n");
                                                               }
                        ;

params                  :  ID                   {insertInList(&head,$1.str);$$.num = 1; }                  /* parantheses maybe ignored for single ID */
                        | '(' param_id_list ')' {
                                                   $$.num = $2.num;                                              
                                                }
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

block_id                : ID     {  if(!firstLetterCapital($1.str)){
                                       yyerror("lexical error: block identifiers start with uppercase letter");
                                       return 1;
                                    } 
                                    $$.str = $1.str;
                                 }  /* check first letter capital here */
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

register                : NUMBER  { if($1.num < 0){
                                       yyerror("semantic error: register numbers are non-negative");
                                       return 1;
                                    } 
                                    $$.num = $1.num;
                                    $$.flag=0;
                                    $$.str = (char *)malloc(sizeof(char)*20);
                                    snprintf($$.str,20,"%d",$1.num);
                                 }/* check non negative*/
                        | ID     {
                                    if(isInBlock){insertInList(&id_list,$1.str);}
                                    $$.flag = 1;
                                    assignString($$.str,$1.str);
                                    if(!isInOutput && !isInBlock) {
                                       if(!inList(&head,$1.str)) {yyerror("semantic error: variable used without declaration (1)"); return 1;}
                                    }
                                 }
                        ;


/* separate rules for gate calls and block calls because same syntax means different things for both */
call_stmt               : classic_control GATE quantum_control ARROW simple_expr {
                                                                                 fprintf(fp,"Pre - defined Gate call statement\n");
                                                                                 if(1){
                                                                                    fprintf(out, "if(%s) {\n", $1.str);
                                                                                    fprintf(out, "op = %s.kronecker_control_fill(%s, quantum_register_map(%s), quantum_registers) * op;\n", $2.str, $3.str, $5.str);
                                                                                    fprintf(out, "}\n");
                                                                                 }
                                                                                 free($1.str);
                                                                                 free($2.str);
                                                                                 free($3.str);
                                                                                 free($5.str);
                                                                              }
                        | classic_control ID quantum_control ARROW simple_expr   {fprintf(fp,"user - defined Gate call statement\n");
                                                                                 if(1){
                                                                                    fprintf(out, "if(%s) {\n", $1.str);
                                                                                    fprintf(out, "op = %s.kronecker_control_fill(%s, quantum_register_map(%s), quantum_registers) * op;\n", $2.str, $3.str, $5.str);
                                                                                    fprintf(out, "}\n");
                                                                                 }
                                                                                 free($1.str);
                                                                                 free($2.str);
                                                                                 free($3.str);
                                                                                 free($5.str);                                                                                 free($5.str);
                                                                              }
                        | GATE quantum_control ARROW simple_expr                 {fprintf(fp,"Pre - defined Gate call statement\n");
                                                                                 if(1){
                                                                                    fprintf(out, "op = %s.kronecker_control_fill(%s, quantum_register_map(%s), quantum_registers) * op;\n", $1.str, $2.str, $4.str);
                                                                                 }
                                                                                 free($1.str);
                                                                                 free($2.str);
                                                                                 free($4.str);    
                                                                              }
                        | ID quantum_control ARROW simple_expr                   {fprintf(fp,"User - defined Gate call statement\n");
                                                                                 if(!BlockCallSemanticCheck($1.str,$2.num)){
                                                                                    yyerror("semantic error: block not defined");
                                                                                    return 1;
                                                                                 }
                                                                                 if(1){
                                                                                    fprintf(out, "op = %s.kronecker_control_fill(%s, quantum_register_map(%s), quantum_registers) * op;\n", $1.str, $2.str, $4.str);
                                                                                 }
                                                                                 free($1.str);
                                                                                 free($2.str);
                                                                                 free($4.str);                                                                                   
                                                                              }
                        | classic_control block_id parameters optional        {  fprintf(fp,"Block call statement\n");
                                                                                 if(!isInBlock){
                                                                                    if(!BlockCallSemanticCheck($2.str,$3.num)){
                                                                                       yyerror("semantic error: block not defined");
                                                                                       free($1.str);
                                                                                       free($2.str);
                                                                                       free($3.str);
                                                                                       return 1;
                                                                                    }
                                                                                    fprintf(out, "if(%s) {\n", $1.str);
                                                                                    fprintf(out, "op = %s(%s);\n", $2.str, $3.str);
                                                                                    fprintf(out, "}\n");
                                                                                    free($1.str);
                                                                                    free($2.str);
                                                                                    free($3.str);
                                                                                 }
                                                                              }
                        | block_id parameters optional                        {  fprintf(fp,"Block call statement\n");
                                                                                 if(!isInBlock){
                                                                                    if(!BlockCallSemanticCheck($1.str,$2.num)){
                                                                                       yyerror("semantic error: block not defined");
                                                                                       return 1;
                                                                                    }
                                                                                    fprintf(out, "op = %s(%s);\n", $1.str, $2.str);
                                                                                    free($1.str);
                                                                                    free($2.str);
                                                                                 }
                                                                              }
                        ;

parameters              : '(' register_list ')'            {
                                                      $$.num = $2.num; 
                                                      $$.str = $2.str;
                                                   }
                        ;

optional                : 
                        | ARROW target
                        ;

register_list           : register_list ',' simple_expr  {
                                                         $$.num = 1 + $1.num; 
                                                         $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+3));
                                                         snprintf($$.str,strlen($1.str)+strlen($3.str)+3,"%s, %s",$1.str,$3.str);
                                                         free($3.str);
                                                         free($1.str);
                                                         }  
                        | simple_expr                    { 
                                                         $$.num = 1; 
                                                         $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+1));
                                                         snprintf($$.str,strlen($1.str)+1,"%s",$1.str);
                                                         free($1.str);
                                                      }
                        ;

classic_control         : control_expr '?'                 {
                                                               $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+1));
                                                               snprintf($$.str,strlen($1.str)+1,"%s",$1.str); 
                                                               // assignString($$.str,$1.str); 
                                                               free($1.str); 
                                                            }        /* removing epsilon rule resolved all conflicts */
                        | '(' control_expr_list ')' '?'    {
                                                               $$.str = (char *)malloc(sizeof(char)*(strlen($2.str)+1));
                                                               snprintf($$.str,strlen($2.str)+1,"%s",$2.str);
                                                               // assignString($$.str,$2.str);
                                                               free($2.str);
                                                            }
                        ;

quantum_control_list    : quantum_control_list ',' register  {
                                                                $$.num = 1 + $1.num;
                                                                $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+29));
                                                                snprintf($$.str,strlen($1.str)+strlen($3.str)+29,"%s|(1<<quantum_register_map(%s))",$1.str,$3.str);
                                                                free($3.str);
                                                                free($1.str);
                                                             }
                        | register                          { 
                                                                $$.num = 1; 
                                                                $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+28));
                                                                snprintf($$.str,strlen($1.str)+28,"(1<<quantum_register_map(%s))",$1.str);
                                                                free($1.str);
                                                            }
                        ;

quantum_control         : /* epsilon */                         /* optional */ {
                                                                  $$.str = (char*) malloc(sizeof(char)*2);
                                                                  $$.str[0] = '0';
                                                                  $$.str[1] = '\0';
                                                               }
                        | ':' simple_expr                         {
                                                                  $$.str = (char *)malloc(sizeof(char)*(strlen($2.str)+28));
                                                                  snprintf($$.str,strlen($2.str)+28,"(1<<quantum_register_map(%s))",$2.str);
                                                                  free($2.str);
                                                               }
                        | ':' '(' quantum_control_list ')'     {
                                                                  $$.str = (char *)malloc(sizeof(char)*(strlen($3.str)+1));
                                                                  snprintf($$.str,strlen($3.str)+1,"%s",$3.str);
                                                                  free($3.str);
                                                               }      
                        ;

target                  : register                           {free($1.str);}   /* blocks allow multiple targets */
                        | '(' register_list ')'              {free($2.str);}
                        ;

/* for simple expressions for classic control */
control_expr           : register                                   {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+11));
                                                                        snprintf($$.str,strlen($1.str)+11,"c_output[%s]",$1.str);
                                                                        free($1.str);
                                                                     }                 
                        | '!' register                               {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($2.str)+12));
                                                                        snprintf($$.str,strlen($2.str)+12,"!c_output[%s]",$2.str);
                                                                        free($2.str);
                                                                     }      
                        ;

control_expr_list      : control_expr_list ',' control_expr       {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+7));
                                                                        snprintf($$.str,strlen($1.str)+strlen($3.str)+7,"%s && (%s)",$1.str,$3.str);
                                                                        free($1.str);
                                                                        free($3.str);    
                                                                     }   
                        | control_expr                              {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+3));
                                                                        snprintf($$.str,strlen($1.str)+3,"(%s)",$1.str);
                                                                        free($1.str);
                                                                     }                    
                        ;


measure_stmt            : MEASURE ':' register ARROW register {
                           if((!$3.flag && ($3.num < 0 || $3.num >= quantum_registers)) || (!$5.flag && ($5.num < 0 || $5.num >= classical_registers))){
                              yyerror("semantic error: register number out of bounds"); 
                              free($3.str); 
                              free($5.str);
                              return 1;
                           }
                           fprintf(out,"q_output = q_output.transform(op);\n");
                           fprintf(out,"c_output[%s] = q_output.measure_prob(quantum_register_map(%s));\n", $5.str, $3.str);        
                           fprintf(out, "quantum_registers--;\n");                                                                  
                           fprintf(out, "op = Matrix(1<<quantum_registers);\n");                                                    /* renewed op matrix */
                           fprintf(out, "quantum_register_dict[%s] = -1;\n", $3.str);
                           fprintf(out, "for(int i=%s+1; i<%d; i++){quantum_register_dict[i]--;}\n", $3.str, quantum_registers);     /* shifting mapping */
                           free($3.str);
                           free($5.str);
                        } /* check if register1 and register2 are in bounds */
                        ;

barrier_stmt            : '\\' BARRIER    {
                                             fprintf(out,"q_output = q_output.transform(op);\n");
                                             fprintf(out, "op = Matrix(1<<quantum_registers);\n");
                                          }
                        ;

condition_stmt          : CONDITION '(' expr ')'                                       {fprintf(out,"if(%s){\n",$3.str); free($3.str);} 
                         '{' main_stmt_list '}'                                        {fprintf(out,"}\n");} 
                         otherwise_list otherwise_final         
                        ;

otherwise_list          : otherwise_list OTHERWISE '(' expr ')'                        {fprintf(out,"else if(%s){\n",$4.str); free($4.str);} 
                        '{' main_stmt_list '}'                                         {fprintf(out,"}\n");} 
                        | /* epsilon */
                        ;

otherwise_final         : OTHERWISE                                                    {fprintf(out,"else{\n");}
                         '{' main_stmt_list '}'                                        {fprintf(out,"}\n");} 
                        | /* epsilon */
                        ;

simple_expr         :      simple_expr '+' simple_expr                    {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                                        snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s + %s",$1.str,$3.str);
                                                                        free($1.str);
                                                                        free($3.str);           
                                                                     }
                        | simple_expr '-' simple_expr                {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                                        snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s - %s",$1.str,$3.str);
                                                                        free($1.str);
                                                                        free($3.str);           
                                                                     }
                        | simple_expr '*' simple_expr                {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                                        snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s * %s",$1.str,$3.str);
                                                                        free($1.str);
                                                                        free($3.str);           
                                                                     }
                        | simple_expr '/' simple_expr                {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                                        snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s / %s",$1.str,$3.str);
                                                                        free($1.str);
                                                                        free($3.str);           
                                                                     }
                        | simple_expr '%' simple_expr                {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                                        snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s %% %s",$1.str,$3.str);
                                                                        free($1.str);
                                                                        free($3.str);           
                                                                     }
                        | ID                                         {
                                                                        if(!isInOutput) {
                                                                           if(!isInBlock && !inList(&head,$1.str)) {yyerror("semantic error: variable used without declaration (2)"); free($1.str); return 1;}
                                                                           $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+1));
                                                                           snprintf($$.str,strlen($1.str)+1,"%s",$1.str);
                                                                           free($1.str);  
                                                                        }  
                                                                     }
                        | NUMBER                                     {
                                                                        $$.str = (char *)malloc(sizeof(char)*20);
                                                                        snprintf($$.str,20,"%d",$1.num);
                                                                     }
                        /* |  '(' simple_expr ')'                       {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+3));
                                                                        snprintf($$.str,strlen($1.str)+3,"(%s)",$1.str);
                                                                        free($1.str);          
                                                                     } */
                        ;


expr                    : expr COMP expr                             {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($2.str)+strlen($3.str)+3));
                                                                        snprintf($$.str,strlen($1.str)+strlen($2.str)+strlen($3.str)+5,"%s %s %s",$1.str,$2.str,$3.str);
                                                                        free($1.str);
                                                                        free($3.str);           
                                                                     }
                        | expr EQUALITY expr                         {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+5));
                                                                        snprintf($$.str,strlen($1.str)+strlen($3.str)+5,"%s == %s",$1.str,$3.str);
                                                                        free($1.str);
                                                                        free($3.str);           
                                                                     }
                        | expr AND expr                              {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+5));
                                                                        snprintf($$.str,strlen($1.str)+strlen($3.str)+5,"%s && %s",$1.str,$3.str);
                                                                        free($1.str);
                                                                        free($3.str);           
                                                                     }
                        | expr OR expr                               {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+5));
                                                                        snprintf($$.str,strlen($1.str)+strlen($3.str)+5,"%s || %s",$1.str,$3.str);
                                                                        free($1.str);
                                                                        free($3.str);           
                                                                     }
                        | expr '^' expr                              {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                                        snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s ^ %s",$1.str,$3.str);
                                                                        free($1.str);
                                                                        free($3.str);           
                                                                     }
                        | expr '&' expr                              {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                                        snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s & %s",$1.str,$3.str);
                                                                        free($1.str);
                                                                        free($3.str);           
                                                                     }
                        | expr '|' expr                              {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                                        snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s | %s",$1.str,$3.str);
                                                                        free($1.str);
                                                                        free($3.str);           
                                                                     }
                        | '(' expr ')'                               {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($2.str)+3));
                                                                        snprintf($$.str,strlen($2.str)+3,"(%s)",$2.str);
                                                                        free($1.str);          
                                                                     }
                        | expr '+' expr                              {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                                        snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s + %s",$1.str,$3.str);
                                                                        free($1.str);
                                                                        free($3.str);           
                                                                     }
                        | expr '-' expr                              {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                                        snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s - %s",$1.str,$3.str);
                                                                        free($1.str);
                                                                        free($3.str);           
                                                                     }
                        | expr '*' expr                              {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                                        snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s * %s",$1.str,$3.str);
                                                                        free($1.str);
                                                                        free($3.str);           
                                                                     }
                        | expr '/' expr                              {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                                        snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s / %s",$1.str,$3.str);
                                                                        free($1.str);
                                                                        free($3.str);           
                                                                     }
                        | expr '%' expr                              {
                                                                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                                        snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s %% %s",$1.str,$3.str);
                                                                        free($1.str);
                                                                        free($3.str);           
                                                                     }
                        | ID                                         {
                                                                        if(!isInOutput) {
                                                                           if(!isInBlock && !inList(&head,$1.str)) {yyerror("semantic error: variable used without declaration (2)"); free($1.str); return 1;}
                                                                           $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+1));
                                                                           snprintf($$.str,strlen($1.str)+1,"%s",$1.str);
                                                                           free($1.str);  
                                                                        }  
                                                                     }
                        | NUMBER                                     {
                                                                              $$.str = (char *)malloc(sizeof(char)*20);
                                                                        snprintf($$.str,20,"%d",$1.num);
                                                                     }
                     
                        | TRUE                                       {
                                                                        $$.str = (char *)malloc(sizeof(char)*(2));
                                                                        snprintf($$.str,1,"1");        
                                                                     }
                        | FALSE                                      {
                                                                        $$.str = (char *)malloc(sizeof(char)*(2));
                                                                        snprintf($$.str,1,"0");       
                                                                     }
                        ;

/* negative numbers? */
value                   : NUMBER             {$$.str = IntToString($1.num);}
                        | ID                 {$$.str = $1.str;}
                        ;

range                   : value ':' value    {$$.start = $1.str; $$.end = $3.str; $$.step = IntToString(1);}
                        | value ':' value ':' value   {$$.start = $1.str; $$.end = $3.str; $$.step = $5.str;}
                        ;

range_list              : range ',' range_list     {  $$.num = 1 + $3.num;
                                                      struct List2* newNode = (struct List2*)malloc(sizeof(struct List2));
                                                      newNode->start = $1.start;
                                                      newNode->end = $1.end;
                                                      newNode->step = $1.step;
                                                      newNode->next = range_list;
                                                      range_list = newNode;
                                                   }
                        | range                    {  $$.num = 1;
                                                      struct List2* newNode = (struct List2*)malloc(sizeof(struct List2));
                                                      newNode->start = $1.start;
                                                      newNode->end = $1.end;
                                                      newNode->step = $1.step;
                                                      newNode->next = NULL;
                                                      range_list = newNode;
                                                   }
                        ;

var_list                : ID ',' var_list   {  if(isInOutput){
                                                   if(getOutputSymbolEntry(&OutputSymbolTable,$1.str,outputLevel + 1,1) == NULL){
                                                      yyerror("semantic error: variable used without declaration (3)");
                                                      return 1;
                                                   }
                                                }     
                                                if(!inList(&head,$1.str)){
                                                   insertInList(&head,$1.str);
                                                } 
                                                else {
                                                   yyerror("semantic error: loop variable redeclaration");
                                                   return 1;
                                                } 
                                                $$.num = 1 + $3.num;
                                             }
                        | ID                 {  if(isInOutput){
                                                   if(getOutputSymbolEntry(&OutputSymbolTable,$1.str,outputLevel + 1,1) == NULL){
                                                      yyerror("semantic error: variable redeclaration");
                                                      return 1;
                                                   }
                                                } 
                                                if(!inList(&head,$1.str)){
                                                   insertInList(&head,$1.str);
                                                } 
                                                else{
                                                   yyerror("semantic error: loop variable redeclaration");
                                                   return 1;
                                                } 
                                                $$.num = 1;
                                             }
                        ;

for_stmt                : FOR ID                                        {  if(!inList(&head,$2.str)){
                                                                              insertInList(&head,$2.str);
                                                                           } 
                                                                           else{
                                                                              yyerror("semantic error: loop variable redeclaration"); 
                                                                              return 1;
                                                                           }
                                                                        } 
                          IN '(' range ')'                              {   
                                                                           fprintf(out,"for(int %s = %s;%s < %s;%s += %s){\n",$2.str,$6.start,$2.str,$6.end,$2.str,$6.step);  }
                          '{' main_stmt_list '}'                        {
                                                                           fprintf(out,"}\n");
                                                                           removeTopKFromList(&head,1);
                                                                        }
                        ;

for_lex_stmt            : FOR_LEX '(' var_list ')' IN '(' range_list ')' { if($3.num != $7.num){
                                                                              yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                              return 1;
                                                                           }
                                                                           printForLex($3.num, 1);
                                                                         } 
                          '{' main_stmt_list '}'                         {
                                                                           printForLex($3.num, 0);
                                                                           removeTopKFromList(&head,$3.num);
                                                                        }
                        ;

for_zip_stmt            : FOR_ZIP '(' var_list ')' IN '(' range_list ')' { if($3.num != $7.num){
                                                                              yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                              return 1;
                                                                           }
                                                                           printForZip($3.num, 1);
                                                                         } 
                          '{' main_stmt_list '}' {
                                                      removeTopKFromList(&head,$3.num); 
                                                      printForZip($3.num, 0);
                                                 }
                        ;

while_stmt              : WHILE '(' expr ')'                          {fprintf(out,"while(%s){\n",$3.str);} 
                         '{' main_stmt_list '}'                       {fprintf(out,"}\n");}                                                                                                   
                        ;

// /* ................ 
//     OUTPUT SECTION 
//    ................
// */

/* Datatypes */
out_id                  : ID   {$$.out_flag = 0; $$.str = $1.str;}
                        | COUT {$$.out_flag = 1; $$.type = Uint; $$.prim = false; $$.dim = (classical_registers); $$.rows = 0; $$.str = (char *)malloc(sizeof(char)*(9));strcpy($$.str,"c_master");}
                        ;

prim_type               : INT       {$$.type = Int; $$.prim = true;fprintf(out,"int ");}
                        | UINT      {$$.type = Uint; $$.prim = true;fprintf(out,"unsigned int ");}
                        | FLOAT     {$$.type = Float; $$.prim = true;fprintf(out,"float ");}
                        | COMPLEX   {$$.type = Complex; $$.prim = true;fprintf(out,"Complex ");}
                        | STRING    {$$.type = String; $$.prim = true;fprintf(out,"string ");}
                        | MATRIX    {$$.type = Matrix; $$.prim = true;fprintf(out,"Matrix ");}
                        | STATE     {$$.type = State; $$.prim = true;fprintf(out,"StateVec ");}
                        | BOOL      {$$.type = Bool; $$.prim = true;fprintf(out,"bool ");}
                        ;

list_type               : LIST '[' {fprintf(out,"vector<");} prim_type ']' {$$.type = $4.type; $$.prim = false;fprintf(out,">");}
                        ;

/* data_type               : prim_type
                        | list_type
                        ; */

bool_const              : TRUE      {$$.num = 1;}
                        | FALSE     {$$.num = 0;}
                        ;

num                     : DEC       {$$.real = $1.real;}
                        | NEG       {$$.real = $1.real;}
                        | EXP       {$$.real = $1.real;}
                        | NUMBER    {$$.real = $1.num;}
                        
complex_const           : '(' num ',' num ')'      {$$.cpx.real = $2.real; $$.cpx.imag = $4.real;}
                        ;

matrix_const            : '[' row_list ']'         { if($2.rows == $2.cols) {
                                                         $$.rows = $2.rows;
                                                     } 
                                                     else{
                                                         yyerror("semantic error: only square matrices permitted"); 
                                                         return 1;
                                                     }
                                                     isFirst = 1;
                                                   }
                        ;

row_list                : row_list ',' row         {  $$.rows = $1.rows + 1; 
                                                      if($1.cols == $3.cols){
                                                         $$.cols = $1.cols;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: rows of different length cannot form matrix"); 
                                                         return 1;
                                                      }
                                                      struct List3* temp = cpx_list;
                                                      while(temp->next != NULL){
                                                         temp = temp->next;
                                                      }
                                                      curr->next = cpx_list;
                                                      curr = temp;
                                                   }
                        | row                         {  $$.rows = 1; $$.cols = $1.cols;
                                                         struct List3* temp = cpx_list;
                                                         while(temp->next != NULL){
                                                            temp = temp->next;
                                                         }
                                                         curr = temp;
                                                         if(isFirst){
                                                            cpx_head = cpx_list;
                                                            isFirst = 0;
                                                         }
                                                      }
                        ;

row                     : '[' comps ']'               {$$.cols = $2.cols;}
                        ;

comps                   : comps ',' compatible_const  {$$.cols = $1.cols + 1;}
                        | compatible_const            {$$.cols = 1;}
                        ;

compatible_const        : complex_const
                        | num
                        ;

state_const             : '{' temp ',' temp '}'       {$$.q.first = $2.cpx; $$.q.second = $4.cpx;}
                        ;

temp                    : complex_const               {$$.cpx = $1.cpx;}
                        | num                         {$$.cpx.real = $1.real; $$.cpx.imag = 0;}
                        ;

prim_const              : bool_const      {  $$.type = Bool;
                                             $$.str = (char *)malloc(sizeof(char)*6);
                                             if($$.num)snprintf($$.str,6,"true");
                                             else snprintf($$.str,6,"false");
                                          }
                        | complex_const   {  $$.type = Complex;
                                             $$.str = (char *)malloc(sizeof(char)*120);
                                             snprintf($$.str,120,"Complex(%f,%f)",$1.cpx.real,$1.cpx.imag);
                                          }
                        | matrix_const    {  $$.type = Matrix; 
                                             $$.rows = $1.rows;
                                             $$.str = (char *)malloc(sizeof(char)*($$.rows*$$.rows*50));
                                          }
                        | state_const     {$$.type = State;}
                        | NUMBER          {$$.type = Uint;$$.str = (char *)malloc(sizeof(char)*20);snprintf($$.str,20,"%d",$1.num);}
                        | NEG             {$$.type = Int;$$.str = (char *)malloc(sizeof(char)*20);snprintf($$.str,20,"%d",$1.num);}
                        | DEC             {$$.type = Float;$$.str = (char *)malloc(sizeof(char)*20);snprintf($$.str,20,"%f",$1.real);}
                        | EXP             {$$.type = Float;$$.str = (char *)malloc(sizeof(char)*20);snprintf($$.str,20,"%f",$1.real);}
                        | STRING          {$$.type = String;$$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+1));snprintf($$.str,strlen($1.str)+1,"%s",$1.str);}
                        ;

vec_const               : '[' vec_list ']'      {  $$.dim = $2.dim; 
                                                   $$.type = $2.type; 
                                                   $$.veconst = 1;
                                                   if($$.type == Matrix){
                                                      $$.rows = $2.rows;
                                                   } 
                                                   else{
                                                      $$.rows = 0;
                                                   } 
                                                   $$.str = (char *)malloc(sizeof(char)*(strlen($2.str)+3));
                                                   snprintf($$.str,strlen($2.str)+3,"{%s}",$2.str);
                                                   free($2.str);
                                                }
                        ;

vec_list                : vec_list ',' prim_const   {  temp_type = compatibleCheck($1.type, $3.type); 
                                                      if(temp_type != -1){
                                                         $$.type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: incompatible types in list"); 
                                                         return 1;
                                                      } 
                                                      $$.dim = $1.dim + 1; 
                                                      if($$.type == Matrix){
                                                         if($1.rows != $3.rows){
                                                            yyerror("semantic error: incompatible matrix dimensions in list");
                                                            return 1;
                                                         }
                                                         else{
                                                            $$.rows = $1.rows;
                                                         } 
                                                      }
                                                      insertInList(&head,$3.str);
                                                      $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+2));
                                                      snprintf($$.str,strlen($1.str)+strlen($3.str)+2,"%s,%s",$1.str,$3.str);
                                                      free($1.str);
                                                      free($3.str);
                                                   }
                        | prim_const               {  $$.type = $1.type; $$.dim = 1; 
                                                      if($$.type == Matrix){
                                                         $$.rows = $1.rows;
                                                      }
                                                      $$.str = $1.str;
                                                      head = NULL;
                                                      insertInList(&head,$1.str);
                                                   }
                        ;

/* Calls : Must Define Dimensions */
calls                : ADD '(' out_rhs ',' out_rhs ')'   /* List (uint, int, float, complex, matrix, state, string??) */   
                     {
                        temp_type = compatibleCheckAdv($5.type, $3.type, $5.prim, $3.prim, $5.dim, $3.dim); 
                        if((!$3.prim) && (temp_type>= 0) && ((temp_type<=COMPATIBLE) || temp_type==Matrix || temp_type==State)){
                           $$.prim = false; 
                           $$.type = temp_type; 
                           $$.dim = $3.dim;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands");
                           return 1;
                        }
                        if($3.veconst == 0 && $5.veconst == 0)
                        {
                           $$.str = (char *)malloc(sizeof(char)*(strlen($5.str)+strlen($3.str)+strlen($1.str)+4));
                           snprintf($$.str,strlen($5.str)+strlen($3.str)+8+4,"add(%s,%s)",$3.str,$5.str);
                           free($3.str);
                           free($5.str);
                        }
                        else
                        {
                           yyerror("semantic error : initialize first, cannot directly pass as argument");
                           return 1;
                        }
                     }
                     | SUB '(' out_rhs ',' out_rhs ')'   /* List (uint, int, float, complex, matrix, state) */             
                     {
                        temp_type = compatibleCheckAdv($5.type, $3.type, $5.prim, $3.prim, $5.dim, $3.dim); 
                        if((!$3.prim) && (temp_type>= 0) && ((temp_type<=COMPATIBLE) || temp_type==Matrix || temp_type==State)){
                           $$.prim = false; 
                           $$.type = temp_type; 
                           $$.dim = $3.dim;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
                        if($3.veconst == 0 && $5.veconst == 0)
                        {
                           $$.str = (char *)malloc(sizeof(char)*(strlen($5.str)+strlen($3.str)+strlen($1.str)+4));
                           snprintf($$.str,strlen($5.str)+strlen($3.str)+8+4,"sub(%s,%s)",$3.str,$5.str);
                           free($3.str);
                           free($5.str);
                        }
                        else
                        {
                           yyerror("semantic error : initialize first, cannot directly pass as argument");
                           return 1;
                        }
                     }      
                     | DOT '(' out_rhs ',' out_rhs ')'   /* List (uint, int, float, complex), List(Comp*Mat), State*State*/
                     {
                        temp_type = compatibleCheckAdv($5.type, $3.type, $5.prim, $3.prim, $5.dim, $3.dim); 
                        if((!$3.prim) && (temp_type>= 0) && (temp_type<=COMPATIBLE)){
                           $$.prim = true; 
                           $$.type = temp_type; 
                           $$.dim = $3.dim;
                        } 
                        else if((!$3.prim) && (!$5.prim) && ($3.type<=COMPATIBLE) && ($5.type==Matrix)){
                           $$.prim = true; 
                           $$.type = Matrix; 
                           $$.dim = 0;
                        } 
                        else if($3.prim && (temp_type==State)){
                           $$.prim = true; 
                           $$.type = Complex;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
                        if($3.type != Complex && (($3.veconst == 0 && $5.veconst == 0))){
                           $$.str = (char *)malloc(sizeof(char)*(strlen($5.str)+strlen($3.str)+strlen($1.str)+4));
                           snprintf($$.str,strlen($5.str)+strlen($3.str)+strlen($1.str)+4,"%s(%s,%s)",$1.str,$3.str,$5.str);
                           free($3.str);
                           free($5.str);
                        } 
                        else if($3.veconst == 0 && $5.veconst == 0){
                           $$.str = (char *)malloc(sizeof(char)*(strlen($5.str)+strlen($3.str)+24));
                           snprintf($$.str,strlen($5.str)+strlen($3.str)+24,"dotProductComplex(%s,%s)",$3.str,$5.str);
                           free($3.str);
                           free($5.str);
                        }
                        else
                        {
                           yyerror("semantic error : initialize first, cannot directly pass as argument");
                           return 1;
                        }
                     }        
                     | STD_DEV '(' out_rhs ')'           /* List (uint, int) */                                            
                     {
                        if((!$3.prim) && (($3.type==Uint) || ($3.type==Int) || ($3.type==Float))){
                           $$.prim = true; 
                           $$.type = $3.type; 
                           $$.dim = $3.dim;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
                        if(($3.veconst == 0))
                        {
                        $$.str = (char *)malloc(sizeof(char)*(strlen($3.str)+strlen($1.str)+3));
                        snprintf($$.str,strlen($3.str)+strlen($1.str)+3,"%s(%s)",$1.str,$3.str);
                        free($3.str);
                        }
                        else
                        {
yyerror("semantic error : initialize first, cannot directly pass as argument");
                           return 1;
                        }
                     }   
                     | VAR '(' out_rhs ')'               /* List (uint, int) */                                            
                     {
                        if((!$3.prim) && (($3.type==Uint) || ($3.type==Int) || ($3.type==Float))){
                           $$.prim = true; 
                           $$.type = $3.type; 
                           $$.dim = $3.dim;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands");
                           return 1;
                        }
                        if(($3.veconst == 0))
                        {                     $$.str = (char *)malloc(sizeof(char)*(strlen($3.str)+strlen($1.str)+3));
                        snprintf($$.str,strlen($3.str)+strlen($1.str)+3,"%s(%s)",$1.str,$3.str);
                        free($3.str);
                     }
                     }
                     | CONDENSE '(' out_rhs ',' NUMBER ')'     /* List (uint, int)  with reduction */                      
                     { 
                        if((!$3.prim) && (($3.type==Uint) || ($3.type==Int))){
                           $$.prim = false; 
                           $$.type = $3.type;
                           $$.dim = condenser($3.dim, 1);
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
                        if(($3.veconst == 0))
                        {
                           $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+23));
                        snprintf($$.str,strlen($1.str)+strlen($3.str)+23,"%s(%s,1<<%d)",$1.str,$3.str,$5.num);
                        free($3.str);
                        }
                        else
                        {
                           yyerror("semantic error : initialize first, cannot directly pass as argument");
                           return 1;
                        }
                        
                     }
                     /* | CONDENSE '(' out_rhs ',' '(' uint_list ')' ')'   /* List (uint, int) with reduction             
                     {
                        if((!$3.prim) && (($3.type==Uint) || ($3.type==Int))){
                           $$.prim = false; 
                           $$.type = $3.type; 
                           $$.dim = condenser($3.dim, $6.cond_count);
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
                        $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+strlen($6.str)));
                        snprintf($$.str,strlen($1.str)+strlen($3.str)+20,"%s(%s,(%s))",$1.str,$3.str,$6.str);
                        free($3.str);
                        free($6.str);
                     } */
                     | SUM '(' out_rhs ')'               /* List (uint, int, float, complex, matrix, string??) */          
                     {
                        if((!$3.prim) && (($3.type<=COMPATIBLE) || $3.type==Matrix)){
                           $$.prim = true; 
                           $$.type = $3.type; 
                           $$.dim = 0;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
                        if($3.type == Complex && ($3.veconst == 0)){
                           $$.str = (char *)malloc(sizeof(char)*(strlen($3.str)+24));
                           snprintf($$.str,strlen($3.str)+24,"sumComplex(%s)",$3.str);
                           free($3.str);
                        } 
                        else if ($3.veconst == 0){
                           $$.str = (char *)malloc(sizeof(char)*(strlen($3.str)+strlen($1.str)+3));
                           snprintf($$.str,strlen($3.str)+strlen($1.str)+3,"%s(%s)",$1.str,$3.str);
                           free($3.str);
                        }
                        else
                        {
                           yyerror("semantic error : initialize first, cannot directly pass as argument");
                           return 1;
                        }
                     }
                     | AVG '(' out_rhs ')'               /* List (uint, int, float, complex, matrix) */                  
                     {
                        if((!$3.prim) && (($3.type<=COMPATIBLE) || $3.type==Matrix)){
                           $$.prim = true; 
                           $$.type = $3.type; 
                           $$.dim = 0;
                        } 
                        else{
                           yyerror("semantic error: incompatible operands"); 
                           return 1;
                        }
                        if($3.type == Complex && ($3.veconst == 0)){
                           $$.str = (char *)malloc(sizeof(char)*(strlen($3.str)+24));
                           snprintf($$.str,strlen($3.str)+24,"meanComplex(%s)",$3.str);
                           free($3.str);
                        } 
                        else if(($3.veconst == 0)){
                           $$.str = (char *)malloc(sizeof(char)*(strlen($3.str)+strlen($1.str)+3));
                           snprintf($$.str,strlen($3.str)+strlen($1.str)+3,"%s(%s)",$1.str,$3.str);
                           free($3.str);
                        }
                        else
                        {
                           yyerror("semantic error : initialize first, cannot directly pass as argument");
                           return 1;
                        }
                     }
                        /*| REAL */
                        /*| IMAG */
                        
                        ;

/* Expressions :*/
out_rhs                 : prim_const            { $$.prim = true; $$.type = $1.type;$$.str = $1.str;}
                        | vec_const             { $$.prim = false; $$.dim = $1.dim; 
                                                  $$.type = $1.type; 
                                                  if($$.type == Matrix){
                                                      $$.rows = $1.rows;
                                                  } 
                                                  else $$.rows = 0;
                                                  $$.str = $1.str;
                                                }
                        | out_id                {  if($$.out_flag == 0){
                                                      struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,$1.str,outputLevel,1); 
                                                      if(sample != NULL){
                                                         $$.prim = sample->primitive; 
                                                         $$.type = sample->type; 
                                                         if($$.type == Matrix){
                                                            $$.rows = sample->matrix_dim;
                                                         } 
                                                         if(!$$.prim){
                                                            $$.dim = sample->dim;
                                                         }
                                                      } 
                                                      else{
                                                         yyerror("semantic error: variable not declared"); 
                                                         return 1;
                                                      }
                                                   } 
                                                   else if($$.out_flag == 1){
                                                      $$.type = Uint; $$.prim = false; 
                                                      $$.dim = (classical_registers); 
                                                      $$.rows = 0;
                                                   } 
                                                   else{
                                                      $$.type = State; 
                                                      $$.prim = false; 
                                                      $$.dim = quantum_registers; 
                                                      $$.rows = 0;
                                                   }
                                                   $$.str = $1.str;
                                                }
                        | out_id '[' out_rhs ']'{
                                                   if($$.out_flag == 0){
                                                      struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,$1.str,outputLevel,1); 
                                                      if(sample != NULL){
                                                         if($3.type <= Uint){
                                                            if(sample->primitive){
                                                               if(sample->type==State){
                                                                  $$.type = Complex; 
                                                                  $$.prim = true;
                                                               } 
                                                               else{
                                                                  yyerror("semantic error"); 
                                                                  return 1;
                                                               }
                                                            }
                                                            else{
                                                               $$.type = sample->type; 
                                                               $$.prim = true;
                                                            }
                                                         } 
                                                         else{
                                                            yyerror("semantic error 2"); 
                                                            return 1;
                                                         }
                                                      } 
                                                      else{
                                                         yyerror("semantic error: variable not declared"); 
                                                         return 1;
                                                      }
                                                   } 
                                                   else if($$.out_flag == 1){
                                                      $$.type = Uint; 
                                                      $$.prim = true;
                                                   } 
                                                   else{
                                                      $$.type = State; 
                                                      $$.prim = true;
                                                   }
                                                   $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+3)); 
                                                   snprintf($$.str,strlen($1.str)+strlen($3.str)+3,"%s[%s]",$1.str,$3.str); 
                                                   free($1.str);
                                                   free($3.str);
                                                }
                        | out_id '[' out_rhs ']' '[' out_rhs ']'                 
                                                {
                                                   if($$.out_flag == 0){
                                                      struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,$1.str,outputLevel,1); 
                                                      if(sample != NULL){
                                                         if(($3.type <= Uint) && ($5.type <= Uint)){
                                                            if(sample->type) {
                                                               if(sample->type==Matrix){
                                                                  $$.type = Complex; 
                                                                  $$.prim = true;
                                                               } 
                                                               else{
                                                                  yyerror("semantic error: variable not declared"); 
                                                                  return 1;
                                                               }
                                                            } 
                                                            else if(sample->type==State){
                                                               $$.type = Complex; 
                                                               $$.prim = true;
                                                            } 
                                                            else{
                                                               yyerror("semantic error 3"); 
                                                               return 1;
                                                            }
                                                         }
                                                      } 
                                                      else{
                                                         yyerror("semantic error 4"); 
                                                         return 1;
                                                      }
                                                   } 
                                                   else if($$.out_flag == 1){
                                                      yyerror("semantic error 5");
                                                      return 1;
                                                   } 
                                                   else{
                                                      $$.type = Complex; 
                                                      $$.prim = true;
                                                   }
                                                   $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+strlen($6.str)+5)); 
                                                   snprintf($$.str,strlen($1.str)+strlen($3.str)+strlen($6.str)+5,"%s[%s][%s]",$1.str,$3.str,$6.str);    
                                                   free($1.str);
                                                   free($3.str);
                                                   free($6.str);                                                
                                                }
                        | out_id '[' out_rhs ']' '[' out_rhs ']' '[' out_rhs ']' 
                                                {
                                                   if($$.out_flag == 0){
                                                      struct OutputSymbolEntry* sample = getOutputSymbolEntry(&OutputSymbolTable,$1.str,outputLevel,1); 
                                                      if(sample != NULL){
                                                         if(($3.type <= Uint) && ($5.type <= Uint) && ($7.type <= Uint)){
                                                            if(sample->primitive){
                                                               yyerror("semantic error: variable not declared"); 
                                                               return 1;
                                                            } 
                                                            else if(sample->type==Matrix){
                                                               $$.type = Complex; 
                                                               $$.prim = true;
                                                            } 
                                                            else{
                                                               yyerror("semantic error 6"); 
                                                               return 1;
                                                            }
                                                         }
                                                      } 
                                                      else{
                                                         yyerror("semantic error 7");
                                                         return 1;
                                                      }
                                                   } 
                                                   else{
                                                      yyerror("semantic error 8"); 
                                                      return 1;
                                                   }
                                                   $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+strlen($6.str)+strlen($9.str)+5)); 
                                                   snprintf($$.str,strlen($1.str)+strlen($3.str)+strlen($6.str)+5,"%s[%s][%s][%s]",$1.str,$3.str,$6.str, $9.str);    
                                                   free($1.str);
                                                   free($3.str);
                                                   free($6.str); 
                                                   free($9.str);
                                                }
                           | calls                 {  $$.prim = $1.prim; 
                                                      $$.type = $1.type; 
                                                      if($1.type == Matrix) $$.rows = $1.rows; 
                                                      if(!$$.prim) $$.dim = $1.dim; 
                                                   }
                        | '(' out_rhs ')'         {   $$.type = $2.type;
                                                      $$.prim = $2.prim;
                                                      $$.str = (char *)malloc(sizeof(char)*(strlen($2.str)+3));
                                                      snprintf($$.str,strlen($2.str)+3,"(%s)",$2.str);
                                                      free($2.str);
                                                  }
                        | '!' out_rhs             {  if($2.type==Bool && $2.prim){
                                                         $$.prim = true; 
                                                         $$.type = Bool;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 9"); 
                                                         return 1;
                                                      }  
                                                      $$.str = (char *)malloc(sizeof(char)*(strlen($2.str)+1));
                                                      snprintf($$.str,strlen($2.str)+2,"!%s",$2.str);
                                                      free($2.str);
                                                   }                         
                           | out_rhs AND out_rhs   {  if($1.type==Bool && $1.prim && $3.type==Bool && $3.prim){
                                                         $$.prim = true; 
                                                         $$.type = Bool;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 10"); 
                                                         return 1;
                                                      } 
                                                      $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+5));
                                                      snprintf($$.str,strlen($1.str)+strlen($3.str)+5,"%s && %s",$1.str,$3.str);
                                                      free($1.str);
                                                      free($3.str);

                                                   }
                        | out_rhs OR out_rhs    {  if($1.type==Bool && $1.prim && $3.type==Bool && $3.prim){
                                                      $$.prim = true; 
                                                      $$.type = Bool;
                                                   } 
                                                   else{
                                                      yyerror("semantic error 11"); 
                                                      return 1;
                                                   } 
                                                      $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+5));
                                                      snprintf($$.str,strlen($1.str)+strlen($3.str)+5,"%s || %s",$1.str,$3.str);
                                                      free($1.str);
                                                      free($3.str);
                                                }
                        | out_rhs COMP  out_rhs  {  temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); 
                                                   if(temp_type != -1 && temp_type < COMPARABLE){
                                                      $$.prim = true; 
                                                      $$.type = Bool;
                                                   } 
                                                   else{
                                                      yyerror("semantic error 12"); 
                                                      return 1;
                                                   }
                                                      $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+strlen($2.str)+3));
                                                      snprintf($$.str,strlen($1.str)+strlen($3.str)+strlen($2.str)+3,"%s %s %s",$1.str,$2.str,$3.str);
                                                      free($1.str);
                                                      free($3.str);
                                                }
                        | out_rhs EQUALITY out_rhs { temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); 
                                                      if(temp_type != -1 && temp_type < COMPARABLE){
                                                         $$.prim = true; 
                                                         $$.type = Bool;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 13"); 
                                                         return 1;
                                                      } 
                                                      $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+strlen($2.str)+3));
                                                      snprintf($$.str,strlen($1.str)+strlen($3.str)+strlen($2.str)+3,"%s %s %s",$1.str,$2.str,$3.str);
                                                      free($1.str);
                                                      free($3.str); 
                                                   }
                        | out_rhs '*'  out_rhs      {  temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim);
                                                      int f = 0;
                                                      if (($1.prim && $3.prim) && (($1.type == String && $3.type == Uint) || ($3.type == String && $1.type == Uint))) {
                                                         $$.prim = true; 
                                                         $$.type = String;
                                                         f = 1;
                                                      }
                                                      else if($1.prim && $3.prim && $1.type<=Complex && $3.type==Matrix){
                                                         $$.prim = true; 
                                                         $$.type = Matrix;
                                                      } 
                                                      else if($1.prim && (temp_type <= Complex && temp_type >= 0)){
                                                         $$.prim = true; 
                                                         $$.type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 14"); 
                                                         return 1;
                                                      }
                                                      if(f == 0)
                                                      {
                                                         $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                         snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s * %s",$1.str,$3.str);
                                                         free($1.str);
                                                         free($3.str);
                                                      }
                                                      else if($1.type == String && $3.type == Uint)
                                                      {
                                                         $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+16));
                                                         snprintf($$.str,strlen($1.str)+strlen($3.str)+16,"repeatString(%s,%s)",$1.str,$3.str);
                                                         free($1.str);
                                                         free($3.str);
                                                      }
                                                      else if($3.type == String && $1.type == Uint)
                                                      {
                                                         $$.str = (char *)malloc(sizeof(char)*(strlen($3.str)+strlen($1.str)+16));
                                                         snprintf($$.str,strlen($3.str)+strlen($1.str)+16,"repeatString(%s,%s)",$3.str,$1.str);
                                                         free($1.str);
                                                         free($3.str);
                                                      }
                                                   }
                        | out_rhs '/' out_rhs      {  temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); 
                                                      if($1.prim && (temp_type <= Complex && temp_type >= 0)){
                                                         $$.prim = true; 
                                                         $$.type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 15"); 
                                                         return 1;
                                                      }
                                                      $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                      snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s / %s",$1.str,$3.str);
                                                      free($1.str);
                                                      free($3.str);
                                                   }
                        | out_rhs '+' out_rhs   /* Works for uint, int, float, complex, matrix, *state*, list (uint, int, float, complex, matrix, *state*), string-concatenate */      
                                                   {  temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); 
                                                      if(temp_type == Matrix || temp_type == State || (temp_type <= Complex && temp_type >= 0)){
                                                         $$.prim = $1.prim; 
                                                         $$.type = temp_type; 
                                                         if(temp_type == Matrix){
                                                            $$.rows=$1.rows;
                                                         } 
                                                         $$.dim=$1.dim;
                                                      } 
                                                      else if (($1.prim==true) && ($1.type == String)){
                                                         $$.prim = true; 
                                                         $$.type = String;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 16");
                                                         return 1;
                                                      }
                                                      if($1.prim){
                                                         $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                         snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s + %s",$1.str,$3.str);
                                                         free($1.str);
                                                         free($3.str);
                                                      } 
                                                      else if($1.veconst == 0 && $3.veconst == 0){
                                                         $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+12));
                                                         snprintf($$.str,strlen($1.str)+strlen($3.str)+12,"add(%s,%s)",$1.str,$3.str);
                                                         free($1.str);
                                                         free($3.str);
                                                      }
                                                      else 
                                                      {
                                                         yyerror("semantic error : initialize first, cannot directly pass as argument");
                                                         return 1;
                                                      }
                                                   }
                        | out_rhs '-' out_rhs   /* Works for uint, int, float, complex, matrix, *state*, list (uint, int, float, complex, matrix, *state*) */                {  temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); 
                                                      if(temp_type == Matrix || temp_type == State || (temp_type <= Complex && temp_type >= 0)){
                                                         $$.prim = $1.prim; 
                                                         $$.type = temp_type; 
                                                         if(temp_type == Matrix) $$.rows=$1.rows; 
                                                         $$.dim=$1.dim;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 17");
                                                         return 1;
                                                      } 
                                                      if($1.prim){
                                                         $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                         snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s - %s",$1.str,$3.str);
                                                         free($1.str);
                                                         free($3.str);
                                                      } 
                                                      else if($1.veconst == 0 && $3.veconst == 0){
                                                         $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+12));
                                                         snprintf($$.str,strlen($1.str)+strlen($3.str)+12,"sub(%s,%s)",$1.str,$3.str);
                                                         free($1.str);
                                                         free($3.str);
                                                      }
                                                      else
                                                      {
                                                         /* Cannot initialize */
                                                         yyerror("semantic error : initialize first, cannot directly pass as argument");
                                                         return 1;
                                                      }                                                      
                                                   }
                        | out_rhs '@'  out_rhs   /* Works for matrix, *state*, list (uint, int, float, complex); list(complex)*list(matrix)*/                         {  temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); 
                                                      if($1.prim && temp_type == Matrix){
                                                         if($1.rows == $3.rows){
                                                            $$.prim = true; 
                                                            $$.type = temp_type; 
                                                            $$.rows = $1.rows;
                                                         } 
                                                         else{
                                                            yyerror("semantic error 18"); 
                                                            return 1;
                                                         }
                                                      } 
                                                      else if($1.prim && temp_type == State){
                                                         $$.prim = true; 
                                                         $$.type = Complex;
                                                      } 
                                                      else if(!$1.prim && (temp_type <= COMPATIBLE) && (temp_type >= 0)){
                                                         $$.prim = true; 
                                                         $$.type = Float; 
                                                         $$.dim = 0;
                                                      } 
                                                      else if($1.type==Complex && $3.type==Matrix){
                                                         $$.prim = true; 
                                                         $$.type = Matrix; 
                                                         $$.dim = 0;
                                                      } 
                                                      else{
                                                         yyerror("semantic error 19"); 
                                                         return 1;
                                                      }
                                                      if($1.prim && temp_type == Matrix)
                                                      {
                                                         $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                         snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s * %s",$1.str,$3.str);
                                                         free($1.str);
                                                         free($3.str);
                                                      } 
                                                      else if((!$1.prim && temp_type <= Float) && ($1.veconst == 0 && $3.veconst == 0)){
                                                         $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+14));
                                                         snprintf($$.str,strlen($1.str)+strlen($3.str)+14,"dot(%s,%s)",$1.str,$3.str);
                                                         free($1.str);
                                                         free($3.str);
                                                      }
                                                      else if(!$1.prim && temp_type == Complex  && ($1.veconst == 0 && $3.veconst == 0))
                                                      {
                                                         $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+21));
                                                         snprintf($$.str,strlen($1.str)+strlen($3.str)+21,"dotProductComplex(%s,%s)",$1.str,$3.str);
                                                         free($1.str);
                                                         free($3.str);
                                                      } 
                                                      else if(!$1.prim && !$3.prim && ($1.type == Complex) && ($3.type == Matrix)  && ($1.veconst == 0 && $3.veconst == 0)){
                                                         $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+19));
                                                         snprintf($$.str,strlen($1.str)+strlen($3.str)+19,"dotProductCross(%s,%s)",$1.str,$3.str);
                                                         free($1.str);
                                                         free($3.str);
                                                      }
                                                      else
                                                      {
                                                         yyerror("semantic error : initialize first, cannot directly pass as argument");
                                                         return 1;
                                                      }
                                                   }
                        | out_rhs '&' out_rhs   /* Works for uint, int, list(uint, int)*/ 
                                                   {  temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); 
                                                      if(temp_type <= Int){
                                                         $$.prim = $1.prim; 
                                                         $$.type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: incompatible operands"); 
                                                         return 1;
                                                      }
                                                      if($1.prim){
                                                         $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                         snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s & %s",$1.str,$3.str);
                                                         free($1.str);
                                                         free($3.str);
                                                      } 
                                                      else if($1.veconst == 0 && $3.veconst == 0){
                                                         $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+14));
                                                         snprintf($$.str,strlen($1.str)+strlen($3.str)+14,"bitwiseAnd(%s,%s)",$1.str,$3.str);
                                                         free($1.str);
                                                         free($3.str);
                                                      }
                                                      else
                                                      {
                                                         yyerror("semantic error : initialize first, cannot directly pass as argument");
                                                         return 1;
                                                      }
                                                   }
                        | out_rhs '^' out_rhs   /* Works for uint, int, list(uint, int)*/                                                     
                                                   {  temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); 
                                                      if(temp_type <= Int){
                                                         $$.prim = $1.prim; 
                                                         $$.type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: incompatible operands"); 
                                                         return 1;
                                                      }
                                                      if($1.prim){
                                                         $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                         snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s ^ %s",$1.str,$3.str);
                                                         free($1.str);
                                                         free($3.str);
                                                      } 
                                                      else if($1.veconst == 0 && $3.veconst == 0){
                                                         $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+14));
                                                         snprintf($$.str,strlen($1.str)+strlen($3.str)+14,"bitwiseXor(%s,%s)",$1.str,$3.str);
                                                         free($1.str);
                                                         free($3.str);
                                                      }   
                                                      else
                                                      {
                                                         yyerror("semantic error : initialize first, cannot directly pass as argument");
                                                         return 1;
                                                      }                                                  
                                                   }
                        | out_rhs '|' out_rhs   /* Works for uint, int, list(uint, int) */                                             
                                                   { temp_type = compatibleCheckAdv($1.type, $3.type, $1.prim, $3.prim, $1.dim, $3.dim); 
                                                      if(temp_type <= Int){
                                                         $$.prim = $1.prim; 
                                                         $$.type = temp_type;
                                                      } 
                                                      else{
                                                         yyerror("semantic error: incompatible operands"); 
                                                         return 1;
                                                      }
                                                      if($1.prim){
                                                         $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+4));
                                                         snprintf($$.str,strlen($1.str)+strlen($3.str)+4,"%s | %s",$1.str,$3.str);
                                                         free($1.str);
                                                         free($3.str);
                                                      } 
                                                      else if ($1.veconst == 0 && $3.veconst == 0){
                                                         $$.str = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+13));
                                                         snprintf($$.str,strlen($1.str)+strlen($3.str)+13,"bitwiseOr(%s,%s)",$1.str,$3.str);
                                                         free($1.str);
                                                         free($3.str);
                                                      }
                                                      else
                                                      {
                                                         yyerror("semantic error : initialize first, cannot directly pass as argument");
                                                         return 1;
                                                      }
                                                   }
                        ;

/* Expressions */
out_expr                : ID '=' out_rhs           {  fprintf(fp,"expression statement\n"); 
                                                      if(isDeclaration){
                                                         $$.type = $3.type; 
                                                         assignString($$.str,$1.str);
                                                         $$.prim = $3.prim; 
                                                         if(!$3.prim) $$.dim = $3.dim; 
                                                         if($3.type == Matrix) $$.rows = $3.rows; 
                                                      } 
                                                      else{
                                                         struct OutputSymbolEntry* entry = getOutputSymbolEntry(&OutputSymbolTable,$1.str,outputLevel,1); if(entry->type != $3.type){
                                                            yyerror("semantic error 20"); 
                                                            return 1;
                                                         }
                                                      }
                                                      
                                                      $$.str2 = (char *)malloc(sizeof(char)*(strlen($1.str)+strlen($3.str)+5));
                                                      snprintf($$.str2,strlen($1.str)+strlen($3.str)+10,"%s = %s;",$1.str,$3.str);
                                                   }
                        ;

decl                    : prim_type out_expr       {  fprintf(fp,"Primitive datatype declaration statement\n"); 
                                                      if(getOutputSymbolEntry(&OutputSymbolTable,$2.str,outputLevel,0) != NULL){
                                                         yyerror("semantic error: variable redeclaration"); 
                                                         return 1;
                                                      } 
                                                      else if(($2.prim==false) || (($1.type < COMPATIBLE) && ($1.type < $2.type)) || (($1.type >= COMPATIBLE) && ($1.type != $2.type))){
                                                         yyerror("semantic error: incompatible types"); 
                                                         return 1;
                                                      } 
                                                      else{
                                                         if($2.type == Matrix) insertInOutputTable(&OutputSymbolTable,$2.str,outputLevel,$2.type,true,$2.rows,0,false);
                                                         else insertInOutputTable(&OutputSymbolTable,$2.str,outputLevel,$2.type,true,0,0,false);
                                                      }
                                                      // printing declaration statements to cpp file
                                                      fprintf(out,"%s\n",$2.str2);
                                                   }

                        | list_type out_expr       {  fprintf(fp,"List datatype declaration statement\n"); 
                                                      if(getOutputSymbolEntry(&OutputSymbolTable,$2.str,outputLevel,0) != NULL){
                                                         yyerror("semantic error: variable redeclaration"); 
                                                         return 1;
                                                      } 
                        else if(($2.prim==true) || (($1.type < COMPATIBLE) && ($1.type < $2.type)) || (($1.type >= COMPATIBLE) && ($1.type != $2.type))){
                                                         yyerror("semantic error: incompatible types"); 
                                                         return 1;
                                                      } 
                                                      else{
                                                         if($2.type == Matrix)insertInOutputTable(&OutputSymbolTable,$2.str,outputLevel,$1.type,false,$2.rows,$2.dim,false); 
                                                         else insertInOutputTable(&OutputSymbolTable,$2.str,outputLevel,$1.type,false,0,$2.dim,false);
                                                      }
                                                      fprintf(out,"%s\n",$2.str2);
                                                   }
                        ;

/* Echo Statement */
echo_stmt               : ECHO '(' echo_list ')'      {  fprintf(fp,"Echo statement\n");
                                                      }
                        ;

echo_list               : echo_list ',' out_rhs       {  
                                                         if($3.prim){
                                                            if($$.type == Bool){
                                                               fprintf(out,"cout<<(%s);",$3.str);
                                                            }
                                                            else{
                                                               fprintf(out,"cout<<%s;",$3.str);
                                                            }
                                                         }
                                                         else{
                                                               fprintf(out,"for(int i=0;i<%d;i++){\n"
                                                                           "\tcout<<%s[i]<<\" \";"
                                                                           "}\n"
                                                               , $3.dim, $3.str);
                                                         }
                                                      }
                        | out_rhs                     {    
                                                         if($1.prim){
                                                            if($$.type == Bool){
                                                               fprintf(out,"cout<<(%s);",$1.str);
                                                            }
                                                            else{
                                                               fprintf(out,"cout<<%s;",$1.str);
                                                            }                                                            
                                                         }
                                                         else{
                                                            fprintf(out,"for(int i=0;i<%d;i++){\n"
                                                                        "\tcout<<%s[i]<<\" \";"
                                                                        "}\n", $1.dim, $1.str
                                                                   );
                                                         }
                                                      }
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

out_cond_stmt           : CONDITION '(' out_rhs ')' '{' {outputLevel++;fprintf(out,"if(%s){\n",$3.str);} out_main '}' {fprintf(out,"}\n");outputLevel--;} out_other_list out_other_final
                        ;

out_other_list          : out_other_list OTHERWISE '(' out_rhs ')' '{' {outputLevel++;fprintf(out,"else if(%s){\n",$4.str);} out_main '}' {fprintf(out,"}\n");outputLevel--;}
                        | /* epsilon */
                        ;

out_other_final         : OTHERWISE '{' {outputLevel++;fprintf(out,"else{\n");} out_main '}' {outputLevel--;fprintf(out,"}\n");}
                        | /* epsilon */
                        ;

out_for_stmt            : FOR ID {  if(getOutputSymbolEntry(&OutputSymbolTable,$2.str,outputLevel + 1,1) == NULL){
                                       yyerror("semantic error: variable used without declaration (4)"); 
                                       return 1;
                                    }
                                 } 
                          IN '(' range ')' '{' {outputLevel++;fprintf(out,"for(%s = %s;%s < %s;%s += %s){\n",$2.str,$6.start,$2.str,$6.end,$2.str,$6.step);} 
                          out_main '}'         {fprintf(out,"}\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel);outputLevel--;}
                        ;

out_for_lex_stmt        : FOR_LEX '(' var_list ')'  IN '(' range_list ')' {   if($3.num != $7.num){
                                                                                 yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                                 return 1;
                                                                              }
                                                                              printForLex($3.num, 2);
                                                                          } 
                          '{' {outputLevel++;} out_main '}'               {   printForLex($3.num, 0);
                                                                              exitOutputSymbolScope(&OutputSymbolTable,outputLevel);
                                                                              outputLevel--;}
                        ;

out_for_zip_stmt        : FOR_ZIP '(' var_list ')'  IN '(' range_list ')' {   if($3.num != $7.num){
                                                                                 yyerror("semantic error: mismatch in loop variables and ranges"); 
                                                                                 return 1;
                                                                              }
                                                                              printForZip($3.num, 2);
                                                                          } 
                          '{' {outputLevel++;} 
                          out_main '}'               {exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--; 
                                                         printForZip($3.num, 0);
                                                      }
                        ;

out_while_stmt          : WHILE '(' out_rhs ')' '{' {outputLevel++;fprintf(out,"while(%s){\n",$3.str);} out_main '}' {fprintf(out,"}\n");exitOutputSymbolScope(&OutputSymbolTable,outputLevel); outputLevel--;}
                        ;


/* Output Statement */
out_main                : out_main out_stmt
                        |
                        ;

out_stmt                : out_control
                        | save_stmt
                        | echo_stmt
                        | {isDeclaration = false;} out_expr {fprintf(out,"%s\n",$2.str2);}
                        | {isDeclaration = true;} decl
                        ;
%%

void printForZip(int num, int usage){
   if(usage == 0){
      fprintf(out, "}\n");
      return;
   }

   struct List* temp = head;
   struct List2* temp2 = range_list;
   fprintf(out, "for(");
   if(usage==1) {fprintf(out, "int ");}
   for(int i=0;i<num;i++){
      fprintf(out, "%s = %s",temp->id,temp2->start);
      if(i<num-1){fprintf(out, ", ");}
      temp = temp->next;
      temp2 = temp2->next;
   }
   fprintf(out, ";");

   temp = head;
   temp2= range_list;
   for(int i=0;i<num;i++){
      fprintf(out, "%s < %s",temp->id,temp2->end);
      if(i<num-1){fprintf(out, " && ");}
      temp = temp->next;
      temp2 = temp2->next;
   }
   fprintf(out, ";");

   temp = head;
   temp2= range_list;
   for(int i=0;i<num;i++){
      fprintf(out, "%s += %s",temp->id,temp2->step);
      if(i<num-1){fprintf(out, ", ");}
      temp = temp->next;
      temp2 = temp2->next;
   }
   fprintf(out, "){\n");

}

/* usage is 1 for main, 2 for output and 0 for closing*/
void printForLex(int num, int usage){
   if(usage){
      struct List* temp = head;
      struct List2* temp2 = range_list;
      int x = outputLevel-1;
      for(int i=0;i<num;i++){
         for(int j=0;j<x;j++){
            fprintf(out,"\t");
         }
         x++;
         if(usage==1){ fprintf(out,"for(int %s = %s;%s < %s;%s += %s){\n",temp->id,temp2->start,temp->id,temp2->end,temp->id,temp2->step);}
         else if(usage==2){ fprintf(out,"for(%s = %s;%s < %s;%s += %s){\n",temp->id,temp2->start,temp->id,temp2->end,temp->id,temp2->step);}
         temp = temp->next;
         temp2 = temp2->next;
      }
      indent = x;
   }
   else {
      int x = indent-1;
      for(int i=0;i<num;i++){
         for(int j=0;j<x;j++){
            fprintf(out,"\t");
         }
         x--;
         fprintf(out,"}\n");
      }
   }
}

char * IntToString(int n){
   int temp = n,len=0;
   while(temp != 0) {
      temp = temp/10;
      len++;
   }
   len += 1;
   char * str = (char *)malloc(sizeof(char)*len);
   sprintf(str,"%d",n);
   return str;
}

void assignString(char* str1, char* str2){
   str1 = (char*)malloc(sizeof(char)*(strlen(str2)+1));
   for(int i=0;i<strlen(str2);i++){
      str1[i] = str2[i];
   }
   str1[strlen(str2)] = '\0';
}

bool firstLetterCapital(char *str) {
   return (str[0] >= 65 && str[0] <= 90);
}

void insertInList(struct List** Head,char * data){
   struct List* newNode = (struct List*)malloc(sizeof(struct List));
   newNode->id = (char *)malloc(sizeof(char)*(strlen(data)+1));
   for(int i=0;i<strlen(data);i++){
      newNode->id[i] = data[i];
   }
   newNode->id[strlen(data)] = '\0';
   if(*Head == NULL){
      newNode->next = NULL;
   }
   else{
      newNode->next = *Head;
   }
   *Head = newNode;
}

void removeTopKFromList(struct List** Head, int k) {
   if(*Head == NULL) return;

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

int InBlock(struct BlockTable** Head,char * data,int len){
   struct BlockTable* temp = *Head;
   while(temp != NULL){
      if(strcmp(temp->id,data) == 0 && temp->len == len){
         return 1;
      }
      temp = temp->next;
   }
   return 0;
}

int insertInBlockTable(struct BlockTable** Head,char * data,int len,struct List* params){
   if(InBlock(Head,data,len)) return 0;
   struct BlockTable* newNode = (struct BlockTable*)malloc(sizeof(struct BlockTable));
   newNode->id = (char *)malloc(sizeof(char)*strlen(data)+1);
   for(int i=0;i<strlen(data);i++){
      newNode->id[i] = data[i];
   }
   newNode->id[strlen(data)] = '\0';
   newNode->params = params;
   newNode->len = len;
   if(*Head == NULL){
      newNode->next = NULL;
   }
   else{
      newNode->next = *Head;
   }
   *Head = newNode;
   return 1;
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

int insertInGateTable(struct GateTable ** Head,char * data,struct cpx * arr){
   struct GateTable* temp = *Head;
   while(temp != NULL){
      if(strcmp(temp->id,data) == 0){
         return 0;
      }
      temp = temp->next;
   }
   struct GateTable* newNode = (struct GateTable*)malloc(sizeof(struct GateTable));
   newNode->id = (char *)malloc(sizeof(char)*(strlen(data)+1));
   for(int i=0;i<strlen(data);i++){
      newNode->id[i] = data[i];
   }
   newNode->id[strlen(data)] = '\0';

   struct cpx *temp2 = (struct cpx *)malloc(sizeof(struct cpx)*4);
   for(int i=0;i<4;i++){
      temp2[i] = arr[i];
   }
   newNode->arr = temp2;

   if(*Head == NULL){
      newNode->next = NULL;
   }
   else{
      newNode->next = *Head;
   }
   *Head = newNode;
   return 1;
}

void printGateTable(struct GateTable ** GateSymbolTable){
   struct GateTable* temp = *GateSymbolTable;
   while(temp != NULL){
      printf("%s ",temp->id);
      for(int i=0;i<4;i++){
         printf("(%f, %f) ",temp->arr[i].real,temp->arr[i].imag);
      }
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
      if(strcmp(temp->id,block_id) == 0 && temp->len == num_params){
         return 1;
      }
      temp = temp->next;
   }
   return 0;
}

/* Output Section */

/* insert symtab entry at some scope level */
void insertInOutputTable(struct OutputSymbolEntry** Head, char* id, int level, int type, bool primitive, int matrix_dim, int dim, bool isLoopId){
   /* New Entry */
   struct OutputSymbolEntry* newNode = (struct OutputSymbolEntry*)malloc(sizeof(struct OutputSymbolEntry));

   /* ID */
   newNode->id = (char *)malloc(sizeof(char)*(strlen(id)+1));
   for(int i=0;i<strlen(id);i++){
      newNode->id[i] = id[i];
   }
   newNode->id[strlen(id)] = '\0';

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
   /* printf("Insertion : %s %d %d %d %d\n", newNode->id, newNode->level, newNode->primitive, newNode->dim, newNode->matrix_dim); */
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
      printf("%d %d %d %d\n",temp->type, temp->level, temp->primitive, temp->dim);
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
  out = fopen("out.cpp","w");

  return yyparse();
}

void yyerror(char* err){
   printf("Near line %d: %s\n", line, err);
   fprintf(fp,"Near line %d: %s\n",line, err);
}
