@echo off

set mode=
set /p mode=Please choose deploy mode(1-Debug 2-Release):
set dirName=
if "%mode%"=="1" (set dirName=Debug) else (set dirName=Release) 

set dir=.\CardPrinter_%date:~0,4%%date:~5,2%%date:~8,2%
echo %dir%
md %dir%

copy /y .\UninstallOCX.bat                   %dir%
copy /y .\InstallOCX.bat                     %dir%
copy /y .\RedCard.cfg                        %dir%
copy /y ..\%dirName%\RedCard.dll             %dir%
copy /y ..\lib\MagAPI.dll                    %dir%
copy /y ..\%dirName%\CardOCX.dll             %dir%\CardOCX.ocx
copy /y ..\%dirName%\CardInterface.dll       %dir%
copy /y ..\%dirName%\CardManager.exe         %dir%

copy /y ..\%dirName%\CardEngine.dll          %dir%
copy /y ..\%dirName%\CPUUserCard.dll         %dir%
copy /y ..\%dirName%\Commons.dll             %dir%
copy /y ..\%dirName%\Decard.dll              %dir%
copy /y ..\%dirName%\dcrf32.dll              %dir%
copy /y ..\%dirName%\PsamCard.dll            %dir%
copy /y ..\%dirName%\log4cplus.properties    %dir%
copy /y ..\%dirName%\RedCard.properties      %dir%

if "%mode%"=="1" (copy /y ..\%dirName%\log4cplusUD.dll  %dir%) else (copy /y ..\%dirName%\log4cplusU.dll  %dir%) 

pause

