#!/bin/bash
cd ..;
rm src/y.tab.*;
rm src/lex.yy.c;
make clean; make remove;
