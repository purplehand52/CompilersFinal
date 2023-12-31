%{
#define YYSTYPE struct st
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
#include "st.h"

extern struct st yylval;

FILE *fp2;
extern FILE* yyin;
int line = 1,flag=0,flag2=0;

void printComparator();
void printLogical();
void printDatatype();
void printConditional();
void printOperator();
void printSpecial();
void printReserved();
void error();
void handleNewLines();
void allocateMemory();
%}
/* contains frequently used declarations */

digit                   [0-9]
letter                  [a-zA-Z]
id                      {letter}({letter}|{digit}|_)*
Number                  {digit}+
Neg                     [-]{digit}+
Dec                     {digit}+\.{digit}+
Exp                     {digit}+\.{digit}+E(Number|Neg)
Imag                    [I]

/*Calls                   (add|sub|dot|std_dev|var|avg|condense|sum)*/
/*datatypes               (int|float|list|complex|matrix)*/

Arrow                   (->)
String                  \"([^\"\\]*(\\.)?)*\"
Character                \'(.|\\.)\'


/* Reserved symbols */
Logicals                (^|&|\|)
Comparators             (<|>|>=|<=)
Equality                (==|!=)  

%%

[\t ]                   {}
[\n]                    {line++;}
[;]                     {fprintf(fp2,"punctuation: %s\n",yytext);return yytext[0];}
[:]                     {fprintf(fp2,"punctuation: %s\n",yytext);return yytext[0];}
[,]                     {printSpecial();return yytext[0];}
[\)\(\[\]\{\}]          {printSpecial();return yytext[0];}
"\\"                    {printSpecial();return yytext[0];}

($[^$]*$)               {handleNewLines();}

"?"                     {printSpecial();return yytext[0];}
"#"                     {printSpecial();return yytext[0];}
"\."                    {printSpecial();return yytext[0];}
{Arrow}                 {printSpecial();return ARROW;}

"add"                   {printReserved();allocateMemory();return ADD;}
"sub"                   {printReserved();allocateMemory();return SUB;}
"dot"                   {printReserved();allocateMemory();return DOT;}
"std_dev"               {printReserved();allocateMemory();return STD_DEV;}
"var"                   {printReserved();allocateMemory();return VAR;}
"avg"                   {printReserved();allocateMemory();return AVG;}
"condense"              {printReserved();allocateMemory();return CONDENSE;}
"sum"                   {printReserved();allocateMemory();return SUM;}

"c_output"              {printReserved();allocateMemory();return COUT;}

"true"                  {printReserved();return TRUE;}
"false"                 {printReserved();return FALSE;}

"bool"                  {printReserved();return BOOL;}
"int"                   {printReserved();return INT;}
"uint"                  {printReserved();return UINT;}
"float"                 {printReserved();return FLOAT;}
"complex"               {printReserved();return COMPLEX;}
"string"                {printReserved();return STRING;}
"matrix"                {printReserved();return MATRIX;}
"state"                 {printReserved();return STATE;}
"list"                  {printReserved();return LIST;}

"gate"                  {printReserved();return GATE_DEF; }

"in"                    {printReserved();return IN;}
"save"                  {printReserved();return SAVE;}
"echo"                  {printReserved();return ECHO;}
"return"                {printReserved();return RETURN;}
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
"end_main"              {printReserved();return MAIN_END;}
"barrier"               {printReserved();return BARRIER;}
[XYZH]                  {printReserved();allocateMemory();return GATE; }

{Comparators}           {printComparator();allocateMemory(); return COMP;}
{Equality}              {printComparator();allocateMemory();return EQUALITY;}
{Logicals}              {printLogical();allocateMemory();return yytext[0];}
"||"                    {printLogical();allocateMemory();return OR;}
"&&"                    {printLogical();allocateMemory();return AND;}
"!"                     {printLogical();return yytext[0];}

{String}                {allocateMemory();yytext[strlen(yytext)-1]='\0';fprintf(fp2,"punctuation: \"\nconstant: %s\npunctuation: \"\n",yytext+1);return STRING;}
{Character}             {yytext[strlen(yytext)-1]='\0';fprintf(fp2,"punctuation: '\nconstant: %s\npunctuation: '\n",yytext+1);}

{Number}                {fprintf(fp2,"constant: %s\n",yytext); yylval.num = atoi(yytext); return NUMBER;}
{Neg}                   {fprintf(fp2,"constant: %s\n",yytext); yylval.num = atoi(yytext); return NEG;}
{Dec}                   {fprintf(fp2,"constant: %s\n",yytext); yylval.real = atof(yytext); return DEC;}
{Exp}                   {fprintf(fp2,"constant: %s\n",yytext); yylval.real = atof(yytext); return EXP;}
{Imag}                  {fprintf(fp2,"constant: %s\n",yytext); return IMAG;} 
{id}                    {fprintf(fp2,"ID: %s\n",yytext);allocateMemory();return ID;}
[-+*/=%@]               {printOperator();return yytext[0];}
.                       {printf("%s\n",yytext);} /*If code reaches here then there is an error */

%%

void allocateMemory(){
    yylval.str = (char *)malloc(sizeof(char)*strlen(yytext+1)); 
    for(int i=0;i<strlen(yytext);i++){
        yylval.str[i] = yytext[i];
    }
    yylval.str[strlen(yytext)] = '\0';
}

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

void handleNewLines() {
    int i = 0;
    while(yytext[i]!='\0'){
        if(yytext[i]=='\n'){
            line++;
        }
        i++;
    }
}

int yywrap(void){}
  
/* int main(int argc, char*argv[])
{  
    fp2 = fopen("out_token.txt","w"); // for writing token stream

    yyin = fopen("in.txt","r"); // input file
    while(yylex());
  
    return 0;
} */