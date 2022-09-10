#include "fechas.h" 

void Introduction(char* argv[]) {
    std::string function_name = "";
    std::stringstream(argv[0]) >> function_name;
    std::cout << '\n' << function_name << " - Gestión de fechas\n";
    std::cout << "Modo de uso: " << function_name << " dd/mm/aa N fichero_salida.txt\n";
    std::cout << "Pruebe '" << function_name << " --help' para más información\n\n";
}

void Help() {
    std::cout << '\n' << "Hola, soy un programa que gestiona fechas, tomo como parámetros por líneas de comandos un día, mes y año que tú me das (una fecha en sí),\n";
    std::cout << "un número que representaremos por N, y un nombre que le quieras dar a un fichero de salida\n";
    std::cout << "mi forma de funcionar es la siguiente, tú me das tres parámetros, una fecha(primer parámetro), un número(el segundo) y un nombre de un fichero(el tercero),\n";
    std::cout << "y yo imprimiré en el fichero de salida (tercer parámetro) las N (segundo parámetro) fechas\n";
    std::cout << "cronológicamente posteriores a la introducida (primer parámetro) con una separación de un día entre fechas sucesivas\n";
    std::cout << "aquí te dejo un ejemplo de los posibles parámetros que me podrías pasar para probarme: 01/01/2021 5 fichero_con_fechas.txt\n\n";
}

void NotEnoughArguments() {
    std::cout << '\n' << "Faltan/Sobran argumentos para ejecutar correctamente el programa\n"; 
    std::cout << "Ejecución abortada\n\n";
}

void WrongDate() {
    std::cout << "\n Has puesto la fecha que debias darme en un formato incorrecto\n";
    std::cout << "Ejecución abortada\n\n";
}

void Usage(int& argc, char* argv[]) {

    if(argc == 1) {
        Introduction(argv);
        exit(EXIT_SUCCESS); 
    }

    if(strcmp(argv[1], "--help") == 0) {
        Help();
        exit(EXIT_SUCCESS);
    }

    if( (argc < 4) || (argc > 4) ) {
        NotEnoughArguments();
        exit(EXIT_FAILURE);
    }
}




Dates::Dates(int user_day, int user_month, int user_year) {
    user_day_ = user_day; user_month_ = user_month; user_year_ = user_year;
}

