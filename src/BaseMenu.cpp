#include "BaseMenu.hpp"

Menu::Menu(std::string Filename = "Menu.txt"):
    m_FilePtr(Filename), m_Lines(1), m_SelectedLine(1) {
    if (m_FilePtr.is_open()) {
        //Contamos los renglones
        char Char;
        while (m_FilePtr.get(Char)) {
            if (Char == '\n') {
                m_Lines++;
            }
        }
        m_FilePtr.clear();
        m_FilePtr.seekg(0);
    } else {
        std::cerr << "Ocurrió un error.\n";
        exit(EXIT_FAILURE);
    }
}

void Menu::PrintOptions() {
    std::string StreamBuffer;
    while (std::getline(m_FilePtr, StreamBuffer)) {
        PrintUnderlineText(StreamBuffer);
    }
    m_FilePtr.clear();
    m_FilePtr.seekg(0);
}

std::string Menu::PrintUnderlineText(std::string Str) {
    static unsigned int TimesCalled = 1;
    if (TimesCalled > m_Lines) {
        TimesCalled = 1;
    }
    if (TimesCalled == m_SelectedLine) {
        std::cout << rang::style::underline << Str << rang::style::reset;
    }
}

void Menu::UpdateSelection() {
    switch (m_Arrow) {
        #ifdef __linux__
        case 'A': m_SelectedLine--; break;
        case 'B': m_SelectedLine++; break;
        #endif
        #ifdef __WIN32
        case 72: m_Selection--; break;
        case 80: m_Selection++; break;
        #endif
    }
    if (m_SelectedLine > m_Lines) {
        m_SelectedLine = 1;
    }
    if (m_SelectedLine < 1) {
        m_SelectedLine = m_Lines;
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