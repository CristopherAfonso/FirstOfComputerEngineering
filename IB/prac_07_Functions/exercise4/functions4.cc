#include <iostream>
#include <string>
#include <sstream>

void introduction() {
    std::cout << "Hola, soy un programa que te dice todos los días que tiene un mes" << std::endl;
    std::cout << "para ello, tú debes darme un número entero positivo y sin decimales" << std::endl;
    std::cout << "(aunque si me das un número con decimales, lo truncaré)" << std::endl;
    std::cout << "el número que me des representará el mes del año, por ejemplo si me das '1', me estas pidiendo los días que tiene enero" << std::endl;
    std::cout << "aunque si me das el número 2, te pediré también el año, para decirte si el mes de febrero en ese año tiene 28 ó 29 días" << std::endl;
    std::cout << "también te aviso, si me das un número que no esté en el intervalo [1, 12], te diré que los días que tiene ese mes son -1 días" << std::endl;
    std::cout << "ya que números fuera de ese intervalo no puedo considerarlos como números asociados a algún mes del año" << std::endl;
    std::cout << "dicho esto, dime, ¿Cúal es el mes del que quieres saber sus días?: ";
}

int stringstream(std::string& my_string){
    int number_of_month{0};

    std::stringstream(my_string) >> number_of_month;

    return number_of_month;
}

void error_menssage() {
    std::cout << "Ese mes tiene -1 días" << std::endl;
}

void number_of_days(int& month, int& days) {
    std::cout << "El mes " << month << " tiene " << days << " días" << std::endl;
}

void number_of_days2(int& month, int& days, int& year) {
    std::cout << "El mes " << month << " tuvo en el año " << year << ", " << days << " días"<< std::endl;
}

void correct_month(int& number_of_month) {

    int days{0};

    switch (number_of_month) {

        case 1:  case 3:  case 5:  case 7:  case 8:  case 10:  case 12:
        days = 31;
        number_of_days(number_of_month, days);
        break;

        case 4:  case 6:  case 9:  case 11:
        days = 30;
        number_of_days(number_of_month, days);
        break;
    }     
}

void correct_month2(int& number_of_month) {
    int actual_year{0};

    std::cout << "Como has elegido el mes de febrero, ¿te tengo que preguntar de que año es el mes de febrero del que quieres saber sus días?: ";
    std::cin >> actual_year;

    if (!(actual_year % 100 == 0) && (actual_year % 4 == 0) || ((actual_year % 400 == 0))) {
        int days{29};
        number_of_days2(number_of_month, days, actual_year);
    }
    else {
        int days{28};
        number_of_days2(number_of_month, days, actual_year);
    }
}