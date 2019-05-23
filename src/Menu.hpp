#ifndef MENU
#define MENU

#include <string>
#include "psconio.h"
#include <iostream>
#include <fstream>
#include <stdio.h>


class Menu {
private:
    unsigned short m_Selection;
    unsigned char  m_Arrow;
    std::string PrintSelection();
    void UpdateSelection();
    std::ifstream m_MenuFile;
    unsigned short m_Lines;
    FILE *fp;
public:
    Menu();
    void PrintOptions();
    void ScanKeyboard();
    void CallSelectedFunction();
    ~Menu();
};

#endif
