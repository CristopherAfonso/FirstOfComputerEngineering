#include <iostream>
#include <sstream>
#include <string>

int main() {
    const double kCostePorMetro = 1624;
    std::string longitud_metros;
    double precio, distancia;

    std::cout << "Hola, soy un programa que puede calcular el coste de creación"
              << " de una carretera en función a su longitud en metros." << std::endl;
    std::cout << "Dime que longitud tendrá la carretera por favor: ";
    std::cin >> longitud_metros;
    std::stringstream(longitud_metros) >> distancia;
    precio = distancia*kCostePorMetro;
    std::cout << "Su carretera tendrá un coste de " << precio << " Euros." << std::endl;
    return 0;
}
