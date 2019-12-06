@echo off

REM Cleanup
del "%~dp0*.sln" /S /Q
del "%~dp0*.vcxproj" /S /Q
del "%~dp0*.vcxproj.filters" /S /Q
del "%~dp0*.vcxproj.user" /S /Q
del "%~dp0*.vcxproj.vpc_crc" /S /Q

echo.

if not "%VS120COMNTOOLS%" == "" (
	set VisualStudio_Version=2013
) else (
	if not "%VS110COMNTOOLS%" == "" (
		set VisualStudio_Version=2012
	) else (
		if not "%VS100COMNTOOLS%" == "" (
			set VisualStudio_Version=2010
		) else (
			echo No Visual Studio C++ could be found, please install VS 2013/2012/2010 and try again
			pause
			exit
		)
	)
)

pushd %~dp0
  devtools\bin\vpc.exe /te120 +game /%VisualStudio_Version% /mksln games-vs%VisualStudio_Version%.sln
popd
pause
