/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 2.nov.2020
 * @brief Escriba un programa que imprima los N primeros términos de la Serie de Fibonacci. 
          Los primeros términos de la serie son: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ...
 * @see https://docs.google.com/document/d/1-3hTIVf8tPrbn9u0vs0Cm2IGyX1XBgv8hReVU0KOSUQ/edit?usp=sharing
 *      https://stackoverflow.com/questions/3773396/declare-variables-at-top-of-function-or-in-separate-scopes
 *
 *      Where to declare variables:
 *      You should declare them as locally as possible, i.e. at the beginning of smallest local block that covers 
 *      the desired lifetime of the variable. 
 *      Sometimes it might even make sense to introduce a "redundant" local block with the only 
 *      purpose of "localizing" the variable declaration.
 */

#include <iostream>

int main () {
  int num_terms;
  const std::string kSpace = " ";

  std::cout << "Este programa imprime los N primeros términos de la serie de Fibonacci" << std::endl << std::endl;
  std::cout << "Introduzca el número de términos a imprimir: ";
  std::cin >> num_terms;
  switch (num_terms) {
    case 1:
      std::cout << 0 << kSpace;
      break;
    case 2:
      std::cout << 0 << kSpace;
      std::cout << 1 << kSpace;
      break;
    default:
      int last, before_last, next;
      before_last = 0;
      last = 1;
      std::cout << before_last << kSpace;
      std::cout << last << " ";
      for (int i = 0; i < (num_terms - 2); ++i) {
        next = last + before_last;
        std::cout << next << kSpace;
        before_last = last;
      }
      break;
  }
  std::cout << std::endl; 
  return 0;
}
