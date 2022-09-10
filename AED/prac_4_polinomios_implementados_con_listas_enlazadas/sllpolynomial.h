// AUTOR: Cristopher Manuel Afonso Mora
// FECHA: 12/04/2021
// EMAIL: alu0101402031@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef SLLPOLYNOMIAL_H_
#define SLLPOLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "pair_t.h"
#include "sll_t.h"
#include "vector_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;  // Campo data_ de SllPolynomial
typedef sll_node_t<pair_double_t> SllPolyNode;  // Nodos de SllPolynomial

// Clase para polinomios basados en listas simples de pares
class SllPolynomial : public sll_t<pair_double_t> {
 public:
  // constructores
  SllPolynomial(void) : sll_t() {};
  SllPolynomial(const vector_t<double>&, const double = EPS);

  // destructor
  ~SllPolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SllPolynomial&, const double = EPS) const;
  void Sum(const SllPolynomial&, SllPolynomial&, const double = EPS);
  double Enesimo() const; // operacion nueva añadida en la modificación
};


bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

// FASE II
// constructor
SllPolynomial::SllPolynomial(const vector_t<double>& v, const double eps) {
  SllPolyNode* actual_node;
  // Declaramos el puntero que nos servirá de apoyo

  for(int i{v.get_size()-1}; i >= 0; --i) {
    // Para reducir la complejidad del programa, usamos "push_front" 
    // pero para que funcione, debemos crear los nodos desde 
    // el último hasta el primero
    if(IsNotZero(v.at(i), eps)) {
      // Nos aseguramos si el valor del vector es distinto de cero
      pair_double_t actual_pair(v.get_val(i), i);
      // Creamos un objeto pair_t, que será el que meteremos en el nodo
      // ya que este acepta solo estos datos
      actual_node = new SllPolyNode(actual_pair);
      // Aquí creamos un nuevo nodo en memoria dinámica guardado 
      // en el puntero actual_node
      push_front(actual_node);
      // Aquí lo metemos en la lista, de manera que en la siguiente iteración
      // al cambiar el valor de actual_node, no lo perdemos y está donde debe
    }
  }
}


// E/S
void SllPolynomial::Write(std::ostream& os) const {
  os << "[ ";
  bool first{true};
  SllPolyNode* aux{get_head()};
  while (aux != NULL) {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};
    if (val > 0)
      os << (!first ? " + " : "") << val;
    else
      os << (!first ? " - " : "-") << fabs(val);
    os << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
    aux = aux->get_next();
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SllPolynomial& p) {
  p.Write(os);
  return os;
}


// Operaciones con polinomios

