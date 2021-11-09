#!/bin/bash

g++ -o solution ./solution.cpp && python3 ../interactive_runner.py python3 ./local_testing_tool.py 0 -- ./solution
