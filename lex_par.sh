#! /bin/bash
yacc -d ./Parser/parser_main.y -o ./exec/y.tab.c
lex ./lexer/lexical.l
mv lex.yy.c ./exec/lex.yy.c
gcc ./exec/y.tab.c ./exec/lex.yy.c -ll -w -o ./exec/a.out
cd ./exec

testpath1="../Tests/UnitTests/"
testpath2="../Tests/IntegrationTests/"
testpath1+=$1
testpath2+=$1
if [ -f $testpath1 ]; then
    ./a.out $testpath1
else
    ./a.out $testpath2
fi

