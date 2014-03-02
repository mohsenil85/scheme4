#!/bin/bash
cd ..;
mkdir -p obj;
mkdir -p bin;
rm src/y.tab.*;
rm src/lex.yy.c;
cd src;
yacc -d parser.y ;
lex tokens.l;
cd ..;
make clean; make remove;  make;
./util/run_tests.sh;
cd util;
../bin/main