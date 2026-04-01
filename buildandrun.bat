@echo off
REM Step 1: Compile
cd src
gcc -Wall main.c scheduler.c usf.c workload.c sync.c metrics.c -o ..\main.exe -lwinpthread

REM Step 2: Run batch experiments
cd ..
echo Running batch experiments...
powershell -ExecutionPolicy Bypass -File experiments\run_experiments.ps1

REM Step 3: Plot results
echo Plotting results...
python experiments\plot_results.py

pause
