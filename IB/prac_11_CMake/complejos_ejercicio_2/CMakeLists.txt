# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeriería Informática
# Informática Básica 
# 
# @author Cristopher Afonso Mora 
# @date 05 Ene 2021 
# @brief este es el archivo CMake para el ejercicio de complejos, el ejercicio 2 de la práctica 11 de IB

# Intrucciones básicas para desarrollar un archivo CMakeLists.txt

cmake_minimum_required(VERSION 3.1) 

project(complejos.cc
    VERSION 1.0
    DESCRIPTION "Este es un simple proyecto CMake para el programa complejos.cc que te permite sumar, restar, multiplicar y dividir números complejos"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)    # Usaremos el estándar 14
set(CMAKE_CXX_STANDARD_REQUIRED True) 

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) 

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3") 

include_directories(${PROJECT_SOURCE_DIR}/src) 

add_executable(complejos
    src/complejos.h 
    src/complejos.cc 
    src/functions_complejos.cc) 

target_compile_features(complejos PRIVATE cxx_std_14) 

target_compile_options(complejos PRIVATE -Wall -Wextra -Weffc++ -Wpedantic) 
