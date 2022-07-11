:: @echo off

set PROG=%1

C:\"Program Files"\tcc\tcc.exe .\cbfb.c
.\cbfb.exe .\%PROG%.bf
C:\"Program Files"\tcc\tcc.exe a.c -o %PROG%.exe
.\%PROG%.exe