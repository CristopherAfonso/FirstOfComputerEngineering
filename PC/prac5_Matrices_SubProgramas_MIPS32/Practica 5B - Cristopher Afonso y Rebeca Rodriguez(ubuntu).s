# Práctica 5B de Principios de Computadores.
# Autores: Cristopher Manuel Afonso Mora (alu0101402031).
#          Rebeca Rodríguez Rodríguez (alu0101394763).
# Fecha: XX/04/2021.


# PSEUDOCÓDIGO EN C++:
#
#   #include <iostream>
#   #include <vector>
#
#   void ShowResults(std::vector<int>& enteros, std::vector<double>& dobles, int& limit) {
#       int counter1{0};
#       int counter2{0};
#
#       std::cout << "\n\n                     Tabla de Resultados\n\n";
#       std::cout << "               Valor n  -  Valor x  -  Result\n";
#
#       for(int i{0}; i < limit; ++i) {
#           if(i != 9) {std::cout << " ";}
#           std::cout << i+1 << "º Resultado:    " << enteros[counter1] << "           ";
#           std::cout << dobles[counter2] << "          " << dobles[++counter2] << std::endl;
#           ++counter1;
#           ++counter2;
#       }
#   }
#
#   double fi(int n, double& x) {
#     double result{0.00};
#     double prev_1 = 0.5;
#     double prev_2 = 1.0;
#     if (n == 0) {
#       return prev_1;
#     }
#     if (n == 1) {
#       return prev_2;
#     }
#     for (int i = 2; i <= n; ++i) {
#       result = prev_1 * prev_2 * x;
#         prev_1 = prev_2;
#         prev_2 = result;
#     }
#     return result;
#   }
#
#   double fr(int n, double& x) {
#       double result{0.00};
#
#       // Casos triviales
#       if(n == 0) { result = 0.5; }
#       if(n == 1) { result = 1; }
#
#       // Caso No Trivial
#       if(n > 1) { result = fr(n - 1, x) * fr(n - 2, x) * x; }
#
#       return result;
#   }
#
#   int main() {
#       std::cout << "\nHola, soy un programa que implementa la siguiente\n";
#       std::cout << "Función matemática:\n\n";
#       std::cout << "           {     0,5                        si  n = 0\n";
#       std::cout << "  f(n,x) = {     1                          si  n = 1\n";
#       std::cout << "           { f(n - 1, x)*f(n - 2, x)*x      si  n > 1\n\n";
#       std::cout << "Donde 'n' es un número entero mayor o igual a 0\n";
#       std::cout << "y 'x' e 'f(n,x)' flotantes en doble precisión\n\n";
#       std::cout << "Este programa permite ejecutar esta función de dos formas\n";
#       std::cout << "distintas, de forma iterativa (llamando a la función solo\n";
#       std::cout << "una vez), y de forma recursiva (la función se llama a sí\n";
#       std::cout << "misma continuamente hasta llegar al caso trivial). Esta\n";
#       std::cout << "función también guarda en memoria, el resultado de los 10\n";
#       std::cout << "últimos resultados que haya dado la fórmula tras ser\n";
#       std::cout << "ejecutada por el usuario, ya sea con la forma iterativa\n";
#       std::cout << "o recursiva\n\n";
#
#       int option{1};
#       int times{0};
#       int limit{0};
#       std::vector<int> ten_first_n;
#       std::vector<double> twenty_first_doubles;
#       ten_first_n.resize(10);
#       twenty_first_doubles.resize(20);
#
#       while(option != 0) {
#           std::cout << "Introduzca opción: <1> Iterativa - <2> Recursiva - <0> Salir: " ;
#           std::cin >> option;
#           std::cout << std::endl;
#
#           while(option < 0 || option > 2) {
#               option = 0; // Ponemos la variable a cero, por si no se lee ningún número, se salga automáticamente
#
#               std::cout << "Número erroneo, ingrese el dato de nuevo\n";
#               std::cout << "Introduzca opción: <1> Iterativa - <2> Recursiva - <0> Salir: " ;
#               std::cin >> option;
#               std::cout << std::endl << std::endl;
#           }
#
#           if(option == 1) {
#               int n{0};
#               double x{0.00};
#               double result{0.00};
#
#               std::cout << "Introduzca el valor de n: ";
#               std::cin >> n;
#               while(n < 0) {
#                   std::cout << "Valor negativo no permitido, ingrese un valor válido: ";
#                   std::cin >> n;
#               }
#               std::cout << "Introduzca el valor de x: ";
#               std::cin >> x;
#               std::cout << std::endl;
#
#               result = fi(n, x);
#
#               if(times >= 0 && times <= 9) {
#                   ten_first_n[times] = n;
#                   twenty_first_doubles[2*times] = x;
#                   twenty_first_doubles[2*times+1] = result;
#                   ++limit;
#               }
#           }
#
#           if(option == 2) {
#               int n{0};
#               double x{0.00};
#               double result{0.00};
#
#               std::cout << "Introduzca el valor de n: ";
#               std::cin >> n;
#               while(n < 0) {
#                   std::cout << "Valor negativo no permitido, ingrese un valor válido: ";
#                   std::cin >> n;
#               }
#               std::cout << "Introduzca el valor de x: ";
#               std::cin >> x;
#               std::cout << std::endl;
#
#               result = fr(n, x);
#
#               if(times >= 0 && times <= 9) {
#                   ten_first_n[times] = n;
#                   twenty_first_doubles[2*times] = x;
#                   twenty_first_doubles[2*times+1] = result;
#                   ++limit;
#               }
#           }
#           ++times;
#       }
#
#       ShowResults(ten_first_n, twenty_first_doubles, limit);
#       std::cout << "\nFin del Programa\n\n";
#
#       return 0;
#   }


