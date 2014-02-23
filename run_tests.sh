#!/bin/bash
#
echo "start tests..."
for i in `ls test`; do
  echo "testing $i..."
  echo
  gcc test/$i; 
  ./a.out; 
  rm a.out;
done
echo
echo
echo "end tests..."
