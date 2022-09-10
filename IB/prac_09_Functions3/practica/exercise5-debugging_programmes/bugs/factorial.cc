/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 7.nov.2020
 * @brief Desarrolle en C++ un programa que imprima en pantalla el valor del factorial de los N primeros números.
 * @see https://docs.google.com/document/d/1-3hTIVf8tPrbn9u0vs0Cm2IGyX1XBgv8hReVU0KOSUQ/edit?usp=sharing
 * @see https://en.wikipedia.org/wiki/Factorial
 */

#include <iostream>
#include <cassert>   // assert

// Prints a Foreword before the complete execution of the program
void Foreword() {
  std::cout << "Este programa imprime el factorial de los N primeros \
                números para un N introducido por el usuario" << std::endl << std::endl;
}

// Returns the factorial of the argument
unsigned long Factorial(unsigned number) {
  switch (number) {
    case 0:
    case 1:
      return 1;
    default:
      unsigned long factorial;
      for (unsigned i = 1; i <= number; ++i) {
        factorial *= i;
      }
      return factorial;
  }
}

int main () {
  Foreword();
  std::cout << "Introduzca el número de factoriales a calcular: ";
  unsigned limit;
  std::cin >> limit;
  for (unsigned i = 1; i <= limit; ++i) {
    std::cout << i << "! = " << Factorial(i) << std::endl; 
  }
  return 0;
}
