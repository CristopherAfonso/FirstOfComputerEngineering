#include <iostream>

int main() {
    int edad, anyo_actual, jubilacion;

    std::cout << "Hola, soy un programa que calcula la edad en que te vas a jubilar" << std::endl;
    std::cout << "Por favor, dime cuantos años tienes:" << std::endl;
    std::cin >> edad;
    std::cout << "Ahora introduce en el que nos encontramos a día de hoy:" << std::endl;
    std::cin >> anyo_actual;
    jubilacion = anyo_actual - edad + 65;
    std::cout << "Te jubilarás en el año " << jubilacion << std::endl;
    return 0;    
}