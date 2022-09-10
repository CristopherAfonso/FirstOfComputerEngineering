#include <iostream>

int main () {
    std::cout << "Soy un programa que te muestra la cantidad de "
    << "memoria que utiliza el compilador para almacenar cada uno "
    << "de los tipos básicos del lenguaje" << std::endl;
    std::cout << "Todos esos datos te los mostraré ahora: " << std::endl << std::endl;

    std::cout << "El tipo de datos 'bool' se representa utilizando " << sizeof(bool) << " bytes" << std::endl;
    std::cout << "El tipo de datos 'char' se representa utilizando " << sizeof(char) << " bytes" << std::endl;
    std::cout << "El tipo de datos 'short' se representa utilizando " << sizeof(short) << " bytes" << std::endl;
    std::cout << "El tipo de datos 'int' se representa utilizando " << sizeof(int) << " bytes" << std::endl;
    std::cout << "El tipo de datos 'float' se representa utilizando " << sizeof(float) << " bytes" << std::endl;
    std::cout << "El tipo de datos 'long' se representa utilizando " << sizeof(long) << " bytes" << std::endl;
    std::cout << "El tipo de datos 'double' se representa utilizando " << sizeof(double) << " bytes" << std::endl;
    std::cout << "El tipo de datos 'string' se representa utilizando " << sizeof(std::string) << " bytes" << std::endl;   
    return 0;
}