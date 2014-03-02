cd ../src;
for i in `ls ../src`; do 
  cp $i tmp.$i.c;
  clang-format -style=Mozilla tmp.$i.c > $i;
done;
rm tmp.*;
