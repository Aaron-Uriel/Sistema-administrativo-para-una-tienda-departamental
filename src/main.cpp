#include <iostream>
#include "Menu.hpp"

/*extern "C" {
    void cover();
}*/


int main() {
    //cover();
    Menu ThisMenu;
    while (true) {
        ThisMenu.Clear();
        ThisMenu.PrintOptions();
        ThisMenu.ScanArrows();
    }
    return 0;
}
