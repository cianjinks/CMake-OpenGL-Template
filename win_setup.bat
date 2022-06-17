@echo off
if not exist "%~dp0/build" mkdir "%~dp0/build"
chdir "%~dp0/build"
call cmake ../
PAUSE