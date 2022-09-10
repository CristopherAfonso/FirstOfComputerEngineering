#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include "functions_mersenne.h"

int main(int argc, char* argv[]) {

    if(argc == 1){
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

    int user_number{0};

    std::stringstream(argv[1]) >> user_number;
    user_number = fabs(user_number);

    if(user_number == 0) {
        AutoExit(user_number);
    }

    AllMersenneNumbers(user_number);

    return 0;
}