@echo off
set /p "File_path=Enter your assembly file's path: "

@echo off
cd Src

@echo off
echo %File_path% > path.txt

gcc -o main.exe main.c

cls

main.exe

@echo off
pause