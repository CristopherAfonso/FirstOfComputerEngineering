#include <iostream>
#include <string>
#include <sstream>

int main () {
    int number_to_compute;
    std::string number_to_compute_into_text;

    std::cout << "Hola, soy un programa diseñado para calcular la Secuencia Collatz de un número entero que tú me des" << std::endl;
    std::cout << "Esta secuencia consiste en que dado un número entero cualquiera, si le aplicamos sucesivas operaciones a este número" << std::endl;
    std::cout << "Al final su resultado tras estas operaciones será la unidad (es decir, 1)" << std::endl;
    std::cout << "Si el número es par, se dividirá entre dos, y si es impar, se multiplicará por tres y se le sumará uno" << std::endl;
    std::cout << "Estas dos formulas se aplicarán al número hasta que dé 1 (ó -1 si me das un número negativo)" << std::endl;
    std::cout << "Y cuando me dés el números que quieres que le aplique la Secuencia Collatz" << std::endl;
    std::cout << "Te mostraré por pantalla todos los valores de las operaciones que se le aplican al número hasta llegar al 1" << std::endl << std::endl;

    std::cout << "Antes de pedirte el número te tengo que avisar que esta Seucencia solo es válida para números enteros, con lo cual" << std::endl;
    std::cout << "Si me das un número decimal, lo truncaré y haré como que no he visto ni un solo decimal, puedes poner decimales pero no los tendré en cuenta" << std::endl;
    std::cout << "Pero si me das un número negativo, la única diferencia es que en vez de llegar a 1 como resultado final, llegaré al -1" << std::endl << std::endl;

    std::cout << "Ya he hablado suficiente, ahora bien, ¿cuál es el número que quieres que le aplique la Secuencia Collatz? ";
    getline(std::cin, number_to_compute_into_text);
    std::stringstream(number_to_compute_into_text) >> number_to_compute;


    if ((number_to_compute > 0) || (number_to_compute < 0)) {

        std::cout << "El número que me has dado es: " << number_to_compute << std::endl << std::endl;

        std::cout << "Su Secuencia Collatz es: " << number_to_compute << ' ';

        while((number_to_compute !=1) && (number_to_compute !=-1)) {
            if (number_to_compute % 2 == 0) {
                number_to_compute /= 2;
                std::cout << number_to_compute << ' ';
            }
            else {
                number_to_compute = number_to_compute * 3 + 1;
                std::cout << number_to_compute << ' ';
            }
        }
    }
    else {
        std::cout << "Lo siento, el número 0 es el único número al que no le puedo calcular su Secuencia Collatz, lo siento :'(";
    }
    
    std::cout << std::endl;
    
    return 0;
}
