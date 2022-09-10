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
titulo: 	.asciiz	"Calcula el bit de paridad par de un enteros de 32 bits.\nIntroduzca un 0 para salir del programa.\n "
msgnumero:	.asciiz	"\n\nIntroduzca un entero positivo para calcular su paridad par: "

msgresultado1:	.asciiz	"\nEl número de unos del numero introducido es  "
msgresultado2:	.asciiz	"\nEl bit de paridad par sera "
msgfin:			.asciiz "\nFIN DEL PROGRAMA."


	.text		# directiva que indica la zona de código
main:
	# IMPRIME EL TITULO POR CONSOLA
	#    std::cout << "Encuentra el número de veces que aparece una cifra en un entero." << std::endl;


	# EL MAYOR PORCENTAJE DEL CÓDIGO C++ SE ENCUENTRA DENTRO DE UNA ESTRUCTURA do { ...  } while (true).
	# IMPLEMENTA EN MIPS ESE BUCLE INFINITO, Y A CONTINUACIÓN DESARROLLA CADA UNA DE LAS SECCIONES QUE 
	# SE ENCUENTRAN EN SU INTERIOR.

	
	# INTRODUCE EN ESTA SECCION EL CÓDIGO MIPS EQUIVALENTE AL SIGUIENTE FRAGMENTO C++
	# TEN EN CUENTA QUE break NO ES SINO UN SALTO A LA SIGUIENTE INSTRUCCION QUE ESTE FUERA DEL BUCLE
	# do { ...  } while (true).

	#        std::cout << "Introduzca un entero positivo para calcular su paridad par: ";
	#        std::cin >> numero;
	#        if (numero == 0) break;
	

	# INTRODUCE EN ESTA SECCION EL CODIGO MIPS EQUIVALENTE AL SIGUIENTE FRAGMENTO C++
	# El desplazamiento a la derecha de un registro entero en MIPS se hace mediante la
	# instruccion srl reg_destino, reg_origen, bits_a_desplazar

	# int unos = 0; // numero de unos que tiene numero
	#for (int i = 0; i < 32 ; i++) {
	#            int lsb = (numero & 1); // lsb contendrá un 1
	#            unos += lsb;
	#            numero = numero >> 1;
	#        }
	#
	#        std::cout << "El número de unos del numero introducido es " << unos << std::endl;
	

	# INTRODUCE EN ESTA SECCION EL CÓDIGO MIPS EQUIVALENTE AL SIGUIENTE FRAGMENTO C++
	# Existen diferentes maneras de realizar el código paridad_par = ((unos % 2) != 0);
	# puedes usar condicionales u operaciones lógicas (practica pensando como se puede hacer de una forma u otra)

	#        int paridad_par = ((unos % 2) != 0);
	#        std::cout << "El bit de paridad par sera " << paridad_par << std::endl;
	

	
	# las siguientes instrucciones  imprimen la cadena de fin y finalizan el programa
	li $v0,4
	la $a0,msgfin
	syscall
	li $v0,10
	syscall
 
