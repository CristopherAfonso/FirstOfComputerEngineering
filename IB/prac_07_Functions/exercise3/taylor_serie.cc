#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "functions3.h"

int main() {
    double exponent_value{0.0};
    unsigned number_of_repetitions{0};
    double final_number{0.0};
    std::string text_exponent_value = " ";
    std::string text_number_of_repetitions = " ";

    introduction ();
    std::cin >> text_exponent_value;
    exponent_value = stringstream1(text_exponent_value);

    introduction2 ();
    std::cin >> text_number_of_repetitions;
    number_of_repetitions = stringstream2(text_number_of_repetitions);

    final_number = MyExp(exponent_value, number_of_repetitions);

    final_message();
    std::cout << final_number << std::endl << std::endl;


    return 0;
}