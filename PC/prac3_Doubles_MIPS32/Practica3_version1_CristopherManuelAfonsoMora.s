# practica 3. Principio de computadoras
# OBJETIVO: introduce el codigo necesario para reproducir el comportamiento del programa
# C++ que se adjunta como comentarios
# Debes documentar debidamente el uso de los registros que has elegido y la correspondencia
# con las variables que has utilizado.
#
#
##include <iostream>
#
#int main() {
#
#  std::cout << "\nSoy un programa que calcula el número irracional 'e'\n"
#            << "Para calcularlo, uso la fórmula: 1/(n!)\n"
#            << "La fórmula es incremental, yo pido un número por teclado\n"
#            << "Y ese número son las veces que repetiré esa fórmula\n"
#            << "Pero si repito la fórmula, 'n' lo incrementaré en 1\n"
#            << "Y se lo sumaré al resultado, entonces cuantas más veces\n"
#            << "Repita la fórmula, mayor será la precisión del número\n"
#            << "Cuando te lo pida, debes darme un número entero\n"
#            << "No puedo hacer 2,5 operaciones por ejemplo\n"
#            << "Dime ¿Cuántas veces quieres que repita la operación?: ";
#
#  int number_of_repetitions{0};
#  std::cin >> number_of_repetitions;
#  if(number_of_repetitions <= 0) {
#      std::cout << "\nFIN DEL PROGRAMA\n\n";
#      return 0;
#  }
#
#  if(number_of_repetitions == 1) {
#      std::cout << "\nPresición(iteraciones) = " << number_of_repetitions;
#      std::cout << "\nNúmero e = 1\n";
#      std::cout << "\nFIN DEL PROGRAMA\n\n";
#      return 0;
#  }
#
#  if(number_of_repetitions == 2) {
#      std::cout << "\nPresición(iteraciones) = " << number_of_repetitions;
#      std::cout << "\nNúmero e = 2\n";
#      std::cout << "\nFIN DEL PROGRAMA\n\n";
#      return 0;
#  }
#
#  double number_e{2.00};
#  int var_den_fact{1};
#
#  for(int i{2}; i < number_of_repetitions; ++i) {
#      var_den_fact *= (1 + var_den_fact);
#      number_e += double(1)/ var_den_fact;
#  }
#
#  std::cout << "\nPresición(iteraciones) = " << number_of_repetitions;
#  std::cout << "\nNúmero e = " << number_e << "\n";
#  std::cout << "\nFIN DEL PROGRAMA\n\n";
#  return 0;
#}
#

    .data       #directiva que indica la zona de datos
titulo:     .asciiz "\nSoy un programa que calcula el número irracional 'e'\nPara calcularlo, uso la fórmula: 1/(n!)\nLa fórmula es incremental, yo pido un número por teclado\nY ese número son las veces que repetiré esa fórmula\nPero si repito la fórmula, 'n' lo incrementaré en 1\nY se lo sumaré al resultado, entonces cuantas más veces\nrepita la fórmula, mayor será la precisión del número\nCuando te lo pida, debes darme un número entero\nNo puedo hacer 2,5 operaciones por ejemplo\nDime ¿Cuántas veces quieres que repita la operación?: "
                # Que conste que en la etiqueta "titulo" he puesto toda la introducción en la misma línea porque sino, 
                # En la consola del QtSpim me salía la string por pantalla de forma que no era igual al programa que tengo en C++

CaracterDeSaltoDeLinea: .asciiz "\n"
PrecisionIteraciones:   .asciiz "\nPresición(iteraciones) = "
NumeroEValor1:          .asciiz "\nNúmero e = 1\n"
NumeroEValor2:          .asciiz "\nNúmero e = 2\n"
NumeroEfor:             .asciiz "\nNúmero e = "
FinDelPrograma:         .asciiz "\nFIN DEL PROGRAMA\n\n"

    # Registros que actuarán como las variables:
    #
    # $s0 = int number_of_repetitions
    # $s1 = int var_den_fact
    # $s2 = int i (variable de iteración del for)
    # $s3 = ++var_den_fact
    # $f20 & $f21 = double number_e   # Uso los registros $f20 y $f21 porque son los primeros registros salvados del CoProcesador1
    # $f4 = $s1 # Es el lugar donde guardo el valor de $s1 en copia cruda, antes de convertirlo a un double, uso este registro porque es el primero temporal del CoProcesador1
    # $f6 & $f7 = double $f4 # Son los registros donde guardo el valor de $s1 que está en el $f4, pero ya convertido a double, 
    # y tras hacer esta operación, estos registros es donde guardo el valor de la división 1.00/$f6, reescribo los registros porque son temporales del CoProcesador1
    # $f22 & $f23 = 1.00 # Estos registros es donde guardo el valor del numerador constante 1.00, el que uso para hacer la división 1.00/$f6, mira la línea 185

    .text
