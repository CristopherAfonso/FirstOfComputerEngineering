#include <iostream>
#include "functions_difference_of_squares.h" 

void Introduction() {
    std::cout << "difference_of_squares: falta un número natural como parámetro" << std::endl;
    std::cout << "Pruebe 'difference_of_squares --help' para más información." << std::endl;
    std::cout << std::endl;

}

void Help() {
    std::cout << "Hola, soy un programa que te pide por línea de comandos un número natural" << std::endl;
    std::cout << "y devuelve por pantalla la diferencia entre el cuadrado de la suma de los primeros 'N' números naturales" << std::endl;
    std::cout << "y la suma de los cuadrados de esos mismos números" << std::endl << std::endl;

    std::cout << "EJEMPLO ==> Si introduces por línea de comandos el número 10, primer calcularé: " << std::endl;
    std::cout << "El cuadrado de la suma de los 10 primeros números naturales es (1 + 2 + ... + 10)2 = 552 = 3025" << std::endl << std::endl;

    std::cout << "Luego, calcularé La suma de los cuadrados de los primeros diez números naturales es 12 + 22 + ... + 102 = 385" << std::endl << std::endl;
    std::cout << "Y por último calcularé la diferencia entre el cuadrado de la suma y la suma de cuadrados, que es 3025 - 385 = 2640" << std::endl << std::endl;
    
    std::cout << "y el número 2640 será el que te devuelva en patalla, el calculo no" << std::endl << std::endl;

    std::cout << "Ten en cuenta que si me das un número negativo o con decimales, lo truncaré y me quedaré con su valor absoluto" << std::endl;
    std::cout << "Además, si me pasas más de un parámetro, no haré nada, aunque alguno de ellos sea '--help'" << std::endl;
    std::cout << "Y por último, si como único parámetro me das una string (una palabra), te devolveré el número 0" << std::endl;
    std::cout << "Ahora, si quieres probarme, vuelve a ejecutarme y dame un número natural :) " << std::endl;
    

}

int SquareOfNFirstNaturalNumbers(int& the_user_number) {

    int sum_of_numbers{0};
    int square_of_sum_of_numbers{0};

    for(int i = 1; i <= the_user_number; ++i) {
        
        sum_of_numbers += i;

    }

    square_of_sum_of_numbers = sum_of_numbers * sum_of_numbers;

    return square_of_sum_of_numbers;
}

int SumOfSquareOfNFirstNaturalsNumbers(int& the_user_number) {

    int final_number{0};

    for(int i = 1; i <= the_user_number; ++i) {

        final_number += (i*i);

    }

    return final_number;
}

void FinalMessage(int& final_number) {
    std::cout << std::endl;
    std::cout << "El número final que he calculado es: " << final_number << std::endl << std::endl;
}