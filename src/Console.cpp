#include "Console.hpp"

Console console;

void Console::Sleep(unsigned int Milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(Milliseconds));
}

void Console::Clear() {
    #ifdef __WIN32
    std::system("cls");
    #endif
    #ifdef __linux__
    std::system("clear");
    #endif
}