# ASIGNACIÓN DE REGISTROS A LAS VARIABLES:
#
#   Estos son registros salvados usados como variables en el main:
#
#   result                -> $f22
#   x                     -> $f20
#   n                     -> $s4
#   twenty_first_doubles  -> $s3 (dirección base en memoria)
#   ten_first_n           -> $s2 (dirección base en memoria)
#   limit                 -> $s1
#   times                 -> $s0
#
#   Registros pasados como parámetros a la funciones:
#        "fi:" y "fr:"
#
#   n                     -> $a0
#   x                     -> $f0
#   result                -> $f2 (resultado que devuelve la función)
#
#   Registros pasados como parámetros a la función:
#         "ShowResults:"
#
#   limit                 -> $a2
#   twenty_first_doubles  -> $a1 (dirección base del vector)
#   ten_first_n           -> $a0 (dirección base del vector)
#


    .data
    .align 2
titulo:      .asciiz "Hola, soy un programa que implementa la siguiente funcion matematica:\n\n\n"
funcion:     .asciiz "           {   0,5                                  si  n = 0\n  f(n,x) = {   1                                    si  n = 1\n           {   f(n - 1, x)*f(n - 2, x)*x     si  n > 1\n\n\nDonde 'n' es un numero entero mayor o igual a 0 y 'x' e 'f(n,x)' flotantes en doble precision.\n\n"
explicacion: .asciiz "Este programa permite ejecutar esta funcion de dos formas distintas, de forma iterativa (llamando a la funcion solo una vez), y de forma recursiva (la funcion se llama a si misma continuamente hasta llegar al caso trivial). Esta función tambien guarda en memoria el resultado de los 10 ultimos resultados que haya dado la formula tras ser ejecutada por el usuario, ya sea con la forma iterativa o recursiva\n\n"
msgopcion:   .asciiz "\nIntroduzca una opcion:\n   < 1 > Iterativa.\n   < 2 > Recursiva.\n   < 0 > Salir del programa.\n\nSu elección: "
msgcontrol:  .asciiz "\nNumero erroneo. Por favor, ingrese el dato de nuevo.\n"
msgcontroln: .asciiz "\nValor negativo no permitido. Por favor, ingrese un valor válido.\n"
msgn:        .asciiz "\nIntroduzca el valor de n: "
msgx:        .asciiz "Introduzca el valor de x: "
resultado:   .asciiz "El resultado de esta llamada es: "
msgtabla:    .asciiz "\n\n                     Tabla de Resultados\n\n               Valor n  -  Valor x  -  Result\n"
msgresult:   .asciiz "º resultado:    "
spaces:      .asciiz "        "
msgfin:      .asciiz "\n-- FIN DEL PROGRAMA --"

option:                .word     1
times:                 .word     0
limit:                 .word     0
                       .align    2
ten_first_n:           .space   40
                       .align    2
