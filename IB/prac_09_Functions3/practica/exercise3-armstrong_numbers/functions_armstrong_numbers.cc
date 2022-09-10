#include <iostream>
#include <vector>
#include <cmath>

void Introduction() {
    std::cout << "armstrong_numbers: se necesita solo un número natural como parámetro" << std::endl;
    std::cout << "Pruebe './armstrong_numbers --help' para más información" << std::endl;
}

void Help() {
    std::cout << "Hola, soy un programa el cual te dice si el número que me has dado es un número Armstrong" << std::endl;
    std::cout << "Un número Armstrong es un número el cual es la suma de sus propios dígitos, cada uno de los cuales está elevado al número de dígitos del número" << std::endl;
    std::cout << "Por ejemplo: el 9 es un número Armstrong porque 9 = 9^1, y 10 no lo es, porque 10 != 1^2 + 0^2" << std::endl;
    std::cout << "Y 153 es un número Armstrong porque 153 = 1^3 + 5^3 +3^3 = 1 + 125 + 27 = 153" << std::endl << std::endl;
    
    std::cout << "Ahora que sabes como funciono, prueba a darme solo un número la próxima vez que me llames" << std::endl;
    std::cout << "Ese número debe ser positivo y sin decimales" << std::endl;
    std::cout << "Aunque si me lo das negativo y con decimales, lo truncaré y cogeré su valor absoluto" << std::endl;
    std::cout << "Pero lo haré solo si me pasas un solo número, si me das más o ninguno no haré nada" << std::endl;
}

void NotSuccess(int& user_number){
    std::cout << "El " << user_number << " no es un número armstrong" << std::endl;
}

void Success(int& user_number) {
    std::cout << "El " << user_number << " si es un número armstrong" << std::endl;
}



void ArmstrongNumbersCheck(int& user_number, int& length_user_number) {

    std::vector<int> all_digits;
    all_digits.reserve(length_user_number);
    int original_user_number{user_number};
    int final_number_to_compare{0};



    if(user_number == 0) {
        Success(original_user_number);
        exit(EXIT_SUCCESS);
    }

    int aux_var_to_compute{0};

    for(int i = 1; i <= length_user_number; ++i) {
        aux_var_to_compute = user_number % 10;
        user_number /= 10;
        aux_var_to_compute = pow(aux_var_to_compute, length_user_number);
        all_digits.emplace_back(aux_var_to_compute);
    }

    for(const auto actual_vector_value: all_digits) {
        final_number_to_compare += actual_vector_value;
    }

    if(original_user_number == final_number_to_compare) {
        Success(original_user_number);
    }
    else {
        NotSuccess(original_user_number);
    }

}