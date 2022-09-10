// AUTOR: Cristopher Manuel Afonso Mora
// FECHA: 09/03/21
// EMAIL: alu0101402031@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g rational_t.cpp main_p2.cpp -o main_p2

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include <iostream>
#include <cmath>

// pauta de estilo [41]: ficheros de cabecera agrupados y separados
#include "rational_t.hpp"

#include "vector_t.hpp"

#include "matrix_t.hpp"

using namespace std;

int main()
{
  rational_t a(1, 2), b(3);

  // FASE I
  cout << "a + b: ";
  (a+b).write(); // en la clase rational_t , vector_t y matrix_t , hay en cada una un metodo llamado write(), pero como C++ sabe que 'a' y 'b' son objetos de tipo rational_t
  // entonces sabe que debe usar el metodo de la clase rational_t y no de las otras clases, pasa lo mismo con el resto de operadores sobrecargados del resto de clases y de la misma

  cout << "b - a: ";
  (b-a).write();

  cout << "a * b: ";
  (a*b).write();
  
  cout << "a / b: ";
  (a/b).write();
  
  cout << endl;
  
  // FASE II
  vector_t<double> v, w;
  v.read(), v.write();
  w.read(), w.write();
  
  cout << "Producto escalar de vector_t<double>: " << scal_prod(v, w) << endl << endl;
  
  vector_t<rational_t> x, y, z1, z2;
  x.read(), x.write();
  y.read(), y.write();
  
  cout << "Producto escalar de vector_t<rational_t>: " << scal_prod(x, y) << endl << endl;
  
  
  // FASE III
  matrix_t<double> A, B, C;
  A.read(), A.write();
  B.read(), B.write();
  
  C.multiply(A, B);
  cout << "Multiplicación de matrices A y B: " << endl;
  C.write();

  // FASE DE MODIFICACION EN EL AULA
  std::cout << "Dado el vector x: ";
  for(int i{0}; i < v.get_size(); ++i)
{
  std::cout << x[i] << "  ";
}
std::cout << "Y dado el vector y: ";
  for(int i{0}; i < v.get_size(); ++i)
{
  std::cout << y[i] << "  ";
}
std::cout << endl << "Sus vectores derivados, cogiendo solo sus posiciones pares son: \n";
std::cout << new_pair_vector(v) << "\n";
std::cout << new_pair_vector(w) << "\n";

  return 0;
}