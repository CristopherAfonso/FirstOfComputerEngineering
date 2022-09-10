#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include "functions_prime.h"

void Introduction() {

    std::cerr << "Hola, soy un programa que acepta solo un número entero por línea de comandos, y devuelve el número primo asociado a ese número" << std::endl;
    std::cerr << "Por ejemplo, si me das el número 5, te devolveré el número 11, puesto que el 11 es el 5º número primo" << std::endl;
    std::cerr << "Tengo que avisarte de que si me das un número negativo o con decimales, lo truncaré y usaré su valor absoluto" << std::endl;
    std::cerr << "Por último, si me das más de un número entero, ignoraré los todos los números salvo el primero que me des, te lo digo para que no escribas sin necesidad :)" << std::endl;
    std::cerr << "Si quieres verme funcionar y que te calcule el número primo que me solicites, vuelve a llamarme en la línea de comandos" << std::endl;
    std::cerr << "Pero al lado del nombre de mi programa y separado por un espacio, pon el número la que quieres que le calcule el número primo que se le asociaría :D" << std::endl;
    
}


void FinalMessage(int& user_number, int& my_prime_number) {

    std::cout << std::endl;
    std::cout << "El " << user_number << "º número primo es el " << my_prime_number << std::endl << std::endl;

}

void TheExactPrimeNumber(int& number_limit) {

    std::vector<int> all_n_first_prime_numbers;
    int number_accumulator{1};

    while(all_n_first_prime_numbers.size() != number_limit) {

        int limit_loop = number_accumulator/2 + 1;

        if(number_accumulator == 2) {

            all_n_first_prime_numbers.emplace_back(number_accumulator);
            ++number_accumulator;
            continue;
        }

        for(int i = 2; i <= limit_loop + 1; ++i) {
            if(number_accumulator % i == 0) {
                break;
            }

            if(number_accumulator/2 + 1 == i) {
                all_n_first_prime_numbers.emplace_back(number_accumulator);
            }
        }

        ++number_accumulator;


    }
    

    FinalMessage(number_limit, all_n_first_prime_numbers.back());

}
