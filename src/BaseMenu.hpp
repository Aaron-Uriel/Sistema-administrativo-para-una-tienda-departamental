#ifndef BASEMENU
#define BASEMENU

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "rang.hpp"
#include "psconio.h"

class BaseMenu {
private:
    char m_Arrow;
    void PrintUnderlineText(std::string Str);
    void UpdateSelection();
    std::ifstream m_FilePtr;
    unsigned int m_Lines;
    unsigned short m_SelectedLine;
public:
    BaseMenu(std::string FileName = "Menu.txt");
    void PrintOptions();
    void ScanKeyboard();
    virtual void CallSelectedFunction();
};

#endif