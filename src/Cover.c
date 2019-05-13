#include <stdio.h>
#include "Console.h"
#include "psconio.h"

void ClearScreen();
void Sleep(int milliseconds);
char getch(void);

void color(){
    #ifdef __WIN32
    system("color 07");
    #endif
}
void colorback(){
    #ifdef __WIN32
    system("color 00");
    #endif
}

void gotoxy(int x,int y) {
    #ifdef __linux__
    printf("%c[%d;%df",0x1B,y,x);
    #endif
    #ifdef __WIN32
    #include <windows.h>  
    void gotoxy(int x,int y){  
        HANDLE hcon;  
        hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
        COORD dwPos;  
        dwPos.X = x;  
        dwPos.Y= y;  
        SetConsoleCursorPosition(hcon,dwPos);  
    }  
    #endif
}

void cover(){
    ClearScreen();
    color();
    printf("Office Depot\n\nCARGANDO ");
    for (int x = 1 ; x <= 50 ; x++){
        gotoxy(x,20); printf("*\n");
        gotoxy(25,20); printf("%%%d" , (x * 100) / 50);
        Sleep(70);
    }
    gotoxy(25,20);printf("Presiona cualquier tecla para continuar");
    getch();
}
