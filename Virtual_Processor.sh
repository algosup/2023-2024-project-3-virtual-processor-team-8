#!/bin/bash

echo "Enter your assembly file's path: "
read File_path

cd Src

echo $File_path > path.txt

gcc -o main main.c

clear

./main

read -p "Press any key to continue... " -n1 -s