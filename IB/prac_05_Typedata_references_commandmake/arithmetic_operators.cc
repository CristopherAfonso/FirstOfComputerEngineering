#include <iostream>

int main () {

    double epsilon{0.00000000001};
    int variable_1{35};
    int variable_2{7};

    
    std::cout << "Soy un programa que te mostrará todas las posibles operaciones aritméticas que C++ permite realizar sobre variables de tipo 'int'" << std::endl;
    std::cout << "Tenemos dos variable de tipo 'int', que son: " << variable_1 << ", " << variable_2 << std::endl << std::endl;
    
    std::cout << "Ahora voy a proceder a mostrar el resultado de todas las operaciones aritméticas existentes:" << std::endl << std::endl;

    std::cout << "El resultado de operar +" << variable_1 << " es: " << +variable_1 << std::endl;
    std::cout << "El resultado de operar -" << variable_1 << " es: " << -variable_1 << std::endl;
    std::cout << "El resultado de operar " << variable_1 << " + " << variable_2 << " es: " << variable_1 + variable_2 << std::endl;
    std::cout << "El resultado de operar " << variable_1 << " - " << variable_2 << " es: " << variable_1 - variable_2 << std::endl;
    std::cout << "El resultado de operar " << variable_1 << " * " << variable_2 << " es: " << variable_1 * variable_2 << std::endl;
    std::cout << "El resultado de operar " << variable_1 << " / " << variable_2 << " es: " << variable_1 / variable_2 << std::endl;
    std::cout << "El resultado de operar " << variable_1 << " % " << variable_2 << " es: " << variable_1 % variable_2 << std::endl;
    std::cout << "El resultado de operar ~" << variable_1 << " es: " << ~variable_1 << std::endl;
    std::cout << "El resultado de operar " << variable_1 << " & " << variable_2 << " es: " << (variable_1 & variable_2) << std::endl;
    std::cout << "El resultado de operar " << variable_1 << " | " << variable_2 << " es: " << (variable_1 | variable_2) << std::endl;
    std::cout << "El resultado de operar " << variable_1 << " ^ " << variable_2 << " es: " << (variable_1 ^ variable_2) << std::endl;
    std::cout << "El resultado de operar " << variable_1 << " << " << variable_2 << " es: " << (variable_1 << variable_2) << std::endl;
    std::cout << "El resultado de operar " << variable_1 << " >> " << variable_2 << " es: " << (variable_1 >> variable_2) << std::endl << std::endl;

    std::cout << "Hasta ahora he usado solo números enteros, pero si tratamos con números con decimales (floats ó doubles) no salen resultados tan fáciles de calcular" << std::endl;
    std::cout << "porque int(35), no es igual al float(35), ni al double(35), ni estos son iguales entres sí" << std::endl;
    std::cout << "Sus primeros dígitos si lo son, pero los últimos no lo son" << std::endl;
    std::cout << "por eso int(35)!=float(35)!=double(35)" << std::endl << std::endl;
    std::cout << "Pero para evitarnos estos errores al hacer operaciones con doubles o floats, tenemos a epsilon" << std::endl;
    std::cout << "epsilon es una variable la cual nosotros podemos darle un valor (debe ser muy pequeño) y nos permite calcular si dos floats ó doubles son iguales (la variable no tiene necesariamente que llamarse epsilon, pero es el nombre general que recibe)"
    << "epsilon se puede declara como una variable o llamando al preprocesador con '#define', seguido del nombre de la variable y seguido de su valor" << std::endl;
    std::cout << "si epsilon vale 0.000000001 y queremos calcular si la variable 'a' es igual a la variable 'b', siendo 'a' y 'b' floats o doubles, entonces deberíamos hacer una desigualdad para averiguarlo, como esta:" << std::endl << std::endl;
    std::cout << " fabs(a - b) < epsilon" << std::endl << std::endl;
    std::cout << "fabs toma el valor absoluto de la resta, y si el valor es menor a epsilon podríamos considerar que son iguales 'a' y 'b'" << std::endl;
    std::cout << "y sabiendo si son iguales o no, podríamos seguir haciendo operaciones sin que estas no den un error por operar con doubles ó floats" << std::endl;

    return 0;
}