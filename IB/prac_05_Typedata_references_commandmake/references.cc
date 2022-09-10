#include <iostream>

int main () {
    int var_interger(10);
    bool var_true{true};
    char var_e_letter = 'e';
    double var_num_decimal = {1.00};

    int& ref_var_interger(var_interger);
    bool& ref_var_true{var_true};
    char& ref_var_e_letter = var_e_letter;
    double& ref_var_num_decimal = {var_num_decimal};

    std::cout << "Soy un programa que te mostrará la capacidad que tiene el lenguaje de programación C++ para crear un alias a una variable de cualquier tipo" << std::endl;
    std::cout << "Este programa tiene 4 variables declaradas: 1 de tipo 'int', 1 de tipo 'bool', 1 de tipo 'char', y 1 de tipo 'double'" << std::endl << std::endl;
    std::cout << "Sus valores actuales son: " << std::endl << std::endl;
    std::cout << "int = " << var_interger << " ; ";
    std::cout << "bool = " << var_true << " ; ";
    std::cout << "char = " << var_e_letter << " ; ";
    std::cout << "double = " << var_num_decimal << std::endl << std::endl;

    std::cout << "Ahora voy a mostrarte en la pantalla el valor de las referencias de cada variable: " << std::endl << std::endl;

    std::cout << "int& = " << ref_var_interger << std::endl;
    std::cout << "bool& = " << ref_var_true << std::endl;
    std::cout << "char& = " << ref_var_e_letter << std::endl;
    std::cout << "double& = " << ref_var_num_decimal << std::endl << std::endl;

    std::cout << "Como se puede apreciar, el valor de las referencias es igual al de las variables originales a las que hacen referencia" << std::endl;
    std::cout << "Lo único que hace la referencia es darle un nuevo nombre válido a la misma variable ya creada" << std::endl;
    std::cout << "Es como si tuviera un 'mote' o un segundo nombre la variable original, por lo tanto, son dos nombres que hacen referencia al mismo conjunto de datos" << std::endl;
    std::cout << "(ya sean estos nº enteros, decimales, cadenas de texto, etc...)" << std::endl;
    std::cout << "Por lo tanto, si se modifica la variable original, la referencia también se modificará para seguir teniendo un valor igual a la variable a la que se refiere, y viceversa" << std::endl;
        
    return 0;
}