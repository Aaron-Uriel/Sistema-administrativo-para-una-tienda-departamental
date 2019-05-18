#ifndef PSCONIO
#define PSCONIO

#ifdef __linux__

#if defined(__cplusplus)
extern "C" {
#endif
    char getch(void);
    char getche(void);
if defined(__cplusplus)
}
#endif

#endif

#ifdef __WIN32

#include <conio.h>

#endif