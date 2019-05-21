#include "Menu.hpp"

Menu::Menu(): m_MenuFile("Menu.txt"), m_Lines(1) {
    if (m_MenuFile.is_open()) {
        while (!m_MenuFile.eof()) {
            if (m_MenuFile.get() == '\n') {
                ++m_Lines;
            }
        }
        m_MenuFile.seekg(0);
    }
    m_Selection = 1;
    m_Arrow     = 0;
    fp = fopen("Product Struct.txt", "r");
}

void Menu::PrintOptions() {
    std::cout << "Seleccione una opción.\n" << std::endl;
    if (m_MenuFile.is_open()) {
        std::string StringFromFile;
        while (std::getline (m_MenuFile, StringFromFile)) {
            std::cout << StringFromFile << PrintSelection() << std::endl;
        }
        m_MenuFile.clear();
        m_MenuFile.seekg(0, std::ios::beg);
    } else {
        std::cout << "No se pudo abrir el archivo \"Menu.txt\"\nCerrando\n"; exit(1);
    }
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
    else if (m_Selection == 6) { exit(1); }
    else { exit(123); }
}

std::string Menu::PrintSelection() {
    static unsigned short TimesCalled = 1;
    if (TimesCalled > m_Lines) {
        TimesCalled = 1;
    }
    if (m_Selection == TimesCalled) {
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
    if (m_Selection > m_Lines) {
        m_Selection = 1;
    }
    if (m_Selection < 1) {
        m_Selection = m_Lines;
    }
}

Menu::~Menu() {
    m_MenuFile.close();
}
