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

const int AnchoVentana = 68;
const int LargoVentana = 26;

void cover(){
    ClearScreen();
    color();
    printf("Office Depot\n\nCARGANDO... ");
    for (int x = 1 ; x <= AnchoVentana ; x++){
        gotoxy(x, LargoVentana / 2);
        printf("*\n");
        gotoxy(AnchoVentana / 2, LargoVentana / 2);
        printf("%d%%" , (x * 100) / AnchoVentana);
        Sleep_(50);
    }
    printf("\nPresiona cualquier tecla para continuar");
    getch();
}
