rem This works if run as administrator - otherwise no files are created
cd /d "%~dp0"
..\..\SourceMonitor.exe /C .\AddCheckpointCmd.xml
pause
