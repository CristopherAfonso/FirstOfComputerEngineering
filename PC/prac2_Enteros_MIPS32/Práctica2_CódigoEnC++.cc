#include <iostream>

int main()
{
    std::cout << "Calcula el bit de paridad par de un enteros de 32 bits." << std::endl;
    std::cout << "Introduzca un 0 para salir del programa." << std::endl;

    unsigned int numero;
    do {
        std::cout << "Introduzca un entero positivo para calcular su paridad par: ";
        std::cin >> numero;
        if (numero == 0) break;
        int unos = 0; // numero de unos que tiene numero
        for (int i = 0; i < 32 ; i++) {
            int lsb = (numero & 1); // lsb contendrá un 1
            unos += lsb;
            numero = numero >> 1;
        }

        std::cout << "El número de unos del numero introducido es " << unos << std::endl;

        int paridad_par = ((unos % 2) != 0);
        std::cout << "El bit de paridad par sera " << paridad_par << std::endl;
    } while (true);
    std::cout << "FIN DEL PROGRAMA. " << std::endl;
    return 0;
}