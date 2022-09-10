#include <iostream>
#include <cmath>

int main() {
    double lado_cuadrado, area, perimetro;

    std::cout << "Hola, soy un programa que calcula el área y perímetro de un cuadrado" << std::endl;
    std::cout << "Introduce la longitud de uno de los lados del cuadrado que quieres que calcule:" << std::endl;
    std::cin >> lado_cuadrado;
    area = lado_cuadrado*lado_cuadrado; perimetro = lado_cuadrado*4;
    std::cout << "El perímetro del cuadrado es de " << perimetro << " metros. " << std::endl;
    std::cout << "El área del cuadrado es de " << area << " metros cuadrado. " << std::endl;
    return 0;
}