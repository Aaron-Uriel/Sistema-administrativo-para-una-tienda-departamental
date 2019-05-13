#ifndef MENU
#define MENU

#include <string>
#include "psconio.h"
#include <iostream>

#ifdef DEBUG
#include <cassert>
#endif

class Menu {
private:
    unsigned short m_Selection;
    unsigned char  m_Arrow;
    const unsigned short m_OptionsNumber = 6;
    std::string PrintSelection(const unsigned short Selection);
    void UpdateSelection();
public:
    Menu();
    void PrintOptions();
    void ScanKeyboard();
    void CallSelectedFunction();
};

#endif