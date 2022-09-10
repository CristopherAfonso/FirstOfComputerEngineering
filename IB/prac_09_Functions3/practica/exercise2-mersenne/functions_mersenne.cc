#include <iostream>
#include <vector>
#include <cmath>

void Help() {
    std::cout << "Hola, soy un programa que toma por línea de comandos un número natural y muestra por pantalla los primeros 'N' nº primos de Mersennne" << std::endl;
    std::cout << "Un primo de Mersenne es un número de la forma 2^p - 1, una propiedad conocida de los primos de Mersenne es que 'p' debe ser también un nº primo" << std::endl;
    std::cout << "El usuario (ústed) deberá darme un número natural (sin decimales o que no sea negativo) y con ese número haré mis calculos" << std::endl;
    std::cout << "(Aunque si me das un número decimal o negativo, lo truncaré y me quedaré con su valor absoluto, y usaré ese número para los calculos" << std::endl;
    std::cout << "Por ejemplo, si me das el número 2, los primeros números primos son el 2 y el 3, con lo cual los primeros números de Mersenne son 3 y 7, con usar la fórmula se ve" << std::endl;
    std::cout << "Por lo tanto te imprimiré por pantalla esos dos números primeros números de Mersenne, aunque si me dieras un número mayor, te imprimiría más números de Mersenne" << std::endl;
    std::cout << "Ahora, cuando vuelvas a llamar al programa, hazlo con un solo número natural para que trabaje" << std::endl;
}

void Introduction(){
    std::cout << "mersenne: es necesario solo un número natural como parámetro" << std::endl;
    std::cout << "Pruebe './mersenne --help' para más información" << std::endl;
}

void AutoExit(int& user_number){

    std::cout << "Como me has dado el número cero, en ese caso no puedo darte ningún número de Marsenne" << std::endl;
    exit(EXIT_SUCCESS);

}

void AllMersenneNumbers(int& user_number) {

    std::vector<int> all_n_first_prime_numbers;
    int number_accumulator{1};
    

    while(all_n_first_prime_numbers.size() != user_number) {

        int limit_loop = number_accumulator/2 + 1;

        if(number_accumulator == 2) {

            all_n_first_prime_numbers.emplace_back(number_accumulator);
            ++number_accumulator;
            continue;
        }

        for(int i = 2; i <= limit_loop + 1; ++i) {
            if(number_accumulator % i == 0) {
                break;
            }

            if(number_accumulator/2 + 1 == i) {
                all_n_first_prime_numbers.emplace_back(number_accumulator);
            }
        }

        ++number_accumulator;

    }


    bool is_prime{true};
    int counter{1};
    int actual_possible_mersenne_number{0};
    const int kCero{0};


    for(const auto actual_vector_value: all_n_first_prime_numbers) {

        is_prime == false;
        actual_possible_mersenne_number = (pow(2, actual_vector_value) - 1);
        
        for(int i = 2; ((i < ((actual_possible_mersenne_number/2) + 2)) && (is_prime == false)); ++i) {

            if( (actual_possible_mersenne_number % i) == kCero  ) {
                is_prime == true;
            }

        }

        if(is_prime == true) {
            std::cout << "El " << counter << "º número de Marsenne es: " << actual_possible_mersenne_number << std::endl;
            ++counter;
        }
        
    }
    
}