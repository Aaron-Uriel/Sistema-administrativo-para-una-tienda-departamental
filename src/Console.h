#ifndef CONSOLE
#define CONSOLE

#if defined(__cplusplus)
extern "C" {
    void Clear();
    void Sleep(int milliseconds);
}
#elif defined(__cplusplus)
void Clear();
void Sleep(int milliseconds);
#endif

#endif
