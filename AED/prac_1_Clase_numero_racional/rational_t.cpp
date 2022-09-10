// AUTOR: Cristopher Manuel Afonso Mora
// FECHA: 25/02/21
// EMAIL: alu0101402031@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método
int
rational_t::get_num() const
{
  return num_;
}



int
rational_t::get_den() const
{
  return den_;
}


  
void
rational_t::set_num(const int n)
{
  num_ = n;
}


  
void
rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}



double
rational_t::value() const { 
  return double(get_num()) / get_den();
}


// comparaciones
bool
rational_t::is_equal(const rational_t& r, const double precision) const {
  const double a{ double(num_) / double(den_)};
  const double b{ double(r.get_num()) / double(r.get_den())};
  if( fabs(a - b) < precision ) {
    if( fabs(a) < precision ) { 
      std::cout << "El primer número es igual a cero\n"; 
      return true;}
    return true;}
  else {return false;}
}



bool
rational_t::is_greater(const rational_t& r, const double precision) const {
  const double a{ double(num_) / double(den_)};
  const double b{ double(r.get_num()) / double(r.get_den())};
  if( (a - b) > precision ) { return true;}
  else {return false;}
}



bool
rational_t::is_less(const rational_t& r, const double precision) const {
  const double a{ double(num_) / double(den_)};
  const double b{ double(r.get_num()) / double(r.get_den())};
  if( (b - a) > precision ) { return true;}
  else {return false;}
}


// operaciones
rational_t
rational_t::add(const rational_t& r) {
  num_ = num_ * r.get_den() + r.get_num()*den_; 
  den_ = den_ * r.get_den();
}



rational_t
rational_t::substract(const rational_t& r) {
  num_ = num_ * r.get_den() - r.get_num() * den_; 
  den_ = den_ * r.get_den();
}



rational_t
rational_t::multiply(const rational_t& r) {
  num_ = num_ * r.get_num(); 
  den_ = den_ * r.get_den();
}



rational_t
rational_t::divide(const rational_t& r) {
  num_ = num_ * r.get_den(); 
  den_ = den_ * r.get_num();
}



// E/S
void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}



void 
rational_t::read(istream& is)
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}
