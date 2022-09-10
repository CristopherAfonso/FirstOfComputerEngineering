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
  std::cout << "Este programa imprime el factorial de los N primeros ";
  std::cout << "números para un N introducido por el usuario (contando el número cero como el primer número factorial)" << std::endl;
  std::cout << "Con lo cual si introduces un número 'N', te devolveré los primeros 'N - 1' números factoriales" << std::endl << std::endl;
} // cuento el número cero porque el enunciado del programa en un inicio no dice que sean los 'N primeros números naturales', no dice naturales
//solo dice 'los N primeros números' y por eso cuento al cero

// Returns the factorial of the argument
unsigned long Factorial(unsigned number) {
  switch (number) {
    case 0: // quiero aclarar que el programa sea cual sea el número que le diera, en un principio, nunca iba a darse el 'case 0' del switch
    case 1: // ya que como a la función 'Factorial()' se le daba como parámetro la variable 'i' y esta inicia en 'i = 1', y nunca sería cero
      return 1;
    default:
      unsigned long factorial{1};
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
  std::cout << std::endl;
  for (unsigned i = 0; i < limit; ++i) {
    std::cout << i << "! = " << Factorial(i) << std::endl; 
  }
  return 0;
}
