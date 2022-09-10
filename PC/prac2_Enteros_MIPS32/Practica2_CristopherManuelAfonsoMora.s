# practica 2. Principio de computadoras
# OBJETIVO: introduce el codigo necesario para reproducir el comportamiento del programa
# C++ que se adjunta como comentarios
# Debes documentar debidamente el uso de los registros que has elegido y la correspondencia
# con las variables que has utilizado.

##include <iostream>

#int main()
#{
#    std::cout << "Calcula el bit de paridad par de un enteros de 32 bits." << std::endl;
#    std::cout << "Introduzca un 0 para salir del programa." << std::endl;
#
#    unsigned int numero;
#    do {
#        std::cout << "Introduzca un entero positivo para calcular su paridad par: ";
#        std::cin >> numero;
#        if (numero == 0) break;
#        int unos = 0; // numero de unos que tiene numero
#        for (int i = 0; i < 32 ; i++) {
#            int lsb = (numero & 1); // lsb contendrá un 1
#            unos += lsb;
#            numero = numero >> 1;
#        }
#
#        std::cout << "El número de unos del numero introducido es " << unos << std::endl;
#
#        int paridad_par = ((unos % 2) != 0);
#        std::cout << "El bit de paridad par sera " << paridad_par << std::endl;
#    } while (true);
#    std::cout << "FIN DEL PROGRAMA. " << std::endl;
#    return 0;
#}

	.data		# directiva que indica la zona de datos
titulo: 	.asciiz	"Encuentra el número de veces que aparece una cifra en un entero.\nCalcula el bit de paridad par de un enteros de 32 bits.\nIntroduzca un 0 para salir del programa.\n "
msgnumero:	.asciiz	"\n\nIntroduzca un entero positivo para calcular su paridad par: "

msgresultado1:	.asciiz	"\nEl número de unos del numero introducido es  "
msgresultado2:	.asciiz	"\nEl bit de paridad par sera "
msgfin:			.asciiz "\nFIN DEL PROGRAMA."


	.text		# directiva que indica la zona de código
main:
	# IMPRIME EL TITULO POR CONSOLA
	#    std::cout << "Encuentra el número de veces que aparece una cifra en un entero." << std::endl;
    la $a0,titulo # Cargo en el registro $a0 la dirección de memoria de la string 'titulo'
    li $v0,4      # Cargo el entero 4 en el registro $v0 para llamar al S.O. y decirle que imprima un string
    syscall       # Llamada al Sistema

	# EL MAYOR PORCENTAJE DEL CÓDIGO C++ SE ENCUENTRA DENTRO DE UNA ESTRUCTURA do { ...  } while (true).
	# IMPLEMENTA EN MIPS ESE BUCLE INFINITO, Y A CONTINUACIÓN DESARROLLA CADA UNA DE LAS SECCIONES QUE 
	# SE ENCUENTRAN EN SU INTERIOR.

	
	# INTRODUCE EN ESTA SECCION EL CÓDIGO MIPS EQUIVALENTE AL SIGUIENTE FRAGMENTO C++
	# TEN EN CUENTA QUE break NO ES SINO UN SALTO A LA SIGUIENTE INSTRUCCION QUE ESTE FUERA DEL BUCLE
	# do { ...  } while (true).
	
	li $t0,0     # Variable 'unsigned int numero' pero en este caso, le inicializo a cero con el regristro $zero para no guardarla como etiqueta y no malgastar recursos
dowhile:				  # Etiqueta donde empieza el bucle while, este es infinito, pues no tiene condición que le haga salir de él debajo de la declaración de la etiqueta

	#        std::cout << "Introduzca un entero positivo para calcular su paridad par: ";
	la $a0,msgnumero # Cargo en el registro $a0, la frase que se va a imprimir en pantalla, para mandarla a la pantalla uso las etiquetas "li" y "syscall"
    li $v0,4
    syscall
	#        std::cin >> numero;
	li $v0,5	# Cargo en el registro $v0, la constante 5 para decirle al sistema que lea un número entero por teclado
	syscall
	move $t0,$v0	# Cuando ese número entero es leído, está almacenado en el registro $v0, y lo que hago es cargar ese número en el registro temporal $t0 hasta tener un valor definitivo
	#        if (numero == 0) break;
	beqz $t0, DoWhileFin	# Si el número leído por consola es un cero exacto, salta a la etiqueta "OmisionDelDoWhile:" y se termina el programa
	

	# INTRODUCE EN ESTA SECCION EL CODIGO MIPS EQUIVALENTE AL SIGUIENTE FRAGMENTO C++
	# El desplazamiento a la derecha de un registro entero en MIPS se hace mediante la
	# instruccion srl reg_destino, reg_origen, bits_a_desplazar

	# int unos = 0; // numero de unos que tiene numero
	li $t2,0	# Se inicializa en el registro $t2, la valor de la variable "unos", pero está en un registro temporal, cuando se tenga el valor definitivo, irá al registro $s2, no se pone en memoria para no malgastar recursos
	#for (int i = 0; i < 32 ; i++) {
	move $t4,$zero	# $t4 es la variable 'i' del bucle for, y la inicializamos a cero con $zero
