#!/bin/bash
clear;
g++ $(pwd)/src/YoungShell.cpp -o $(pwd)/ys; #-Wall -Wextra -Wpedantic;
chmod 755 YoungShell;
./ys;
rm -rf ys;