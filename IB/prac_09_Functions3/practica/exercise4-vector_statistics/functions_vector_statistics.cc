#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cmath>

void Introduction() {
    std::cout << std::endl;
    std::cout << "Hola, soy un programa que pide por línea de comandos 3 números naturales" << std::endl;
    std::cout << "Cuando tenga esos números, lo que haré será coger el primer número que me des, y crear un vector con una longitud igual a ese número" << std::endl;
    std::cout << "Y con los otros dos números, lo que haré será crear números aleatorios en el intervalo que definan los últimos dos números que me des" << std::endl;
    std::cout << "Cuando tenga los 3 números, devolveré por pantalla la suma, el producto, el máximo, el mínimo y la media de todos los números que hayan el el vector" << std::endl;
    std::cout << "Todos los números que tenga el vector, serán de tipo double y habrán sido creados en el intervalo que denoten los dos últimos números que me des" << std::endl;
    std::cout << "Ten en cuenta que si me das en alguno de los 3 parámetros que te pido, una palabra o letra en vez de un número, en ese caso al número al que le correspondería esa palabra lo igualaré a cero" << std::endl;
    std::cout << "Por último, si el primer número que me des es 0, entonces no delvoveré nada, ya que el vector que debería crear sería de longitud cero" << std::endl; 
    std::cout << std::endl;
}


double ToCreateRandomNumbers(int& little_limit, int& big_limit, double& my_actual_random_number) {

    double random_number{0.00};
    
    random_number = (double) (little_limit + (my_actual_random_number / ((double)RAND_MAX/((double)big_limit - (double)little_limit))));

    return random_number;
}

void FinalMessage1(int& first_number, int& second_number, int& third_number){

    std::cout << std::endl;
    std::cout << "He creado un vector de longitud " << first_number << ", y lo he llenado con números aleatorios entre el intervalo: [ " << second_number << " , " << third_number << " ] " << std::endl << std::endl;
    
    std::cout << "Todos los números que llenan el vector son los siguientes: " << std::endl << std::endl;
}

void FinalMessage2(double& whole_sum, double& product, double& maximum, double& minimum, double& average) {

    std::cout << std::endl << std::endl;
    std::cout << "La suma de todos esos datos es: " << whole_sum << std::endl;
    std::cout << "El productor de todos esos datos es: " << product << std::endl;
    std::cout << "El máximo de todos esos datos es: " << maximum << std::endl;
    std::cout << "El mínimo de todos esos datos es: " << minimum << std::endl;
    std::cout << "La media de todos esos datos es: " << average << std::endl;
}