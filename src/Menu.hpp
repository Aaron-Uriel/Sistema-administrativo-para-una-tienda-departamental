#ifndef MENU
#define MENU

#include <string>
#include "psconio.h"
#include <iostream>
#include <fstream>

#ifdef DEBUG
#include <cassert>
#endif

class Menu {
private:
    unsigned short m_Selection;
    unsigned char  m_Arrow;
    const unsigned short m_OptionsNumber = 6;
    std::string PrintSelection();
    void UpdateSelection();
    std::ifstream m_MenuFile;
    unsigned short m_Lines;
public:
    Menu();
    void PrintOptions();
    void ScanKeyboard();
    void CallSelectedFunction();
    ~Menu();
};

#endif