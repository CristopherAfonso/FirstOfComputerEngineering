# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeriería Informática
# Informática Básica 
# 
# @author Cristopher Afonso Mora 
# @date 05 Ene 2021 
# @brief este es el archivo CMake para el ejercicio de fechas, el ejercicio 1 de la práctica 11 de IB

# Intrucciones básicas para desarrollar un archivo CMakeLists.txt


#Paso 1 (Obligatorio): declarar la versión del CMake
cmake_minimum_required(VERSION 3.1) 

#Paso 2 (Obligatorio): poner el nombre del proyecto (del archivo donde se halla el "main")
project(fechas.cc       # Poner el nombre del proyecto es obligatorio
    VERSION 1.0
    DESCRIPTION "Este es un simple proyecto CMake para el programa fechas.cc que te da las N fechas anteriores a la fecha que le das como parámetro por línea de comandos"
    LANGUAGES CXX)

#Paso 3: Especificar el Estandar que se usará de C++
set(CMAKE_CXX_STANDARD 14)    # Usaremos el estándar 14
set(CMAKE_CXX_STANDARD_REQUIRED True) 

#Paso 4 (Obligatorio): Decirle al CMake en qué carpeta debe poner el archivo binario (el binario que va a crear) y las librerías
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) 

#Paso 5: Colocamos las etiquetas ó banderas(FLAGS) de depuración y lanzamiento
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3") 

#Paso 6: Decirle al CMake donde buscar los archivos *.h 
include_directories(${PROJECT_SOURCE_DIR}/src) 

#Paso 7 (Opcional): si tuvieras librerías que añadir en la carpeta src, se crearía la librería (nombre de ejemplo) "libtools"
#add_library(tools src/tools.cc) 

#Paso 8: Añadimos un objetivo ejecutable llamado "fechas" para ser construido desde los archivos de código fuente listados en el comando de invocación
add_executable(fechas
    src/fechas.h 
    src/fechas.cc 
    src/functions_fechas.cc) 

#Paso 9 (Opcional, si se hace el Paso 7): Decirle al enlazador que vincule estos objetos juntos
#Es importante colocar target_link_libraries después de las líneas add_executable y find_package, para que se conozcan todos los componentes vinculados
#target_link_libraries(fechas tools) 

#Paso 10: Agregar características esperadas del compilador a un objetivo (nuestro ejecutable)
target_compile_features(fechas PRIVATE cxx_std_14) 

#Paso 11: Añadir las opciones del compilador a un objetivo (nuestro ejecutable) 
target_compile_options(fechas PRIVATE -Wall -Wextra -Weffc++ -Wpedantic) 

#Fin de las instrucciones para construir el ejecutable de un proyecto

#Inicio de las instrucciones para construir un archivo Doxygen desde el Script CMake


find_package(Doxygen)
option(BUILD_DOCUMENTATION "Create and install the documentation (requires Doxygen)" ${DOXYGEN_FOUND})

if(BUILD_DOCUMENTATION)
    if(NOT DOXYGEN_FOUND)
         message(FATAL_ERROR "Doxygen is needed to build the documentation.")
    endif()

    set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/fechas.Doxyfile)
    set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/doxyfile)

    configure_file(${doxyfile_in} ${doxyfile} @ONLY)

    message("Doxygen build started.")

    add_custom_target(doc ALL
                      COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile_in}
                      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc
                      COMMENT "Generating API documentation with Doxygen"
                      VERBATIM)

    #    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION     share/doc)
endif()