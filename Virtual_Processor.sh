#!/bin/bash

echo "Enter your assembly file's path: "
read File_path

export PATH=/usr/local/bin:$PATH

echo "Searching for the directory..."

Directory=$(find / -type d -name "2023-2024-project-3-virtual-processor-team-8" 2>/dev/null)

cd "$Directory"
cd Src

echo $File_path > path.txt

gcc -o main main.c

clear

./main

read -p "Press any key to continue... " -n1 -s