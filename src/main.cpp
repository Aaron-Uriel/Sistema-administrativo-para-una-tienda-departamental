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
        Clear();
        ThisMenu.PrintOptions();
        ThisMenu.ScanKeyboard();
    }
    return 0;
}
