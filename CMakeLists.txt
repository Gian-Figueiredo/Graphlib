cmake_minimum_required(VERSION 3.10)
project(GraphLib)

# Lista de arquivos fonte
set(SOURCES
    src/soma.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Cria a biblioteca
add_library(graphlib ${SOURCES})

# Headers públicos
target_include_directories(graphlib PUBLIC include)

# TESTE
add_executable(test_soma tests/test_soma.cpp)
target_link_libraries(test_soma graphlib)