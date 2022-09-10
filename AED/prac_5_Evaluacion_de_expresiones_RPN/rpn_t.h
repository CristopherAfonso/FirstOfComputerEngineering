// AUTOR: Cristopher Manuel Afonso Mora
// FECHA: 24/04/2021
// EMAIL: alu0101402031@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <string>
#include <sstream>

#include "queue_l_t.h"


// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);

 private: 
  T stack_;
  void operate_(const char operador);
};


// operaciones
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      stack_.push(i); 
      std::cout << " (es un dígito) " << std::endl
		<< "   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      operate_(c);
    }
  }
  return stack_.top();
}

template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || 
         c == '^' || c == 'r' || c == 'l' || c == 'c');
  
  int operator1{0};
  int operator2{0};
  int result{0};

  operator1 = stack_.top();
  std::cout << "   Sacamos de la pila un operando: ";
  std::cout << operator1 << std::endl;
  stack_.pop();

  if() 

  switch (c) {
    case '+':
      operator2 = stack_.top();
      stack_.pop();
      std::cout << "   Sacamos de la pila otro operando: ";
      std::cout << operator2 << std::endl;

      result = operator1 + operator2;
      stack_.push(result);
      break;
    case '-':
      operator2 = stack_.top();
      stack_.pop();
      std::cout << "   Sacamos de la pila otro operando: ";
      std::cout << operator2 << std::endl;
      result = operator2 - operator1;

      stack_.push(result);
      break;
    case '*':
      operator2 = stack_.top();
      stack_.pop();
      std::cout << "   Sacamos de la pila otro operando: ";
      std::cout << operator2 << std::endl;

      result = operator1 * operator2;
      stack_.push(result);
      break;
    case '/':
      operator2 = stack_.top();
      stack_.pop();
      std::cout << "   Sacamos de la pila otro operando: ";
      std::cout << operator2 << std::endl;

      result = operator2 / operator1;
      stack_.push(result);
      break;
    case '^':
      operator2 = stack_.top();
      stack_.pop();
      std::cout << "   Sacamos de la pila otro operando: ";
      std::cout << operator2 << std::endl;

      result = (double) pow(operator2, operator1);
      stack_.push(result);
      break;
    case 'r':
      result = sqrt(operator1);
      stack_.push(result);
      break;
    case 'l':
      result = log2(operator1);
      stack_.push(result);
      break;
    case 'c':
      result = operator1 * operator1;
      stack_.push(result);
      break;
  }
  std::cout << "   Metemos en la pila el resultado: " << result << '\n';
}

 
#endif  // RPNT_H_
