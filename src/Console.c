#include "Console.h"

void Clear() {
    #ifdef __WIN32
    std::system("cls");
    #endif
    #ifdef __linux__
    std::system("clear");
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
