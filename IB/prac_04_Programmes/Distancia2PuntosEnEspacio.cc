#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

int main() {
    double x1, x2, y1, y2, z1, z2, distancia; // cada variable es una coordenada de uno de los dos puntos
    std::string Sx1, Sx2, Sy1, Sy2, Sz1, Sz2;

    std::cout << "Hola, soy un programa que puede calcular la distancia entre "
              << "dos puntos separados en el espacio tridimensional." << std::endl;
    std::cout << "Para demostrartelo, te voy a pedir que me indiques las coordenadas "
              << "'x','y','z', de dos puntos cualesquiera en el espacio (intrepretaré que me las darás en metros)." << std::endl << std::endl;

    std::cout << "Introduce a continuación, las coordenadas del 1º punto, que llamaremos 'A': " << std::endl;
    std::cout << "Coordenada x de A: ";
    getline(std::cin, Sx1);
    std::stringstream(Sx1) >> x1;
    std::cout << "Coordenada y de A: ";
    getline(std::cin, Sy1);
    std::stringstream(Sy1) >> y1;
    std::cout << "Coordenada z de A: ";
    getline(std::cin, Sz1);
    std::stringstream(Sz1) >> z1;

    std::cout << "Introduce a continuación, las coordenadas del 2º punto, que llamaremos 'B': " << std::endl;
    std::cout << "Coordenada x de B: ";
    getline(std::cin, Sx2);
    std::stringstream(Sx2) >> x2;
    std::cout << "Coordenada y de B: ";
    getline(std::cin, Sy2);
    std::stringstream(Sy2) >> y2;
    std::cout << "Coordenada z de B: ";
    getline(std::cin, Sz2);
    std::stringstream(Sz2) >> z2;

    distancia = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));

    std::cout << " " << std::endl;
    std::cout << "La distancia entre el punto A=(" << x1 << ", " << y1 << ", " << z1 << ") ";
    std::cout << "y el punto B=(" << x2 << ", " << y2 << ", " << z2 << ") es: " << distancia << " metros" << std::endl;
    return 0;
}