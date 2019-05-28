#include <iostream>
#include "Menu.hpp"
#include "Console.h"

extern "C" {
    void cover();
}


int main() {
    cover();
    Menu ThisMenu;
    while (true) {
        ClearScreen();
        ThisMenu.PrintOptions();
        ThisMenu.ScanKeyboard();
    }
    return 0;
}