twenty_first_doubles:  .space  160
counter1:              .word     0
counter2:              .word     0


    .text
ShowResults:
  addi $sp, $sp, -40          # Hacemos 10 espacios en la pila
                              # Guardamos el valor previo de los registros $s, para recuperarlos al salir, tal cual dice el convenio
  sw $s6, 36($sp)             # Variable auxiliar al mostrar resultados en pantalla, uso este registro para preservar el resultado tras un syscall
  sw $s5, 32($sp)             # Variable "i" de iteración del for, variable local
  sw $s4, 28($sp)             # Counter2, variable local
  sw $s3, 24($sp)             # Counter1, variable local
  sw $s2, 20($sp)             # Dirección en memoria de limit
  sw $s1, 16($sp)             # Dirección en memoria de twenty_first_doubles
  sw $s0, 12($sp)             # Dirección en memoria de ten_first_n
  sw $a2, 8($sp)              # Dirección en memoria de limit
  sw $a1, 4($sp)              # Dirección en memoria de twenty_first_doubles
  sw $a0, 0($sp)              # Dirección en memoria de ten_first_n

  move $s4, $zero             # int Counter2{0}
  move $s3, $zero             # int Counter1{0}

                              # Se copia el contenido de los registros $a a $s para que no se pierda su contenido tras los syscall.
  move $s2, $a2               # Dirección en memoria de limit
  lw $s2, 0($s2)              # Sacamos de la memoria, el valor de limit poniendolo en $s2
  move $s1, $a1               # Dirección en memoria de twenty_first_doubles
  move $s0, $a0               # Dirección en memoria de ten_first_n

  la $a0, msgtabla
  li $v0, 4                   # Imprimimos el titulo de la tabla
  syscall

  addi $s1, $s1, -8           # Restamos 8 para que en el for, sumarselos y empezar desde la dirección base

  move $s5, $zero             # int i{0}
  For:
    bge $s5, $s2, FinFor      # Comparamos i < limit

    IfPrintSpace:
      beq $s5, 9, IfFinPrintSpace

      li $a0, 32              # 32 se corresponde con el espacio según el código ASCII.
      li $v0, 11              # 11 es la llamada al sistema para imprimir caracteres.
      syscall                 # Se imprime un espacio.

    IfFinPrintSpace:

      addi $t0, $s5, 1        # Hago i + 1 para mostrarlo por pantalla

      move $a0, $t0
      li $v0, 1               # Se imprime i + 1
      syscall

      la $a0, msgresult
      li $v0, 4               # Imprimimos "Xº Resultado:"
      syscall

      mul $t1, $s3, 4         # Guardo en $t1, los bytes que me tengo que desplazar para llegar al int que debo mostrar
      addu $t1, $t1, $s0      # Guardo en $t1, la dirección de memoria de: enteros[counter1]
      lw $t1, 0($t1)          # Saco el dato en memoria de enteros[counter1], sobreescribiendo $t1

      move $a0, $t1
      li $v0, 1               # Le decimos al S.O. que nos muestre un int, el actual n
      syscall

      la $a0, spaces
      li $v0, 4               # Imprimimos una serie de espacios por pantalla
      syscall

      addu $s1, $s1, 8

      l.d $f4, 0($s1)         # Paso el double al registro $f4

      mov.d $f12, $f4
      li $v0, 3               # Mostramos por pantalla el double X
      syscall

      la $a0, spaces
      li $v0, 4               # Imprimimos una serie de espacios por pantalla
      syscall

      addi $s1, $s1, 8        # Accedemos a la posición de memoria del Result, del número X recién imprimido

      l.d $f6, 0($s1)         # Coloco el número Result, en $f6

      mov.d $f12, $f6
      li $v0, 3               # Muestro por pantalla el double Result
      syscall

      li $a0, 10              # 10 = '\n' en Código ASCII, cargamos el carácter para sacarlo en pantalla
      li $v0, 11              # 11 es la llamada al sistema para imprimir caracteres.
      syscall

    addi $s4, $s4, 1          # ++counter2
    addi $s3, $s3, 1          # ++counter1

    addi $s5, $s5, 1          # ++i

  b   For

  FinFor:

  lw $s6, 36($sp)
  lw $s5, 32($sp)
  lw $s4, 28($sp)             # Devolvemos a todos los registros que hemos usado en la función
  lw $s3, 24($sp)             # El valor que tenían antes de entrar a la función
  lw $s2, 20($sp)
  lw $s1, 16($sp)
  lw $s0, 12($sp)
  lw $a2, 8($sp)
  lw $a1, 4($sp)
  lw $a0, 0($sp)

  addi $sp, $sp, 40

  jr $ra                    # Se regresa a la función main y se sale de la función ShowResults.

