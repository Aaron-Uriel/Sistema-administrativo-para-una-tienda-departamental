#ifndef MENU
#define MENU

#include <string>
#ifdef __linux__
#include "psconio.h"
#endif
#ifdef __WIN32
#include <conio.h>
#endif
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Console.h"

class Menu {
private:
    unsigned short m_Selection;
    unsigned char  m_Arrow;
    std::string PrintSelection();
    void UpdateSelection();
    std::ifstream m_MenuFile;
    unsigned short m_Lines;
public:
    Menu(std::string MenuName = "Menu.txt");
    void PrintOptions();
    void ScanKeyboard();
    void CallSelectedFunction();
    ~Menu();
};

#endif
