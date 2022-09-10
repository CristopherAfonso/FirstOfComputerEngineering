#ifndef FECHAS
#define FECHAS

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>
#include <vector>
#include <fstream>

void Introduction(const char* argv[]);
void Help();
void NotEnoughArguments();
void WrongDate();
void Usage(int& argc, char* argv[]);
void UserDates(int& argc, char* argv[]);

class Dates {
      private:

        int user_day_{0};
        int user_month_{0};
        int user_year_{0};
        
      public:
        
        Dates(int user_day = 0, int user_month = 0, int user_year = 0);

        std::string MakerDate(int user_day, int user_month, int user_year, const std::string& output_file, int number_of_the_next_dates);

    };

#endif