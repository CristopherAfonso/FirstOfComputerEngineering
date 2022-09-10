# Práctica 12. Introducción a la Programación Orientada a Objetos. Clases. Google Tests. Exercism

### Objetivos
Los objetivos de esta práctica son que el alumnado:
* Desarrolle programas sencillos en C++ que utilicen clases, así como todas las características del lenguaje
  estudiadas
* Aloje todo el código fuente de sus programas en repositorios privados de GitHub
* Sepa depurar sus programas usando la interfaz de depuración del VSC
* Incluya en sus programas comentarios en el formato requerido por Doxygen
* Conozca la herramienta CMake y sepa usarla para construir sus programas ejecutables
* Conozca el framework de testing de Google (Google Tests) y sea capaz de desarrollar tests unitarios
  sencillos
* Conozca la plataforma Exercism y sea capaz de interaccionar con la misma para resolver algunos problemas
  sencillos

### Rúbrica de evaluacion de esta práctica
Se señalan a continuación los aspectos más relevantes (la lista no es exhaustiva)
que se tendrán en cuenta a la hora de evaluar esta práctica:
* El alumnado ha de acreditar conocer los conceptos expuestos en el material de referencia de esta práctica.
* El alumnado ha de acreditar que ha realizado todos los ejercicios propuestos, así como ser capaz de desarrollar otros similares.
* Ha de acreditar que es capaz de escribir un fichero CMakeLists.txt para automatizar el proceso de compilación de sus programas.
* El código que escriba ha de estar escrito de acuerdo a los estándares definidos en la 
  [Guía de Estilo de Google para C++](https://google.github.io/styleguide/cppguide.html).
* Todos los identificadores que utilice en su programa (constantes, variables, etc.) deberán ser
  siempre significativos. No utilice nunca identificadores de una única letra, tal vez con la excepción de las
  variables que utilice para iterar en un bucle.
* Antes de su ejecución, todos los programas que desarrolle, deben imprimir en pantalla un
  mensaje indicando la finalidad del programa así como la información que precisará del usuario para su correcta ejecución.
* Ante la presencia de cualquier bug, el alumnado ha de conocer las técnicas básicas de depuración usando
  Visual Studio Code.
* Todos los ficheros de código del proyecto correspondiente a esta práctica han de alojarse en un repositorio de 
  [GitHub](https://github.com/).
* Los programas deben contener comentarios adecuados en el formato requerido por 
  [Doxygen](https://www.doxygen.nl/index.html).
* Los programas deben estructurarse en directorios diferentes para cada "proyecto" y hacer que cada uno de
  ellos contenga un fichero `CMakeLists.txt` con la configuración de despliegue del proyecto.
* Las funciones y métodos que se desarrollen para resolver los ejercicios han de disponer de un conjunto
  mínimo de tests unitarios que comprueben la corrección de cada una de ellas.

### La plataforma de testing de Google
Tal como recoge la
[Wikipedia](https://es.wikipedia.org/wiki/Desarrollo_guiado_por_pruebas),
El desarrollo dirigido por tests (TDD, *Test Driven Development* por sus siglas en inglés) es una práctica de 
ingeniería de software que involucra otras dos técnicas: 
escribir las pruebas primero (Test First Development) y 
[Refactorización](https://es.wikipedia.org/wiki/Refactorizaci%C3%B3n)
(Refactoring) o reestructuración del código.
Para escribir las pruebas generalmente se utilizan las pruebas unitarias (unit test en inglés). 

El TDD se basa en la repetición de un ciclo de desarrollo muy corto que
involucra la repetición de tres pasos:
1. En primer lugar el desarrollador escribe un caso de prueba (test) que falla (a propósito) y que define una mejora deseada (habitualmente una nueva función o método)
2. A continuación se desarrolla el código (de la función) que hace que la prueba pase satisfactoriamente 
3. Finalmente refactoriza el nuevo código hasta obtener un resultado satisfactorio

Esta imagen representa este ciclo repetitivo característico del TDD.

![TDD cycle](https://raw.githubusercontent.com/ULL-ESIT-IB-2020-2021/IB-P12-Classes-GTests-Exercism/master/red-green-refactor.png "Red-Green-Refactor")

El propósito del desarrollo guiado por pruebas es lograr un código limpio que funcione correctamente.
La idea es que los requisitos sean traducidos a pruebas (tests), y de este modo, cuando las pruebas pasen 
se garantizará que el software cumple con los requisitos que se han establecido.


Las "unidades" de código para las que se realizan tests habitualmente son clases, funciones o grupos ellas. 
Supongamos por ejemplo que se está implementando una función (unidad de código) que calcula la suma de dos números enteros.
Una prueba (test unitario) es un código que valida la corrección de esa función: se podría comprobar que lo
que reciba la función sean realmente dos parámetros, y que esos dos parámetros sean números, y que lo que
devuelva la función sea otro número, y que ese número corresponda realmente con la suma. 
Todas estas podrían ser posibles pruebas unitarias que se realicen sobre la función.
Las pruebas unitarias  se suelen realizar utilizando entornos de pruebas (testing) especializados.

Existen diversas plataformas para el desarrollo de tests unitarios en C++.
Algunas de las de uso más extendido son
[Boost.Test](https://www.boost.org/doc/libs/1_49_0/libs/test/doc/html/index.html),
[CppUnit](https://sourceforge.net/projects/cppunit/),
[Cute](https://cute-test.com/)
aunque hay
[muchas otras](https://en.wikipedia.org/wiki/List_of_unit_testing_frameworks#C++)

En esta práctica se propone utilizar el framework 
[Google Test](https://en.wikipedia.org/wiki/Google_Test),
(también conocido como gtest) que es una librería de pruebas unitarias (*unit tests*) para C++.
El entorno permite que los tests se ejecuten de una en uno o todos a la vez. 
Google Tests puede ser utilizado en 
[Visual Studio Code](https://docs.microsoft.com/es-es/visualstudio/test/how-to-use-google-test-for-cpp?view=vs-2019), 
aunque en este documento se propone un uso de la plataforma de modo independiente de VSC.

El primer paso para usar gtest es su instalación. 
Siga para ello los siguientes pasos:

```
$ git clone https://github.com/google/googletest.git -b release-1.10.0
$ cd googletest/
$ mkdir build
$ cd build/
$ cmake .. -DBUILD_GMOCK=OFF
$ make
$ sudo make install
```
que se explican en el documento 
[Standalone CMake Project](https://github.com/google/googletest/blob/master/googletest/README.md#standalone-cmake-project).
El comando `sudo make install` (obsérvese que se ejecuta con privilegios de *root*) 
instalará gtest en el directorio `/usr/local/` del sistema , de modo que en los directorios
```
/usr/local/include
/usr/local/lib
```
se alojan los ficheros de cabecera (`*.h`) y las librerías (`*.a`) necesarios para usar gtest.
Una vez instalada la librería puede eliminar el directorio `googletest` en el que copió el repositorio.

El repositorio de esta práctica contiene un directorio `gtests` con el siguiente contenido:
```
gtests
  ├── CMakeLists.txt
  ├── src
  │   ├── addition.cc
  │   ├── addition.h
  │   ├── date.cc
  │   ├── date_client_program.cc
  │   ├── date.h
  │   ├── factorial.cc
  │   ├── factorial.h
  │   ├── formula.cc
  │   ├── formula.h
  │   ├── main_program.cc
  │   ├── multiply.cc
  │   ├── multiply.h
  │   ├── sample2.cc
  │   ├── sample2.h
  │   ├── square_root.cc
  │   └── square_root.h
  └── test
      ├── gtest_main.cc
      ├── sample2_unittest.cc
      ├── test_addition.cc
      ├── test_date.cc
      ├── test_factorial.cc
      ├── test_formula.cc
      ├── test_multiply.cc
      └── test_square_root.cc
```
Siguiendo la costumbre habitual, el subdirectorio `src` contiene el código fuente del proyecto, que en este
caso es un proyecto ficticio que se usa para ilustrar el uso de tests unitarios.
A modo de ejemplo, el programa principal del proyecto `main_program.cc` (véase su código fuente)
invoca a diferentes funciones de carácter matemático que han sido
desarrolladas por el usuario (ficheros `src/*.cc` y `src/*.h`).

Compile el proyecto cuya configuración viene especificada en el fichero `CMakeLists.txt` ejecutando en el directorio
`gtests`:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```
Esta secuencia de comandos creará en el subdirectorio `build` sendos programas ejecutables: `user_program` y `runTests`.
El primero de ellos corresponde con el programa principal del usuario.
Pruebe a ejecutarlo y revise el código de las diferentes funciones que utiliza ese programa.

Por otra parte, el programa `runTests` ejecuta todos los tests unitarios que se han desarrollado para comprobar el correcto
funcionamiento de las diferentes funciones que intervienen en el programa del usuario.
Pruebe asimismo a ejecutarlo.
Ambos programas se pueden compilar de forma independiente ejecutando en el diectorio `build`:

```
$ make user_program
```
o bien:
```
$ make runTests
```

Estudie el contenido del fichero `CMakeLists.txt` y observe en el mismo (comandos `add_executable(runTests ...)`
y `add_executable(user_program)`) los ficheros que están involucrados en cada uno de los dos programas
anteriores.

Lo que más interesa estudiar a continuación es el contenido del directorio `tests`.
En ese directorio, el programa `gtest_main.cc` invoca la ejecución de todos los tests mientras que los
diferentes ficheros `test_*.cc` contienen los tests correspondientes a las diferentes funciones del usuario
que utiliza el programa `main_program.cc`.

Todos los ficheros del directorio `tests` contienen la línea
```
include <gtest/gtest.h>
```

de inclusión del fichero de cabecera donde se definen las macros y funciones de la librería de testing de
Google que se enlaza (*link*) con el programa.
Cada uno de esos ficheros contiene uno o más tests que tienen la siguiente estructura:
```
TEST(TestSuiteName, TestName) {
  ... test body ...
}
```
El primer parámetro de la macro TEST (`TestSuiteName`) es el nombre que se le da a un conjunto de tests
relacionados mientras que el segundo parámetro es el nombre que se le ha dado al test.

El test del fichero `test_date` es un ejemplo que comprueba métodos de una clase definida por el
usuario.
En este caso el test comprueba un par de métodos de la clase `Date`.

Los ficheros `test/sample2_unittest.cc` y  `src/sample2.*` están tomados de
[Googletest Samples](https://github.com/google/googletest/blob/master/googletest/docs/samples.md) 
donde se pueden hallar ejemplos adicionales de tests.

Estudie los tests que figuran en el directorio `gtests/test` para las diferentes funciones del ejemplo,
conjuntamente con la documentación del 
[Googletest Primer](https://github.com/google/googletest/blob/master/googletest/docs/primer.md)
para aprender sobre los diferentes tipos de 
[aserciones](https://es.wikipedia.org/wiki/Aserci%C3%B3n_(inform%C3%A1tica))
y comparaciones que soporta la plataforma para realizar sus tests.

En todos los programas C++ que desarrolle de ahora en adelante, utilice siempre gtests para comprobar la
corrección de todas sus funciones y métodos.
El enfoque (TDD) le ayudará a hallar los bugs de forma temprana de modo que podrá solucionarlos con un menor
coste en tiempo y esfuerzo.
La técnica de *testing* es fundamental para detectar cuanto antes potenciales errores.
Las funciones que han sido comprobadas mediante tests unitarios son siempre más fiables.
Para cada función que escriba de ahora en adelante, comience siempre por escribir antes que el código de la
función, al menos dos tests: uno para las situaciones "normales" y otro para situaciones "extremas".

La regla a seguir de ahora en adelante es **Convierta en un hábito la escritura de tests para sus programas**.
Desarrolle siempre sus funciones iterando el famoso ciclo TDD que ya se ha expuesto en este documento:
* Escriba un test que falle y que define una mejora deseada o una nueva función
* Escirba el código (función, método) que haga que la prueba pase satisfactoriamente 
* Finalmente refactoriza el nuevo código hasta obtener un resultado satisfactorio

Es fácil encontrar en la web mucha documentación sobre TDD. 
A modo de ejemplo e introducción se recomienda el estudio de
[Mejorar la calidad del código mediante la prueba unitaria](https://www.mql5.com/es/articles/1579).

### Exercism
[Exercism](https://exercism.io/) es una plataforma orientada a aprender a programar o también a mejorar las
capacidades de cualquier programadora.
El objetivo de Exercism es servir como medio para aprender a programar en un determinado lenguaje, y para ello se propone
hacerlo mediante la resolución de ejercicios que otros usuarios han planteado. 
Lo que se persigue es que tanto quien resuelve el problema como quien lo planteó aprendan al mismo tiempo. 
Además, la interacción con el resto de la comunidad podrá llevar a debates para determinar cuál sería la mejor solución para un determinado problema.

La plataforma se basa en una una aplicación de línea de comandos disponible para diferentes sistemas
operativos (Linux, Mac, Windows).
Usando esa aplicación, un usuario puede descargar una serie de ejercicios de programación disponibles en la
plataforma y realizar los correspondientes programas hasta que consiga pasar los diferentes tests que se
suministran con cada ejercicio.

La plataforma puede ser usada en "modo práctica", en cuyo caso no existe la opción de mentorización (solicitar
que una experta le ayude con sus ejercicios), pero aún
así merece la pena practicar los múltiples ejercicios que hallará en la plataforma.

## Primeros pasos en Exercism
Comience por [registrarse en Exercism](https://exercism.io/users/sign_up). 
Si lo desea, puede Ud. hacerlo usando la cuenta de GitHub de la que ya dispone.
Una vez disponga de una cuenta, configure lo básico de la misma y elija un "track" (un lenguaje) en el que
desee practicar.
Obviamente se propone que elija el track correspondiente a C++.

Propóngase a continuación resolver el problema "Hello World".
En la página de ese problema (o de cualquier otro) hallará Ud. un enlace que indica *Get started* y 
[Begin walk-through](https://exercism.io/cli-walkthrough).
Si sigue ese enlace le llevará a la página *Welcome to the Exercism installation guide!* con instrucciones
sobre cómo instalar `exercism`.
En este documento se propone instalarla en la máquina virtual Linux de la asignatura.
Eligiendo la opción *Linux* y a continuación la opción *Using snap* se le pedirá que ejecute
```
$ sudo snap install exercism
```
Ese comando instalará en primer lugar `snap` y a continuación `exercism`, que es lo que se persigue.
También en esa página se indica que se compruebe que la instalación es correcta con el comando
```
$ exercism version
```
[`snap`](https://blogubuntu.com/que-es-ubuntu-snap) es un mecanismo alternativo al ya conocido
`apt-get install` para instalar aplicaciones en Ubuntu Linux.
Si quiere Ud. saber más sobre `snap` puede consultar
[esta referencia](https://snapcraft.io/docs/getting-started),
aunque ello no es necesario para el trabajo que se propone realizar con Exercism.

Una vez instalada la aplicación `exercism` el siguiente paso es configurar la interfaz de comandos (CLI) de la
aplicación.
Para ello se pide que se ejecute el comando
```
$ exercism configure --token=xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
```
donde el *token* que figura en el comando anterior se encuentra (es específico de cada usuario) en la [página
de configuración](https://exercism.io/my/settings) de la cuenta de usuario que se ha creado.
Basta copiar de esa página el token y colocarlo en el comando anterior.

El comando anterior, una vez ejecutado indica:
```
You have configured the Exercism command-line client:

Config dir:                       /home/usuario/snap/exercism/5/.config/exercism
Token:         (-t, --token)      xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
Workspace:     (-w, --workspace)  /home/usuario/snap/exercism/5/exercism
API Base URL:  (-a, --api)        https://api.exercism.io/v1
```
A continuación se puede elegir un problema para pasar a resolverlo.
Se propone, como ya se ha dicho, elegir el problema "Hello World".
En la página de ese problema figura una descripción precisa del problema planteado y en la parte derecha de
esa página figuran las instrucciones para:
* Download. Descargar el problema mediante el comando `exercism download --exercise=hello-world --track=cpp`
* Solve. Para resolver el problema se propone usar el editor favorito del usuario. Se recomienda usar Visual
  Studio Code
* Submit. El comando para subir a la plataforma la solución que el usuario proponga.

Si se ejecuta el comando para descargar el problema el sistema responde:
```
$ exercism download --exercise=hello-world --track=cpp

Downloaded to
/home/usuario/snap/exercism/5/exercism/cpp/hello-world
```
indicando el directorio donde ha colocado el código necesario para trabajar en ese problema.

Si revisa Ud. los ficheros descargados observará que Exercism utiliza `.cpp` como extensión para los ficheros
con código fuente C++ en lugar de la extensión `.cc` que recomienda la Guía de Estilo de Google.
La extensión `.cpp` es muy común para ficheros de código C++.

## Ejecución de los tests para un determinado problema
El siguiente paso consiste en editar el programa (en el caso del problema "Hello World" el fichero a editar es
`hello_world.cpp`).
Edite ese fichero hasta que considere que tiene una versión operativa.
Una vez finalizado su programa, el siguiente paso consiste en pasar (superar) los tests del código.
Cada ejercicio de Exercism va acompañado de una serie de tests que el programa debe superar para ser
considerado válido.

Tal como se explica en la página [Running the Tests](https://exercism.io/tracks/cpp/tests), cada problema va
acompañado de sus tests unitarios y un fichero `CMakeLists.txt` que se
utiliza para automatizar la compilación de los tests y del propio programa.
Tenga en cuenta que **no** debiera editar ni modificar el fichero `CMakeLists.txt`.

Tal como se indica en la página anterior y suponiendo que su ejercicio se llame `bob`, 
debieran existir los ficheros `bob.cpp` y `bob.h` antes de
ejecutar los tests. 
Esos ficheros podrían estar vacíos, pero han de existir.
En el caso del ejercicio `hello-world` los ficheros son `hello-world.cpp` y `hello-world.h`

El siguiente paso es compilar el programa y los tests unitarios.
Para ello, colóquese en el directorio del ejercicio (`/home/usuario/snap/exercism/5/exercism/cpp/hello-world`)
y ejecute:
```
$ touch hello-world.{h,cpp}
$ mkdir build
$ cd build
$ cmake -G "Unix Makefiles" ..
$ make
```
El comando [touch](https://ss64.com/bash/touch.html) modifica la fecha del fichero (ficheros) que se le pasen
como argumentos. 
El directorio `build` que se crea servirá para alojar (entre otros ficheros) un programa ejecutable que pasará
los tests a su código.
Exercism utiliza `cmake` (tendrá Ud. que instalar esa aplicación en su VM si no la tiene instalada).

Al ejecutar `cmake -G "Unix Makefiles" ..` CMake creará un fichero Makefile que le servirá para compilar su
ejercicio.
Al ejecutar `make` en el directorio `build` se compilan los tests que ha de pasar su programa.
Si se producen errores de compilación, tendrá Ud. que solucionarlos en el directorio (padre de `build`) de su
ejercicio.
Una vez que se corrijan los errores, `make` construirá y ejecutará los tests que haya disponibles para el
ejercicio en cuestión.

Normalmente cada problema viene acompañado de un conjunto de tests cuyo código se encuentra en un fichero cuyo
nombre tiene el sufijo `_test` (fichero `hello_world_test.cpp` en el caso del ejercicio "Hello
World").
La estrategia que ha de seguir a la hora de progresar en la mejora de su ejercicio es hacer que su código pase
progresivamente las diferentes pruebas (tests) que figuran en ese fichero.
Para ello basta que "mueva" en el código la línea
```
#if defined(EXERCISM_RUN_ALL_TESTS)
```
para situarla después del siguiente test que quiera probar.
Tenga en cuenta que la plataforma de testing que utiliza Exercism es 
[Catch2](https://github.com/catchorg/Catch2)
y no Google Tests, pero los tests en formato Catch2 son fáciles de entender si se conoce
cualquier otra plataforma de testing.

Cuando su solución al problema pase todos los tests y esté Ud. satisfecha con la misma, puede remitirla a la
plataforma.
Utilice para ello el comando `exercism submit` que hallará Ud. en la página correspondiente al problema.
Una vez que haya enviado su solución a Exercism recibirá un mensaje similar a este:
```
Your solution has been submitted successfully.
You can complete the exercise and unlock the next core exercise at:

https://exercism.io/my/solutions/xxxx
```
A partir de este punto puede ya ver las soluciones que otras usuarias hayan dado al mismo problema o bien
avanzar con otros problemas de ese mismo "track".

### Trabajo previo
Antes de realizar los ejercicios de esta práctica, estudie detenidamente el Capítulo 8 (epígrafes 8.1-8.16) del
[tutorial learncpp](https://www.learncpp.com/cpp-tutorial/81-welcome-to-object-oriented-programming/).
Muchos de los ejemplos de ese tutorial son los mismos que se utilizan en las clases teóricas de la asignatura,
cuyo material debiera Ud. también estudiar.

### Entorno de trabajo
Al realizar los siguientes ejercicios cree dentro de su repositorio de esta práctica un directorio diferente
para cada uno de los ejercicios (proyectos) con un contenido similar al que se ha entregado para la aplicación
de ejemplo `fibonacci_sum`.
Tómese como ejemplo el primero de los ejercicios.
Ponga a cada uno de esos directorios nombres significativos (fechas, complejos, racionales por ejemplo).

Haga que cada uno de sus programas conste de 3 ficheros:
* Un fichero `fechas.cc` (programa principal) que contendrá la función `main` e incluirá el fichero de cabecera `fecha.h`.
* El fichero `fecha.h` que contendrá las declaraciones correspondientes a la clase `Fecha`.
* El fichero `fecha.cc` que contendrá el código (definiciones) correspondientes a la clase `Fecha`.
* Obviamente si el programa principal (`fechas.cc`) utiliza otras clases, debería incluir (`#include`) los
  correspondientes ficheros de cabecera.
Modifique estos nombres de ficheros para adaptarlos al ejercicio en cuestión.

La compilación del programa correspondiente a cada ejercicio se automatizará con un fichero `CMakeLists.txt`
que se utilizará con `cmake`.

Así pues, la estructura de directorios y sus contenidos correspondiente al primero de los ejercicios
propuestos sería la siguiente:
```
fechas
    ├── build           // Directorio inicialmente vacío para alojar el programa ejecutable
    ├── CMakeLists.txt  // Fichero de configuración para cmake
    └── src             // Directorio contenedor del código fuente del ejercicio
        ├── fecha.cc
        ├── fecha.h
        └── fechas.cc
```

Desarrolle cada uno de estos ejercicios de forma incremental, probando cada una de las funciones que va Ud.
desarrollando. Utilice el depurador de VSC para corregir cualquier tipo de error semántico que se produzca en
cualquiera de sus desarrollos.

### Ejercicios
1. La clase `Fecha`.

Desarrolle una clase `Fecha` que permita representar y gestionar fechas.
Incorpore en la clase los miembros de datos y métodos que considere adecuados para la finalidad que se
persigue en este ejercicio.
Incluya un método que permita determinar si el año correspondiente a una fecha es un año bisiesto o
no.
Realice un programa cliente `fechas.cc` que tome como parámetros dos nombres de ficheros correspondientes a
sendos ficheros de texto:

```
./fechas - Gestión de fechas
Modo de uso: ./fechas fichero_entrada.txt fichero_salida.txt
Pruebe ./fechas --help para más información
```
El fichero de entrada contendrá múltiples líneas en cada una de las cuales habrá una fecha escrita en el formato:
```
dd/mm/aa
```
El programa deberá imprimir en el fichero de salida (segundo parámetro) todas las fechas que se encuentran en
el fichero de entrada pero escritas en orden ascendente cronológicamente.
Un modo de proceder es leer todas las fechas del fichero de entrada y almacenarlas en un vector, que será
posteriormente ordenado para luego volcar su contenido en el fichero de salida.
Para proceder de este modo ha de sobrecargar el operador que permite determinar el "orden" (cronológico) de
dos fechas.

Desarrolle un conjunto de tests (gtest) que incluya al menos dos tests para cada una de las funciones que incluya en
su programa.

2. La clase `Complejo`.

Todo
[número complejo](https://es.wikipedia.org/wiki/N%C3%BAmero_complejo)
puede representarse como la suma de un número real y un número imaginario, de la forma `a + bi` donde el
término `a` es la parte real, `b` la parte imaginaria e `i` la
[unidad imaginaria](https://es.wikipedia.org/wiki/Unidad_imaginaria).

En este ejercicio se propone desarrollar una clase `Complejo` que permita operar con números complejos.

Separe el diseño de su clase `Complejo` en dos ficheros, `complejo.h` y `complejo.cc` conteniendo
respectivamente la declaración y la definición de la clase.
Siga las indicaciones del tutorial 
[Class code and header files](https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/)
para realizar esta separación de su clase en dos ficheros.
Siga igualmente las indicaciones del tutorial 
[Header guards](https://www.learncpp.com/cpp-tutorial/header-guards/)
para incluir (siempre de ahora en adelante) *header guards* (guardas de cabecera) en sus ficheros de
definiciones (`*.h`) de modo que se evite la inclusión múltiple del mismo fichero.

Desarrolle un programa cliente `complejos.cc` que permita operar con números complejos y haga uso de la clase `Complejo` que diseñe.
La clase `Complejo` ha de contener al menos métodos que permitan (`Print()`) imprimir un número complejo así como sumar (`Add()`) y restar (`Sub()`) números complejos.
Así la función `main` del programa `complejos.cc` podría contener sentencias como las siguientes:

```
main() {
  Complejo complejo1{4, 5}, complejo2{7, -8};
  Complejo resultado;
  resultado = add(complejo1, complejo2);
  resultado.print();
  resultado = sub(complejo1, complejo2);
  resultado.print();
}
```
que imprimirían en pantalla los resultados de la suma y referencia de números complejos indicada.

Incluya (discrecionalmente) cualesquiera otras operaciones que considere adecuadas como métodos en la clase `Complejo`.

Desarrolle un conjunto de tests (gtest) que incluya al menos dos tests para cada una de las funciones que incluya en su programa.

### Referencias
* [Desarrollo dirigido por Tests](https://es.wikipedia.org/wiki/Desarrollo_guiado_por_pruebas)
* [Google Test](https://en.wikipedia.org/wiki/Google_Test)
* [Cómo usar Google Test para C++ en VSC](https://docs.microsoft.com/es-es/visualstudio/test/how-to-use-google-test-for-cpp?view=vs-2019), 
* [Google Tests build instructions](https://github.com/google/googletest/blob/master/googletest/README.md#standalone-cmake-project)
* [Googletest Primer](https://github.com/google/googletest/blob/master/googletest/docs/primer.md)
* [Mejorar la calidad del código mediante la prueba unitaria](https://www.mql5.com/es/articles/1579).
* [Google Test + gcover. Una lista de recetas](https://usingstdcpp.files.wordpress.com/2016/11/gtest.pdf)
* [Exercism](https://exercism.io/)
* [Exercism en genbeta](https://www.genbeta.com/desarrollo/exercism-fitness-para-nuestras-habilidades-programadoras)
* [¿Qué es Ubuntu `snap`?](https://blogubuntu.com/que-es-ubuntu-snap) 
* [snap quickstart guide](https://snapcraft.io/docs/getting-started)
* [Números complejos](https://es.wikipedia.org/wiki/N%C3%BAmero_complejo)
*	[Class code and header files](https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/)
* [Header guards](https://www.learncpp.com/cpp-tutorial/header-guards/)
* [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
