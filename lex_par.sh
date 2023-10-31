yacc -d ./Parser/parser_main.y
lex ./lexer/lexical.l
gcc ./Parser/y.tab.c ./lexer/lex.yy.c -ll
./a.out