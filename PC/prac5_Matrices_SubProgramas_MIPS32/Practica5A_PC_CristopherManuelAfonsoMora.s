# Practica 5A. Principio de computadoras 
# Creador: Cristopher Manuel Afonso Mora
# OBJETIVO: realizar en ensamblador un programa que dada una matriz de enteros definida en memoria 
# Te permita intercambiar una fila por otra, o una columna por otra.
#
# Adjunto en comentarios a continuación, el Pseudocódigo en C++ hecho por mí,
# que seguí para hacer mejor, más rápido y fácil esta práctica 5A
#
#
#
#
#// Programa en C++ de la Práctica 5A de la asignatura PC
#include <iostream>
#include <vector>
#
#void ShowMatrix(std::vector<int>& matrix, int& nrows, int& ncols) { // metodo que muestra una matríz de enteros por pantalla
#    std::cout << std::endl;
#    int counter{0};
#
#    for(int i{0}; i < nrows; ++i) { // este for muestra uno a uno, los valores fila por fila, de izquierda a derecha de la matriz
#        for(int j{0}; j < ncols; ++j) {
#            std::cout << "   " << matrix[counter];
#            ++counter;
#        }
#        std::cout << std::endl;
#    }
#    std::cout << std::endl << std::endl;
#}
#
#void RowsSwap(std::vector<int>& matrix, int& nrows, int& ncols,
#              int& row1, int& row2) { // este método intercambia dos filas seleccionadas por el usuario
#    std::vector<int> aux_vec1;
#    std::vector<int> aux_vec2;
#    aux_vec1.resize(nrows);
#    aux_vec2.resize(nrows);
#
#    for(int i{0}; i < ncols; ++i) {           // en este for, copiamos las dos filas seleccionadas a dos vectores auxiliares,
#        aux_vec1[i] = matrix[nrows*row1 + i]; 
#        aux_vec2[i] = matrix[nrows*row2 + i];
#    }
#    for(int i{0}; i < ncols; ++i) {           // en este for, cogemos los valores de los vectores, y si un vector cogió los datos
#        matrix[nrows*row1 + i] = aux_vec2[i]; // de una fila, con los datos que tiene, reescribe la otr fila
#        matrix[nrows*row2 + i] = aux_vec1[i];
#    }
#}
#
#void ColumnSwap(std::vector<int>& matrix, int& nrows, int& ncols,
#                int& col1, int& col2) { // este método intercambia dos columnas seleccionadas por el usuario,
#                                      // sigue la misma metodología que la función RowsSwap(), pero con las columnas
#    std::vector<int> aux_vec1;
#    std::vector<int> aux_vec2;
#    aux_vec1.resize(ncols);
#    aux_vec2.resize(ncols);
#
#    for(int i{0}; i < nrows; ++i) {
#        aux_vec1[i] = matrix[col1 + nrows*i];
#        aux_vec2[i] = matrix[col2 + nrows*i];
#    }
#    for(int i{nrows -1}; i >= 0; --i) {
#        matrix[col1 + nrows*i] = aux_vec2[i];
#        matrix[col2 + nrows*i] = aux_vec1[i];
#    }
#}
#
#int main() {
#    std::vector<int> Matrix;   // Vector que almacena la matriz implementada
#    Matrix.resize(100);        // Establecemos el tamaño máximo de la matriz
#    int nrows{0};              // Declaramos dos variables donde guardo las
#    int ncols{0};              // filas y columnas de la matriz
#    int operation_code{1};     // Esta variable la usamos al final, la declaramos a 1, porque un while al final, evalua si esta
#                               // si esta variable es cero, y si es distinto de cero, entra al while, así me aseguro que entre
#                               // lo hago así, porque dentro del while, hay un if, y con el DoWhile tuve problemas, así no los hay
#    std::cout << std::endl;
#    std::cout << "Soy un programa que almacena una matriz dada" << std::endl;
#    std::cout << "por el usuario y permite hacer operaciones con" << std::endl;
#    std::cout << "sus filas y columnas. Por defecto, la matriz" << std::endl;
#    std::cout << "tiene un tamaño máximo de 10 filas y columnas," << std::endl;  // strings de bienvenida y explicación de como funciona el programa
#    std::cout << "puedes readimensionar la matriz para hacer sus" << std::endl;
#    std::cout << "filas y columnas más pequeñas, no más grandes" << std::endl << std::endl;
#
#    std::cout << "¿nº filas? ";
#    std::cin >> nrows;
#    std::cout << "¿nº columnas? ";
#    std::cin >> ncols;
#
#    while(nrows > 10 || nrows < 1 || ncols > 10 || ncols < 1) { // si la cantidad de filas o columnas es negativa o superior a 10, se vuelve a pedir el dato
#        std::cout << std::endl;
#        std::cout << "Error en la asignación, ingrese datos válidos: " << std::endl;
#        std::cout << "¿nº filas? ";
#        std::cin >> nrows;
#        std::cout << "¿nº columnas? ";
#        std::cin >> ncols;
#    }
#
#    std::cout << std::endl << std::endl;
#    Matrix.resize(nrows*ncols); // readimensionamos la matriz para optimizar recursos
#    int counter{0};
#
#    for(int i{0}; i < nrows; ++i) { // estos for pide uno a uno, los valores fila por fila, de izquierda a derecha de la matriz
#        for(int j{0}; j < ncols; ++j) {
#            std::cout << "¿Valor de la posición(" << i << ", " << j << ")? ";
#            std::cin >> Matrix[counter];
#            ++counter;
#        }
#        std::cout << std::endl;
#    }
#    ShowMatrix(Matrix, nrows, ncols); // funcion que muestra la matriz por pantalla
#    std::cout << "La matriz puede modificarse por el usuario" << std::endl;
#
#    while(operation_code != 0) {
#        operation_code = 0;
#        std::cout << "Escribe 1 para intercambiar dos filas" << std::endl;
#        std::cout << "Escribe 2 para intercambiar dos columnas" << std::endl;
#        std::cout << "Escribe 0 para salir del programa" << std::endl << std::endl;
#        std::cout << "Código de la operación: ";
#        std::cin >> operation_code; // se pide un número para hacer alguna de las 4 operaciones disponibles
#
#        while((operation_code < 0) || (operation_code > 2)) { // si el número no es válido, se vuelve a pedir
#            std::cout << "Error al leer la operación" << std::endl;
#            std::cout << "Ingresa un dato válido: ";
#            std::cin >> operation_code;
#            std::cout << std::endl;
#        }
#
#        if(operation_code != 0) { // si el número es cero se termina el programa y ni se evaluan el resto de casos
#                                  // así ahorramos tiempos de ejecución
#            int line1{-1}; // establezco estos valores por defecto, porque son valores que no se le pueden pasar a 
#            int line2{-1}; // las funciones, así, si hay algún en la asignación de valores en el main, lo sabré
#
#            if(operation_code == 1) {
#                if(nrows == 1) {
#                    std::cout << std::endl;
#                    std::cout << "Solo hay una fila, no puedes hacer esta operación" << std::endl;
#                    continue;
#                }
#                do {
#                    std::cout << "¿1º fila? ";
#                    std::cin >> line1;
#                    std::cout << "¿2º fila? ";
#                    std::cin >> line2;
#                    std::cout << std::endl;
#                    if((line1 < 0) || (line1 > (nrows-1)) || 
#                       (line2 < 0) || (line2 > (nrows-1)) ||
#                       (line1 == line2)) { 
#                           std::cout << "Error en parámetros" << std::endl;
#                           std::cout << "ingrese datos válidos" << std::endl;
#                           line1 = -1;
#                           line2 = -1;
#                    }
#                }while((line1 < 0) || (line1 > (nrows-1)) || 
#                       (line2 < 0) || (line2 > (nrows-1)) ||
#                       (line1 == line2)); // si las filas elegidas son inválidas o iguales, se reitera
#                Matrix = RowsSwap(Matrix, nrows, ncols, line1, line2);
#            }
#
#            if(operation_code == 2) {
#                if(ncols == 1) {
#                    std::cout << std::endl;
#                    std::cout << "Solo hay una columna, no puedes hacer esta operación" << std::endl;
#                    continue;
#                }
#                do {
#                    std::cout << "¿1º columna? ";
#                    std::cin >> line1;
#                    std::cout << "¿2º columna? ";
#                    std::cin >> line2;
#                    std::cout << std::endl;
#                    if((line1 < 0) || (line1 > (ncols-1)) || 
#                       (line2 < 0) || (line2 > (ncols-1)) ||
#                       (line1 == line2)) {
#                           std::cout << "Error en parámetros" << std::endl;
#                           std::cout << "ingrese datos válidos" << std::endl;
#                           line1 = -1;
#                           line2 = -1;
#                    }
#                }while((line1 < 0) || (line1 > (ncols-1)) || 
#                       (line2 < 0) || (line2 > (ncols-1)) ||
#                       (line1 == line2)); // si las columnas elegidas son inválidas o iguales, se reitera
#                ColumnSwap(Matrix, nrows, ncols, line1, line2);
#            }
#            ShowMatrix(Matrix, nrows, ncols);
#        }
#    }
#
#    return 0;
#}
#
size = 4 # bytes que ocupa cada elemento
                        .data       #Directica que indica la zona de datos
