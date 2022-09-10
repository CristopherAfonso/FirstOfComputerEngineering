# practica 3. Principio de computadoras
# OBJETIVO: introduce el codigo necesario para reproducir el comportamiento del programa
# C++ que se adjunta como comentarios
# Debes documentar debidamente el uso de los registros que has elegido y la correspondencia
# con las variables que has utilizado.
#
#
#include <iostream>
#
#int main() {
#
#    std::cout << "\n\nPráctica 3. Principios de Computadores - Cristopher Manuel Afonso Mora"
#              << "\nIntroduzca el error máximo permitido: ";
#
#    double number_of_maximum_error{1.00};
#    std::cin >> number_of_maximum_error;
#    if(number_of_maximum_error >= 1.00) {
#        return 0;
#    }
#
#    double number_e{1.00};
#    double formula_actual_value{0.00};
#    int den_fact{1};
#    int counter{0};
#
#    formula_actual_value = double(1)/den_fact;
#    ++counter;
#    
#    while(formula_actual_value > number_of_maximum_error) {
#        formula_actual_value = double(1)/den_fact;
#        den_fact *= (1 + counter);
#        number_e += formula_actual_value;
#        ++counter;
#    }
#
#    std::cout << "\nNúmero e: " << number_e;
#    std::cout << "\nTerminos Calculados: " << counter << "\n\n";
#    return 0;
#}
#

    .data       #directiva que indica la zona de datos
titulo:                     .asciiz "\n\nPractica 3. Principios de Computadores - Cristopher Manuel Afonso Mora\nIntroduzca el error maximo permitido: "

NumeroE:                    .asciiz "\nNumero e: "
TerminosCalculados:         .asciiz "\nTerminos Calculados: "
CaracteresDeSaltoDeLinea:   .asciiz "\n\n"
IteracionActual:            .asciiz " <= valor actual del termino\n"

    # Registros que actuarán como las variables:
    # 
    # $s0 = int den_fact
    # $s1 = int counter
    # $f20 & $f21 = double number_of_maximum_error
    # $f22 & $f23 = double number_e
    # $f24 & $f25 = double formula_actual_value
    #
    .text
main:
    # IMPRIME EL TÍTULO POR CONSOLA 
    #    std::cout << "\n\nPráctica 3. Principios de Computadores - Cristopher Manuel Afonso Mora"
    #              << "\nIntroduzca el error máximo permitido: ";
    la $a0,titulo # Cargo en el registro $a0, la dirección del primer byte de la etiqueta "titulo"
    li $v0,4      # Cargo en el registro $v0, un 4, para mostrar por pantalla la etiqueta "titulo"
    syscall       # Llamada al sistema

    #    double number_of_maximum_error{1.00};
    #    std::cin >> number_of_maximum_error;
    #    if(number_of_maximum_error >= 1.00) {
    #        return 0;
    #    }
    li.d $f26,1.00                  # Inicializamos en el registro $f26 y $f27 con el valor 1.00, pero este registro no se cambiará, porque nos será útil en el resto del programa
    mov.d $f20,$f26                 # Inicializamos en el registro $f20 y $f21 con el valor 1.00, estos registros actuan como la variable number_of_maximum_error

    li $v0,7                        # Cargamos en el registro un 7 para decirle al sistema que lea por teclado un double
    syscall                         # Llamamos al sistema para que lea el double
    mov.d $f20,$f0                  # Movemos el double leído por pantalla, del registro $f0 y $f1, al registro $f20 y $f21

    c.lt.d $f20,$f26                # Condición que evalua si el registro $f22 y $f23 es mayor su valor que el del $f20 y $f21, si se cumple la condición, se termina el programa
    bc1f ProgramaFin

    #    double number_e{1.00};
    #    double formula_actual_value{0.00};
    #    int den_fact{1};
    #    int counter{0};
    mov.d $f22,$f26                 # Inicializamos en el registro $f22 y $f23 con el valor 0.00, estos registros actuan como la variable number_e
    li.d $f24,0.00                  # Inicializamos en el registro $f22 y $f23 con el valor 0.00, estos registros actuan como la variable formula_actual_value
    li $s0,1                        # Inicializamos en el registro $s0 con el valor 1, este registro actua como la variable den_fact
    li $s1,0                        # Inicializamos en el registro $s1 con el valor 0, este registro actua como la variable counter

    #    formula_actual_value = double(1)/den_fact;
    #    ++counter;
    #    
    #    while(formula_actual_value > number_of_maximum_error) {
    #        formula_actual_value = double(1)/den_fact;
    #        ++counter;         
    #        den_fact *= counter;
    #        number_e += formula_actual_value;
    #    }
    mtc1 $s0,$f4                    # Movemos el valor de la variable den_fact, al registro $f4 del CoProcesador1, pero es una copia cruda, hay que transformarla a formato IEEE-754, se mueve a ese registro porque es uno temporal
    cvt.d.w $f6,$f4                 # Con esta instrucción, convertimos el dato del registro $f4, que es un valor entero en CA2, a un número en IEEE-754, se mueve a ese registro porque es uno temporal
    div.d $f24,$f26,$f6             # En esta instrucción, guardamos en el registro salvado $f24, que actua como la variable formula_actual_value, el resultado de la división entre 1.00 y $f6

    add $s1,$s1,1                   # Aumentamos en 1, el valor de la variable counter

