#!/bin/bash
rm src/y.tab.*;
rm src/lex.yy.c;
cd src;
yacc -d parser.y ;
lex tokens.l;
cd .. ;
make clean; make remove;  make; ./bin/main
