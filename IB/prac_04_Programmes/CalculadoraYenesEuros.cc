#include <iostream>
#include <sstream>
#include <string>

int main () {
    const double kYenesAEuros{0.0081}; // dato oficial a 16 de Octubre de 2020
    double EurosConvertidos, EurosSinConvertir;
    std::string EurosUsuario;
  
    std::cout << "Hola, soy un programa que es capaz de calcular cuantos " 
              << "yenes posees depediendo de todos los euros que tengas ahora mismo" << std::endl;
    std:: cout << "Dime cuantos euros tienes y te diré cuantos a cuantos yenes podrías cambiarlos: ";
    std::cin >> EurosUsuario;
    std::stringstream(EurosUsuario) >> EurosSinConvertir;
    EurosConvertidos = EurosSinConvertir/0.0081;
    std::cout << std::endl << "Ahora mismo posees " << EurosConvertidos << " Yenes." << std::endl;
    std::cout << "Este dato es válido a 16 de Octubre de 2020" << std::endl;
    std::cout << "Ya que debido al constante cambio de precios en el mercado, "
              << "este valor no siempre será igual en el futuro para la misma cantidad de euros que quieras pasar a Yenes." << std::endl;
    return 0;
}