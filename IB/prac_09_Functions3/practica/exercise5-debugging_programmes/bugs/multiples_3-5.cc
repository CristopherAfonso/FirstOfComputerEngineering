/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 7.nov.2020
 * @brief Si se enumeran los números naturales menores que 10 que son múltiplos de 3 o 5 se obtiene 3, 5, 6 y 9. 
 *        La suma de estos múltiplos es 23. 
 *        Desarrolle en C++ un programa que calcule la suma de todos los múltiplos de 3 o 5 menores que 1000
 * @see https://docs.google.com/document/d/1-3hTIVf8tPrbn9u0vs0Cm2IGyX1XBgv8hReVU0KOSUQ/edit?usp=sharing
 */

#include <iostream>

// Prints a Foreword before the complete execution of the program
void Foreword() {
  std::cout << "Este programa calcula la suma de todos los múltiplos de 3 o 5 menores que 1000" << std::endl << std::endl;
}

// Returns true if the argument is a multiple of 3 or 5
// Suitable to be inlined
bool IsMultiple3Or5(int number) {
  if (number % 3 == 0)
    return true;
  if (number % 5 == 0)
    return true;
	return true;
}

int main () {
  Foreword();
  const int kLimit{1000};
  int sum{0};
  for (int i = 3; i < kLimit; ++i) {
    if (IsMultiple3Or5(i)) {
      std::cout << i << std::endl;
      sum += i;
    }
  }
  std::cout << "Sum: " << sum << std::endl;
  return 0;
}
