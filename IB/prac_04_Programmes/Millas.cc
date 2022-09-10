#include <iostream>
using namespace std;

int main() {
   float ml, km;
   cout << "Cuantas millas quieres pasar a metros? ";
   cin >> ml;
   km = ml * 1.609;  // 1 //
   cout << "Son " << km << " kilómetros" << endl;
}