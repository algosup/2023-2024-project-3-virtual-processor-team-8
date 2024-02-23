#!/bin/bash

echo "Enter your assembly file's path: "
read File_path
# // if file path is empty set /Users/pierregorin/Documents/GitHub/2023-2024-project-3-virtual-processor-team-8/Src/code.asm as default
if [ -z "$File_path" ]
then
    File_path="/Users/pierregorin/Documents/GitHub/2023-2024-project-3-virtual-processor-team-8/Src/code.asm"
fi

cd Src

echo $File_path > path.txt

gcc -o main main.c

clear

./main

read -p "Press any key to continue... " -n1 -s