FinDeLinea:             .asciiz     "\n"
FinDobleLinea:          .asciiz     "\n\n"
Titulo:                 .asciiz     "\nSoy un programa que almacena una matriz dada\npor el usuario y permite hacer operaciones con\nsus filas y columnas. Por defecto, la matriz\ntiene un tamaño máximo de 10 filas y columnas,\npuedes readimensionar la matriz para hacer sus\nfilas y columnas más pequeñas, no más grandes\n\n"
PregFilas:              .asciiz     "¿nº Filas? "
PregColumnas:           .asciiz     "¿nº Columnas? "
ErrorAsignacion:        .asciiz     "Error en la asignación, ingrese datos válidos: \n"
ValPos1:                .asciiz     "¿Valor de la posición("
ValPos2:                .asciiz     ", "
ValPos3:                .asciiz     ")? "
Space:                  .asciiz     "   "
PoderModif:             .asciiz     "La matriz puede modificarse por el usuario\n"
Instrucciones:          .asciiz     "\nEscribe 1 para intercambiar dos filas\nEscribe 2 para intercambiar dos columnas\nEscribe 0 para salir del programa\n\nCódigo de la operación: "
ErrorOperacion:         .asciiz     "\nError al leer la operación\nIngresa un dato válido: "
ErrorUnaFila:           .asciiz     "Solo hay una fila, no puedes hacer esta operación"
ErrorUnaColumna:        .asciiz     "Solo hay una columna, no puedes hacer esta operación"
ErrorParametros:        .asciiz     "Error en parámetros\ningrese datos válidos\n"
Fila1:                  .asciiz     "¿1º Fila? "
Fila2:                  .asciiz     "¿2º Fila? "
Columna1:               .asciiz     "¿1º Columna? "
Columna2:               .asciiz     "¿2º Columna? "
FinPrograma:            .asciiz     "\n\nFin Del Programa\n"


                        .align           2    #Directiva para alinear las posiciones en memoria de matrix:
matrix:                 .space         400
nrows:                  .word            0
ncols:                  .word            0
                        .align           2
aux_vec1:               .space          40
                        .align           2
aux_vec2:               .space          40
operationcode:          .word            0
kConstante11:           .word           11


# Registros que actuarán como las variables
#
# Nota Importante: la variable int counter en MIPS no me hizo falta, está en el programa de C++, pero en este programa MIPS no la usé
# $s0 = std::vector<int> Matrix
# $s1 = int nrows
# $s2 = int ncols
# $s3 = int operation_code
# $s4 = int line1 // en la función ShowMatrix, uso los registros $s4-$s7 para la iteración de dos for
# $s5 = int line2 // y en el resto de funciones, solo uso el registro $s4
# $s6 = std::vector<int> aux_vec1 // En las funciones RowsSwap, ColumnSwap
# $s7 = std::vector<int> aux_vec2 // es donde usaré estos registros
# 

                        .text