##############################################################################################

fi:
  addi $sp, $sp, -12        # Hacemos espacio en la pila para 2 variables, un int, y un double
                            # Usaremos el registro $f2, para devolver el valor final de result a la función main
  s.d $f0, 4($sp)           # Guardamos X en la pila
  sw $a0, 0($sp)            # Guardamos n en la pila

  li.d $f4, 0,00            # Se inicializa la variable result.
  li.d $f6, 0,50            # Se inicializa la variable prev_1.
  li.d $f8, 1,00            # Se inicializa la variable prev_2.

  IfIgualCero:              # Si n es igual a 0, la función devolverá 0.5
    bnez $a0, FinIgualCero
    mov.d $f4, $f6          # Guardo en $f4 el valor de result
  FinIgualCero:


    li $t0, 1               # Constante 1, nos ayudará en IfIgualUno
  IfIgualUno:               # Si n es igual a 1, la función devolverá 1
    bne $a0, $t0, FinIfIgualUno
    mov.d $f4, $f8          # Guardo en $f4 el valor de result
  FinIfIgualUno:


    li $t3, 2               # Se inicializa a 2 la variable i del bucle for.
  ForMayorIgualDos:
    lw $a0, 0($sp)
    bgt $t3, $a0, FinForMayorIgualDos

    mul.d $f4, $f6, $f8
    mul.d $f4, $f4, $f0     # Se calcula el nuevo valor de result.

    mov.d $f6, $f8          # Se iguala prev_1 a prev_2
    mov.d $f8, $f4          # Se iguala prev_2 a result

    addi $t3, $t3, 1        # ++i

    b ForMayorIgualDos
  FinForMayorIgualDos:

    mov.d $f2, $f4              # Movemos el resultado a $f2, que se retomará en el main.

    l.d $f0, 4($sp)             # Cargamos X en el registro al que entro a la funcion
    lw $a0, 0($sp)              # Cargamos n en el registro en el que entro a la funcion
    addi $sp, $sp, 12           # Devolvemos la pila a su posición original

    jr $ra                      # Regresamos a la función main y se sale de fi.

##############################################################################################

fr:
  addi $sp, $sp, -16            # Hacemos espacio en la pila para 2 variables, un int, y un double
                                # Usaremos el registro $f2, para devolver el valor final de result a la función main
                                # Tenemos pasado como parámetro, el valor X del main, no se guarda en la pila porque nunca en esta función modificamos el registro o usamos un syscall
  s.d $f0, 8($sp)               # Guardamos X en la pila
  sw $ra, 4($sp)
  sw $a0, 0($sp)                # Guardamos n en la pila

  li.d $f4, 1,00                # Se inicializa la variable result.

  li $t0, 1

  beq $a0, $zero, NIgualCero    # Si n = 0 se salta a la etiqueta NIgualCero

  beq $a0, $t0, NIgualUno       # Si n = 1 se salta a la etiqueta NIgualUno

  bgt $a0, $t0, NMayorUno       # Si n > 1, se salta a la etiqueta NMayorUno


  NIgualCero:                   # Si n es igual a 0, la función devolverá 0.5
    li.d $f4, 0,50              # Guardamos en $f4 el valor de result
    b FinFr

  NIgualUno:                    # Si n es igual a 1, la función devolverá 1
    li.d $f4, 1,00              # Guardamos en $f4 el valor de result
    b FinFr

  NMayorUno:                    # En caso de que n sea mayor que 1:
    addi $a0, $a0, -1           # Le quitamos 1 a n para pasarla a la función fr de nuevo

    jal fr                      # Llamada a la función. Devuelve el resultado en $f2.

    mov.d $f6, $f2              # Copiamos el resultado a $f6.

    addi $sp, $sp, -8
    s.d $f6, 0($sp)             # Guardamos $f6 en la pila para no perder su valor.

    addi $a0, $a0, -1           # Le quitamos 1 de nuevo a n para pasarla a la función fr por segunda vez

    jal fr                      # Llamada a la función. Devuelve el resultado en $f2.

    l.d $f6, 0($sp)
    addi $sp, $sp, 8            # Recuperamos $f6 de la pila una vez que hemos hecho la segunda llamada.

    mov.d $f8, $f2              # Movemos el segundo resultado a $f8.

    mul.d $f4, $f6, $f8         # Multiplicamos f(n-1, x) * f(n-2, x) y lo guardamos en $f4.
    mul.d $f4, $f4, $f0         # Multiplicamos el contenido de $f4 por x y lo guardamos en el mismo registro.

  FinFr:
    mov.d $f2, $f4              # Pasamos a $f2 el valor result que retornaremos a la función main

    lw $a0, 0($sp)              # Recuperamos n en el registro en el que entro a la función.
    lw $ra, 4($sp)              # Recuperamos la dirección desde la que se llamó a la función.
    l.d $f0, 8($sp)             # Recuperamos x de la pila.
    addi $sp, $sp, 16           # Devolvemos la pila a su posición original.

    jr $ra                      # Volvemos a la dirección desde donde se llamó a la función y salimos de fr.

