#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

void introduction() {
    std::cout << "Hola, soy un programa que calcula números palíndromos dentro de un intervalo que el usuario (tú en este caso) me das" << std::endl;
    std::cout << "mi trabajo es simple, yo te pediré dos números enteros positivos, que llamaré 'factores' (si son negativos trabajaré con su valor absoluto)" << std::endl;
    std::cout << "esos dos números denotarán los límites superior y inferior de un intervalo" << std::endl;
    std::cout << "y lo que yo haré con esos dos números será encontrar el número palíndromo más grande y más pequeño que sea sean productos de números dentro de ese rango" << std::endl;
    std::cout << "cuando halle los números palíndromos más grande y más pequeño que hay en ese intervalo, te devolveré sus factores por pantalla " << std::endl;
    std::cout << "(es decir, los dos números que he multiplicado que me han dado como resultado ese número palíndromo concreto)" << std::endl;
    std::cout << "ahora por favor, dame el primer número del intervalo: ";
}

void introduction2() {
    std::cout << "ahora por favor, introduce el segundo número del intervalo: ";
}

void final_message(int& palindrome, std::string& factors) {
    std::cout << "El palíndromo más grande es: " << palindrome << std::endl;
    std::cout << "y sus factores son: " << factors << std::endl;
}

void final_message2(int& palindrome2, std::string& factors2) {
    std::cout << "El palíndromo más pequeño es: " << palindrome2 << std::endl;
    std::cout << "y sus factores son: " << factors2 << std::endl;
}

int stringstream(std::string& my_string) {
    int final_number{0};

    std::stringstream(my_string) >> final_number;
    final_number = fabs(final_number);

    return final_number;
}

bool stringstream2(int& my_interger) {
    bool is_palindrome{true};
    std::string final_text = "";
    
    final_text = std::to_string(my_interger);

    int left_side{0};
    int right_side = final_text.size() - 1;

    while (left_side < right_side) {

        if ((final_text[left_side]) != (final_text[right_side])) {
            is_palindrome = false;
        }
        left_side += 1;
        right_side -= 1;
    }


    return true;
}

void palindrome_numbers(int& minimum_number, int& maximum_number) {

    std::string text_maximum_palindrome = "";
    std::string text_minimum_palindrome = "";
    std::string text_maximum_factors_palindrome = "";
    std::string text_minimum_factors_palindrome = "";
    int maximum_palindrome{0};
    int minimum_palindrome{0};

    for(int i = minimum_number; i <= maximum_number; ++i) {

        int possible_palindrome{0};

        for(int e = minimum_number; e <= maximum_number; ++e){

            bool is_palindrome{false};
            

            possible_palindrome = e * i;
            is_palindrome = stringstream2(possible_palindrome);

            if ((is_palindrome == true) && (text_maximum_palindrome == "") && (text_minimum_palindrome == "")) {

                text_maximum_palindrome = std::to_string(possible_palindrome);
                text_minimum_palindrome = std::to_string(possible_palindrome);
                text_maximum_factors_palindrome = "(" + std::to_string(i) + ", " + std::to_string(e) + ") ";
                text_minimum_factors_palindrome = "(" + std::to_string(i) + ", " + std::to_string(e) + ") ";
                maximum_palindrome = possible_palindrome;
                minimum_palindrome = possible_palindrome;
            }

            if ((is_palindrome == true) && (possible_palindrome == maximum_palindrome)) {
                
                text_maximum_factors_palindrome += "(" + std::to_string(i) + ", " + std::to_string(e) + ") ";

            }

            if ((is_palindrome == true) && (possible_palindrome > maximum_palindrome))  {

                maximum_palindrome = possible_palindrome;
                text_maximum_factors_palindrome = "(" + std::to_string(i) + ", " + std::to_string(e) + ") ";

            }



            if ((is_palindrome == true) && (possible_palindrome == minimum_palindrome)) {
                
                text_minimum_factors_palindrome += "(" + std::to_string(i) + ", " + std::to_string(e) + ") ";

            }

            if ((is_palindrome == true) && (possible_palindrome < minimum_palindrome))  {

                minimum_palindrome = possible_palindrome;
                text_minimum_factors_palindrome = "(" + std::to_string(i) + ", " + std::to_string(e) + ") ";

            }


        }
    }

    std::cout << std::endl << "Ya he calculado los palíndromos maś grandes y más pequeños" << std::endl << std::endl;
    
    std::cout << "El palíndromo más grande es el " << maximum_palindrome << ", y sus factores son: " + text_maximum_factors_palindrome << std::endl << std::endl;

    std::cout << "El palíndromo más pequeño es el " << minimum_palindrome << ", y sus factores son: " + text_minimum_factors_palindrome << std::endl << std::endl;

}