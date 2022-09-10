// Programa en C++ de la Práctica 5B de la asignatura PC
#include <iostream>
#include <vector>

void ShowResults(std::vector<int>& enteros, std::vector<double>& dobles, int& limit) {
    int counter1{0};
    int counter2{0};

    std::cout << "\n\n                     Tabla de Resultados\n\n";
    std::cout << "               Valor n  -  Valor x  -  Result\n";

    for(int i{0}; i < limit; ++i) {
        if(i != 9) {std::cout << " ";}
        std::cout << i+1 << "º Resultado:    " << enteros[counter1] << "           ";
        std::cout << dobles[counter2] << "          " << dobles[++counter2] << std::endl;
        ++counter1;
        ++counter2;
    }
}

double fi(int n, double& x) {
    double result{0.00};
    double prev_1 = 0.5;
    double prev_2 = 1;
    if (n == 0) {
        return prev_1;
    }
    if (n == 1) {
        return prev_2;
    }
    if (n >= 2) {
        for (int i = 2; i <= n; ++i) {
            result = prev_1 * prev_2 * x;
            prev_1 = prev_2;
            prev_2 = result;
        }
    }
    return result;
}

double fr(int n, double& x) {
    double result{0.00};

    // Casos triviales
    if(n == 0) { return result = 0.5; }
    if(n == 1) { return result = 1; }

    // Caso No Trivial
    if(n > 1) { result = (fr(n-1,x) * fr(n-2,x) * x); }

    return result;
}

int main() {
    std::cout << "\nHola, soy un programa que implementa la siguiente\n";
    std::cout << "Función matemática:\n\n";
    std::cout << "           {     0,5                        si  n = 0\n";
    std::cout << "  f(n,x) = {     1                          si  n = 1\n";
    std::cout << "           { f(n - 1, x)*f(n - 2, x)*x      si  n > 1\n\n";
    std::cout << "Donde 'n' es un número entero mayor o igual a 0\n";
    std::cout << "y 'x' e 'f(n,x)' flotantes en doble precisión\n\n";
    std::cout << "Este programa permite ejecutar esta función de dos formas\n";
    std::cout << "distintas, de forma iterativa (llamando a la función solo\n";
    std::cout << "una vez), y de forma recursiva (la función se llama a sí\n";
    std::cout << "misma continuamente hasta llegar al caso trivial). Esta\n";
    std::cout << "función también guarda en memoria, el resultado de los 10\n";
    std::cout << "últimos resultados que haya dado la fórmula tras ser\n";
    std::cout << "ejecutada por el usuario, ya sea con la forma iterativa\n";
    std::cout << "o recursiva\n\n";

    int option{1};
    int times{0};
    int limit{0};
    std::vector<int> ten_first_n;
    std::vector<double> twenty_first_doubles;
    ten_first_n.resize(10);
    twenty_first_doubles.resize(20);

    while(option != 0) {
        std::cout << "Introduzca opción: <1> Iterativa - <2> Recursiva - <0> Salir: " ;
        std::cin >> option;
        std::cout << std::endl;

        while(option < 0 || option > 2) {
            option = 0; // Ponemos la variable a cero, por si no se lee ningún número, se salga automáticamente

            std::cout << "Número erroneo, ingrese el dato de nuevo\n";
            std::cout << "Introduzca opción: <1> Iterativa - <2> Recursiva - <0> Salir: " ;
            std::cin >> option;
            std::cout << std::endl << std::endl;
        }

        if(option == 1) {
            int n{0};
            double x{0.00};
            double result{0.00};

            std::cout << "Introduzca el valor de n: "; 
            std::cin >> n;
            while(n < 0) {
                std::cout << "Valor negativo no permitido, ingrese un valor válido: ";
                std::cin >> n;
            }
            std::cout << "Introduzca el valor de x: ";
            std::cin >> x;
            std::cout << std::endl;

            result = fi(n, x);

            if(times >= 0 && times <= 9) {
                ten_first_n[times] = n;
                twenty_first_doubles[2*times] = x;
                twenty_first_doubles[2*times+1] = result;
                ++limit;
            }
        }

        if(option == 2) {
            int n{0};
            double x{0.00};
            double result{0.00};

            std::cout << "Introduzca el valor de n: "; 
            std::cin >> n;
            while(n < 0) {
                std::cout << "Valor negativo no permitido, ingrese un valor válido: ";
                std::cin >> n;
            }
            std::cout << "Introduzca el valor de x: ";
            std::cin >> x;
            std::cout << std::endl;

            result = fr(n, x);

            if(times >= 0 && times <= 9) {
                ten_first_n[times] = n;
                twenty_first_doubles[2*times] = x;
                twenty_first_doubles[2*times+1] = result;
                ++limit;
            }
        }
        ++times;
    }

    ShowResults(ten_first_n, twenty_first_doubles, limit);
    std::cout << "\nFin del Programa\n\n";

    return 0;
}
