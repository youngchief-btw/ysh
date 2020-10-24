#!/bin/bash
clear;
export USER=$(whoami);
export HOSTNAME=$(hostname);
export DIRS=$(dirs -c;dirs +0 || pwd | sed 's|^$HOME|~|' );
g++ $(pwd)/src/YoungShell.cpp -o $(pwd)/ys -Wall -Wextra -Wpedantic;
chmod 755 ys;
./ys
# rm -rf ys;
