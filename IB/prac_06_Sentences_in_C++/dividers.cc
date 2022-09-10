#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

int main () {
    int number_to_divide;
    int divider;
    std::string number_to_divide_into_text;

    std::cout << "Hola, soy un programa que muestra por pantalla todos los divisores de un número natural que tú me des" << std::endl;
    std::cout << "Eso quiere decir que si me das un número como 6 (cuando te lo pida, que será en breve) te devolveré por pantalla los números: 1, 2, 3, 6" << std::endl;
    std::cout << "Como esos 4 números son los divisores de 6, por eso serán lo que te mostraré en pantalla" << std::endl;
    std::cout << "Ahora bien, te voy a pedir un número natural, y te devolveré sus divisores, pero te diré esto para que quede claro" << std::endl;
    std::cout << "Si me das un número decimal lo truncaré (haŕe como que no he visto sus decimales), y si me das un número negativo me quedaré con su valor absoluto y será el que operaré" << std::endl << std::endl;
    std::cout << "Ahora que ya sabes esto, dime, ¿cual es el número que tú quieres que calcule sus divisores? ";
    getline(std::cin, number_to_divide_into_text);
    std::stringstream(number_to_divide_into_text) >> number_to_divide;
    number_to_divide = fabs(number_to_divide);

    std::cout << std::endl;

    
    std::cout << std::endl;

    if (number_to_divide == 0) {
        std::cout << "Lo siento, has elegido el único número que no tiene divisores, el cero es especial en ese sentido :'(" << std::endl;
    }
    else {
        std::cout << "El número que operaré será " << number_to_divide << std::endl << std::endl;
        std::cout << "Y sus divisores son: ";

        for(int i = 1; i <= number_to_divide; ++i) {
            divider = number_to_divide % i;
               
            if (divider == 0) {
                std::cout << i << ' ';
            }
        }
        std::cout << std::endl;

    }

   return 0;
}