#include <iostream>

int main() {

    std::cout << "\nPráctica 3. Principios de Computadores - Cristopher Manuel Afonso Mora"
              << "\nIntroduzca el error máximo permitido: ";

    double number_of_maximum_error{1.00};
    std::cin >> number_of_maximum_error;
    if(number_of_maximum_error >= 1.00) {
        return 0;
    }

    double number_e{0.00};
    double formula_actual_value{0.00};
    int den_fact{1};
    int counter{0};

    number_e = 1.00;
    formula_actual_value = double(1)/den_fact;
    ++counter;
    
    while(formula_actual_value > number_of_maximum_error) {
        formula_actual_value = double(1)/den_fact;
        den_fact *= (1 + counter);
        number_e += formula_actual_value;
        ++counter;       
    }

    std::cout << "\nNúmero e: " << number_e;
    std::cout << "\nTerminos Calculados: " << counter << "\n\n";
    return 0;
}