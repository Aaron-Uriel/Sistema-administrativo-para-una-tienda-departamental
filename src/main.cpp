#include <iostream>
#include "terminal.hpp"

/*extern "C" {
    void cover();
}*/

int main() {
    //cover();
    Terminal ThisTerminal;
    while (true) {
        ThisTerminal.PrintOptions();
        std::cin.ignore(32767, '\n');
    }
    return 0;
}