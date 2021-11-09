#!/bin/bash
exit=0
i=0
g++ -o gameprof ./gameprof.cpp && g++ -o ideal ./ideal.cpp
while [ $exit -eq 0 ]
do
    python3 genTestCase.py
./gameprof < testInput.txt > myoutput.txt
./ideal < testInput.txt > idealoutput.txt
diff myoutput.txt idealoutput.txt > diff.txt
    i=$[$i+1]
    echo Loop $i completed
    if [ $? -eq 1 ]
    then
        exit=1
    fi
done