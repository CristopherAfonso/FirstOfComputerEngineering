#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include "functions_find_first_of.h"

int main (int argc, char* argv[]) {

    if(argc == 1) {
        Introduction();
        exit(EXIT_SUCCESS);
    }

    if( strcmp(argv[1], "--help") == 0 ){
        Help();
        exit(EXIT_SUCCESS);
    }

    if( (argc < 3) || (argc > 3) ) {
        Introduction();
        exit(EXIT_SUCCESS);
    }

    std::string word = "";
    std::string string_caracter = "";

    std::stringstream(argv[1]) >> word;
    std::stringstream(argv[2]) >> string_caracter;

    char letter = string_caracter.front();

    FindLetter(word, letter);           

    return 0;
}