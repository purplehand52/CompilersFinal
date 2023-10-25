#!/bin/bash

lex lexical.l
gcc lex.yy.c
./a.out