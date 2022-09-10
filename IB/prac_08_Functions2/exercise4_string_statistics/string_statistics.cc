#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "functions_string_statistics.h"

int main() {

    std::vector<std::string> the_vector = {"abracadabra", "espialidoso", "programar", "bulldog", "estornocleidomastoideo", "calculadora", "telefono", "raton", "bucear", "napoleon"};

    Introduction();

    for(const auto actual_vector_value: the_vector) { //este for muestra todos los componentes del vector
        std::cout << actual_vector_value + "     ";
    }



    Introduction2();

    for(const auto actual_vector_value: the_vector) { // este for muestra la longitud de todas las strings del vector
        std::cout << "La palabra '" << actual_vector_value << "' tiene " << actual_vector_value.length() << " letras" << std::endl;
    }

    Spaces();

    for(const auto actual_vector_value: the_vector) { // este for muestra el primer caracter de todas las strings
        std::cout << "La primera letra de la palabra '" << actual_vector_value << "' es: '" << actual_vector_value.front() << "' " << std::endl;
    }

    Spaces();

    for(const auto actual_vector_value: the_vector) { // este for muestra el ultimo caracter de todas las strings
        std::cout << "La última letra de la palabra '" << actual_vector_value << "' es: '" << actual_vector_value.back() << "' " << std::endl;
    }

    Spaces();


    std::string abracadabra = "abracadabra";

    for(const auto actual_vector_value: the_vector) { // este for dice si la palabra contiene el texto 'abracadabra'
        std::cout << "La palabra '" << actual_vector_value;

        if (actual_vector_value.find(abracadabra) == std::string::npos) {
            std::cout << "' no contiene el texto  'abracadabra'" << std::endl;
        }
        else {
            std::cout << "' si contiene el texto 'abracadabra'" << std::endl;
        }

    }

    return 0;
}