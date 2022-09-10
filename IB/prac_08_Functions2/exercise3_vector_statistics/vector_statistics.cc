#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cstring>
#include <cmath>
#include "functions_vector_statistics.h"

int main (int argc, char* argv[]) {

    if ( (argc < 4) || (argc > 4) ) {
        Introduction();
        exit(EXIT_SUCCESS);
    }

    int first_number{0};
    int second_number{0};
    int third_number{0};
    std::srand(std::time(NULL));

    std::stringstream(argv[1]) >> first_number;
    std::stringstream(argv[2]) >> second_number;
    std::stringstream(argv[3]) >> third_number;

    if(second_number > third_number){
        int aux{0};
        aux = second_number;
        second_number = third_number;
        third_number = aux;
    }

    if((first_number < 0) || (second_number < 0) || (third_number < 0)){
        first_number = fabs(first_number);
        second_number = fabs(second_number);
        third_number = fabs(third_number);
    }

    std::vector<double> the_vector;

    the_vector.reserve(first_number);



    double actual_random_number{0.00};

    double average{0.00};
    double standard_deviation{0.00};
    double maximum;
    double minimum;
    double random_number{0};

    std::srand(std::time(NULL));

    for(int i = 0; i < first_number; ++i){

        random_number = rand();        
        actual_random_number = ToCreateRandomNumbers(second_number, third_number, random_number);
        average += actual_random_number;
        the_vector.emplace_back(actual_random_number);

        if(i == 0) {
            maximum = actual_random_number;
            minimum = actual_random_number;
        }

        if (actual_random_number > maximum){
            maximum = actual_random_number;
        }
        if (actual_random_number < minimum){
            minimum = actual_random_number;
        }

    }

    average /= first_number;


    for(int i = 0; i < first_number; ++i){

        standard_deviation += StandardDeviation(the_vector[i], average);
    }

    standard_deviation /= first_number;

    FinalMessage1(first_number, second_number, third_number);

    for(const auto actual_vector_component: the_vector) {
        std::cout << actual_vector_component << "    ";
    }

    FinalMessage2(average, standard_deviation, maximum, minimum);
    
    return 0;
}