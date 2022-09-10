#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include "functions2.h"

void introduction() {
    std::cout << "Hola, soy un programa que le pide al usuario (a tí) una cantidad concreta de palabras para leer y guardar" << std::endl;
    std::cout << "para ello, primero te pediré un número, luego te pediré que me des una cantidad de palabras iguales al número que me diste" << std::endl;
    std::cout << "(sobra decir que el número que me tienes que dar debe ser un entero sin decimales, aunque si me lo das con decimales y negativo, lo truncaré y cogeré su valor absoluto)" << std::endl;
    std::cout << "ahora por favor, dame el número de palabras que quieres que te pida: ";
}

int number_of_words (std::string& text_number){
    int number_words{0};
    std::stringstream(text_number) >> number_words;
    number_words = fabs(number_words);
    return number_words;
}

void error_message() {
    std::cout << "El número que me has dado es cero, por favor, ingresa un número que tras truncarlo y coger su valor absoluto, de distinto de cero: "; 
}

void final_message1() {
    std::cout << "Todas las palabras que me has dado son: " << std::endl << std::endl;
}

void final_message2() {
    std::cout << "y las palabras palíndromas que están dentro de todas las que me has dado son: " << std::endl << std::endl;
}

bool IsPalindrome(std::string my_string){
    int left_side = 0;
    int right_side = my_string.size() - 1;

    while (left_side < right_side){
        if (my_string[left_side] != my_string[right_side]){
            return false;
        }
        ++left_side;
        --right_side;
    }
    return true;
}