while:
    c.le.d $f24,$f20                # Se comprueba una expresión booleana con doubles, si $f24 <= $f22, entonces da un valor true
    bc1t whileFin                   # Si la expresión de arriba da true, entonces salta a la etiqueta whileFin

    mtc1 $s0,$f4                    # Movemos el valor de la variable den_fact, al registro $f4 del CoProcesador1, pero es una copia cruda, hay que transformarla a formato IEEE-754, se mueve a ese registro porque es uno temporal
    cvt.d.w $f6,$f4                 # Con esta instrucción, convertimos el dato del registro $f4, que es un valor entero en CA2, a un número en IEEE-754, se mueve a ese registro porque es uno temporal
    div.d $f24,$f26,$f6             # En esta instrucción, guardamos en el registro salvado $f24, que actua como la variable formula_actual_value, el resultado de la división entre 1.00 y $f6

    add $s1,$s1,1                   # Aumentamos en 1, el valor de la variable counter

    mul $s0,$s0,$s1                 # El nuevo valor del registro $s0, que actua como la variable den_fact, es su valor anterior multiplicado por $s1, que actua como la variable counter, en el paso anterior esta variable se incrementó en 1

    add.d $f22,$f22,$f24            # Al registro $f22 y $f23, que actuan como la variable number_e, cogemos el valor que ya tenían, y le sumamos el valor del registro $f24 y $f25, que actuan como la variable formula_actual_value

    b       while                   # Salto incondicional a la etiqueta while

    #    std::cout << "\nNúmero e: " << number_e;
    #    std::cout << "\nTerminos Calculados: " << counter << "\n\n";
whileFin:
    la $a0,NumeroE              # Cargamos en el registro $a0, la dirección del primer byte de la etiqueta NumeroE
    li $v0,4                    # Cargamos en el registro $v0, un 4 para decirle al sistema que muestre un string por pantalla
    syscall                     # Llamamos al sistema para que muestre la string por pantalla

    mov.d $f12,$f22             # Movemos el valor de los registros $f22 y $f23, que actua como la variable number_e, al registro $f12 y $f13
    li $v0,3                    # Cargamos en el registro $v0, un 3 para decirle al sistema que muestre un double por pantalla
    syscall                     # Llamamos al sistema para que muestre el double por pantalla

    la $a0,TerminosCalculados   # Cargamos en el registro $a0, la dirección del primer byte de la etiqueta TerminosCalculados
    li $v0,4                    # Cargamos en el registro $v0, un 4 para decirle al sistema que muestre una string por pantalla
    syscall                     # Llamamos al sistema para que muestre la string por pantalla

    move $a0,$s1                # Movemos el valor del registro $s1, que actua como la variable counter, al registro $a0 para imprimirlo por pantalla
    li $v0,1                    # Cargamos en el registro $v0, un 1 para decirle al sistema que imprima un entero por pantalla
    syscall                     # Llamamos al sistema para que imprima el entero por pantalla

ProgramaFin:
    li $v0,10                   # Cargamos un 10 en el registro $v0, para decirle al sistema que termine la ejecución del programa
    syscall                     # Llamamos al sistema para decirle que termine la ejecución del programa
