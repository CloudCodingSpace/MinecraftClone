@echo off
SetLocal EnableDelayedExpansion

SET SRCS=
FOR /R %%f IN (*.cpp) DO (
    set SRCS=!SRCS! %%f
)

FOR /R %%f IN (*.c) DO (
    set SRCS=!SRCS! %%f
)

SET includep=-Idependencies/include 
SET libp=-Ldependencies/lib
SET libflags=-lglfw3dll -lassimp.dll

g++ -g %includep% %libp% %SRCS% %libflags% -o bin/MinecraftClone.exe