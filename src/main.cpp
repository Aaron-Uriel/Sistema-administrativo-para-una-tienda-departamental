#include <iostream>

extern "C" {
    void cover();
}

int main() {
    cover();
    return 0;
}