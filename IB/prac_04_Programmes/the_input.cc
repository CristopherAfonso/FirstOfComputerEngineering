#include <iostream>

int main () {
	int edad;
	std::string name;

	std::cout << "Hola, por favor, introduce tu nombre: "; 
	std::cin >> name;
	std::cout << "Ahora dame tu edad actual por favor: ";
	std::cin >> edad;
	std::cout << "Te llamas " << name << " y tienes " << edad << " años." << std::endl;
	return 0;
}
