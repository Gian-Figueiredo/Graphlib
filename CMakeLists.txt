cmake_minimum_required(VERSION 3.15)
project(GraphLib)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Lista de arquivos fonte
set(SOURCES
    src/graph/GraphMatrix.cpp
    src/graph/GraphList.cpp
    src/digraph/DigraphMatrix.cpp
    src/digraph/DigraphList.cpp
)

# Cria a biblioteca
add_library(graphlib ${SOURCES})

# Defina o compilador para a biblioteca
target_compile_features(graphlib PUBLIC cxx_std_17)

# Headers públicos
target_include_directories(graphlib PUBLIC include)

# Testes
option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()