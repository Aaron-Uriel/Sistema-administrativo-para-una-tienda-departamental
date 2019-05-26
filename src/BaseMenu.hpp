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
    std::string PrintUnderlineText(std::string Str);
    void UpdateSelection();
    std::ifstream m_FilePtr;
    unsigned int m_Lines;
    unsigned short m_SelectedLine;
public:
    BaseMenu(std::string FileName);
    void PrintOptions();
    void ScanKeyboard();
    virtual void CallSelectedFunction() = 0;
    ~BaseMenu();
};

#endif