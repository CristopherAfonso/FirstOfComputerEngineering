#include <iostream>

int main() {
    int kAnyoDeNacimiento;
 
    std::cout << "¿En qué año naciste?" << std::endl;
    std::cin >> kAnyoDeNacimiento;
std::cout << "Tienes " << 2020 - kAnyoDeNacimiento << " años" << std::endl;
    return 0;
}