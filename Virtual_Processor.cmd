
@echo off
cd Src


@echo off
set /p use_path="Do you want to use a file path (y/n): "


IF "%use_path%"=="y" (set /p "File_path=Enter your assembly file's path: ") ELSE (set /p File_path=<path.txt)

IF File_path=="" set File_path=path.txt

echo %File_path% > path.txt

gcc -o main.exe main.c

cls

main.exe

@echo off
pause