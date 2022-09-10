#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "functions1.h"

void introduction() {
    std::cout << "Hola, soy un programa cuya misión es pedirle un número entero al usuario (en este caso tú)" << std::endl;
    std::cout << "y calcular todos los números primos que van desde el 1 (sin contar a este) hasta el número que me has dado (sin incluirlo en el intervalo a este último)" << std::endl;
    std::cout << "cuando los calcule, te los mostraré todos por pantalla" << std::endl;
    std::cout << "te tengo que pedir que los únicos números que no me puedes dar son el cero y el uno ó el uno negativo, ya con ellos no se puede aplicar la definición de un número entero" << std::endl;
    std::cout << "(como solo soy un programa que calcula números primos, si me das un número entero pero negativo, trabajaré con su valor absoluto)" << std::endl;
    std::cout << "ahora por favor, dame el número entero para poder hacer mis calculos: ";
}

void wrong_number() {
    std::cout << "Te dije que me dieras un número entero distinto de cero, uno ó uno negativo, por favor, ingresa un número válido: ";
}

int user_number(std::string& numbers_user) {
    int user_number{0};

    std::stringstream(numbers_user) >> user_number;
    user_number = fabs(user_number);

    return user_number;
}

void finalmessage(int& final_number_user) {
    std::cout << "Todos los números primos menores que " << final_number_user << " son: " << std::endl;
}

void loop_prime_numbers(int& limit_number) {

    for(int i = 3; i < limit_number; ++i){

        if (i == 3){
            std::cout << "2";
        }

        bool IsPrime(false);

        bool IsNotPrime(false);

        int divisor_number{2};


        while ((divisor_number < i) && (IsPrime == false) && (IsNotPrime == false)) {

            int possible_prime_number = i % divisor_number;

            if (possible_prime_number == 0){
                IsNotPrime = true;
            }

            if ((divisor_number == (i-1)) && (IsPrime == false) && (IsNotPrime == false)) {
                IsPrime = true;
            }

            divisor_number += 1;

        }




        if (IsPrime == true){
            std::cout <<", " << i;
        }      
    }
    std::cout << std::endl;
}