#
#void ShowMatrix(std::vector<int>& matrix, int& nrows, int& ncols) { // metodo que muestra una matríz de enteros por pantalla
#    std::cout << std::endl;
#    int counter{0};
#
#    for(int i{0}; i < nrows; ++i) { // este for muestra uno a uno, los valores fila por fila, de izquierda a derecha de la matriz
#        for(int j{0}; j < ncols; ++j) {
#            std::cout << "   " << matrix[counter];
#            ++counter;
#        }
#        std::cout << std::endl;
#    }
#    std::cout << std::endl << std::endl;
#}
#
ShowMatrix:
    addi $sp,$sp,-32                        #Hacemos espacio en la pila para 8 variables
    sw $s7,28($sp)
    sw $s6,24($sp)                          #Guardo en la pila, los valores de los 4 registros $s que uso
    sw $s5,20($sp)                          #Uso registros salvados en la función, porque uso el syscall, y si usara registros $t, no se guardarían sus valores
    sw $s4,16($sp)
    sw $s3,12($sp)                          #Guardo en la pila la dirección de operation_code
    sw $a2,8($sp)                           #Guardo el valor de ncols
    sw $a1,4($sp)                           #Guarda el valor de nrows
    sw $a0,0($sp)                           #Guardo en la pila, la dirección de Matrix
                                            #Guargo los parámetros en la pila, para que no se pierdan al hacer el syscall 
    move $s3,$a0                            #Muevo el valor de matrix a $s3, para usarlo como variable en el for
                                            
    la $a0,FinDeLinea
    li $v0,4                                #Le digo al sistema que muestre un string
    syscall
                                            #Debería declarar counter, pero como en los dos for uso la pila, no lo necesito
    move $s4,$zero                          #Declaro "i" en un registro salvado para no perder su valor al usar syscall
    lw $s5,4($sp)
    For3:
        bge $s4,$s5,FinFor3                 #Comparo i < nrows

        move $s6,$zero                      #Declaro "j" en un registro salvado para no perder su valor al usar syscall
        lw $s7,8($sp)
        For4:
            bge $s6,$s7,FinFor4             #Comparo j < ncols

            la $a0,Space
            li $v0,4                        #Le digo al sistema que muestre un string
            syscall

            lw $t0,0($s3)                   #Cargo desde $s3 usando la dirección de memoria de matrix, el número a imprimir en $t0
            move $a0,$t0                    #Cargo en $a0, el primer número no mostrado de Matrix
            li $v0,1                        #Le digo al sistema que muestre un int
            syscall    
            addi $s3,$s3,4                  #Le sumo a la dirección base de Matrix, 4 bytes para que la siguiente vez muestre el siguiente número

                                            #Debería hacer ++counter, pero no lo necesito en MIPS
            addi $s6,$s6,1                  # ++j

            b   For4

        FinFor4:
        
        la $a0,FinDeLinea
        li $v0,4                            #Le digo al sistema que muestre un string
        syscall
        addi $s4,$s4,1                      # ++i

        b   For3

    FinFor3:

    la $a0,FinDobleLinea
    li $v0,4                                #Le digo al sistema que imprima un string        
    syscall

    lw $s7,28($sp)
    lw $s6,24($sp)                          #Cargo en la pila, los valores de los 4 registros $s que uso
    lw $s5,20($sp)
    lw $s4,16($sp)
    lw $s3,12($sp)                          #Cargo el valor de la dirección de operation_code
    lw $a2,8($sp)                           #Cargo el valor de ncols
    lw $a1,4($sp)                           #Cargo el valor de nrows
    lw $a0,0($sp)                           #Cargo de la pila, el valor de matrix al registro de donde vino
    addi $sp,$sp,32                         #Restablecemos la pila a su posición original

    jr $ra                                  #Esta instrucción me permite volver a la función main

#
#void RowsSwap(std::vector<int>& matrix, int& nrows, int& ncols,
#              int& row1, int& row2) { // este método intercambia dos filas seleccionadas por el usuario
#    std::vector<int> aux_vec1;
#    std::vector<int> aux_vec2;
#    aux_vec1.resize(nrows);
#    aux_vec2.resize(nrows);
#
#    for(int i{0}; i < ncols; ++i) {           // en este for, copiamos las dos filas seleccionadas a dos vectores auxiliares,
#        aux_vec1[i] = matrix[nrows*row1 + i]; 
#        aux_vec2[i] = matrix[nrows*row2 + i];
#    }
#    for(int i{0}; i < ncols; ++i) {           // en este for, cogemos los valores de los vectores, y si un vector cogió los datos
#        matrix[nrows*row1 + i] = aux_vec2[i]; // de una fila, con los datos que tiene, reescribe la otr fila
#        matrix[nrows*row2 + i] = aux_vec1[i];
#    }
#}
#
RowsSwap:
    addi $sp,$sp,-36            #Hago espacio en la pila para 9 variables, la variable line2 ya había sido puesta, así que está en la posición 36($sp)

                                #Valor line2 en 36($sp), aquí será row2
    sw $a3,32($sp)              #Valor line1, aquí será row1
    sw $a2,28($sp)              #Dirección ncols
    sw $a1,24($sp)              #Dirección de nrows
    sw $a0,20($sp)              #Dirección base original de la matriz
    sw $s4,16($sp)              #Variable "i" que usarán los dos for
    sw $s3,12($sp)              #Dirección de la matriz ubicada en la posición matrix[nrows*row2 + i]
    sw $s2,8($sp)               #Dirección de la matriz ubicada en la posición matrix[nrows*row1 + i]
    sw $s1,4($sp)               #Variable aux_vec2
    sw $s0,0($sp)               #Variable aux_vec1
    

    la $s0,aux_vec1             # Cargo la dirección de memoria de aux_vec1
    la $s1,aux_vec2             # Cargo la dirección de memoria de aux_vec2

    move $s2,$a0
    move $s3,$a0                # Cargo la dirección base de matrix en $s2 y $s3

    lw $t0,24($sp)
    lw $t0,0($t0)               # Cargo desde la pila, el valor de nrows
    lw $t1,32($sp)              # Cargo desde la pila, el valor de row1
    lw $t2,36($sp)              # Cargo desde la pila, el valor de row2

    mul $t2,$t2,$t0             # Hago nrows * row2, sobrescribiendo row2
    mul $t2,$t2,4               # Ahora tengo la cantidad de bytes que debo desplazarme
    mul $t1,$t1,$t0             # Hago nrows * row1, sobrescribiendo row1
    mul $t1,$t1,4               # Ahora tengo la cantidad de bytes que debo desplazarme

    addu $s2,$s2,$t1            # Guardo en $s2 la posición matrix[nrows*row1]
    addu $s3,$s3,$t2            # Guardo en $s3 la posición matrix[nrows*row2]

    move $s4,$zero              # Inicializamos la variable "i" a cero
    For5:
        lw $t0,28($sp)
        lw $t0,0($t0)       
        bge $s4,$t0,FinFor5     # Comparo i < ncols

        lw $t1,0($s2)           # Meto en $t1, el valor actual de matrix[nrows*row1 + i]
        sw $t1,0($s0)           # Meto en aux_vec1[i], el valor de $t1
        addiu $s2,$s2,4         # Sumo 4 bytes para situarme en la siguiente posición
        addiu $s0,$s0,4         # Sumo 4 bytes para situarme en la siguiente posición

        lw $t2,0($s3)           # Meto en $t2, el valor actual de matrix[nrows*row2 + i]
        sw $t2,0($s1)           # Meto en aux_vec2[i], el valor de $t2
        addiu $s3,$s3,4         # Sumo 4 bytes para situarme en la siguiente posición
        addiu $s1,$s1,4         # Sumo 4 bytes para situarme en la siguiente posición

        addi $s4,$s4,1          #Hago ++i
        b   For5

    FinFor5:


    la $s0,aux_vec1             # Cargo la dirección de memoria de aux_vec1
    la $s1,aux_vec2             # Cargo la dirección de memoria de aux_vec2

    move $s2,$a0
    move $s3,$a0                # Cargo la dirección base de matrix en $s2 y $s3

    lw $t0,24($sp)
    lw $t0,0($t0)               # Cargo desde la pila, el valor de nrows
    lw $t1,32($sp)              # Cargo desde la pila, el valor de row1
    lw $t2,36($sp)              # Cargo desde la pila, el valor de row2

    mul $t2,$t2,$t0             # Hago nrows * row2, sobrescribiendo row2
    mul $t2,$t2,4               # Ahora tengo la cantidad de bytes que debo desplazarme
    mul $t1,$t1,$t0             # Hago nrows * row1, sobrescribiendo row1
    mul $t1,$t1,4               # Ahora tengo la cantidad de bytes que debo desplazarme

    addu $s2,$s2,$t1            # Guardo en $s1 la posición matrix[nrows*row1]
    addu $s3,$s3,$t2            # Guardo en $s1 la posición matrix[nrows*row2]


    move $s4,$zero
    For6:
        lw $t0,28($sp)       
        lw $t0,0($t0)   
        bge $s4,$t0,FinFor6     #Comparo i < ncols

        lw $t1,0($s1)           # Meto en $t1, el valor actual de aux_vec2[i]
        sw $t1,0($s2)           # Meto en matriz[nrows*row1 + i], el valor de $t1
        addiu $s1,$s1,4         # Sumo 4 bytes para situarme en la siguiente posición
        addiu $s2,$s2,4         # Sumo 4 bytes para situarme en la siguiente posición

        lw $t2,0($s0)           # Meto en $t2, el valor actual de aux_vec1[i]
        sw $t2,0($s3)           # Meto en matriz[nrows*row2 + i], el valor de $t2
        addiu $s0,$s0,4         # Sumo 4 bytes para situarme en la siguiente posición
        addiu $s3,$s3,4         # Sumo 4 bytes para situarme en la siguiente posición

        addi $s4,$s4,1          #Hago ++i
        b   For6

    FinFor6:


                                #Valor line2 en 36($sp), como se pasó por la pila, no hago nada
    lw $a3,32($sp)              #Valor line1 restaurado
    lw $a2,28($sp)              #Dirección ncols restaurado
    lw $a1,24($sp)              #Dirección de nrows restaurada
    lw $a0,20($sp)              #Dirección matriz restaurada
    lw $s4,16($sp)
    lw $s3,12($sp)
    lw $s2,8($sp)               #En estas 5 instrucciones restauro el valor de los registros $s
    lw $s1,4($sp)               
    lw $s0,0($sp)               
    addi $sp,$sp,36             #Restauro la posición del puntero de pila

    jr $ra                      #Vuelvo a la función main


