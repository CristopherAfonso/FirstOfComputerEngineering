// AUTOR: Cristopher Manuel Afonso Mora
// FECHA: 09/03/21
// EMAIL: alu0101402031@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
//

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // pautas de estilos [44] y [73]: primero "public" y después "private"
public: // todos los elementos publicos de la clase rational_t estan declarados entre las lineas 28 y 57 y son todos metodos de la clase
  rational_t(const int = 0, const int = 1); // Construtor de la clase rational_t, solo hay uno definido
  ~rational_t() {} // Destructor de la clase rational_t, hace lo mismo que el destructor por defecto
  
  // pauta de estilo [71]: indentación a 2 espacios
  
  // getters
  int get_num() const; // 1º metodo para acceder a atributos, getter 1, variable num_
  int get_den() const; // 2º metodo para acceder a atributos, getter 2, variable den_
  
  // setters
  void set_num(const int); // 3º metodo para acceder a atributos, setter 1, variable num_
  void set_den(const int); // 4º metodo para acceder a atributos, setter 2, variable den_

  double value(void) const;
  rational_t opposite(void) const; // metodo que devuelve el valor absoluto del numero real, pero con signo contrario
  rational_t reciprocal(void) const; // metodo que devuelve el inverso del numero real, matematicamente lo eleva a -1

  bool is_equal(const rational_t&, const double precision = EPSILON) const; // metodo que sobrecarga el operador == entre objetos de la clase
  bool is_greater(const rational_t&, const double precision = EPSILON) const; // metodo que sobrecarga el operador > entre objetos de la clase
  bool is_less(const rational_t&, const double precision = EPSILON) const; // metodo que sobrecarga el operador < entre objetos de la clase

  rational_t add(const rational_t&) const; // metodo que sobrecarga el operador + entre objetos de la clase, el primero de los objetos sera el que cambiara su valor
  rational_t substract(const rational_t&) const; // metodo que sobrecarga el operador - entre objetos de la clase, el primero de los objetos sera el que cambiara su valor
  rational_t multiply(const rational_t&) const; // metodo que sobrecarga el operador * entre objetos de la clase, el primero de los objetos sera el que cambiara su valor
  rational_t divide(const rational_t&) const; // metodo que sobrecarga el operador / entre objetos de la clase, el primero de los objetos sera el que cambiara su valor

  void write(ostream& os = cout) const; // metodo para lectura desde teclado de la clase rational_t
  void read(istream& is = cin); // metodo para escritura a pantalla de la clase rational_t
  
private: // todos los elementos privados de la clase rational_t estan declarados entre las lineas 58 y 60 y son todos atributos
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  int num_, den_; //num_ y den_ son atributos privados de la clase rational_t
};


// sobrecarga de los operadores de E/S
ostream& operator<<(ostream& os, const rational_t&); 
istream& operator>>(istream& is, rational_t&);

// FASE I: operadores
rational_t operator+(const rational_t&, const rational_t&); // metodo que sobrecarga el operador + entre objetos de la clase, con este metodo, se crea un nuevo objeto a partir de los dos dados
rational_t operator-(const rational_t&, const rational_t&); // metodo que sobrecarga el operador - entre objetos de la clase, con este metodo, se crea un nuevo objeto a partir de los dos dados
rational_t operator*(const rational_t&, const rational_t&); // metodo que sobrecarga el operador * entre objetos de la clase, con este metodo, se crea un nuevo objeto a partir de los dos dados
rational_t operator/(const rational_t&, const rational_t&); // metodo que sobrecarga el operador / entre objetos de la clase, con este metodo, se crea un nuevo objeto a partir de los dos dados

