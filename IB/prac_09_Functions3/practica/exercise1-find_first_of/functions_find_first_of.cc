#include <iostream>
#include <string>

void Introduction() {
    std::cout << "find_first_of: falta un palabra y una letra como parámetros" << std::endl;
    std::cout << "Pruebe './find_first_of --help' para más información" << std::endl;
}

void Help() {
    std::cout << "Hola, soy un programa el cual puede localizar una letra dentro de una palabra" << std::endl;
    std::cout << "Para demostrartelo, solo necesito que me des una palabra y una letra por línea de comandos, y cuando lo hagas" << std::endl;
    std::cout << "Te diré la posición en que esa letra está dentro de la palabra, empezando desde la izquierda a la derecha" << std::endl;
    std::cout << "(pero contando la primera letra, como la posición cero), pero si no encuentro la letra, te devolveré por pantalla '-1'" << std::endl;
    std::cout << "Esto es un ejemplo: si me das la palabra 'hola' y la letra 'a', te diré que la letra 'a', está en la posición 3" << std::endl;
    std::cout << "Ya que la primera posición es la cero (que es la de la letra 'h'), pero si me das la letra 'e'" << std::endl;
    std::cout << "Te devolveré por pantalla un '-1', ya que la letra 'e' no está dentro de la palabra 'hola'" << std::endl;
    std::cout << "Un último detalle, si la letra aparece más de una vez en la palabra, te daré la posición de la primera que encuentre, y el resto las ignoraré" << std::endl;
    std::cout << "Ahora que ya sabes como funciono, para darte una demostración debes introducir el nombre de este programa" << std::endl;
    std::cout << "una palabra y una letra por línea de comandos, y debes hacerlo en ese orden, sino no funcionaré" << std::endl << std::endl;
}

void NotSuccess(std::string& word, char& letter) {

    std::cout << "La posición de la letra '" << letter << "', en la palabra '" << word << "', es: -1" << std::endl << std::endl;

}

void Success(std::string& word, char& letter) {

    std::cout << "La posición de la letra '" << letter << "', en la palabra '" << word << "', es: " << word.find_first_of(letter) << std::endl << std::endl; 

}

void FindLetter(std::string& word, char& letter) {

    if( word.find(letter) == std::string::npos  ) {
        NotSuccess(word, letter);
    }
    else {

        Success(word, letter);

    }

}