##############################################################################################

main:
  la $a0, titulo
  li $v0, 4
  syscall                           # Se imprime el título por pantalla.

  la $a0, funcion
  li $v0, 4
  syscall                           # Se imprime la función que implementa el programa.

  la $a0, explicacion
  li $v0, 4
  syscall                           # Se imprime una pequeña explicación del funcionamiento del programa.

  move $s0, $zero                   # Se inicializa la variable times a 0. Se almacena en $s0.
  move $s1, $zero                   # Se inicializa la variable limit a 0. Se almacena en $s1.
                                    # Cuando los registros $s0 y $s1 cambien de valor, se guardará en memoria
  la $s2, ten_first_n               # Cargamos la dirección base del vector de enteros
  la $s3, twenty_first_doubles      # Cargamos la dirección base del vector de doubles

  while:
    la $a0, msgopcion
    li $v0, 4
    syscall                         # Se pide al usuario que introduzca una opción (llamar a  fr o fi, o salir).

    li $v0, 5
    syscall
    move $t0, $v0                   # Se almacena la opción del usuario en $t0.

    blt $t0, 0, Control             # Si la opción introducida es menor que 0 o mayor que 2,
    bgt $t0, 2, Control             # se salta a la etiqueta Control.

    beq $t0, 0, PrintResults        # Si la opción introducida es 0, se salta al final del programa (etiqueta PrintResults).
    beq $t0, 1, IterativeFunction   # Si la opción introducida es 1, se salta a la etiqueta IterativeFunction.
    beq $t0, 2, RecursiveFunction   # Si la opción introducida es 2, se salta a la etiqueta RecursiveFunction.

    Control:
      la $a0, msgcontrol
      li $v0, 4
      syscall                       # Se imprime el mensaje de control (se indica que el dato introducido no es válido).

      b while                       # Se salta al principio del bucle while.

    IterativeFunction:
      move $s4, $zero               # Valor de n
      li.d $f20, 0,00               # Valor de x
      li.d $f22, 0,00               # Valor de Result

      la $a0, msgn
      li $v0, 4
      syscall                       # Se pide el valor de n.

      li $v0, 5
      syscall
      move $s4, $v0                 # Se lee n y se almacena su valor en $s4

      fi_Control_n:
        bgez $s4, After_fi_Control_n

        la $a0, msgcontroln
        li $v0, 4                   # Se imprime el mensaje de error en el parámetro n
        syscall

        b IterativeFunction         # Volvemos al inicio de IterativeFuncion para volver a pedir n

      After_fi_Control_n:

        la $a0, msgx
        li $v0, 4                   # Se pide el valor de x.
        syscall

        li $v0, 7
        syscall
        mov.d $f20, $f0             # Se lee x y se almacena su valor en $f20.

        la $a0,resultado
        li $v0, 4                   # Muestro el resultado actual de la función
        syscall

        move  $a0, $s4              # Cargamos el n leído como parámetro a la función
        sw   $s4, 0($s2)
        mov.d $f0, $f20             # Cargamos el x leído como parametro a la función

        jal fi                      # Se salta a la función fi.

        mov.d $f22, $f2

        mov.d $f12, $f22            # Muevo el double para mostrarlo por pantalla
        li $v0, 3                   # Le digo al S.O. que imprima un double
        syscall

        li $a0, 10
        li $v0, 11                  # 11 es la llamada al sistema para imprimir caracteres.
        syscall                     # Se imprime un salto de línea.

        li $a0, 10
        li $v0, 11                  # 11 es la llamada al sistema para imprimir caracteres.
        syscall                     # Se imprime un salto de línea.

        IfNFi:
          bgt $s0, 9, Fin_IterativeFunction    # Hago if(times >= 0 && times <= 9) {
          blt $s0, $zero, Fin_IterativeFunction


          sw $s4, 0($s2)            # Almacenamos el número n
          addiu $s2, $s2, 4         # Sumamos 4 bytes a la posición

          s.d $f20, 0($s3)          # Guardamos en memoria el valor de X
          addiu $s3, $s3, 8

          s.d $f22, 0($s3)          # Guardamos en memoria el valor de Result
          addiu $s3, $s3, 8

          addi $s1, $s1, 1          # ++limit
          la $t2, limit             # Cargamos la dirección de limit
          sw $s1, 0($t2)            # Reescribimos el valor en memoria de limit

      Fin_IterativeFunction:
        addi $s0, $s0, 1            # ++times

        b while                     # Reiteramos

    RecursiveFunction:
      move $s4, $zero               # Valor de n
      li.d $f20, 0,00               # Valor de x
      li.d $f22, 0,00               # Valor de Result

      la $a0, msgn
      li $v0, 4
      syscall                       # Se pide el valor de n.

      li $v0, 5
      syscall
      move $s4, $v0                 # Se lee n y se almacena su valor en $s4

      fr_Control_n:
        bgez $s4, After_fr_Control_n

        la $a0, msgcontroln
        li $v0, 4                   # Se imprime el mensaje de error en el parámetro n
        syscall

        b RecursiveFunction         # Volvemos al inicio de IterativeFuncion para volver a pedir n

      After_fr_Control_n:

        la $a0, msgx
        li $v0, 4                   # Se pide el valor de x.
        syscall

        li $v0, 7
        syscall
        mov.d $f20, $f0             # Se lee x y se almacena su valor en $f20.

        la $a0,resultado
        li $v0, 4                   # Muestro el resultado actual de la función
        syscall

        move $a0, $s4               # Cargamos el n leído como parámetro a la función
        mov.d $f0, $f20             # Cargamos el x leído como parametro a la función

        jal fr                      # Se salta a la función fr.

        mov.d $f22, $f2

        mov.d $f12, $f22            # Movemos el double para mostrarlo por pantalla
        li $v0, 3                   # Le decimos al S.O. que imprima un double
        syscall

        li $a0, 10
        li $v0, 11                  # 11 es la llamada al sistema para imprimir caracteres.
        syscall                     # Se imprime un salto de línea.

        li $a0, 10
        li $v0, 11                  # 11 es la llamada al sistema para imprimir caracteres.
        syscall                     # Se imprime un salto de línea.

        IfNFr:
          bgt $s0, 9, Fin_RecursiveFunction    # Hacemos if(times >= 0 && times <= 9) {
          blt $s0, $zero, Fin_RecursiveFunction


          sw $s4, 0($s2)            # Almacenamos el número n
          addiu $s2, $s2, 4         # Sumamos 4 bytes a la posición

          s.d $f20, 0($s3)          # Guardamos en memoria el valor de X
          addiu $s3, $s3, 8

          s.d $f22, 0($s3)          # Guardamos en memoria el valor de Result
          addiu $s3, $s3, 8

          addi $s1, $s1, 1          # ++limit
          la $t2, limit             # Cargamos la dirección de limit
          sw $s1, 0($t2)            # Reescribimos el valor en memoria de limit

      Fin_RecursiveFunction:
        addi $s0, $s0, 1            # ++times

        b while                     # Reiteramos

  PrintResults:
    la $a2,limit
    la $a1,twenty_first_doubles     # Le pasamos los argumentos a la funcion ShowResults
    la $a0,ten_first_n
    jal ShowResults                 # Llamamos a la función que muestra los 10 primeros resultados

  la $a0, msgfin
  li $v0, 4
  syscall                           # Se imprime el mensaje final.

  fin:
    li $v0, 10
    syscall                         # Se acaba el programa.