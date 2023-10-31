#!bin/bash
yacc -d ./Parser/parser_main.y
lex ./lexer/lexical.l
gcc y.tab.c lex.yy.c -ll -w
str="./Tests/UnitTests/"
str+=$1
./a.out $str