// FASE III
// Evaluación de un polinomio representado por lista simple
double SllPolynomial::Eval(const double x) const {
  double result{0.0};
  // poner el código aquí
  SllPolyNode* actual_node{get_head()}; 
  //actual_node es un puntero que recorre toda la lista
  while(actual_node != NULL) { // salimos del while al recorre toda la lista
    result += actual_node->get_data().get_val() * 
    pow(x, actual_node->get_data().get_inx());
    // cogemos el coeficiente del nodo y lo multiplicamos
    // por la x elevada al indice del nodo
    actual_node = actual_node->get_next();
    // pasamos al nodo siguiente si hay, sino salimos del while
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por listas simples
bool SllPolynomial::IsEqual(const SllPolynomial& sllpol,
			    const double eps) const {
  bool differents = false; // bandera, cuando cambie de valor, terminamos
  // poner el código aquí
  SllPolyNode* aux_local{get_head()};
  // puntero que recorre la lista del objeto que invoca
  SllPolyNode* aux_external{sllpol.get_head()};
  //puntero que recorre la lista del objeto invocado

  while((aux_local != NULL) && (aux_external != NULL)) {
  // mientras los dos punteros no sean nulos, recorremos la lista
  // si uno deja de ser uno y el otro no, son diferentes
  // si dejan de ser nulos ambos y no se levanta la bandera son diferentes
    if( ((fabs(aux_local->get_data().get_val())) < eps)  && aux_external->get_next() != NULL ) {
      aux_local = aux_local->get_next();
      continue;
    }
    if( (fabs(aux_external->get_data().get_val()) < eps) && aux_external->get_next() != NULL ) {
      aux_external = aux_external->get_next();
      continue;
    }

    if(!((fabs(aux_local->get_data().get_val() - 
       aux_external->get_data().get_val()) < eps) && (
       aux_local->get_data().get_inx() == 
       aux_external->get_data().get_inx()))) {      
    // esto es un if que compara si el coeficiente de los nodos y el 
    //indice de los nodos, son iguales, y los compara a la vez
    //en el mismo if, por eso es tan largo
      differents = !differents;
      break;
      // si se entra en el if, se levanta la bandera y se sale del bucle
    }
  }
  aux_local = aux_local->get_next();
  aux_external = aux_external->get_next();
  // si no se levanta la bandera, se pasan a los dos nodos siguientes

  if( (aux_external != NULL) || (aux_local != NULL) ) {
    differents = !differents;
  }
  // si se sale del while y todavía no se ha levantado la bandera, todavía se
  // puede levantar, si una lista de las dos tiene más términos, si los tiene
  // son diferentes

  return !differents;
}

// FASE IV
// Generar nuevo polinomio suma del polinomio invocante mas otro polinomio
void SllPolynomial::Sum(const SllPolynomial& sllpol,
			SllPolynomial& sllpolsum,
			const double eps) {
  // poner el código aquí
  SllPolyNode* aux_local{get_head()}; 
  // puntero que recorre la lista del objeto invocante
  SllPolyNode* aux_external{sllpol.get_head()};
  // puntero que recorre la lista del vector que es invocado
  SllPolyNode* aux_sum{sllpolsum.get_head()};
  // puntero siempre situado en el último nodo creado de la nueva lista
  SllPolyNode* aux_new_node{NULL};
  // puntero usado para guardar el valor dinámico de un objeto SllPolyNode,
  // este valor se le pasará al método insert_after para ampliar la lista
  pair_double_t* aux_pair{NULL};
  // puntero usado para guardar el valor dinámico de un objeto pair_double_t
  // y este valor se le pasará al operador new para crear el objeto SllPolyNode
  // en el puntero aux_new_node
  double local_coefficient{0.00}; //coeficiente del nodo de la lista que invoca
  int local_index{0}; // indice del nodo de la lista que invoca
  double external_coefficient{0.00};//coeficiente del nodo de la lista invocada
  int external_index{0}; // indice del nodo de la lista invocada
  // estas últimas 4 variables son dispensables, pero las uso para escribir 
  // menos código en el while de abajo que empieza en la línea 188

  while((aux_local != NULL) && (aux_external != NULL)) {
    // mientras las dos listas tengan elementos, el while continua
    local_coefficient = aux_local->get_data().get_val();
    local_index = aux_local->get_data().get_inx();
    external_coefficient = aux_external->get_data().get_val();
    external_index = aux_external->get_data().get_inx();
    // inicializamos las 4 variables que nos ahorran escribir de más

    if(sllpolsum.empty()) { // en este if solo se entra al inicio del programa
      if(local_index == external_index) {
        if(fabs(local_coefficient + external_coefficient) < eps) {
          //si el valor de la suma de los coeficientes es menor a una constante
          // se asume que los coeficientes son iguales de signos contrarios
          // y su suma daría cero, por eso el programa hace como que no los vío
          // para no meter ceros en la lista
          aux_local = aux_local->get_next();
          aux_external = aux_external->get_next();
          continue;
          // como se hacen cero, se pasa a los dos siguientes nodos y con el
          // continue volvemos al inicio del while, porque ya hemos calculado
          // lo que queríamos calcular y porque al final del while, hay dos 
          // instrucciones que pasan a los nodos siguientes, están para los 
          // if que no terminan en continue
        }
        aux_pair = new pair_double_t(local_coefficient + external_coefficient,
        local_index); //creamos un pair_double_t dinamico, sumando coeficientes
        aux_new_node = new SllPolyNode(*(aux_pair));
        // metemos el pair_double_t dinamico en aux_new_node también dinamico
        sllpolsum.push_front(aux_new_node);
        // metemos el aux_new_node en la lista en el primer elemento, hacemos
        // los dos pasos anteriores porque el método solo acepta un puntero
        aux_sum = aux_new_node;
        // el puntero aux_sum está siempre en el último elemento de la lista
        // por eso le damos el valor de aux_new_node, porque es el último
      }
      if(local_index < external_index) {
        // a partir de ahora voy a no comentar algunas cosas porque ya las he 
        // aclarado antes
        aux_pair = new pair_t<double>(local_coefficient, local_index);
        // el coeficiente de aux_pair es el que acompaña al menor indice
        aux_new_node = new SllPolyNode(*(aux_pair));
        sllpolsum.push_front(aux_new_node);
        aux_local = aux_local->get_next();
        // solo aumentamos aux_local porque aux_external tendremos que meterlo
        // a la lista cuando sea menor o igual al elemento de la otra lista
        aux_sum = aux_new_node;
        continue;
      }
      if(local_index > external_index) {
        aux_pair = new pair_t<double>(external_coefficient, external_index);
        aux_new_node = new SllPolyNode(*(aux_pair));
        sllpolsum.push_front(aux_new_node);
        aux_external = aux_external->get_next();
        aux_sum = aux_new_node;
        continue;
      }

    }else {
      delete aux_pair; // este delete borra el objeto dinámico aux_pair
      // porque ya lo hemos metido en la lista, y no nos hace falta
      // y lo pongo aquí para que en las siguientes iteraciones, nada 
      // más entrar, se borre
      if(local_index == external_index) {
        if(fabs(local_coefficient + external_coefficient) < eps) {
          aux_local = aux_local->get_next();
          aux_external = aux_external->get_next();
          continue;
        }
        aux_pair = new pair_t<double>(local_coefficient + external_coefficient,
        local_index);
        aux_new_node = new SllPolyNode(*(aux_pair));
        // el constructor SllPolyNode necesita un objeto pair para funcionar
        // por eso le paso el contenido del puntero aux_pair
        sllpolsum.insert_after(aux_sum, aux_new_node);
        aux_sum = aux_sum->get_next();
      }
      // el metodo insert_after necesita dos punteros para funcionar
      // uno con el nodo tras el que se meterá el nuevo nodo, y el nuevo nodo
      // y en nuestro caso son aux_sum porque siempre pondré los nuevos 
      // elementos al final, y aux_new_node porque lo creo para meterlo aquí
      if(local_index < external_index) {
        aux_pair = new pair_t<double>(local_coefficient, local_index);
        aux_new_node = new SllPolyNode(*(aux_pair));
        sllpolsum.insert_after(aux_sum, aux_new_node);
        aux_sum = aux_sum->get_next();
        aux_local = aux_local->get_next();
        continue;
      }
      if(local_index > external_index) {
        aux_pair = new pair_t<double>(external_coefficient, external_index);
        aux_new_node = new SllPolyNode(*(aux_pair));
        sllpolsum.insert_after(aux_sum, aux_new_node);
        aux_sum = aux_sum->get_next();
        aux_external = aux_external->get_next();
        continue;
      }
    }
    aux_local = aux_local->get_next();
    aux_external = aux_external->get_next();
    // si se da el caso de que los indices son iguales y no se hacen cero
    // estas dos líneas hacen avanzar a los siguientes nodos
  }
  delete aux_pair; // este delete borra el último pair al salir del while
  
  while(aux_local != NULL) { 
    // si la lista invocada se ha vaciado pero la invocante no se entra aquí
    aux_sum->set_next(aux_local); // se coloca el elemento de la lista después
    // de aux_sum que es el último nodo
    aux_sum = aux_sum->get_next();
    aux_external = aux_external->get_next();
  }
  while(aux_external != NULL) {
    // si la lista invocante se ha vaciado pero la invocada no, se entra aquí
    aux_sum->set_next(aux_external);
    aux_sum = aux_sum->get_next();
    aux_external = aux_external->get_next();
  }
}

// Fase Modificacion en el aula del CC
// Crear un método que haga la media de los coeficientes de los dos ultimos
double SllPolynomial::Enesimo() const {
  SllPolyNode* last_node{NULL};
  SllPolyNode* penultimate_node{get_head()};
  double average{0.00};

  if(!empty()) {
    if(penultimate_node->get_next() == NULL) {
      average = penultimate_node->get_data().get_val();
    }else {
      last_node = penultimate_node->get_next();
      while(last_node->get_next() != NULL) {
        penultimate_node = last_node;
        last_node = last_node->get_next();
      }
      average = (penultimate_node->get_data().get_val() 
                + last_node->get_data().get_val()) / 2;
    }
  }else {
    std::cout << "La lista está vacía, no puedo hacer ninguna media\n\n";
  }

  return average;
}

#endif  // SLLPOLYNOMIAL_H_
