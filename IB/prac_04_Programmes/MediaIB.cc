#include <iostream>
#include <sstream>
#include <string>

int main () {
    double AlumnoA, AlumnoB, AlumnoC;
    std::string SAlumnoA, SAlumnoB, SAlumnoC;

    std::cout << "Hola, soy un programa que puede calcular medias ponderales." << std::endl
              << "En concreto, la media de 3 alumnos de la asignatura Informática Básica." << std::endl
              << "Solo necesito que me des la calificación de cada uno" << std::endl
              << "Evidentemente debes darme valores entre el 0 y el 10, sean o no decimales. No se aceptan valores fuera de ese intervalo." << std::endl << std::endl;
              
    do {
    std::cout << "Introduce la calificación del 1º alumno: ";
    std::getline (std::cin, SAlumnoA);
    std::stringstream(SAlumnoA) >> AlumnoA;
}while (0.0 > AlumnoA || 10.0 < AlumnoA);

    do {
    std::cout << "Ahora introduce la calificación del 2º alumno: ";
    std::getline (std::cin, SAlumnoB);
    std::stringstream(SAlumnoB) >> AlumnoB;
}while (0.0 > AlumnoB || 10.0 < AlumnoB);;

    do {
    std::cout << "Por último introduce la calificación del 3º alumno: ";
    std::getline (std::cin, SAlumnoC);
    std::stringstream(SAlumnoC) >> AlumnoC;
}while (0.0 > AlumnoC || 10.0 < AlumnoC);;

    std::cout << "La media ponderal de los 3 alumnos es de "
              << ((AlumnoA + AlumnoB + AlumnoC)/3) << " Puntos" << std::endl << std::endl;

    return 0;
    }

    