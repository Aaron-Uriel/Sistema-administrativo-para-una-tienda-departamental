#include "Console.h"
#include <stdlib.h>

void Clear() {
    #ifdef __WIN32
    system("cls");
    #endif
    #ifdef __linux__
    system("clear");
    #endif
}

void Sleep(int milliseconds){
  #ifdef __WIN32
  #include <windows.h>
  Sleep(milliseconds);
  #endif
  #ifdef __linux__
  #include <unistd.h>
  usleep(milliseconds*1000);
  #endif
}
