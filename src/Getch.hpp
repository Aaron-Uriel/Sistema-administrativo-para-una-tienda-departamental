#ifndef GETCH
#define GETCH

#ifdef __linux__

extern "C" {
    char getch(void);
    char getche(void);
}

#endif

#ifdef __WIN32

#include <conio.h>

#endif

#endif