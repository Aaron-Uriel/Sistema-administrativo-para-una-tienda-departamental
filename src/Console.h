#ifndef CONSOLE
#define CONSOLE

#ifdef __cplusplus
extern "C" {
#endif
    void ClearScreen();
    void Sleep_(int milliseconds);
    void gotoxy(int x,int y);

#ifdef __cplusplus
}
#endif

#endif