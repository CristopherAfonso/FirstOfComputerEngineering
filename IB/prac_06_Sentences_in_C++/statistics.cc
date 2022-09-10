#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main () {
    std::vector<float> random_vec;
    std::srand(std::time(NULL));
    const float kVectorSize = 10.0f;
    float actual_random_number;
    float sum_of_the_10_elements = 0.0f;
    float average;
    float lower_number;
    float higher_number;
    
    std::cout << "Hola, soy un programa que mostrará por pantalla 10 números aleatorios" << std::endl;
    std::cout << "Tras mostrarte esos 10 números aleatorios, te diré cuál es el número más grande (máximo), el más pequeño (mínimo)" << std::endl;
    std::cout << "Y te diré cuál es la media entre todos esos números, ahora bien, aquí tienes los 10 números: " << std::endl << std::endl;

    random_vec.reserve(kVectorSize);

    for(int i = 0; i < int(kVectorSize); ++i){
        actual_random_number = (float)(1 + rand() % 1000) / 100;
        random_vec.emplace_back(actual_random_number);
        sum_of_the_10_elements += actual_random_number;

        if(i == 0){
           lower_number = random_vec[i];
           higher_number = random_vec[i];
        }

        if(actual_random_number < lower_number){
           lower_number = actual_random_number;
        }
        
        if(actual_random_number > higher_number){
           higher_number = actual_random_number;
        }
    }

    for(float each_number: random_vec) {
        std::cout << each_number << "   ";
    }

    std::cout << std::endl << std::endl;

    average = sum_of_the_10_elements/kVectorSize;

    std::cout << "La media de los 10 números es: " << average << std::endl;
    std::cout << "El máximo de los 10 números es: " << higher_number << std::endl;
    std::cout << "El mínimo de los 10 números es: " << lower_number << std::endl << std::endl;
    
    return 0;
}