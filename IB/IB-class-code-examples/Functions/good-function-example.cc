/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 16 Jun 2020
 * @brief Example of a good function
 *
 * The function returns a vector with perfect squares in range [0, size^2]
 * 
 * The function:
 *   Is small enough to see all the code at once
 *   Name clearly states what the function does
 *   Function does a single thing
 *
 * @see https://en.cppreference.com/w/cpp/language/functions
 * @see http://www.cplusplus.com/doc/tutorial/functions/
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> CreateVectorOfFullSquares(int size) {
  vector<int> result(size);     // Vector of size `size `

  for (int i = 0; i < size; ++i) {
    result[i] = i * i;
  }
  return result;
}

int main () {
  auto squares = CreateVectorOfFullSquares(20);
  for (int i = 0; i < 20; ++i) {
    std::cout << squares[i] << ", ";
  }
  std::cout << std::endl;
  return 0;
}



