#include "terminal.hpp"
#include <iostream>

using term_t = unsigned short;

void Terminal::PrintOptions() {
    std::cout << "Seleccione una opción.\n" << std::endl <<
        "1.- Agregar un producto."  << std::endl <<
        "2.- Eliminar un producto." << std::endl <<
        "3.- Cambiar el precio de un producto." << std::endl <<
        "4.- Aplicar un descuento." << std::endl <<
        "5.- Salir.\n" << std::endl;
}