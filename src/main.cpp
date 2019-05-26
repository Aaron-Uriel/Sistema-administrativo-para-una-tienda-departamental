#include <iostream>
#include "Menu.hpp"
#include "Console.h"
extern "C" {
    void cover();
}


int main() {
    cover();
    MainMenu ThisMenu;
    while (true) {
        ClearScreen();
        ThisMenu.PrintOptions();
        ThisMenu.ScanKeyboard();
    }
    return 0;
}
