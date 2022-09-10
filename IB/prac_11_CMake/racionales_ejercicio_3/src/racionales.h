#ifndef RACIONALES
#define RACIONALES

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

void Usage(int argc, char *argv[]);

class Racional {

  private: 

    int numerator_;
    int denominator_;

  public:

    Racional(int number = 0, int denom = 0);

    std::string add(const Racional& objet_rac);
    std::string subtrac(const Racional& object_rac);
    std::string multiplication(const Racional& object_rac);
    std::string division(const Racional& object_rac);

    void show();

    bool ItIsEqual(const Racional& object_rac);

    friend void operator>>(std::string &file_input, Racional &obj);
};


#endif