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

using namespace std;

template<class T>
class vector_t
{
public: // entre las lineas 21 y 44 estan declarados los elementos publicos, todos son metodos
  vector_t(const int = 0); // constructor de la clase vector_t, solo hay uno definido
  ~vector_t(); // destructor de la clase vector_t
  
  void resize(const int); // 1º metodo para acceder a los atributos, redimensiona la clase vector
  
  // getters
  T get_val(const int) const; // 2º metodo para acceder a atributos, getter que devuelve un valor concreto dentro del vector, pero ese valor es constante
  int get_size(void) const; // 3º metodo para acceder a atributos, getter que devuelve la longitud del vector
  
  // setters
  void set_val(const int, const T); // 4º metodo para acceder a atributos, setter que 
  
  // getters-setters
  T& at(const int); // 5º metodo para acceder a atributos, devuelve una posición en concreta del vector, pero es un valor no constante
  T& operator[](const int); // 6º metodo para acceder a atributos, llama a la función at(), este metodo sobrecarga al operador [] a la hora de llamar a las posiciones de memoria
  
  // getters constantes
  const T& at(const int) const; // 7º metodo para acceder a atributos, igual que el 5º, pero constante
  const T& operator[](const int) const; // 8º metodo para acceder a atributos, igual que el 6º, pero constante

  void write(ostream& = cout) const; // metodo para escritura a pantalla, este metodo sobrecarga al operador <<
  void read(istream& = cin); //metodo para lectura desde el teclado, este metodo sobrecarga al operador >>

private: // entre las lineas 45 y 50 estan declarados los elementos privados, los dos primeros son atributos y los otros dos son metodos
  T *v_;
  int sz_;
  
  void build(void);
  void destroy(void);
};



template<class T>
vector_t<T>::vector_t(const int n)
{ sz_ = n;
  build();
}



template<class T>
vector_t<T>::~vector_t()
{
  destroy();
}



template<class T>
void
vector_t<T>::build()
{
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}



template<class T>
void
vector_t<T>::destroy()
{
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}



template<class T>
void
vector_t<T>::resize(const int n)
{
  destroy();
  sz_ = n;
  build();
}



template<class T>
inline T
vector_t<T>::get_val(const int i) const
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}



template<class T>
inline int
vector_t<T>::get_size() const
{
  return sz_;
}



template<class T>
void
vector_t<T>::set_val(const int i, const T d)
{
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}



template<class T>
T&
vector_t<T>::at(const int i)
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}



template<class T>
T&
vector_t<T>::operator[](const int i)
{
  return at(i);
}
// sobrecargamos el operador [], para hacer referencia a que lo "estamos usando en la clase", y el operador llama a otra funcion que es la que hace el trabajo



template<class T>
const T&
vector_t<T>::at(const int i) const
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}



template<class T>
const T&
vector_t<T>::operator[](const int i) const
{
  return at(i);
}



template<class T>
void
vector_t<T>::write(ostream& os) const
{ 
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}



template<class T>
void
vector_t<T>::read(istream& is)
{
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; ++i)
    is >> at(i);
}


// FASE II: producto escalar
template<class T>
T
scal_prod(const vector_t<T>& v, const vector_t<T>& w)
{
  T scal_prod{0};
  for(int i{0}; i < v.get_size(); ++i) 
  {
    scal_prod = scal_prod + ( v.at(i) * w.at(i) );
  }
  return scal_prod;
}



double
scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w)
{
  double scal_prod{0.00};
  int counter{v.get_size()};
  
  for(int i{0}; i < counter; ++i) 
  {
    scal_prod = scal_prod + ( v[i].value() * w[i].value()  );
  }
  return scal_prod;

}

// Modificación de la práctica
template<class T>
T
new_pair_vector(const vector_t<T>& v)
{
  vector_t<T> new_vector;
  for(int i{1}; i <= v.get_size(); ++i)
  {
    if( i % 2 == 0 )
    {
      new_vector[i] = v[i];
    }
  }
  std::cout << new_vector.write();
  return T(0);
}