std::string Dates::MakerDate(int user_day, int user_month, int user_year, const std::string& output_file_name, int number_of_the_next_dates) {

    std::string text_user_day = std::to_string(user_day);
    std::string text_user_month = std::to_string(user_month);
    std::string text_user_year = std::to_string(user_year);

    std::string actual_date = text_user_day + '/' + text_user_month + '/' + text_user_year;

    std::ofstream output_file{output_file_name};

    switch (user_month) {
         
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
        if(user_day > 31) {
            user_day = 0;
            user_month += 1;
            if(user_month > 12) {
                user_month = 0;
                user_year += 1;
            }
        }
        break;

        case 4: case 6: case 9: case 11: 
        if(user_day > 31) {
            user_day = 0;
            user_month += 1;
            if(user_month > 12) {
                user_month = 0;
                user_year += 1;
            }
        }
        break;

        case 2: 

        if( ( (user_year % 4 == 0)  && (user_year % 100 != 0) ) || (user_year % 400 == 0) ){

            if(user_day > 29) {
                user_day = 0;
                user_month += 1;
                
                if(user_month > 12) {
                    user_month = 0;
                    user_year += 1;
                }
            }
        }
        else{
            
            if(user_day > 28) {
                user_day = 0;
                user_month += 1;
                
                if(user_month > 12) {
                    user_month = 0;
                    user_year += 1;
                }
            }

        }

        if(  ( (user_year % 4 == 0)  && (user_year % 100 != 0) ) || (user_year % 400 == 0) ) {
            std::cout << "\nEl año marcado en la fecha, es un año bisiesto\n\n";
        }
        else{
            std::cout << "\nEl año introducido por el usuario no es un año bisiesto\n\n";
        }

    }
    
    std::string actual_line = "";

    output_file.open(actual_line, std::ios::out);

    std::cout << "Las próximas " + std::to_string(number_of_the_next_dates) + " fechas cronológias a la entregada por el usuario son:" << std::endl << std::endl;

    output_file << "Las próximas " + std::to_string(number_of_the_next_dates) + " fechas cronológias a la entregada por el usuario son:" << std::endl << std::endl;

    for (int i = 1; i <= number_of_the_next_dates; ++i) {

        ++user_day;

        switch (user_month) {

            
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
            
            if(user_day > 31) {
                user_day = 1;
                user_month += 1;
                
                if(user_month > 12) {
                    user_month = 1;
                    user_year += 1;
                }
            }
            break;

            case 4: case 6: case 9: case 11: 

            if(user_day > 31) {

                user_day = 1;
                user_month += 1;
                
                if(user_month > 12) {
                    user_month = 1;
                    user_year += 1;
                }
            }
            break;

            case 2: 


            if( ( (user_year % 4 == 0)  && (user_year % 100 != 0) ) || (user_year % 400 == 0) ){

                if(user_day > 29) {
                    user_day = 1;
                    user_month += 1;
                
                    if(user_month > 12) {
                        user_month = 1;
                        user_year += 1;
                    }
                }
            }
            else{
            
                if(user_day > 28) {
                    user_day = 1;
                    user_month += 1;
                
                    if(user_month > 12) {
                        user_month = 1;
                        user_year += 1;
                    }
                }

            }



        }

        if(user_day < 10) { 
            std::cout << "0" + std::to_string(user_day) + '/';
            output_file << "0" + std::to_string(user_day) + '/';
        }
        else {std::cout << std::to_string(user_day) + '/'; output_file << std::to_string(user_day) + '/';}

        if(user_month < 10) { 
            std::cout << "0" + std::to_string(user_month) + '/';
            output_file << "0" + std::to_string(user_month) + '/';
        }
        else {std::cout << std::to_string(user_month) + '/'; output_file << std::to_string(user_month) + '/';}

        if(user_year < 10) { 
            std::cout << "0" + std::to_string(user_year) + '\n';
            output_file << "0" + std::to_string(user_year) + '\n';
        }
        else {std::cout << std::to_string(user_year) + '\n'; output_file << std::to_string(user_year) + '\n';}

    }

    std::cout << '\n';
    std::cout << "(Este mensaje mostrado en pantalla es una copia del texto que hay en el archivo '" + output_file_name + "', dicho archivo acaba de crearlo el programa)\n\n";
    output_file.close();

    //exit(EXIT_SUCCESS);

}

void UserDates(int& argc, char* argv[]){

    int number_of_the_next_dates{0};
    std::stringstream(argv[2]) >> number_of_the_next_dates;
    number_of_the_next_dates = fabs(number_of_the_next_dates);

    std::string output_file_name = "";
    std::stringstream(argv[3]) >> output_file_name;    
    
    std::string text_user_date = "";
    std::stringstream(argv[1]) >> text_user_date;

    if(text_user_date.length() != 8) {

        WrongDate();
        exit(EXIT_SUCCESS);
    }

    char aux_var_char = ' ';
    std::vector <char> aux_var_vec_char;
    aux_var_vec_char.reserve(6);
    
    for(const auto actual_character: text_user_date) {

        aux_var_char = actual_character;
        if(aux_var_char != '/') {

            aux_var_vec_char.emplace_back(actual_character);            
        }
    }

    int year{0};
    int month{0};
    int day{0};

    int counter{1};

    for(auto actual_character: aux_var_vec_char) {
        
        int aux_var_int{0};;
        std::string aux_var_str = "";

        switch (actual_character) {

            case '0': aux_var_int = 0; break;
            case '1': aux_var_int = 1; break;
            case '2': aux_var_int = 2; break;
            case '3': aux_var_int = 3; break;
            case '4': aux_var_int = 4; break;
            case '5': aux_var_int = 5; break;
            case '6': aux_var_int = 6; break;
            case '7': aux_var_int = 7; break;
            case '8': aux_var_int = 8; break;
            case '9': aux_var_int = 9; break;
        }

        switch (counter){

        case 1:

        day = aux_var_int;
            break;
        case 2:
        day = 10*day + aux_var_int;

        case 3:
        month = aux_var_int;
            break;
        case 4:
        month = 10*month + aux_var_int;

        case 5:
        year = aux_var_int;
            break;
        case 6:
        year = 10*year + aux_var_int;
        
        default:
            break;
        }

        ++counter;
    }

    Dates actual_date(day, month, year);

    actual_date.MakerDate(day, month, year, output_file_name, number_of_the_next_dates);
}