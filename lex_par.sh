#!bin/bash
yacc -d ./Parser/parser_main.y -o ./exec/y.tab.c
lex ./lexer/lexical.l
mv lex.yy.c ./exec/lex.yy.c
gcc ./exec/y.tab.c ./exec/lex.yy.c -ll -w -o ./exec/a.out
cd ./exec
str="../Tests/UnitTests/"
str+=$1
./a.out $str
