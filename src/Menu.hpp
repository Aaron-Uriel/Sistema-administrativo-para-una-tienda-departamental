#ifndef MENU
#define MENU

#include <string>
#include "psconio.hpp"
#include <iostream>

#ifdef DEBUG
#include <cassert>
#endif

std::string PrintSelection(const unsigned short Selection);
void UpdateSelection(unsigned short &Selection, unsigned char &Arrow);

class Menu {
private:
    unsigned short m_Selection;
    unsigned char  m_Arrow;
public:
    Menu();
    void PrintOptions();
    void ScanKeyboard();
    void CallSelectedFunction();
};

#endif