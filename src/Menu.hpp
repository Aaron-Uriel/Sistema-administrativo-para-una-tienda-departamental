#ifndef MENU
#define MENU

#include <string>
#include "psconio.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "BaseMenu.hpp"


class MainMenu: public BaseMenu {
private:
    unsigned short m_SelectedLine;
public:
    void CallSelectedFunction();
};

#endif
