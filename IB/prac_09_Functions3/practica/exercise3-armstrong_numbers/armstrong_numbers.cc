#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>
#include "functions_armstrong_numbers.h"

int main(int argc, char* argv[]) {

    if(argc == 1) {
        Introduction();
        exit(EXIT_SUCCESS);
    }

    if( strcmp(argv[1], "--help") == 0 ) {
        Help();
        exit(EXIT_SUCCESS);
    }

    if(argc != 2) {
        Introduction();
        exit(EXIT_SUCCESS); 
    }

    std::string text_user_number = "";
    std::stringstream(argv[1]) >> text_user_number;
    int length_user_number = text_user_number.size();

    int user_number{0};
    std::stringstream(argv[1]) >> user_number;
    user_number = fabs(user_number);

    ArmstrongNumbersCheck(user_number, length_user_number);



    return 0;
}