#
#void ColumnSwap(std::vector<int>& matrix, int& nrows, int& ncols,
#                int& col1, int& col2) { // este método intercambia dos columnas seleccionadas por el usuario,
#                                      // sigue la misma metodología que la función RowsSwap(), pero con las columnas
#    std::vector<int> aux_vec1;
#    std::vector<int> aux_vec2;
#    aux_vec1.resize(ncols);
#    aux_vec2.resize(ncols);
#
#    for(int i{0}; i < nrows; ++i) {
#        aux_vec1[i] = matrix[col1 + nrows*i];
#        aux_vec2[i] = matrix[col2 + nrows*i];
#    }
#    for(int i{nrows -1}; i >= 0; --i) {
#        matrix[col1 + nrows*i] = aux_vec2[i];
#        matrix[col2 + nrows*i] = aux_vec1[i];
#    }
#}
#
ColumnSwap:
    addi $sp,$sp,-36            #Hago espacio en la pila para 9 variables, la variable line2 ya había sido puesta, así que está en la posición 36($sp)

                                #Valor line2 en 36($sp), aquí será col2
    sw $a3,32($sp)              #Valor line1, aquí será col1
    sw $a2,28($sp)              #Dirección ncols
    sw $a1,24($sp)              #Dirección de nrows
    sw $a0,20($sp)              #Dirección base original de la matriz
    sw $s4,16($sp)              #Variable "i" que usarán los dos for
    sw $s3,12($sp)              #Dirección de la matriz ubicada en la posición matrix[nrows*row2 + i]
    sw $s2,8($sp)               #Dirección de la matriz ubicada en la posición matrix[nrows*row1 + i]
    sw $s1,4($sp)               #Variable aux_vec2
    sw $s0,0($sp)               #Variable aux_vec1
    

    la $s0,aux_vec1             # Cargo la dirección de memoria de aux_vec1
    la $s1,aux_vec2             # Cargo la dirección de memoria de aux_vec2

    move $s2,$a0
    move $s3,$a0                # Cargo la dirección base de matrix en $s2 y $s3

    lw $t1,32($sp)              # Cargo desde la pila, el valor de col1
    lw $t2,36($sp)              # Cargo desde la pila, el valor de col2

    mul $t1,$t1,4               # Ahora tengo la cantidad de bytes que debo desplazarme hasta col1
    mul $t2,$t2,4               # Ahora tengo la cantidad de bytes que debo desplazarme hasta col2

    addu $s2,$s2,$t1            # Guardo en $s2 la posición matrix[col1]
    addu $s3,$s3,$t2            # Guardo en $s3 la posición matrix[col2]

    move $s4,$zero              # Inicializamos la variable "i" a cero
    For7:
        lw $t0,24($sp)
        lw $t0,0($t0)           # Cargo desde la pila, el valor de nrows
        bge $s4,$t0,FinFor7     # Comparo i < nrows

        mul $t1,$t0,$s4         # Hago nrows * i, resultado en $t1
        mul $t1,$t1,4           # Ahora tengo la cantidad de bytes que debo desplazarme
        addu $t1,$t1,$s2        # Ahora tengo la posición en memoria matrix[col1 + nrows*i] en $t1

        lw $t2,0($t1)           # Cargo en $t2, el primer elemento no sacado ya de matrix[col1 + nrows*i]
        sw $t2,0($s0)           # Meto en aux_vec1[i], el valor de $t2

        addiu $s0,$s0,4         # Sumo 4 bytes para situarme en la siguiente posición de aux_vec1

        
        mul $t1,$t0,$s4         # Hago nrows * i, resultado en $t1
        mul $t1,$t1,4           # Ahora tengo la cantidad de bytes que debo desplazarme
        addu $t1,$t1,$s3        # Ahora tengo la posición en memoria matrix[col2 + nrows*i] en $t1

        lw $t2,0($t1)           # Cargo en $t2, el primer elemento no sacado ya de matrix[col2 + nrows*i]
        sw $t2,0($s1)           # Meto en aux_vec2[i], el valor de $t2

        addiu $s1,$s1,4         # Sumo 4 bytes para situarme en la siguiente posición de aux_vec2

        addi $s4,$s4,1          #Hago ++i
        b   For7

    FinFor7:


    la $s0,aux_vec1             # Cargo la dirección de memoria de aux_vec1
    la $s1,aux_vec2             # Cargo la dirección de memoria de aux_vec2

    move $s2,$a0
    move $s3,$a0                # Cargo la dirección base de matrix en $s2 y $s3

    lw $t1,32($sp)              # Cargo desde la pila, el valor de col1
    lw $t2,36($sp)              # Cargo desde la pila, el valor de col2

    mul $t1,$t1,4               # Ahora tengo la cantidad de bytes que debo desplazarme hasta col1
    mul $t2,$t2,4               # Ahora tengo la cantidad de bytes que debo desplazarme hasta col2

    addu $s2,$s2,$t1            # Guardo en $s2 la posición matrix[col1]
    addu $s3,$s3,$t2            # Guardo en $s3 la posición matrix[col2]

    # Este for en concreto lo programé al revés que como lo hice en C++, pero la razón es simple
    # En las líneas 571 y 572 de este programa, vuelvo a la dirección base de los vectores auxiliares
    # Y desde ahí, voy cogiendo los valores y los meto en la matriz, quería hacerlo así originalmente en C++
    # Pero tal cual lo hice en C++ me pareció más fácil, y tal cual está en MIPS, me parece más fácil
    # Por eso lo dejo así
    
    # for(int i{0}; i < nrows; ++i) sería el verdadero for implementado como For8:

    move $s4,$zero              # Hago int i{0}
    For8:
        lw $t0,24($sp)          # Cargo en $t0, la dirección de nrows
        lw $t0,0($t0)           # Sobreescirbo $t0, con el valor de nrows
        bge $s4,$t0,FinFor8     # Comparo i < nrows

        mul $t1,$t0,$s4         # Hago nrows * i, resultado en $t1
        mul $t1,$t1,4           # Ahora tengo la cantidad de bytes que debo desplazarme
        addu $t1,$t1,$s2        # Ahora tengo la posición en memoria matrix[col1 + nrows*i] en $t1

        lw $t2,0($s1)           # Cargo en $t2, el primer elemento no sacado ya de aux_vec2
        sw $t2,0($t1)           # Meto en matrix[col1 + nrows*i], el valor de $t2

        addiu $s1,$s1,4         # Sumo 4 bytes para situarme en la siguiente posición de aux_vec2

        
        mul $t1,$t0,$s4         # Hago nrows * i, resultado en $t1
        mul $t1,$t1,4           # Ahora tengo la cantidad de bytes que debo desplazarme
        addu $t1,$t1,$s3        # Ahora tengo la posición en memoria matrix[col2 + nrows*i] en $t1

        lw $t2,0($s0)           # Cargo en $t2, el primer elemento no sacado ya de aux_vec1[i]
        sw $t2,0($t1)           # Meto en matrix[col2 + nrows*i], el valor de $t2

        addiu $s0,$s0,4         # Sumo 4 bytes para situarme en la siguiente posición de aux_vec1

        addi $s4,$s4,1          #Hago ++i
        b   For8

    FinFor8:

                                #Valor line2 en 36($sp), como se pasó por la pila, no hago nada
    lw $a3,32($sp)              #Valor line1 restaurado
    lw $a2,28($sp)              #Dirección ncols restaurado
    lw $a1,24($sp)              #Dirección de nrows restaurada
    lw $a0,20($sp)              #Dirección matriz restaurada
    lw $s4,16($sp)
    lw $s3,12($sp)
    lw $s2,8($sp)               #En estas 5 instrucciones restauro el valor de los registros $s
    lw $s1,4($sp)               
    lw $s0,0($sp)               
    addi $sp,$sp,36             #Restauro la posición del puntero de pila

    jr $ra                      #Vuelvo a la función main

