#ifndef MENU
#define MENU

#include <string>

std::string PrintSelection(const unsigned short Selection);
void UpdateSelection(unsigned short &Selection, unsigned char &Arrow);

class Menu {
private:
    unsigned short m_Selection;
    unsigned char  m_Arrow;
public:
    Menu();
    void PrintOptions();
    void Clear();
    void ScanArrows();
};

#endif