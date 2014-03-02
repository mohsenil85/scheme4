#!/bin/bash
#
echo "start tests..."
cd ..;
for i in `ls test`; do
  echo "testing $i..."
  echo
  clang --std=c99  test/$i; 
  ./a.out; 
  rm a.out;
done
echo
echo
cd util;
echo "end tests..."
