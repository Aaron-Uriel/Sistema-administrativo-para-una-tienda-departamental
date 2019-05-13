#ifndef CONSOLE
#define CONSOLE

#if defined(__cplusplus)
extern "C" {
    void ClearScreen();
    void Sleep(int milliseconds);
}
#elif defined(__cplusplus)
void ClearScreen();
void Sleep(int milliseconds);
char getch(void);
#endif

#endif