#

main:
#    std::vector<int> Matrix;   // Vector que almacena la matriz implementada
#    Matrix.resize(100);        // Establecemos el tamaño máximo de la matriz
#    int nrows{0};              // Declaramos dos variables donde guardo las
#    int ncols{0};              // filas y columnas de la matriz
#    int operation_code{1};     // Esta variable la usamos al final, la declaramos a 1, porque un while al final, evalua si esta
#                               // si esta variable es cero, y si es distinto de cero, entra al while, así me aseguro que entre
#                               // lo hago así, porque dentro del while, hay un if, y con el DoWhile tuve problemas, así no los hay
    la $s0,matrix 
    la $s1,nrows                    # Inicializo los 4 registros con las direcciones base de las variables
    la $s2,ncols
    la $s3,operationcode
    li $t0,1
    sw $t0,0($s3)                   #Asignamos aquí el valor 1 a operation_code y no en la memoria, por si el programa se ejecuta más de una vez
    

#    std::cout << std::endl;
#    std::cout << "Soy un programa que almacena una matriz dada" << std::endl;
#    std::cout << "por el usuario y permite hacer operaciones con" << std::endl;
#    std::cout << "sus filas y columnas. Por defecto, la matriz" << std::endl;
#    std::cout << "tiene un tamaño máximo de 10 filas y columnas," << std::endl;  // strings de bienvenida y explicación de como funciona el programa
#    std::cout << "puedes readimensionar la matriz para hacer sus" << std::endl;
#    std::cout << "filas y columnas más pequeñas, no más grandes" << std::endl << std::endl;
    la $a0,Titulo       #Titulo, explico como funciona el programa
    li $v0,4            #Le digo al sistema que muestre un string
    syscall

#    std::cout << "¿nº filas? ";
#    std::cin >> nrows;
#    std::cout << "¿nº columnas? ";
#    std::cin >> ncols;
    la $a0,PregFilas    #Pregunto cuantas filas tendrá la matriz
    li $v0,4            #Le digo al sistema que muestre un string
    syscall

    li $v0,5            #Le digo al sistema que me lea la cantidad de filas
    syscall
    sw $v0,0($s1)       #Almaceno la cantidad de filas

    la $a0,PregColumnas #Pregunto cuantas columnas tendrá la matriz
    li $v0,4            #Le digo al sistema que me lea la cantidad de columnas
    syscall

    li $v0,5            #Le digo al sistema que me lea la cantidad de columnas
    syscall
    sw $v0,0($s2)       #Almaceno la cantidad de columnas

#    while(nrows > 10 || nrows < 1 || ncols > 10 || ncols < 1) { // si la cantidad de filas o columnas es negativa o superior a 10, se vuelve a pedir el dato
#        std::cout << std::endl;
#        std::cout << "Error en la asignación, ingrese datos válidos: " << std::endl;
#        std::cout << "¿nº filas? ";
#        std::cin >> nrows;
#        std::cout << "¿nº columnas? ";
#        std::cin >> ncols;
#    }
    While1:
        la $t0,kConstante11     #Cargo en $t0, la dirección de la constante 10
        lw $t0,0($t0)           #Cargo la constante 10 en $t0, sobrescribiendo la dirección de memoria
        la $t1,operationcode    #Cargo en $t1, la dirección de la variable operation_code
        lw $t1,0($t1)           #Cargo en $t1, el valor de operation_code que es 1
        lw $t2,0($s1)           #Cargo en $t2, el valor de nrows para usarlo
        lw $t3,0($s2)           #Cargo en $t3, el valor de ncols para usarlo

        slt $t4,$t2,$t0         #Comparo la primera expresión con nrows, resultado en $t4
        sgt $t5,$t2,$zero       #Comparo la segunda expresión con nrows, resultado en $t5
        and $t4,$t4,$t5         #Comparo si nrows está en el rango (1, 10)

        slt $t5,$t3,$t0         #Comparo la primera expresión con ncols, resultado en $t5
        sgt $t6,$t3,$zero       #Comparo la segunda expresión con ncols, resultado en $t6
        and $t5,$t5,$t6         #Comparo si ncols está en el rango (1, 10)

        and $t4,$t4,$t5         #Comparo si nrows y ncols están en el rango (1, 10) a la vez

        beq $t1,$t4,NotWhile1   #Si todo va bien, se salta a NotWhile, sino, algún número está mal

        la $a0,FinDeLinea
        li $v0,4                #Le digo al sistema que muestre un string
        syscall

        la $a0,ErrorAsignacion
        li $v0,4                #Le digo al sistema que muestre un string, un mensaje de error
        syscall

        la $a0,PregFilas
        li $v0,4                #Le digo al sistema que muestre un string, pregunta nº filas
        syscall

        li $v0,5                #Le digo al sistema que lea un entero por teclado, el nº de filas
        syscall
        sw $v0,0($s1)

        la $a0,PregColumnas
        li $v0,4                #Le digo al sistema que muestre un string, pregunta nº columnas
        syscall

        li $v0,5                #Le digo al sistema que lea un entero por teclado, el nº de columnas
        syscall
        sw $v0,0($s2)

        b   While1

    NotWhile1:

