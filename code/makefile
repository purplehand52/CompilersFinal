# this is a comment
PHASE="IV"
cc=gcc
cc_=g++

.SILENT: create_folders complex matrix state out Parser parse lexe clean all

all: create_folders out complex matrix state
	$(cc_) -std=c++17 -w exec/out.cpp ./CodeGen/Basic/complex.cpp ./CodeGen/Basic/matrix.cpp ./CodeGen/Basic/state.cpp -Iheaders/ -o ./exec/a.out
	exec/a.out
	mv result.csv ./exec/result.csv

create_folders:
	@mkdir -p exec
	rm -rf exec/*

complex: ./headers/complex.h ./CodeGen/Basic/complex.cpp
matrix: ./headers/matrix.h ./CodeGen/Basic/matrix.cpp
state: ./headers/state.h ./CodeGen/Basic/state.cpp

out: Parser
	./exec/parser ../testcases/Phase-$(PHASE)-testcases/$(SRC)
	mv out.cpp ./exec/out.cpp
	mv output.parsed ./exec/output.parsed
	mv tokens.txt ./exec/tokens.txt

Parser: parse lexe
	$(cc) ./exec/lex.yy.c ./exec/y.tab.c -w -o ./exec/parser -Iheaders/

parse:
	yacc -d ./Parser/parser_main.y
	mv y.tab.c ./exec/y.tab.c
	mv y.tab.h ./headers/y.tab.h

lexe:
	lex ./Lexer/lexical.l
	mv lex.yy.c ./exec/lex.yy.c

clean: 
	rm -rf exec headers/y.tab.h
