@echo off
cd C:\

@echo off
set /p "File_path=Enter your assembly file's path: "

@echo off
set Path=C:\MinGW\bin;%PATH%

cd C:\Users\LaurentBOUQUIN\Documents\GitHub\2023-2024-project-3-virtual-processor-team-8\Src

echo %File_path% > path.txt

gcc -o main.exe main.c

cls

main.exe

@echo off
pause