#    std::cout << std::endl << std::endl;
#    Matrix.resize(nrows*ncols); // readimensionamos la matriz para optimizar recursos
#    int counter{0};
    la $a0,FinDobleLinea
    li $v0,4                    #Le digo al sistema que imprima una string
    syscall

    addi $s4,$zero,0              #Inicializamos la variable counter

#    for(int i{0}; i < nrows; ++i) { // estos for piden uno a uno, los valores fila por fila, de izquierda a derecha de la matriz
#        for(int j{0}; j < ncols; ++j) {
#            std::cout << "¿Valor de la posición(" << i << ", " << j << ")? ";
#            std::cin >> Matrix[counter];
#            ++counter;
#        }
#        std::cout << std::endl;
#    }
    li $t0,-1                               #Inicializamos la variable local "int i{0}", pongo -1, por el caso en que nrows = 0
    addi $sp,$sp,-8                         #Desplazo la posición del puntero de pila para que quepan 2 variables int
    sw $t0,0($sp)                           #La cargo en la pila "i", para salvarla de las llamadas del sistema, haré lo mismo más adelante
    For1:
        lw  $t0,0($sp)
        lw  $t1,0($s1)
        addi $t1,$t1,-1                     #Le restamos 1 para equilibrarlo con i
        bge $t0,$t1,FinFor1                 #Comparo i < nrows

        li $t0,-1
        sw $t0,4($sp)                       #Cargo en la pila "j"
        For2:
            lw  $t0,4($sp)
            lw  $t1,0($s2)
            addi $t1,$t1,-1                 #Le restamos 1 para equilibrarlo con j
            bge $t0,$t1,FinFor2             #Comparo j < ncols

            la $a0,ValPos1
            li $v0,4                        #Aquí y en las siguientes 4 llamadas al sistema, el sistema mostrará 3 strings en memoria y 2 variables
            syscall

            lw $t0,0($sp)                   #Cargo la dirección en memoria de "i" desde la pila a $t0
            addi $t0,$t0,1                  #Como "i" se inicializa con -1, hay que sumarle 1, para que apunte a la fila correcta por pantalla
            la $a0,0($t0)                   #Cargo el valor de "i" como argumento desde $t0
            li $v0,1                        #Le digo al sistema que muestre un int
            syscall

            la $a0,ValPos2
            li $v0,4                        #Le digo al sistema que muestre un string
            syscall

            lw $t0,4($sp)                   #Cargo la dirección en memoria de "j" desde la pila a $t0
            addi $t0,$t0,1                  #Como "j" se inicializa con -1, hay que sumarle 1, para que apunte a la fila correcta por pantalla
            la $a0,0($t0)                   #Cargo el valor de "j" como argumento desde $t0
            li $v0,1                        #Le digo al sistema que muestre un int
            syscall

            la $a0,ValPos3
            li $v0,4                        #Le digo al sistema que muestre un string
            syscall

            li $v0,5                        #Le digo al sistema que lea un int
            syscall
            sw $v0,0($s0)                   #Cojo el entero leído, y lo guardo en la primera posición de Matrix que todavía no haya sido escrita   
            addi $s0,$s0,4                  #Le sumo a la dirección base de Matrix, 4 bytes para la siguiente vez que tenga que asignarle valor

                                            #Debería hacer ++counter, pero no lo necesito en MIPS
            lw $t0,4($sp)
            addi $t0,1                      #En estas 3 instruciones hago ++j
            sw $t0,4($sp)

            b   For2                        #Vuelvo a For2
        FinFor2:
        
        la $a0,FinDeLinea
        li $v0,4                            #Le digo al sistema que muestre un string
        syscall

        lw $t0,0($sp)
        addi $t0,1                          #En estas 3 instruciones hago ++i
        sw $t0,0($sp)

        b   For1                            #Vuelvo a For1
    FinFor1:

    addi $sp,$sp,8                          #Sumo 8 bytes a $sp para devolverlo a su posición original en la base de la pila
    la $s0,matrix                           #Las operacioens de los dos for, afectaron al valor de $s0, por eso lo vuelvo a asignar

#    ShowMatrix(Matrix, nrows, ncols); // funcion que muestra la matriz por pantalla
#    std::cout << "La matriz puede modificarse por el usuario" << std::endl;
    lw $a2,ncols
    lw $a1,nrows                 #En estas 3 instruciones, paso los parámetros que la función necesita
    la $a0,matrix                
    jal ShowMatrix               #Salto a la función ShowMatrix

    la $a0,PoderModif
    li $v0,4                     #Le digo al sistema que muestra un string
    syscall

#    while(operation_code != 0) {
#        operation_code = 0;
#        std::cout << "Escribe 1 para intercambiar dos filas" << std::endl;
#        std::cout << "Escribe 2 para intercambiar dos columnas" << std::endl;
#        std::cout << "Escribe 0 para salir del programa" << std::endl << std::endl;
#        std::cout << "Código de la operación: ";
#        std::cin >> operation_code; // se pide un número para hacer alguna de las 4 operaciones disponibles
#
#        while((operation_code < 0) || (operation_code > 2)) { // si el número no es válido, se vuelve a pedir
#            std::cout << "Error al leer la operación" << std::endl;
#            std::cout << "Ingresa un dato válido: ";
#            std::cin >> operation_code;
#            std::cout << std::endl;
#        }
    While2:
        lw $t0,0($s3)
        beq $t0,$zero,FinWhile2         #Comparo operation_code != 0
        sw $zero,0($s3)                 #operation_code = 0

        la $a0,Instrucciones
        li $v0,4                        #Le digo al sistema que muestre un string
        syscall

        li $v0,5                        #Le digo al sistema que lea un entero
        syscall
        sw $v0,0($s3)                   #Reescribo la variable operation_code

            While3:
                li $t0,-1               #Constante -1, actuará de variable en la función booleana
                lw $t1,0($s3)           #Nuevo valor operation_code cargado
                sgt $t0,$t1,$t0         #Comparo operation_code < 0 , resultado en $t0

                li $t1,3                
                lw $t2,0($s3)           #Nuevo valor operation_code cargado
                slt $t1,$t2,$t1         #Comparo operation_code > 2 , resultado en $t1

                and $t0,$t0,$t1         #Comparo la puerta OR del while 3, resultado en $t0
                bnez $t0,FinWhile3      #Si $t0 == 0 , entonces sale de while



                la $a0,ErrorOperacion
                li $v0,4                #Le digo al sistema que muestre un string
                syscall

                li $v0,5                #Le digo al sistema que lea un int
                syscall                 
                sw $v0,0($s3)           #Rescribo la variable operation_code con el nuevo valor leído

                la $a0,FinDeLinea
                li $v0,4                #Le digo al sistema que muestre un string
                syscall

                b   While3

            FinWhile3:

