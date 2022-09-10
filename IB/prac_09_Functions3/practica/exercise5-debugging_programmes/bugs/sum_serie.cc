/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 2.nov.2020
 * @brief  La suma de los 5 primeros números naturales es 1+2+3+4+5=15. 
 *         Desarrolle en C++ un programa que solicite al usuario el valor de un número natural, N 
 *         y calcule la suma de los N primeros números naturales.
 * @see https://docs.google.com/document/d/1-3hTIVf8tPrbn9u0vs0Cm2IGyX1XBgv8hReVU0KOSUQ/edit?usp=sharing
 *
 */

#include <iostream>

int main () {
  std::cout << "Este programa imprime la suma de los N primeros números naturales" << std::endl << std::endl;
  std::cout << "Introduzca el número de términos a sumar: ";
  unsigned num_terms;
  std::cin >> num_terms;
  unsigned long sum{0};
  for (unsigned term = 1; term <= num_terms; ++term) {
    sum += term;
  }
  std::cout << "La suma de los primeros " << num_terms << " números es: " << sum << std::endl; 
  return 0;
}
