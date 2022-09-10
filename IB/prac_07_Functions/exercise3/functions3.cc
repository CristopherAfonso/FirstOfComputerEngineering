#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

void introduction () {
    std::cout << "Hola, soy un programa que calcula la función exponencial:  f(x) = e^x" << std::endl;
    std::cout << "para poder calcularte esa función, necesito que me des dos números" << std::endl;
    std::cout << "el 1º debe ser el valor que le quieres dar al exponente (la variable 'x' que será un valor que aceptará decimales)" << std::endl;
    std::cout << "el 2º debe ser el número de términos del desarrollo de Taylor (es decir, cuantas veces tendré que desarrollar la serie Taylor para darte un dato más exacto)" << std::endl;
    std::cout << "ahora bien, ¿Cúal va a ser el valor que le quieres dar a la variable 'x' (al exponente)?: ";
}

void introduction2 () {
    std::cout << "ahora bien, ¿Cúal es el valor que le quieres dar al 2º número que me tienes que dar (es el número de veces que repetíre la serie Taylor)?: ";
}

double stringstream1(std::string my_string1) {
    double my_double{0.0};
    std::stringstream(my_string1) >> my_double;
    return my_double;
}

unsigned stringstream2(std::string my_string2) {
    unsigned my_unsigned{0};
    std::stringstream(my_string2) >> my_unsigned;
    return my_unsigned;
}

int factorial(int my_factorial){

    int final_factorial{1};

    for(int i = 1; i <= my_factorial; ++i) {
        final_factorial *= i;
    }
    return final_factorial;
}

double MyExp(double exponent, unsigned num_terms) {

    double final_number{1.0};
    double actual_sum{0.0};

    for(double i = 1; i <= num_terms; ++i){

        actual_sum = pow(exponent, i)*(1.00/factorial(i));

        final_number += actual_sum;
        actual_sum = 0.0;
    }
    return final_number;
}

void final_message () {
    std::cout << "El valor final de: f(x) = e^x " << std::endl;
    std::cout << "Es este: ";
}