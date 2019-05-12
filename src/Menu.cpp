#include "Menu.hpp"
#include <iostream>
#include <cstdlib>
#include "psconio.hpp"
#include <cassert>

constexpr unsigned short g_OptionsNumber = 4;


Menu::Menu() {
    m_Selection = 1;
    m_Arrow     = 0;
}

void Menu::PrintOptions() {
    std::cout << "Seleccione una opción.\n" << std::endl <<
        "1.- Agregar producto." << PrintSelection(m_Selection) << std::endl <<
        "2.- Eliminar producto." << PrintSelection(m_Selection) << std::endl <<
        "3.- Aplicar un descuento." << PrintSelection(m_Selection) << std::endl <<
        "4.- Salir." << PrintSelection(m_Selection) << std::endl << std::endl;
}

void Menu::ScanKeyboard() {
    if (getch() == '\n') { std::cout << "Espacio en desarrollo" << std::endl;}
    getch();
    m_Arrow = getch();
    UpdateSelection(m_Selection, m_Arrow);
}

std::string PrintSelection(const unsigned short Selection) {
    static unsigned short TimesCalled = 1;
    if (TimesCalled > g_OptionsNumber) {
        TimesCalled = 1;
    }
    if (Selection == TimesCalled) {
        TimesCalled++;
        return " <-";
    }
    TimesCalled++;
    return "";
}

void UpdateSelection(unsigned short &Selection, unsigned char &Arrow) {
    switch (Arrow) {
        case 'A': Selection--; break;
        case 'B': Selection++; break;
    }
    if (Selection > g_OptionsNumber) {
        Selection = 1;
    }
    if (Selection < 1) {
        Selection = 4;
    }
}
