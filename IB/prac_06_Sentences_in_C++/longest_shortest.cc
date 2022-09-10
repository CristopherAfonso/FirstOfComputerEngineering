#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

int main () {
    int first_number_to_introduce;
    std::string first_number_to_introduce_in_text;
    std::string longest_word;
    std::string shortest_word;
    std::string current_word_entered;
    std::vector<std::string> all_users_words;

    std::cout << "Hola, soy un programa que tiene una misión muy clara con el usuario que me ejecute (en este caso, ese eres tú ahora mismo)" << std::endl;
    std::cout << "Te pediré un número entero, que lo llamaremos 'cantidad de palabras' (pero si me das un número decimal, negativo, ó decimal y negativo, lo truncaré y me quedaré solo con su parte entera y su valor absoluto)" << std::endl;
    std::cout << "Tras darme el número entero, te pediré que me des una cantidad de palabras iguales al número entero que me diste al inicio" << std::endl;
    std::cout << "En cada palabra que me des puedes poner cualquier palabra que quieras, pero debe ser una palabra, no una frase" << std::endl;
    std::cout << "Finalmente, cuando hayas introducido todas las palabras, te diré cual es la palabra más larga y cual es la más corta" << std::endl << std::endl;
    
    std::cout << "Ahora bien, que valor le quieres dar a 'Cantidad de palabras': ";
    getline(std::cin, first_number_to_introduce_in_text);
    std::stringstream(first_number_to_introduce_in_text) >> first_number_to_introduce;
    first_number_to_introduce = fabs(first_number_to_introduce);
    std::cout << std::endl;

    while (first_number_to_introduce == 0){
        std::cout << "El cero es el único número que puedes introducir y no me vale, por favor dame un número distinto de cero: " << std::endl;
        getline(std::cin, first_number_to_introduce_in_text);
        std::stringstream(first_number_to_introduce_in_text) >> first_number_to_introduce;
        first_number_to_introduce = fabs(first_number_to_introduce);
        std::cout << std::endl;
    }

    all_users_words.reserve(first_number_to_introduce);

    for(int i = 0; i < first_number_to_introduce; i++) {

        std::cout << "Introduce la " << i + 1 << "ª palabra: ";
        std::cin >> current_word_entered;
        all_users_words.emplace_back(current_word_entered);
        std::cout << std::endl;
        
        if (i == 0) {
            longest_word = shortest_word;
            shortest_word = current_word_entered;
        }

        if (current_word_entered.length() < shortest_word.length()) {
            shortest_word = current_word_entered;
        }

        if (current_word_entered.length() > longest_word.length()) {
            longest_word = current_word_entered;
        }
    }
    
    std::cout << "Todas las palabras que me has dado son: " << std::endl;

    for(std::string each_word: all_users_words) {
        std::cout << each_word << ' ';
    }

    std::cout << std::endl << std::endl;
    
    std::cout << "La palabra más larga de todas esas es: " << longest_word << std::endl;
    std::cout << "La palabra más corta de todas esas es: " << shortest_word << std::endl << std::endl; 

    std::cout << "Ten en cuenta que si me has dado 2 ó más palabras con la misma longitud y son las más largas o las más cortas" << std::endl;
    std::cout << "La palabra que te habré devuelto como 'más larga' ó 'más corta', será la primera que hay visto (o sea, la primera que me diste)" << std::endl << std::endl;

    return 0;
}
