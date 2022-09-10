#include <iostream>
#include <string>
#include <sstream>
#include "functions5.h"

int main() {
    std::string text_lower_number = " ";
    int lower_number{0};
    std::string text_higher_number = " ";
    int higher_number{0};


    introduction();
    std::cin >> text_lower_number;
    lower_number = stringstream(text_lower_number);

    introduction2();
    std::cin >> text_higher_number;
    higher_number = stringstream(text_higher_number);

    if (higher_number < lower_number) {
        int aux_var{0};

        aux_var = lower_number;
        lower_number = higher_number;
        higher_number = aux_var;
    }

    palindrome_numbers(lower_number, higher_number);

    return 0;
}