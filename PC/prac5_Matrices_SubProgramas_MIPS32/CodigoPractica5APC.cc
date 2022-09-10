// Programa en C++ de la Práctica 5A de la asignatura PC
#include <iostream>
#include <vector>

void ShowMatrix(std::vector<int> matrix, int nrows, int ncols) { // metodo que muestra una matríz de enteros por pantalla
    std::cout << std::endl;
    int counter{0};

    for(int i{0}; i < nrows; ++i) { // este for muestra uno a uno, los valores fila por fila, de izquierda a derecha de la matriz
        for(int j{0}; j < ncols; ++j) {
            std::cout << "   " << matrix[counter];
            ++counter;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}

std::vector<int> RowsSwap(std::vector<int> matrix, int nrows, int ncols,
              int row1, int row2) { // este método intercambia dos filas seleccionadas por el usuario
    std::vector<int> aux_vec1;
    std::vector<int> aux_vec2;
    aux_vec1.resize(nrows);
    aux_vec2.resize(nrows);

    for(int i{0}; i < ncols; ++i) {           // en este for, copiamos las dos filas seleccionadas a dos vectores auxiliares,
        aux_vec1[i] = matrix[nrows*row1 + i]; 
        aux_vec2[i] = matrix[nrows*row2 + i];
    }
    for(int i{0}; i < ncols; ++i) {           // en este for, cogemos los valores de los vectores, y si un vector cogió los datos
        matrix[nrows*row1 + i] = aux_vec2[i]; // de una fila, con los datos que tiene, reescribe la otr fila
        matrix[nrows*row2 + i] = aux_vec1[i];
    }
    return matrix;
}

std::vector<int> ColumnSwap(std::vector<int> matrix, int nrows, int ncols,
                int col1, int col2) { // este método intercambia dos columnas seleccionadas por el usuario,
                                      // sigue la misma metodología que la función RowsSwap(), pero con las columnas
    std::vector<int> aux_vec1;
    std::vector<int> aux_vec2;
    aux_vec1.resize(ncols);
    aux_vec2.resize(ncols);

    for(int i{0}; i < nrows; ++i) {
        aux_vec1[i] = matrix[col1 + nrows*i];
        aux_vec2[i] = matrix[col2 + nrows*i];
    }
    for(int i{nrows -1}; i >= 0; --i) {
        matrix[col1 + nrows*i] = aux_vec2[i];
        matrix[col2 + nrows*i] = aux_vec1[i];
    }
    return matrix;
}

std::vector<int> InvertColumn(std::vector<int> matrix,
                  int ncols, int nrows, int col1) { // este método invierte una columna elegida por el usuario
    std::vector<int> aux_vec1;
    std::vector<int> aux_vec2;
    aux_vec1.resize(ncols);
    aux_vec2.resize(ncols);

    for(int i{0}; i < nrows; ++i) { // este for copia la columna elegida a un vector auxiliar
        aux_vec1[i] = matrix[col1 + nrows*i];
    }
    for(int i{nrows - 1}, j{0}; i >= 0; --i, ++j) { // este for coge el vector auxiliar, y reescribe la columna
        matrix[col1 + nrows*j] = aux_vec1[i];       // del usuario con sus valores invertidos
    }
    return matrix;
}

int main() {
    std::vector<int> Matrix;   // Vector que almacena la matriz implementada
    Matrix.resize(100);        // Establecemos el tamaño máximo de la matriz
    int nrows{0};              // Declaramos dos variables donde guardo las
    int ncols{0};              // filas y columnas de la matriz
    int operation_code{1};     // Esta variable la usamos al final, la declaramos a 1, porque un while al final, evalua si esta
                               // si esta variable es cero, y si es distinto de cero, entra al while, así me aseguro que entre
                               // lo hago así, porque dentro del while, hay un if, y con el DoWhile tuve problemas, así no los hay
    std::cout << std::endl;
    std::cout << "Soy un programa que almacena una matriz dada" << std::endl;
    std::cout << "por el usuario y permite hacer operaciones con" << std::endl;
    std::cout << "sus filas y columnas. Por defecto, la matriz" << std::endl;
    std::cout << "tiene un tamaño máximo de 10 filas y columnas," << std::endl;  // strings de bienvenida y explicación de como funciona el programa
    std::cout << "puedes readimensionar la matriz para hacer sus" << std::endl;
    std::cout << "filas y columnas más pequeñas, no más grandes" << std::endl << std::endl;

    std::cout << "¿nº filas? ";
    std::cin >> nrows;
    std::cout << "¿nº columnas? ";
    std::cin >> ncols;

    while(nrows > 10 || nrows < 1 || ncols > 10 || ncols < 1) { // si la cantidad de filas o columnas es negativa o superior a 10, se vuelve a pedir el dato
        std::cout << std::endl;
        std::cout << "Error en la asignación, ingrese datos válidos: " << std::endl;
        std::cout << "¿nº filas? ";
        std::cin >> nrows;
        std::cout << "¿nº columnas? ";
        std::cin >> ncols;
    }

    std::cout << std::endl << std::endl;
    Matrix.resize(nrows*ncols); // readimensionamos la matriz para optimizar recursos
    int counter{0};

    for(int i{0}; i < nrows; ++i) { // este for pide uno a uno, los valores fila por fila, de izquierda a derecha de la matriz
        for(int j{0}; j < ncols; ++j) {
            std::cout << "¿Valor de la posición(" << i << ", " << j << ")? ";
            std::cin >> Matrix[counter];
            ++counter;
        }
        std::cout << std::endl;
    }
    ShowMatrix(Matrix, nrows, ncols); // funcion que muestra la matriz por pantalla
    std::cout << "La matriz puede modificarse por el usuario" << std::endl;

    while(operation_code != 0) {
        operation_code = 0;
        std::cout << "Escribe 1 para intercambiar dos filas" << std::endl;
        std::cout << "Escribe 2 para intercambiar dos columnas" << std::endl;
        std::cout << "Escribe 3 para invertir una columna" << std::endl;
        std::cout << "Escribe 0 para salir del programa" << std::endl << std::endl;
        std::cout << "Código de la operación: ";
        std::cin >> operation_code; // se pide un número para hacer alguna de las 4 operaciones disponibles

        while((operation_code < 0) || (operation_code > 3)) { // si el número no es válido, se vuelve a pedir
            std::cout << "Error al leer la operación" << std::endl;
            std::cout << "Ingresa un dato válido: ";
            std::cin >> operation_code;
            std::cout << std::endl;
        }

        if(operation_code != 0) { // si el número es cero se termina el programa y ni se evaluan el resto de casos
                                  // así ahorramos tiempos de ejecución
            int line1{-1}; // establezco estos valores por defecto, porque son valores que no se le pueden pasar a 
            int line2{-1}; // las funciones, así, si hay algún en la asignación de valores en el main, lo sabré

            if(operation_code == 1) {
                if(nrows == 1) {
                    std::cout << std::endl;
                    std::cout << "Solo hay una fila, no puedes hacer esta operación" << std::endl;
                    continue;
                }
                do {
                    std::cout << "¿1º fila? ";
                    std::cin >> line1;
                    std::cout << "¿2º fila? ";
                    std::cin >> line2;
                    std::cout << std::endl;
                    if((line1 < 0) || (line1 > (nrows-1)) || 
                       (line2 < 0) || (line2 > (nrows-1)) ||
                       (line1 == line2)) { 
                           std::cout << "Error en parámetros" << std::endl;
                           std::cout << "ingrese datos válidos" << std::endl;
                           line1 = -1;
                           line2 = -1;
                    }
                }while((line1 < 0) || (line1 > (nrows-1)) || 
                       (line2 < 0) || (line2 > (nrows-1)) ||
                       (line1 == line2)); // si las filas elegidas son inválidas o iguales, se reitera
                Matrix = RowsSwap(Matrix, nrows, ncols, line1, line2);
            }

            if(operation_code == 2) {
                if(ncols == 1) {
                    std::cout << std::endl;
                    std::cout << "Solo hay una columna, no puedes hacer esta operación" << std::endl;
                    continue;
                }
                do {
                    std::cout << "¿1º columna? ";
                    std::cin >> line1;
                    std::cout << "¿2º columna? ";
                    std::cin >> line2;
                    std::cout << std::endl;
                    if((line1 < 0) || (line1 > (ncols-1)) || 
                       (line2 < 0) || (line2 > (ncols-1)) ||
                       (line1 == line2)) {
                           std::cout << "Error en parámetros" << std::endl;
                           std::cout << "ingrese datos válidos" << std::endl;
                           line1 = -1;
                           line2 = -1;
                    }
                }while((line1 < 0) || (line1 > (ncols-1)) || 
                       (line2 < 0) || (line2 > (ncols-1)) ||
                       (line1 == line2)); // si las columnas elegidas son inválidas o iguales, se reitera
                Matrix = ColumnSwap(Matrix, nrows, ncols, line1, line2);
            }
            
            if(operation_code == 3) {
                do {
                    std::cout << "¿columna a invertir? ";
                    std::cin >> line1;
                    std::cout << std::endl;
                    if((line1 < 0) || (line1 > (ncols-1))) {
                           std::cout << "Error en parámetros" << std::endl;
                           std::cout << "ingrese datos válidos" << std::endl;
                           line1 = -1;
                    }
                }while((line1 < 0) || (line1 > (ncols-1))); // si la columna elegida es inválida, se reitera
                Matrix = InvertColumn(Matrix, nrows, ncols, line1);
            }
            ShowMatrix(Matrix, nrows, ncols);
        }
    }

    return 0;
}