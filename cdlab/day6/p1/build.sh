#!/bin/sh
bison -y -d parser.y
lex lexer.l
gcc lex.yy.c parser.tab.c -lfl
