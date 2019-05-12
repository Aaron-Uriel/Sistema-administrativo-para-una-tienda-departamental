#include <iostream>
#include "Menu.hpp"
#include "Console.hpp"

/*extern "C" {
    void cover();
}*/


int main() {
    //cover();
    Menu ThisMenu;
    while (true) {
        console.Clear();
        ThisMenu.PrintOptions();
        ThisMenu.ScanKeyboard();
    }
    return 0;
}
