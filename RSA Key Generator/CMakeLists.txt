cmake_minimum_required(VERSION 3.21)
project(RSA_Key_Generator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(RSA_Key_Generator
        Funciones.cpp
        Funciones.h
        main.cpp
        RSA.cpp
        RSA.h)
