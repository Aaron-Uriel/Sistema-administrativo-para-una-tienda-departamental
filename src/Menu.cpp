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
    if (getch() == '\n') { this->CallSelectedFunction(); }
    getch();
    m_Arrow = getch();
    UpdateSelection();
}

void Menu::CallSelectedFunction() {
    switch (m_Selection) {
        case 1:  ; break;
        case 2:  ; break;
        case 3:  ; break;
        case 4:  ; break;
        case 5:  ; break;
        case 6: exit(0) ; break;
        default: exit(1);
    }
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
        case 'A': m_Selection--; break;
        case 'B': m_Selection++; break;
    }
    if (m_Selection > m_OptionsNumber) {
        m_Selection = 1;
    }
    if (m_Selection < 1) {
        m_Selection = 4;
    }
}
