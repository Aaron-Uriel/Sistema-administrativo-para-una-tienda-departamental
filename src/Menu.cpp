#include "Menu.hpp"

Menu::Menu() {
    m_Selection = 1;
    m_Arrow     = 0;
}

void Menu::PrintOptions() {
    std::cout << "Seleccione una opción.\n" << std::endl <<
        "1.- Agregar producto." << PrintSelection(m_Selection) << std::endl <<
        "2.- Eliminar producto." << PrintSelection(m_Selection) << std::endl <<
        "3.- Aplicar un descuento." << PrintSelection(m_Selection) << std::endl <<
        "4.- Ver estado de los productos." << PrintSelection(m_Selection) << std::endl <<
        "5.- Editar productos." << PrintSelection(m_Selection) << std::endl <<
        "6.- Salir." << PrintSelection(m_Selection) << std::endl << std::endl;
}

void Menu::ScanKeyboard() {
    m_Arrow = getch();
    if (m_Arrow == '\n') { this->CallSelectedFunction(); }
    #ifdef __linux__
    getch();
    m_Arrow = getch();
    #endif
    UpdateSelection();
}

void Menu::CallSelectedFunction() {
    if (m_Selection == 1) {}
    else if (m_Selection == 2) {}
    else if (m_Selection == 3) {}
    else if (m_Selection == 4) {}
    else if (m_Selection == 5) {}
    else if (m_Selection == 6) {}
    else { exit(123); }
}

std::string Menu::PrintSelection(const unsigned short Selection) {
    static unsigned short TimesCalled = 1;
    if (TimesCalled > m_OptionsNumber) {
        TimesCalled = 1;
    }
    if (Selection == TimesCalled) {
        TimesCalled++;
        return " <-";
    }
    TimesCalled++;
    return "";
}

void Menu::UpdateSelection() {
    switch (m_Arrow) {
        #ifdef __linux__
        case 'A': m_Selection--; break;
        case 'B': m_Selection++; break;
        #endif
        #ifdef __WIN32
        case 72: m_Selection--; break;
        case 80: m_Selection++; break;
        #endif
    }
    if (m_Selection > m_OptionsNumber) {
        m_Selection = 1;
    }
    if (m_Selection < 1) {
        m_Selection = m_OptionsNumber;
    }
}
