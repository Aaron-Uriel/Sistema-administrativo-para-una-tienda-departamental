#include <stdio.h>
#include "Console.h"
#include "psconio.h"
#include <stdlib.h>

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

void cover(){
    ClearScreen();
    color();
    printf("Office Depot\n\nCARGANDO ");
    for (int x = 1 ; x <= 50 ; x++){
        gotoxy(x,20); printf("*\n");
        gotoxy(25,20); printf("%%%d" , (x * 100) / 50);
        Sleep_(70);
    }
    gotoxy(25,20);
    printf("Presiona cualquier tecla para continuar");
    getch();
}
