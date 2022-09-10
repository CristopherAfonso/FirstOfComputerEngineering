#include <iostream>

int main () {
    bool variable_1;
    bool variable_2;

    std::cout << "Soy un programa que muestra por pantalla las tablas de la verdad de los 3 operadores lógicos: AND; OR; NOT " << std::endl;
    std::cout << "Si tenemos dos variables booleanas cualesquiera, que las llamaremos 'variable 1' y 'variable 2' " << std::endl;
    std::cout << "y tenemos en cuenta todos los valores posibles que pueden tener las variables a la vez" << std::endl;
    std::cout << "(que en unas variables booleanas, cada variable solo puede tomar a la vez uno de estos dos valores, 0 ó 1)" << std::endl;
    std::cout << "tendríamos 4 valores posibles formados entre las dos variables y son: 00; 01; 10; 11." << std::endl;
    std::cout << "A continuación mostraremos las 3 tablas de la verdad con sus resultados." << std::endl << std::endl;

    variable_1 = false; variable_2 = false;

    std::cout << "         Tabla del operador AND" << std::endl;
    std::cout << " _____________________________________" << std::endl;
    std::cout << "| Variable 1 | Variable 2 | Resultado |" << std::endl;
    std::cout << "|     " << variable_1 << "      |     " << variable_2 << "      |   " << "  " << (variable_1 && variable_2) << "     |" << std::endl;
    variable_1 = false; variable_2 = true;
    std::cout << "|     " << variable_1 << "      |     " << variable_2 << "      |   " << "  " << (variable_1 && variable_2) << "     |" << std::endl;
    variable_1 = true; variable_2 = false;
    std::cout << "|     " << variable_1 << "      |     " << variable_2 << "      |   " << "  " << (variable_1 && variable_2) << "     |" << std::endl;
    variable_1 = true; variable_2 = true;
    std::cout << "|     " << variable_1 << "      |     " << variable_2 << "      |   " << "  " << (variable_1 && variable_2) << "     |" << std::endl << std::endl << std::endl;
    
    variable_1 = false; variable_2 = false;

    std::cout << "         Tabla del operador OR" << std::endl;
    std::cout << " _____________________________________" << std::endl;
    std::cout << "| Variable 1 | Variable 2 | Resultado |" << std::endl;
    std::cout << "|     " << variable_1 << "      |     " << variable_2 << "      |   " << "  " << (variable_1 || variable_2) << "     |" << std::endl;
    variable_1 = false; variable_2 = true;
    std::cout << "|     " << variable_1 << "      |     " << variable_2 << "      |   " << "  " << (variable_1 || variable_2) << "     |" << std::endl;
    variable_1 = true; variable_2 = false;
    std::cout << "|     " << variable_1 << "      |     " << variable_2 << "      |   " << "  " << (variable_1 || variable_2) << "     |" << std::endl;
    variable_1 = true; variable_2 = true;
    std::cout << "|     " << variable_1 << "      |     " << variable_2 << "      |   " << "  " << (variable_1 || variable_2) << "     |" << std::endl << std::endl << std::endl;

    variable_1 = false; variable_2 = false;

    std::cout << "         Tabla del operador NOT" << std::endl;
    std::cout << " _____________________________________________________" << std::endl;
    std::cout << "| Variable 1 | Resultado 1 | Variable 2 | Resultado 2 |" << std::endl;
    std::cout << "|     " << variable_1 << "      |     " << (!variable_1) << "       |   " << "  " << variable_2 << "      |     " << (!variable_2) << "       |"<< std::endl;
    variable_1 = false; variable_2 = true;
    std::cout << "|     " << variable_1 << "      |     " << (!variable_1) << "       |   " << "  " << variable_2 << "      |     " << (!variable_2) << "       |"<< std::endl;
    variable_1 = true; variable_2 = false;
    std::cout << "|     " << variable_1 << "      |     " << (!variable_1) << "       |   " << "  " << variable_2 << "      |     " << (!variable_2) << "       |"<< std::endl;
    variable_1 = true; variable_2 = true;
    std::cout << "|     " << variable_1 << "      |     " << (!variable_1) << "       |   " << "  " << variable_2 << "      |     " << (!variable_2) << "       |"<< std::endl << std::endl;
    

    return 0;
}