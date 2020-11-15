#!/bin/bash
clear;
export USER=$(whoami);
export HOSTNAME=$(hostname);
export DIRS=$(dirs -c;dirs +0 || pwd | sed 's|^$HOME|~|' );
g++ $(pwd)/src/YoungShell.cpp -o $(pwd)/ysh -Wall -Wextra -Wpedantic;
chmod 755 ysh;
./ysh
# rm -rf ysh;
