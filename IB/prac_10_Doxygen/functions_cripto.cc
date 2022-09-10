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
#include <cstring>
#include <sstream>
#include <fstream>
#include <bitset>
#include "functions_cripto.h"

void Introduction(std::string& programme_name) {
    std::cout << std::endl;
    std::cout << programme_name << " -- Cifrado de ficheros" << std::endl;
    std::cout << "Modo de uso: " << programme_name << " fichero_entrada fichero_salida método password operación" << std::endl;
    std::cout << "Pruebe '" << programme_name << " --help' para más información " << std::endl << std::endl;
}

void Help(std::string& programme_name) {
    
    std::cout << std::endl;
    std::cout << programme_name << " -- Cifrado de ficheros" << std::endl;
    std::cout << "Modo de uso: " << programme_name << " fichero_entrada fichero_salida método password operación" << std::endl << std::endl;

    std::cout << "fichero_entrada: Fichero a codificar" << std::endl;
    std::cout << "fichero_salida:  Fichero codificado" << std::endl;
    std::cout << "método:          Indicar el método de encriptado" << std::endl;
    std::cout << "                   1: Cifrado xor" << std::endl;
    std::cout << "                   2: Cifrado de César" << std::endl;
    std::cout << "password:        Palabra secreta en el caso del método 1, Valor de K en el método 2" << std::endl;
    std::cout << "operación:       Operación a realizar en el fichero" << std::endl;
    std::cout << "                   +: encriptar el fichero" << std::endl;
    std::cout << "                   -: desencriptar el fichero" << std::endl << std::endl;
}

void NotFoundText() {

    std::cout << std::endl;
    std::cout << "Archivo a (des)encriptar no encontrado" << std::endl;
    std::cout << "Ejecución abortada" << std::endl << std::endl;
}

void NotEnoughArguments() {

    std::cout << std::endl;
    std::cout << "Faltan/Sobran argumentos para ejecutar el programa" << std::endl;
    std::cout << "Ejecución abortada" << std::endl << std::endl;
}

void NotCorrectArguments() {

    std::cout << std::endl;
    std::cout << "Hay errores en los argumentos de entrada" << std::endl;
    std::cout << "Ejecución abortada" << std::endl << std::endl;
}

void Usage(int& argc, char**& argv) {

    std::string programme_name = "";

    if( argc == 1 ) {

        std::stringstream(argv[0]) >> programme_name;
        Introduction(programme_name);
        exit(EXIT_SUCCESS);
    } 

    if(strcmp(argv[1], "--help") == 0) {

        std::stringstream(argv[0]) >> programme_name;
        Help(programme_name);
        exit(EXIT_SUCCESS);
    }

   
    if( (argc > 6) || (argc < 6) ) {

        NotEnoughArguments();
        exit(EXIT_SUCCESS); 
    }
}

void TestingArguments(char**& argv, std::string& input_file, std::string& output_file, std::string& password_method_one, 
int& password_method_two, int& method, char& operation) {

    std::stringstream(argv[1]) >> input_file;
    std::stringstream(argv[2]) >> output_file;
    std::stringstream(argv[3]) >> method;
    std::stringstream(argv[5]) >> operation;

    if( (operation != '+') && (operation != '-') ) {
        NotCorrectArguments();
        exit(EXIT_SUCCESS);
    }

    switch (method) {
        case 1: 
        std::stringstream(argv[4]) >> password_method_one;
        break;

        case 2: 
        std::stringstream(argv[4]) >> password_method_two;
        break;

        default:
        NotCorrectArguments();
        exit(EXIT_SUCCESS);
    }

}

std::string EncryptedCaesar(std::string& all_text, int& password_method_two, char& operation) {

    if(operation == '-') {
        password_method_two = -password_method_two;
    }

    for(std::string::iterator string_itr = all_text.begin(); string_itr != all_text.end(); string_itr++){

        string_itr += password_method_two;
    }

    return all_text;
}

std::string EncryptedXOR(std::string& all_text, std::string& password_method_one, char& operation) {

    return all_text;
}

void MakingNewEncryptedFile(std::string& input_file, std::string& output_file, const int& method, std::string& password_method_one, int& password_method_two, char& operation) {
    
    std::ifstream readed_file{input_file};

    std::string actual_line = "";

    readed_file.open(input_file, std::ios::in);

    if(readed_file.fail()) {
        NotFoundText();
        exit(EXIT_SUCCESS);
    }

    std::ofstream maked_file{output_file};

    switch (method) {
        case 1:

        maked_file.open(output_file, std::ios::out);
        while(!readed_file.eof()) {
            
            getline(readed_file, actual_line);
            maked_file << EncryptedXOR(actual_line, password_method_one, operation);
        }
        maked_file.close();
        break;


        case 2: 

        maked_file.open(output_file, std::ios::out);
        while(!readed_file.eof()) {
            
            getline(readed_file, actual_line);
            maked_file << EncryptedCaesar(actual_line, password_method_two, operation);
        }
        maked_file.close();
        break;

        default: break;
    }
}