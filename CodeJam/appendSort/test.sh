g++ -o appendsort appendsort.cpp && ./appendsort < ./test_set_1/ts1_input.txt > output.txt;
diff output.txt ./test_set_1/ts1_output.txt

g++ -o appendsort appendsort.cpp && ./appendsort < ./test_set_2/ts2_input.txt > output.txt;
diff output.txt ./test_set_2/ts2_output.txt