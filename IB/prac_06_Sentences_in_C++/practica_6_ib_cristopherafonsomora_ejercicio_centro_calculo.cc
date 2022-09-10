#include <iostream>
#include <string>

int main () {

    std::string first_word;
    std::string second_word;
    std::string third_word;
    std::string four_word;
    std::string five_word;
    char first_caracter;
    char second_caracter;
    char third_caracter;
    char four_caracter;
    char five_caracter;
    
    std::cout << "Hola, soy un programa que te pedirá 5 palabras, todas las palabras que me des deben empezar por una vocal" << std::endl;
    std::cout << "Si alguna de las 5 palabras que me des no empieza por una vocal, te volveré a pedir la palabra hasta que empiece por una vocal" << std::endl << std::endl;



    std::cout << "Ahora por favor, dame la primera palabra, debe empezar por la letra 'a': ";
    std::cin >> first_caracter;
    std::cin >> first_word;
    std::cout << std::endl;

    while(first_caracter != 'a'){
        std::cout << "esa palabra no me vale, ingresa otra por favor: ";
        std::cin >> first_caracter;
        std::cin >> first_word;
    }

    first_word = "a" + first_word;      
    
    

    std::cout << "Ahora dame la segunda palabra, debe empezar por la letra 'e': ";
    std::cin >> second_caracter;
    std::cin >> second_word;
    std::cout << std::endl;

    while(second_caracter != 'e'){
        std::cout << "esa palabra no me vale, ingresa otra por favor: ";
        std::cin >> second_caracter;
        std::cin >> second_word;
    }

    second_word = "e" + second_word;




    std::cout << "Ahora dame la tercera palabra, debe empezar por la letra 'i': ";
    std::cin >> third_caracter;
    std::cin >> third_word;
    std::cout << std::endl;

    while(third_caracter != 'i'){
        std::cout << "esa palabra no me vale, ingresa otra por favor: ";
        std::cin >> third_caracter;
        std::cin >> third_word;
    }

    third_word = "i" + third_word;






    std::cout << "Ahora dame la cuarta palabra, debe empezar por la letra 'o': ";
    std::cin >> four_caracter;
    std::cin >> four_word;
    std::cout << std::endl;

    while(four_caracter != 'o'){
        std::cout << "esa palabra no me vale, ingresa otra por favor: ";
        std::cin >> four_caracter;
        std::cin >> four_word;
    }

    four_word = "o" + four_word;





    std::cout << "Ahora dame la quinta palabra, debe empezar por la letra 'u': ";
    std::cin >> five_caracter;
    std::cin >> five_word;
    std::cout << std::endl;

    while(five_caracter != 'u'){
        std::cout << "esa palabra no me vale, ingresa otra por favor: ";
        std::cin >> five_caracter;
        std::cin >> five_word;
    }

    five_word = "u" + five_word;

    std::cout << "El orden alfabético de las palbras es: " << std::endl << std::endl;

    std::cout << first_word + ", " + second_word + ", " + third_word + ", " + four_word + ", " + five_word << std::endl;

  
    return 0;
}
