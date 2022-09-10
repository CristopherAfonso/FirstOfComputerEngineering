#include "racionales.h"


void Usage(int argc, char *argv[]){

    if(  (argc == 2) && (strcmp(argv[1], "--NumerosRacionales") == 0)  ){
        std::cout << "Modo de uso: ./racionales fichero_entrada fichero_salida\n"
                    "fichero_entrada: Fichero de texto conteniendo líneas con un par de números racionales: `a/b c/d` separados por un espacio\n"
                    "fichero_salida:  Fichero de texto que contendrá líneas con las operaciones realizadas: `a/b + c/d = n/m`\n" << std::endl;
        exit(EXIT_SUCCESS);
    }
    if(  (argc == 2) && (strcmp(argv[1], "--help") == 0)  ){
        std::cout << "Modo de uso: ./racionales fichero_entrada fichero_salida/n"
                     "Pruebe ./racionales --help para más información" << std::endl;
        exit(EXIT_SUCCESS);
    }
    if(argc != 2){
        std::cout << "\nFaltan/Sobran argumentos que se le dan al programa, pruebe --help para mayor informacion\n\n";
        exit(EXIT_SUCCESS);
    }
}


Racional::Racional(int number, int denom) {
    numerator_ = number;
    denominator_ = denom;
}

std::string Racional::add(const Racional& object_rac) {
    int numerator_result{denominator_ * object_rac.numerator_ + numerator_ * object_rac.denominator_};
    int denominator_result{denominator_ * object_rac.denominator_};
    denominator_ = denominator_result;
    numerator_ = numerator_result;
    std::string text_racional_1 = std::to_string(numerator_) + '/' + std::to_string(denominator_);
    std::string text_racional_2 = std::to_string(object_rac.numerator_) + '/' + std::to_string(object_rac.denominator_);
    std::string all_text = text_racional_1 + " + " + text_racional_2 + " = " + std::to_string(numerator_result) + '/' +std::to_string(denominator_result); 
    return all_text;
}

std::string Racional::subtrac(const Racional& object_rac) {
    int numerator_result{denominator_ * object_rac.numerator_ - numerator_ * object_rac.denominator_};
    int denominator_result{denominator_ * object_rac.denominator_};
    denominator_ = denominator_result;
    numerator_ = numerator_result;
    std::string text_racional_1 = std::to_string(numerator_) + '/' + std::to_string(denominator_);
    std::string text_racional_2 = std::to_string(object_rac.numerator_) + '/' + std::to_string(object_rac.denominator_);
    std::string all_text = text_racional_1 + " + " + text_racional_2 + " = " + std::to_string(numerator_result) + '/' +std::to_string(denominator_result); 
    return all_text;
}

std::string Racional::multiplication(const Racional& object_rac) {
    int numerator_result{ numerator_ * object_rac.numerator_};
    int denominator_result{ denominator_ * object_rac.denominator_};
    denominator_ = denominator_result;
    numerator_ = numerator_result;
    std::string text_racional_1 = std::to_string(numerator_) + '/' + std::to_string(denominator_);
    std::string text_racional_2 = std::to_string(object_rac.numerator_) + '/' + std::to_string(object_rac.denominator_);
    std::string all_text = text_racional_1 + " + " + text_racional_2 + " = " + std::to_string(numerator_result) + '/' +std::to_string(denominator_result); 
    return all_text;
}

std::string Racional::division(const Racional& object_rac) {
    int numerator_result{ numerator_ * object_rac.denominator_};
    int denominator_result{ denominator_ * object_rac.numerator_};
    denominator_ = denominator_result;
    numerator_ = numerator_result;
    std::string text_racional_1 = std::to_string(numerator_) + '/' + std::to_string(denominator_);
    std::string text_racional_2 = std::to_string(object_rac.numerator_) + '/' + std::to_string(object_rac.denominator_);
    std::string all_text = text_racional_1 + " + " + text_racional_2 + " = " + std::to_string(numerator_result) + '/' +std::to_string(denominator_result); 
    return all_text;
}

void Racional::show(){
    std::cout << numerator_ << "/" << denominator_ << std::endl;
}

bool Racional::ItIsEqual(const Racional& object_rac){

    if (  (denominator_ == object_rac.denominator_)  &&  (numerator_ == object_rac.numerator_)  ){
        std::cout << "\nEstos son cocientes iguales\n" << std::endl;
        return 1;
    }
    else{
        std::cout << "\nNo son cocientes iguales\n" << std::endl;
        return 0;
    }
}

void operator>>(std::string& file_input, Racional& object_rac){
    int numerator = std::stoi(&file_input[0]);
    int denominator = std::stoi(&file_input[2]);

    if(denominator == 0)
        throw "El denominador no puede ser 0";

    object_rac.numerator_ = numerator;
    object_rac.denominator_ = denominator;
}

