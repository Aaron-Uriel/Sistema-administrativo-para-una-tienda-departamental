#include "Console.h"
#include <stdlib.h>
#include <stdio.h>
#ifdef __WIN32
#include <windows.h>
#endif
#ifdef __linux__
#include <unistd.h>
#endif

void ClearScreen() {
    #ifdef __WIN32
    system("cls");
    #endif
    #ifdef __linux__
    system("clear");
    #endif
}

void Sleep_(int milliseconds){
    #ifdef __WIN32
    Sleep(milliseconds);
    #endif
    #ifdef __linux__
    usleep(milliseconds*1000);
  #endif
}

void gotoxy(int x,int y) {
    #ifdef __linux__
    printf("%c[%d;%df",0x1B,y,x);
    #endif
    #ifdef __WIN32
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    #endif
}