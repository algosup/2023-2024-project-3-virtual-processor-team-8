@echo off
cd C:\

@echo off
set /p "File_path=Enter your assembly file's path: "

@echo off
set Path=C:\MinGW\bin;%PATH%

echo Searching for the directory...

@echo off
FOR /F "tokens=1" %%G IN ('dir /AD /s /b 2023-2024-project-3-virtual-processor-team-8') DO set Directory=%%G

@echo off
cd %Directory%

@echo off
cd Src

@echo off
echo %File_path% > path.txt

gcc -o main.exe main.c

cls

main.exe

@echo off
pause