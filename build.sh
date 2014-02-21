#!/bin/bash
rm *.{c,h}; rm a.out;
yacc -d scheme.y; lex scheme.l; gcc lex.yy.c y.tab.c; ./a.out
