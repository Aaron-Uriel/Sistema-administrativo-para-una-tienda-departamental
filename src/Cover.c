#include <stdio.h>

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
    #ifdef __WIN32
    system("color 07");
    #endif
    printf("Office Depot\n\nCARGANDO ");
    for (int x = 1 ; x <= 100 ; x++){
        printf("*");
        #ifdef __WIN32
        sleep (400);
        #endif
    }
}
