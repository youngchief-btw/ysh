#!/bin/bash
clear;
export USER=$(whoami);
export HOSTNAME=$(hostname);
export DIRS=$(dirs -c;dirs);
g++ $(pwd)/src/YoungShell.cpp -o $(pwd)/ys; -Wall -Wextra -Wpedantic;
chmod 755 YoungShell;
./ys;
#rm -rf ys;
