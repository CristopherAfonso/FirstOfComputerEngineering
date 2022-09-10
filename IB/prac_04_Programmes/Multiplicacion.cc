#include <iostream>

int main () {
    int numero1, numero2;

    std::cout << "Soy un programa que calcula la multiplicación de dos números que tú me des." << std::endl;
    std::cout << "Introduce el primer número: ";
    std::cin >> numero1;
    std::cout << "Ahora introduce el segundo número: ";
    std::cin >> numero2;
    std::cout << "El resultado es: " << numero1*numero2 << std::endl;
    return 0;
}