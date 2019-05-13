#ifndef PSCONIO
#define PSCONIO

#ifdef __linux__

#if defined(__cplusplus)
extern "C" {
    char getch(void);
    char getche(void);
}
#elif defined(__cplusplus)
char getch(void);
char getche(void);
#endif

#endif

#ifdef __WIN32

#include <conio.h>

#endif

#endif