#        if(operation_code != 0) { // si el número es cero se termina el programa y ni se evaluan el resto de casos
#                                  // así ahorramos tiempos de ejecución
#            int line1{-1}; // establezco estos valores por defecto, porque son valores que no se le pueden pasar a 
#            int line2{-1}; // las funciones, así, si hay algún en la asignación de valores en el main, lo sabré
            If1:
                lw $t0,0($s3)           #Cargo operation_code
                beq $t0,$zero,FinIf1    #Si operation_code == 0, no ejecuta If1

                li $s4,-1               #Declaramos la variable int line1
                li $s5,-1               #Declaramos la variable int line2

#            if(operation_code == 1) {
#                if(nrows == 1) {
#                    std::cout << std::endl;
#                    std::cout << "Solo hay una fila, no puedes hacer esta operación" << std::endl;
#                    continue;
#                }
#                do {
#                    std::cout << "¿1º fila? ";
#                    std::cin >> line1;
#                    std::cout << "¿2º fila? ";
#                    std::cin >> line2;
#                    std::cout << std::endl;
#                    if((line1 < 0) || (line1 > (nrows-1)) || 
#                       (line2 < 0) || (line2 > (nrows-1)) ||
#                       (line1 == line2)) { 
#                           std::cout << "Error en parámetros" << std::endl;
#                           std::cout << "ingrese datos válidos" << std::endl;
#                           line1 = -1;
#                           line2 = -1;
#                    }
#                }while((line1 < 0) || (line1 > (nrows-1)) || 
#                       (line2 < 0) || (line2 > (nrows-1)) ||
#                       (line1 == line2)); // si las filas elegidas son inválidas o iguales, se reitera
#                RowsSwap(Matrix, nrows, ncols, line1, line2);
#            }
            If2:
                lw $t0,0($s3)                   #Cargo operation_code
                li $t1,1                        #Cargo constante 1
                bne $t0,$t1,FinIf2              #Si operation_code != 1, no ejecuta If2

                If3:
                    lw $t0,nrows
                    li $t1,1
                    bne $t0,$t1,FinIf3          #Si nrows != 1, no ejecuta If3

                    la $a0,FinDeLinea
                    li $v0,4                    #Le digo al sistema que muestre un string
                    syscall

                    la $a0,ErrorUnaFila
                    li $v0,4                    #Le digo al sistema que muestre un string
                    syscall

                    b  While2                   #Continue;
                FinIf3:

                DoWhile1:
                    la $a0,Fila1
                    li $v0,4                    #Le digo al sistema que muestre un string
                    syscall

                    li $v0,5                    #Le digo al sistema que lea un entero
                    syscall
                    move $s4,$v0                #Rescribo el valor de line1 con el entero leído

                    la $a0,Fila2
                    li $v0,4                    #Le digo al sistema que muestre un string
                    syscall

                    li $v0,5                    #Le digo al sistema que lea un entero
                    syscall
                    move $s5,$v0                #Rescribo el valor de line1 con el entero leído

                    la $a0,FinDeLinea
                    li $v0,4                    #Le digo al sistema que muestre un string
                    syscall

                    If4:
#                    if((line1 < 0) || (line1 > (nrows-1)) || 
#                       (line2 < 0) || (line2 > (nrows-1)) ||
#                       (line1 == line2)) {                       
                        slt $t0,$s4,$zero       #Comparo line1 < 0
                        lw $t4,nrows            #Cargo nrows
                        addi $t4,$t4,-1         #Obtengo nrows -1
                        sgt $t1,$s4,$t4         #Comparo line1 > (nrows-1)

                        slt $t2,$s5,$zero       #Comparo line2 < 0
                        lw $t5,nrows            #Cargo nrows
                        addi $t5,$t5,-1         #Obtengo nrows -1
                        sgt $t3,$s5,$t5         #Comparo line1 > (nrows-1)

                        or $t0,$t0,$t1          
                        or $t0,$t0,$t2          #Tengo las 4 primeras expresiones del if4 guardadas en los 4 primeros registros $t, ahora meto su valor booleano en $t0
                        or $t0,$t0,$t3

                        seq $t1,$s4,$s5         #Hago line1==line2
                        or $t0,$t0,$t1          #Lo comparo con las 4 primeras expresiones
                        not $t0,$t0             #Si hay un error en los parámetros, $t0 tendrá un -2, si todo va bien, habrá un -1
                        addi $t0,$t0,1          #Ahora, si hay un error, habrá un -1, y si todo va bien, habrá un 0

                        beqz $t0,FinIf4

                        la $a0,ErrorParametros
                        li $v0,4                #Le digo al sistema que muestre un string
                        syscall

                        li $t6,-1
                        move $s4,$t6
                        li $t7,-1               #Reescribo las variables line1 y line2 con el valor -1
                        move $s5,$t7

                    FinIf4:

                    slt $t0,$s4,$zero
                    lw $t4,nrows                #Las condiciones booleanas de este while, son exactamente iguales que el If4
                    addi $t4,$t4,-1
                    sgt $t1,$s4,$t4

                    slt $t2,$s5,$zero
                    lw $t5,nrows
                    addi $t5,$t5,-1
                    sgt $t3,$s5,$t5

                    or $t0,$t0,$t1
                    or $t0,$t0,$t2
                    or $t0,$t0,$t3

                    seq $t1,$s4,$s5
                    or $t0,$t0,$t1
                    not $t0,$t0
                    addi $t0,$t0,1

                    bnez $t0,DoWhile1

                    addi $sp,$sp,-4                 #Hago espacio en la pila para 1 variable, ya se me acabarón los registros $a para pasarle a la función
                    
                    sw $s5,0($sp)                   #Paso a la función line2
                    move $a3,$s4                    #Paso a la función line1
                    la $a2,ncols
                    la $a1,nrows                    #Cargo 5 variables para pasarle a la función, 4 en registros $a, y la última en la pila
                    la $a0,matrix

                    jal RowsSwap                    #Salto a la función RowsSwap

                    addi $sp,$sp,4                  #Restauramos la pila a su valor original

                #Aquí es el fin del DoWhile1, no lo pongo como etiqueta porque ninguna instrucción me salta aquí

            FinIf2:

