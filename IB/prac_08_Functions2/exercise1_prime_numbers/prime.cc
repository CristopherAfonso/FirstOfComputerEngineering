#include <iostream>
#include <cmath>
#include <cstdlib>
#include "functions_prime.h"

int main(int argc, char* argv[]) {

    if (argc == 1) {

        Introduction();
        exit(EXIT_SUCCESS);
    }

    int user_number{0};
    
    std::stringstream(argv[1]) >> user_number;
    user_number = fabs(user_number);

   TheExactPrimeNumber(user_number);    

    return 0;
}
