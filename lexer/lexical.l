%{
#include<stdio.h>
#include<string.h>

FILE * fp, *fp2;
extern FILE* yyin;
int line = 0,flag=0,flag2=0;

void printComparator();
void printLogical();
void printDatatype();
void printConditional();
void printOperator();
void printSpecial();
void printReserved();
void error();
%}
/* contains frequently used declarations */
special                 [-@#*+_/:.\\]
digit                   [0-9]
letter                  [a-zA-Z]
id                      ({letter})({letter}|{digit}|_)*
Number                  {digit}+

Question                (?)
Colon                   (:)
SemiColon               (;)
Arrow                   ("->")

String                  \"([^\"\\]*(\\.)?)*\"
Character                \'(.|\\.)\'

/* Reserved keywords */
Logicals                (\|\||&&)
Comparators             (<|>|>=|<=|==|!=)
datatypes               (int|float|list|complex|matrix)  

%%

[ \t]                   {}
[\n]                    {line++;}
[;]                     {fprintf(fp2,"punctuation: %s\n",yytext);}
[:]                     {fprintf(fp2,"punctuation: %s\n",yytext);}
[,]                     {printSpecial();}
[()\[\]{}]              {printSpecial();}
[\\]                    {printSpecial();}
[\_]                    {printSpecial();}


($[^$]*$)             {}

"?"                     {printSpecial();return yytext[0];}
"#"                     {printSpecial();return yytext[0];}
"."                     {printSpecial();return yytext[0];}
{Arrow}                 {printSpecial();return ARROW;}

"gate"                  {printReserved();return GATE;}
"diff"                  {printReserved();}
"sum"                   {printReserved();}
"std_dev"               {printReserved();}
"var"                   {printReserved();}
"in"                    {printReserved();return IN;}
"save"                  {printReserved();}
"echo"                  {printReserved();}
"return"                {printReserved();}
"init"                  {printReserved();}
"condition"             {printReserved();return CONDITION;}
"otherwise"             {printReserved();return OTHERWISE;}
"measure"               {printReserved();return MEASURE;}
"registers"             {printReserved();return REGISTERS;}
"quantum"               {printReserved();return QUANTUM;}
"classical"             {printReserved();return CLASSICAL;}
"iters"                 {printReserved();return ITERS;}
"set"                   {printReserved();return SET;}
"states"                {printReserved();return STATES;}
"block"                 {printReserved();return BLOCK;}
"for"                   {printReserved();return FOR;}
"for_lex"               {printReserved();return FOR_LEX;}
"for_zip"               {printReserved();return FOR_ZIP;}
"begin_output"          {printReserved();return OUTPUT_BEGIN;}
"end_output"            {printReserved();return OUTPUT_END;}
"begin_init"            {printReserved();return INIT_BEGIN;}
"end_init"              {printReserved();return INIT_END;}
"begin_main"            {printReserved();return MAIN_BEGIN;}
"begin_end"             {printReserved();return MAIN_END;}
"barrier"               {printReserved();return BARRIER;}
[XYZH]                  {printReserved();return GATE;}
{datatypes}             {printReserved();}

{Comparators}           {printComparator();}
{Logicals}              {printLogical();}        

{String}                {fprintf(fp,"%s",yytext);yytext[strlen(yytext)-1]='\0';fprintf(fp2,"punctuation: \"\nconstant: %s\npunctuation: \"\n",yytext+1);}
{Character}             {fprintf(fp,"%s",yytext);yytext[strlen(yytext)-1]='\0';fprintf(fp2,"punctuation: '\nconstant: %s\npunctuation: '\n",yytext+1);}

{Number}                {fprintf(fp2,"constant: %s\n",yytext);} 
{id}                    {fprintf(fp2,"ID: %s\n",yytext);}
[-+*/=%]                {printOperator();}
.                       {} /*If code reaches here then there is an error */

%%

void printReserved(){
    fprintf(fp2,"reserved keyword : %s\n",yytext);
}

void printLogical(){
    fprintf(fp2,"logical: %s\n",yytext);
}

void printSpecial(){
    fprintf(fp2,"special symbol: %s\n",yytext);
}

void printComparator(){
    fprintf(fp2,"comparator: %s\n",yytext);
}

void printOperator(){
    fprintf(fp2,"operator: %s\n",yytext);
}

void error(){
    fprintf(fp2,"\nerror at line %d\n",line);
}

int yywrap(void){}
  
int main(int argc, char*argv[])
{  
    fp2 = fopen("out_token.txt","w"); // for writing token stream

    yyin = fopen("in.txt","r"); // input file
    while(yylex());
  
    return 0;
}