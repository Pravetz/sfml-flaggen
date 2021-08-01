#!/bin/sh

g++ -c main.cpp
g++ main.o -o main -lsfml-window -lsfml-graphics -lsfml-system

exit 0
