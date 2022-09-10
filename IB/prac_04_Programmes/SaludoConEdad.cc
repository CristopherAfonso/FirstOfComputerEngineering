#include <iostream>
#include <string>

int main () {
    std::string name;
    int edad;

    std::cout << "Hola, ¿Cómo te llamas?" << std::endl;
    std::cin >> name;
    std::cout << "Es un bonito nombre, ahora dime cuantos años tienes" << std::endl;
    std::cin >> edad;
    std::cout << "Hola, eres " << name << " y tienes " << edad << " años." << std::endl;
    return 0;
}