main:
    # IMPRIME EL TÍTULO POR CONSOLA 
    # std::cout << "\nSoy un programa que calcula el número irracional 'e'\n"
    #           << "Para calcularlo, uso la fórmula: 1/(n!)\n"
    #           << "La fórmula es incremental, yo pido un número por teclado\n"
    #           << "y ese número son las veces que repetiré esa fórmula\n"
    #           << "Pero si repito la fórmula, 'n' lo incrementaré en 1\n"
    #           << "y se lo sumaré al resultado, entonces cuantas más veces\n"
    #           << "repita la fórmula, mayor será la precisión del número\n"
    #           << "Cuando te lo pida, debes darme un número entero\n"
    #           << "No puedo hacer 2,5 operaciones por ejemplo\n"
    #           << "Dime ¿Cuántas veces quieres que repita la operación?: ";
    la $a0,titulo # Cargo en el registro $a0, la dirección del primer byte de la etiqueta "titulo"
    li $v0,4      # Cargo en el registro $v0, un 4, para mostrar por pantalla la etiqueta "titulo"
    syscall       # Llamada al sistema

    #  int number_of_repetitions{0};
    #  std::cin >> number_of_repetitions;
    #  if(number_of_repetitions <= 0) {
    #      std::cout << "\nFIN DEL PROGRAMA\n\n";
    #      return 0;
    #  }
    move $s0,$zero    # Inicializo la variable number_of_repetitions al valor cero
    li $v0,5        # Cargo un 5 en el registro $v0, para leer un entero por teclado
    syscall         # Llamo al sistema para leer el entero

    move $s0,$v0    # Como el número leído esta en el registro $v0, lo muevo al registro $s0
    ble $s0,$zero, Fin # Si la variable number_of_repetitions es <= 0, entonces se salta a la etiqueta Fin y se termina el programa

    #  if(number_of_repetitions == 1) {
    #      std::cout << "\nPresición(iteraciones) = " << number_of_repetitions;
    #      std::cout << "\nNúmero e = 1\n";
    #      std::cout << "\nFIN DEL PROGRAMA\n\n";
    #      return 0;
    #  }
    bne $s0,1, NoIfOne          # Evaluo la condición, si $s0 es != 1, entonces salto a la etiqueta NoIfOne

    la $a0,PrecisionIteraciones # Cargo la dirrección de la etiqueta para mostrarla por pantalla
    li $v0,4                    # Cargo un 4 en el registro $v0, para decirle al sistema que muestre una string
    syscall                     # Llamo al sistema para que muestre la string

    move $a0,$s0                # Cargo el entero que quiero mostrar por pantalla en el registro $a0
    li $v0,1                    # Cargo un 1 en el registro $v0, para decirle al sistema que muestre un entero por pantalla
    syscall                     # Llamo al sistema para que muestre el entero

    la $a0,NumeroEValor1        # Cargo la dirrección de la etiqueta para mostrarla por pantalla
    li $v0,4                    # Cargo un 4 en el registro $v0, para decirle al sistema que muestre una string
    syscall                     # Llamo al sistema para que muestre la string

    b   Fin                     # Para no repetir código, como el programa debe finalizar, hago que salte
                                # A la etiqueta Fin para aprovechar ese código y no repetirlo


    #  if(number_of_repetitions == 2) {
    #      std::cout << "\nPresición(iteraciones) = " << number_of_repetitions;
    #      std::cout << "\nNúmero e = 2\n";
    #      std::cout << "\nFIN DEL PROGRAMA\n\n";
    #      return 0;
    #  }
