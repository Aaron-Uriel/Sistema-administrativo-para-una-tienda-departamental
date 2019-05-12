#ifndef CONSOLE
#define CONSOLE

#include <chrono>
#include <thread>

class Console {
    public:
    void Sleep(unsigned int Milliseconds);
    void Clear();
};

extern Console console;

#endif