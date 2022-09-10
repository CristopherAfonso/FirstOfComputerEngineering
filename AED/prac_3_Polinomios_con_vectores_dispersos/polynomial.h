// AUTOR: Cristopher Manuel Afonso Mora
// FECHA: 22/03/21
// EMAIL: alu0101402031@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "vector_t.h"
#include "sparse_vector_t.h"

// Clase para polinomios basados en vectores densos de doubles
class Polynomial : public vector_t<double> {
 public:
  // constructores
  Polynomial(const int n = 0) : vector_t<double>(n) {};
  Polynomial(const Polynomial& pol)
      : vector_t<double>(pol) {}; // constructor de copia

  // destructor
  ~Polynomial() {};

  // E/S
  void Write(std::ostream& = std::cout, const double eps = EPS) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
 };


// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public sparse_vector_t {
 public:
  // constructores
  SparsePolynomial(const int n = 0) : sparse_vector_t(n) {};
  SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol) {};
  SparsePolynomial(const SparsePolynomial&);  // constructor de copia

  // destructor
  ~SparsePolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SparsePolynomial&, const double = EPS) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
  //operación de la modificación
  void GreaterThan(const int& reference_value) const;
};

// E/S
void Polynomial::Write(std::ostream& os, const double eps) const {
  os << get_size() << ": [ ";
  bool first{true};
  for (int i{0}; i < get_size(); i++)
    if (IsNotZero(at(i), eps)) {
      os << (!first ? " + " : "") << at(i)
	 << (i > 1 ? " x^" : (i == 1) ? " x" : "");
      if (i > 1)
	os << i;
      first = false;
    }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector denso
double Polynomial::Eval(const double x) const {
  double result{0.0}; // declaración de la varaible que retornaremos
  for(int i{0}; i < get_size(); ++i) { // for que recorre todos los elementos del vector para  calcular el resultado del polinomio
    result += double(get_val(i) * pow(x, i)); // resultado que iremos sumando consecutivamente a la variable result
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores densos
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false; // bandera, que cuando cambie de estado, nos dirá si son diferentes los polinomios
  
  for(int i{0}; i < get_size() - 1; ++i) { // for con límite el tamaño del vector -1, para no tocar direcciones de memoria prohibidas
    if (pol.at(i) != at(i)) { //evaluación entre las posiciones iguales de un vector
      differents = true; // si se da el if, se cambia la bandera
    }
  }
  return !differents;
}

// constructor de copia
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;   // se invoca directamente al operator=
}

// E/S
void SparsePolynomial::Write(std::ostream& os) const {
  os << get_n() << "(" << get_nz() << "): [ ";
  bool first{true};
  for (int i{0}; i < get_nz(); i++) {
    int inx{at(i).get_inx()};
    os << (!first ? " + " : "") << at(i).get_val()
       << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector disperso
double SparsePolynomial::Eval(const double x) const {
  double result{0.0}; //declaración de variable que retornaremos
  for(int i{0}; i < get_nz(); ++i) { // for que busca recorrer todos los elementos del vector disperso, para hallar su valor cuando le damos un valor a la X
    result += operator[](i).get_val() * pow(x, operator[](i).get_inx()); // resultado que iremos sumando consecutivamente a la variable que retornaremos
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores dispersos
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol
			       , const double eps) const {
  bool differents = false; // bandera que nos dice si los polinomios son diferentes
    for(int i{0}; i < get_nz() - 1; ++i) { // for con límite, el tamaño del vector -1, para no tocar direccioens de memoria prohibidas
    if ((spol.at(i).get_val() != at(i).get_val()) || (spol.at(i).get_inx() != at(i).get_inx())) {
      differents = true; // el if evalua si el coeficiente que multiplica a la X, ó la potencia de la X son diferentes, entonces son diferentes
    }
  }
  return !differents;
}

// Comparación si son iguales dos polinomios representados por
// vector disperso y vector denso
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false; // bandera declarada

    for(int i{0}, j{0}; j < get_nz() - 1; ++i) { // for con dos variables, una recorre el vector denso, la i, y la j, recorre el disperso
      if (IsNotZero(pol.at(i))) { // si la posición elegida en el vector denso es !=0, entonces evalua los vectores en esa posición, sino pasa a la siguiente posición en el vector denso
        if ((!(IsNotZero(at(j).get_val() - pol.at(i)))) && (at(j).get_inx() == i)) { // evaluación de los vectores en las posiciones elegidas si la posicion en el vector denso es !=0
          ++j;
        }else { // si es verdad que la posiciones elegidas en los vectores son iguales, se pasa a la siguiente posicion en el vector disperso, sino, son diferentes y se levanta la bandera
          return false;
        }
      }
    }
    return !differents;  
}

// Fase de modificación de la práctica, grupo PE104
// Para un SparsePolynomial, mostrar los coeficientes distintos de cero de los monomios cuyo grado sea mayores que un valor dado
void SparsePolynomial::GreaterThan(const int& reference_value) const {

  std::cout << "Los coeficientes de los monomios mayores a " << reference_value << ", son: \n";

  for(int i{0}; i < get_nz(); ++i) {
    if (at(i).get_inx() > reference_value) {
      std::cout << "Coeficiente: " << at(i).get_val()
       << ", potencia del monomio asociada a ese coeficiente: " << at(i).get_inx() << std::endl;
    }
  }
  std::cout << std::endl;
}

#endif  // POLYNOMIAL_H_
