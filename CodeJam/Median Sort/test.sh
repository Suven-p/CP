#!/bin/bash

i=1

g++ -o medianSort ./medianSort.cpp && python3 ../interactive_runner.py python3 ./local_testing_tool.py $i -- ./medianSort

echo -e "\n\n\n"

g++ -o "medianSort old" "./medianSort old.cpp" && python3 ../interactive_runner.py python3 ./local_testing_tool.py $i -- "./medianSort old"
