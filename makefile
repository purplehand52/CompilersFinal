# this is a comment

cc=gcc
cc_=g++

.SILENT: create_folders complex matrix state out Parser parse lexer clean

all: create_folders out complex matrix state
	$(cc_) exec/out.cpp ./CodeGen/Basic/complex.cpp ./CodeGen/Basic/matrix.cpp ./CodeGen/Basic/state.cpp -Iheaders/ -o ./exec/a.out
	exec/a.out

create_folders:
	@mkdir -p exec
	rm -rf exec/*

complex: ./headers/complex.h ./CodeGen/Basic/complex.cpp
matrix: ./headers/matrix.h ./CodeGen/Basic/matrix.cpp
state: ./headers/state.h ./CodeGen/Basic/state.cpp

out: Parser
	./exec/parser $(SRC)
	mv out.cpp ./exec/out.cpp
	mv output.parsed ./exec/output.parsed
	mv tokens.txt ./exec/tokens.txt

Parser: parse lexer
	$(cc) ./exec/lex.yy.c ./exec/y.tab.c -w -o ./exec/parser -Iheaders/

parse:
	yacc -d ./Parser/parser_main.y
	mv y.tab.c ./exec/y.tab.c
	mv y.tab.h ./headers/y.tab.h

lexer:
	lex ./Lexer/lexical.l
	mv lex.yy.c ./exec/lex.yy.c

clean: 
	rm -rf exec headers/y.tab.h