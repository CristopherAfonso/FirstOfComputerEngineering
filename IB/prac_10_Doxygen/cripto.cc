/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file cripto.cc
  * @author Cristopher Afonso Mora alu0101402031@ull.edu.es
  * @date 02 Enero 2021
  * @brief El programa recibe una serie de parámetros, entre ellos el nombre de
  *        un archivo de texto(.txt) en el directorio donde se encuentre este programa,
  *        tras recibirlo, lo (des)encripta (según el parámetro que se le pase) 
  *        y crea un nuevo archivo de texto que contiene el texto (des)encriptado,
  *        para deshacer el (des)encriptado, hay que hacer la operación inversa con este programa.
  * @bug No hay bugs conocidos
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
*/

#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include <bitset>
#include "functions_cripto.h"

int main(int argc, char* argv[]) {

  Usage(argc, argv);

  std::string input_file = "";
  std::string output_file = "";
  int method{0};
  std::string password_method_one = "";
  int password_method_two{0};
  char operation = ' ';


  TestingArguments(argv, input_file, output_file, password_method_one, password_method_two, method, operation);

  MakingNewEncryptedFile(input_file, output_file, method, password_method_one, password_method_two, operation);
  
  
  return 0;
}