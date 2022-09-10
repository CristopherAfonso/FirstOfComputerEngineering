#include <iostream>
#include <string>
#include <sstream>
#include "functions1.h"

int main() {
    int user_number_final{0};
    std::string text_user_number = "";


    introduction(); 
    std::cin >> text_user_number;

    user_number_final = user_number(text_user_number);

    if ((user_number_final == 0) || (user_number_final == 1)) {
        while ((user_number_final == 0) || (user_number_final == 1)) {
            wrong_number();
            std::cin >> text_user_number;
            user_number_final = user_number(text_user_number);
        }
    }

    finalmessage(user_number_final);

    if (user_number_final == 2) {
        std::cout << "ninguno, el 2 no tiene números primos menores que él" << std::endl;
    }

    loop_prime_numbers(user_number_final);

    return 0;
}