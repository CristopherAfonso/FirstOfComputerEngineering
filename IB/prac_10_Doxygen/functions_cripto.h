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
#include <string>

void Introduction(std::string& programme_name);
void Help(std::string& programme_name);
void NotFoundText();
void NotEnoughArguments();
void NotCorrectArguments();
void Usage(int& argc, char**& argv);
void TestingArguments(char**& argv, std::string& input_file, std::string& output_file, std::string& password_method_one, int& password_method_two, int& method, char& operation);
void MakingNewEncryptedFile(std::string& input_file, std::string& output_file, const int& method, std::string& password_method_one, int& password_method_two, char& operation);
std::string EncryptedCaesar(std::string& all_text, const int& method, char& operation);
std::string EncryptedXOR(std::string& all_text, const int& method, char& operation);