#            if(operation_code == 2) {
#                if(ncols == 1) {
#                    std::cout << std::endl;
#                    std::cout << "Solo hay una columna, no puedes hacer esta operación" << std::endl;
#                    continue;
#                }
#                do {
#                    std::cout << "¿1º columna? ";
#                    std::cin >> line1;
#                    std::cout << "¿2º columna? ";
#                    std::cin >> line2;
#                    std::cout << std::endl;
#                    if((line1 < 0) || (line1 > (ncols-1)) || 
#                       (line2 < 0) || (line2 > (ncols-1)) ||
#                       (line1 == line2)) {
#                           std::cout << "Error en parámetros" << std::endl;
#                           std::cout << "ingrese datos válidos" << std::endl;
#                           line1 = -1;
#                           line2 = -1;
#                    }
#                }while((line1 < 0) || (line1 > (ncols-1)) || 
#                       (line2 < 0) || (line2 > (ncols-1)) ||
#                       (line1 == line2)); // si las columnas elegidas son inválidas o iguales, se reitera
#                ColumnSwap(Matrix, nrows, ncols, line1, line2);
#            }
            If5:
                lw $t0,0($s3)                   #Cargo operation_code
                li $t1,2                        #Cargo constante 2
                bne $t0,$t1,FinIf5              #Si operation_code != 2, no ejecuta If5

                If6:
                    lw $t0,ncols
                    li $t1,1
                    bne $t0,$t1,FinIf6          #Si ncols != 1, no ejecuta If3

                    la $a0,FinDeLinea
                    li $v0,4                    #Le digo al sistema que muestre un string
                    syscall

                    la $a0,ErrorUnaColumna
                    li $v0,4                    #Le digo al sistema que muestre un string
                    syscall

                    b  While2                   #Continue;
                FinIf6:

                DoWhile2:
                    la $a0,Columna1
                    li $v0,4                    #Le digo al sistema que muestre un string
                    syscall

                    li $v0,5                    #Le digo al sistema que lea un entero
                    syscall
                    move $s4,$v0                #Rescribo el valor de line1 con el entero leído

                    la $a0,Columna2
                    li $v0,4                    #Le digo al sistema que muestre un string
                    syscall

                    li $v0,5                    #Le digo al sistema que lea un entero
                    syscall
                    move $s5,$v0                #Rescribo el valor de line1 con el entero leído

                    la $a0,FinDeLinea
                    li $v0,4                    #Le digo al sistema que muestre un string
                    syscall

                    If7:
#                    if((line1 < 0) || (line1 > (nrows-1)) || 
#                       (line2 < 0) || (line2 > (nrows-1)) ||
#                       (line1 == line2)) {                       
                        slt $t0,$s4,$zero          #Comparo line1 < 0
                        lw $t4,nrows               #Cargo nrows
                        addi $t4,$t4,-1            #Obtengo nrows -1
                        sgt $t1,$s4,$t4            #Comparo line1 > (nrows-1)

                        slt $t2,$s5,$zero          #Comparo line2 < 0
                        lw $t5,nrows               #Cargo nrows
                        addi $t5,$t5,-1            #Obtengo nrows -1
                        sgt $t3,$s5,$t5            #Comparo line1 > (nrows-1)

                        or $t0,$t0,$t1          
                        or $t0,$t0,$t2             #Tengo las 4 primeras expresiones del if4 guardadas en los 4 primeros registros $t, ahora meto su valor booleano en $t0
                        or $t0,$t0,$t3

                        seq $t1,$s4,$s5            #Hago line1==line2
                        or $t0,$t0,$t1             #Lo comparo con las 4 primeras expresiones
                        not $t0,$t0                #Si hay un error en los parámetros, $t0 tendrá un -2, si todo va bien, habrá un -1
                        addi $t0,$t0,1             #Ahora, si hay un error, habrá un -1, y si todo va bien, habrá un 0

                        beqz $t0,FinIf7

                        la $a0,ErrorParametros
                        li $v0,4                   #Le digo al sistema que muestre un string
                        syscall

                        li $t6,-1
                        move $s4,$t6
                        li $t7,-1                  #Reescribo las variables line1 y line2 con el valor -1
                        move $s5,$t7

                    FinIf7:

                    slt $t0,$s4,$zero
                    lw $t4,nrows                   #Las condiciones booleanas de este while, son exactamente iguales que el If4
                    addi $t4,$t4,-1
                    sgt $t1,$s4,$t4

                    slt $t2,$s5,$zero
                    lw $t5,nrows
                    addi $t5,$t5,-1
                    sgt $t3,$s5,$t5

                    or $t0,$t0,$t1
                    or $t0,$t0,$t2
                    or $t0,$t0,$t3

                    seq $t1,$s4,$s5
                    or $t0,$t0,$t1
                    not $t0,$t0
                    addi $t0,$t0,1

                    bnez $t0,DoWhile2

                    addi $sp,$sp,-4                 #Hago espacio en la pila para 1 variable, ya se me acabarón los registros $a para pasarle a la función
                    
                    sw $s5,0($sp)                   #Paso a la función line2
                    move $a3,$s4                    #Paso a la función line1
                    la $a2,ncols
                    la $a1,nrows                    #Cargo 5 variables para pasarle a la función, 4 en registros $a, y la última en la pila
                    la $a0,matrix

                    jal ColumnSwap                  #Como todos los parámetros de la función se pasan por referencia, no cargo ninguna variable en los registros $a para darle a la matriz

                    addi $sp,$sp,4                   #Restauramos la pila a su valor original

                #Aquí termina el DoWhile2

            FinIf5:

#            ShowMatrix(Matrix, nrows, ncols);
#        } // Fin del If1
#    } // Fin del while2
#
#    return 0;
#}
#

            #Como en la función ShowMatrix uso los registros $s4 y $s5, primero salvo sus valores en la pila, y al terminar la función los restauro
            addi $sp,$sp,-8              #Hago espacio en la pila para 2 variables
            sw $s4,4($sp)                #Pongo en la pila los valores de line1 y line2
            sw $s5,0($sp)

            lw $a2,ncols
            lw $a1,nrows                 #En estas 3 instruciones, paso los parámetros que la función necesita
            la $a0,matrix                
            jal ShowMatrix               #Salto a la función ShowMatrix

            lw $s4,4($sp)                #Saco de la pila los valores de line1 y line2
            lw $s5,0($sp)
            addi $sp,$sp,8               #Restablezo el valor de la pila a su valor original

            FinIf1:

        b   While2
    FinWhile2:

    la $a0,FinPrograma
    li $v0,4                     #String que muestro por pantalla para ayudarme a depurar
    syscall

    li $v0,10                    #Le digo al sistema que el programa ha terminado
    syscall