NoIfOne:
    bne $s0,2, NoIfTwo         # Evaluo la condición, si $s0 es != 2, entonces salto a la etiqueta NoIfTwo

    la $a0,PrecisionIteraciones # Cargo la dirrección de la etiqueta para mostrarla por pantalla
    li $v0,4                    # Cargo un 4 en el registro $v0, para decirle al sistema que muestre una string
    syscall                     # Llamo al sistema para que muestre la string

    move $a0,$s0                # Cargo el entero que quiero mostrar por pantalla en el registro $a0
    li $v0,1                    # Cargo un 1 en el registro $v0, para decirle al sistema que muestre un entero por pantalla
    syscall                     # Llamo al sistema para que muestre el entero

    la $a0,NumeroEValor2        # Cargo la dirrección de la etiqueta para mostrarla por pantalla
    li $v0,4                    # Cargo un 4 en el registro $v0, para decirle al sistema que muestre una string
    syscall                     # Llamo al sistema para que muestre la string

    b   Fin                     # Para no repetir código, como el programa debe finalizar, hago que salte
                                # A la etiqueta Fin para aprovechar ese código y no repetirlo

    #  double number_e{2.00};
    #  int var_den_fact{1};
    #
    #  for(int i{2}; i < number_of_repetitions; ++i) {
    #      var_den_fact *= (1 + var_den_fact);
    #      number_e += double(1)/ var_den_fact;
    #  }
    #
    #  std::cout << "\nPresición(iteraciones) = " << number_of_repetitions;
    #  std::cout << "\nNúmero e = " << number_e << "\n";
NoIfTwo:
    li.d $f20,2.00      # Inicializamos el registro $f20 y $f21 con el double 2.00, actuan como la variable number_e
    li.d $f22,1.00      # Inicializamos el registro $f22 y $f23 con el doube 1.00, que actuará de numerador constante en la división con el registro $f6, para luego sumarlo al $f20
    li $s1,1            # Inicializamos el registro $s1 con el valor 1, actua como la variable var_den_fact
    li $s2,2            # Inicializamos el registro $s4 con el valor 2, actua como la variable i, para iterar el bucle for

For:
    bge $s2,$s0, ForFin # Condición booleana del while del for, si, i >= number_of_repetitions, entonces se sale del for

    add $s3,$s1,1       # En el registro $s5, guardo el valor de la variable var_den_fact +1, para multiplicalo luego por el valor -1
    mul $s1,$s1,$s3     # En el registro $s0, guardo el resultado de multplicar var_den_fact y var_den_fact +1

    mtc1 $s1,$f4        # Cargo en el registro $f4, el valor de var_den_fact, porque el registro $f4 es un registro temporal del CoProcesador1
    cvt.d.w $f6,$f4     # Convierto el registro $f4, que está codificado como un número entero en CA2, a un número double, codificado en IEEE-754
    div.d $f6,$f22,$f6  # Hago la división de 1.00/$f6 y el resultado lo guardo en el registro $f6
    add.d $f20,$f20,$f6 # Tras hallar el resultado de la división, ese resultado se le suma al valor de number_e, localizado en el registro $f20

    add $s2,$s2,1       # Incremento la variable i, equivale al ++i
    b   For             # Salto incondicional a la etiqueta For

ForFin:
    la $a0,PrecisionIteraciones     # Cargo la etiqueta que quiero mostrar por pantalla en el registro $a0
    li $v0,4                        # Cargo directamente un 4 en el registro $v0 para decirle al sistema que muestre una string
    syscall                         # Llamo al sistema para que muestre la string

    move $a0,$s0    # Muevo el número int number_of_repetitions al registro $a0 para mostrarlo por pantalla
    li $v0,1        # Cargo un 1 en el registro $v0 para decirle al sistema que muestre un entero por pantalla
    syscall         # Llamo al sistema para que muestre el número

    la $a0,NumeroEfor   # Cargo la etiqueta que quiero mostrar por pantalla
    li $v0,4            # Cargo un 4 en $v0 para decirle al sistema que muestre una string
    syscall             # Llamo al sistema para que la muestre

    mov.d $f12,$f20     # Cargo en $a0, el double que quiero mostrar por pantalla
    li $v0,3            # Cargo un 3 en $v0 para decirle al sistema que me muestre un double por pantalla
    syscall             # Llamo al sistema para que lo muestre

    la $a0,CaracterDeSaltoDeLinea   # Cargo en el registro $a0, la etiqueta que quiero que sacar por pantalla
    li $v0,4                        # Cargo en el registro $v0, un 4 para decirle al sistema que muestre una string por pantalla
    syscall                         # Llamo al sistema para que muestre la string

    #  std::cout << "\nFIN DEL PROGRAMA\n\n";
    #  return 0;
    #}
Fin:
    la $a0,FinDelPrograma  # Cargamos la primera dirección de la etiquet "FinPrograma" en el registro $a0
    li $v0,4            # Cargamos un 4 en el registro $v0 para luego, decirle al sistema que se mostrará una string
    syscall             # Llamamos al sistema para leer esa string
    li $v0,10           # Cargamos un 10 en el registro $v0 para decirle luego al sistema que terminará el programa
    syscall             # Llamamos al sistema para terminar el programa
