@echo off
:loop
	RAND.exe %random% >TEXT.txt
	BASIC.exe < TEXT.txt > OUTPUT.txt
	FORCE.exe < TEXT.txt > FORCEOUT.txt
	fc OUTPUT.txt FORCEOUT.txt
if not errorlevel 1 goto loop
pause
goto loop