#include <iostream>
#include <string>
#include <sstream>
#include "functions4.h"

int main() {
    std::string text_number_of_month = " ";
    int number_of_month{0};


    introduction();
    std::cin >> text_number_of_month;
    std::cout << std::endl;

    number_of_month = stringstream(text_number_of_month);

    if ((number_of_month < 1) || (number_of_month > 12)) {
        error_menssage();
    }
    else {
        if (number_of_month == 2) {
            correct_month2(number_of_month);
        }
        else {
            correct_month(number_of_month);
        }
    }
    return 0;
}