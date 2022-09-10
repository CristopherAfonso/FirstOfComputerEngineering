// AUTOR: Cristopher Manuel Afonso Mora
// FECHA: 09/03/21
// EMAIL: alu0101402031@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

using namespace std;

template<class T>
class matrix_t
{
public: // entre las lineas 23 y 46 estan declaradas todos los elementos publicos de la clase, todos son metodos
  matrix_t(const int = 0, const int = 0); // constructor de la clase matrix_t, solo hay uno definido
  ~matrix_t(); // destructor de la clase matrix_t, hace lo mismo que el destructor por defecto porque no se le pasan parametros o invoca a otras funciones
  
  void resize(const int, const int); // 1º metodo para acceder a atributos, readimensiona la matriz
  
  // getters
  int get_m(void) const; // 2º metodo para acceder a los atributos, devuelve constante el numero de filas de la matriz
  int get_n(void) const; // 3º metodo para acceder a los atriburtos, devuelve constante el numero de columnas de la matriz
  
  // getters-setters
  T& at(const int, const int); // 4º metodo para acceder a atributos, devuelve una posición en concreto de la matriz, para ello llama al metodo privado pos() que devuelve una constante
  T& operator()(const int, const int); // 5º metodo para acceder a los atributos, sobrecarga el operador (), para poder llamar a la funcion T& at(), para poder devolver una posicion concreta de la matriz
  
  // getters constantes
  const T& at(const int, const int) const; // 6º metodo para acceder a atributos, igual que el 4º pero constante 
  const T& operator()(const int, const int) const; // 7º metodo para acceder a atributos, igual que el 5º pero constante
  
  // operaciones y operadores
  void multiply(const matrix_t<T>&, const matrix_t<T>&); // 8º metodo para acceder a atributos, permite multiplicar dos matrices entre si, si se puede hacer la operacion

  void write(ostream& = cout) const; // metodo para lectura desde teclado de la clase, este metodo sobrecarga el operador <<
  void read(istream& = cin); // metodo para escritura a pantalla, este metodo sobrecarga el operador >>

private: // entre las lineas 47 y 51 estan declarados todos los elementos privados de la clase, son 4, el 1º y 2º son atributos, el 3º es el vector, y el 4º es un metodo
  int m_, n_; // m_ filas y n_ columnas
  vector_t<T> v_;
  
  int pos(const int, const int) const;
};



template<class T>
matrix_t<T>::matrix_t(const int m, const int n)
{ 
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}



template<class T>
matrix_t<T>::~matrix_t()
{}



template<class T>
void
matrix_t<T>::resize(const int m, const int n)
{
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}



template<class T>
inline int
matrix_t<T>::get_m() const
{
  return m_;
}



template<class T>
inline int
matrix_t<T>::get_n() const
{
  return n_;
}



template<class T>
T&
matrix_t<T>::at(const int i, const int j)
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}



template<class T>
T&
matrix_t<T>::operator()(const int i, const int j)
{
  return at(i, j);
}



template<class T>
const T&
matrix_t<T>::at(const int i, const int j) const
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}



template<class T>
const T&
matrix_t<T>::operator()(const int i, const int j) const
{
  return at(i, j);
}
// al sobrecargar el operador (), es como si la clase "lo estuviera usando" pero es para dejar claro,
// que vamos a pasar mas de un parametro a una funcion y que luego esa funcion hara lo que haria el operador ()



template<class T>
void
matrix_t<T>::write(ostream& os) const
{ 
  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}



template<class T>
void
matrix_t<T>::read(istream& is)
{
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}


template<class T>
inline
int
matrix_t<T>::pos(const int i, const int j) const
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}



// FASE III: producto matricial
template<class T>
void
matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B)
{
  assert(A.get_m() == B.get_n());
  m_ = A.get_m();
  n_ = B.get_n();

  v_.resize(m_ * n_);
  for( int i{1}; i <= A.get_m() ; ++i )
  {
    for( int j{1}; j <= B.get_n() ; ++j )
    {
      for( int k{1}; k <= (A.get_m() + 1); ++k )
      {
        at(i,j) = at(i,j) + A.at(i,k) * B.at(k,j);
      }
    }
  }
}
