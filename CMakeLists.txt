cmake_minimum_required(VERSION 3.16)
project(Picross)

set(CMAKE_CXX_STANDARD 14)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(Picross main.cpp Fenetre.cpp Fenetre.h Grille.cpp Grille.h Logique.cpp Logique.h)
target_link_libraries(Picross ${CONAN_LIBS})