/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 20 Jul 2020
 * @brief  Computes the Sum of Square of first n Natural numbers. 
 *
 */

#include<iostream>

using namespace std;

int main() {
    unsigned long number, sum, square;
    cout << "Enter any number: ";
    cin >> number;

    for(int i = 1; i <= number; ++i) {
        square = i * i;
        sum += square;
    }

    cout<<"\nSum of square of [ "<< number <<" ] Numbers = " << sum << "\n";
    return 0;
}