For:
	bge $t4,32, ForFin	#condición que evalua el valor booleano para el bucle for, si $t4 es mayor o igual a 32, salta a la etiqueta "OmisionDelFor"
	#            int lsb = (numero & 1); // lsb contendrá un 1
	and $t6,$t0,1	#El registro $t6 actua como la variable "int lsb", y con la etiqueta 'and', le estoy diciendo que aplique esa operación sobre la constante '1' y sobre el registro $t0 y todos sus bits
	#            unos += lsb;
	add $t2,$t2,$t6	#El registro $t2 es la variable "unos" y aquí al registro suma, le sumo su propio valor y el contenido del registro $t6, que es la variable "lsb"
	#            numero = numero >> 1;
	srl $t0,$t0,1	#La etiqueta "srl" me permite coger un número y rodar todos sus bits a la derecha o a la izquierda, y aquí le estoy diciendo que coga el número del registro $t0,
					#y vuelva a copiar el mismo numero en el registro $t0 (es el mismo registro) pero la copia tiene todos los bits rodados una posición a la derecha

	add $t4,$t4,1	#Incremento en una unidad de la variable de iteración del for, aquí se hace, lo que en C/C++ supondría: "i++"
	b 	For			#Esta etiqueta es un salto incondicional, si el programa llega a esta instrucción, sí o sí salta a la etiqueta "For" y ejecuta las instrucciones de ahí en adelante
	#        }
ForFin:		#Etiqueta que marca, la salida del For, si la condición de la línea 85 se cumple, se salta a esta línea y se siguen leyendo instrucciones desde esta línea
	move $s0,$t0	#En estas 4 ordenes, se cargan los datos de los registros temporales, en registros salvados, ya que se han terminado las operaciones sobre las variables, y hay que guardarlas para no perder los datos
	move $s2,$t2	#Se guardan en registros pares, porque por convenio, los impares acompañan al registro inmediatamente menor a ellos por si se guardan en ellos, datos de tipo double o superiores a 4 bytes de espacio
	move $s4,$t4
	move $s6,$t6
	#
	#        std::cout << "El número de unos del numero introducido es " << unos << std::endl;
	li $v0,4
	la $a0,msgresultado1	#Las insrucciones que hay entre las líneas 104 y 109, muestran por pantalla la cadena de caracteres con etiqueta "msgresultado 1"
	syscall					#y el valor de la variable "unos" guardada en el registro $s2
	move $a0,$s2
	li $v0,1
	syscall
	

	# INTRODUCE EN ESTA SECCION EL CÓDIGO MIPS EQUIVALENTE AL SIGUIENTE FRAGMENTO C++
	# Existen diferentes maneras de realizar el código paridad_par = ((unos % 2) != 0);
	# puedes usar condicionales u operaciones lógicas (practica pensando como se puede hacer de una forma u otra)

	#        int paridad_par = ((unos % 2) != 0);
	rem $t6,$t2,2				#Instrucción que divide el registro $t2 entre 2, y coge su resto para meterlo en en resgistro $t6, que actua como la variable "paridad_par"

	bne $t6,$zero, NotEqual		#Instrucción booleana que comprueba el valor del registro $t6

	move $t8,$zero	#Esta instrucción asigna el valor 0 a la variable "paridad_par" cuando se da el caso en que se cumple la condición de que el numero de "unos" es par
	b 	MuestraEnPantalla

NotEqual:
	li $t8,1		#Esta instrucción asigna el valor 1 a la variable "paridad_par" cuando se da el caso en que se cumple la condición de que el numero de "unos" es impar

MuestraEnPantalla:

	#        std::cout << "El bit de paridad par sera " << paridad_par << std::endl;
	li $v0,4
	la $a0,msgresultado2	#La línea anterior, la actual y las siguientes 4, muestran por pantall el valor de la cadena de caracteres con etiqueta "msgresultado2"
	syscall					# y el valor de la variable "paridad_par" guardada en el registro $t8
	li $v0,1
	move $a0,$t8
	syscall

	b 	dowhile		#Salto Incondicional hacia la etiqueta "while"
	

	# las siguientes instrucciones  imprimen la cadena de fin y finalizan el programa
DoWhileFin:
	li $v0,4
	la $a0,msgfin
	syscall
	li $v0,10
	syscall