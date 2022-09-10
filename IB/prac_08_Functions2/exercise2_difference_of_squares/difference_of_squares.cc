#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include "functions_difference_of_squares.h"


int main (int argc, char* argv[]) {

    

    if (argc == 1) {

    Introduction();
    exit(EXIT_SUCCESS);

    } 

    if (argc > 2) {

    exit(EXIT_SUCCESS);

    } 

    if (strcmp(argv[1], "--help") == 0) {

    Help();
    exit(EXIT_SUCCESS);

    }

    int user_number{0};
    int square_of_n_first_natural_numbers{0};
    int sum_of_square_of_n_first_naturals_numbers{0};
    int difference_of_numbers{0};

    std::stringstream(argv[1]) >> user_number;

    user_number = fabs(user_number);

    square_of_n_first_natural_numbers = SquareOfNFirstNaturalNumbers(user_number);

    sum_of_square_of_n_first_naturals_numbers = SumOfSquareOfNFirstNaturalsNumbers(user_number);

    difference_of_numbers = square_of_n_first_natural_numbers - sum_of_square_of_n_first_naturals_numbers;

    FinalMessage(difference_of_numbers);


    return 0;
}