#include <iostream>
#include <string>

int main () {
    int edad;
    std::string name;

    std::cout << "¿Cómo te llamas? " << std::endl;
    std::cin >> name;
    std::cout << "Muy buenas " << name << ", eres un gran programador." << std::endl;
    return 0;
}
