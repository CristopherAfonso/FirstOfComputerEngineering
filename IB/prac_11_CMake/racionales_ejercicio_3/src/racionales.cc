#include "racionales.h"


int main(int argc, char* argv[]) {

    Usage(argc, argv);


    std::string input_file_name = argv[1];
    std::string output_file_name = argv[2];
    std::string actual_line = "";

    std::ifstream input_file_stream(input_file_name);
    std::ofstream output_file_stream(output_file_name);


    while(  std::getline(input_file_stream, actual_line)  ){

        std::cout << actual_line << std::endl;

        std::string file_racional_1 = actual_line.substr(0, 3);
        std::string file_racional_2 = actual_line.substr(4, 3);

        Racional object_racional_1;
        Racional object_racional_2;

        file_racional_1 >> object_racional_1;
        file_racional_2 >> object_racional_2;

        output_file_stream << object_racional_1.add(object_racional_2);
        output_file_stream << "\n\n";
        output_file_stream << object_racional_1.subtrac(object_racional_2);
        output_file_stream << "\n\n";
        output_file_stream << object_racional_1.multiplication(object_racional_2);
        output_file_stream << "\n\n";
        output_file_stream << object_racional_1.division(object_racional_2);
        output_file_stream << "\n\n";
    }

    return 0;
}