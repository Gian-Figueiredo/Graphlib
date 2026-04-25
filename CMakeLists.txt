cmake_minimum_required(VERSION 3.10)
project(GraphLib)

# Lista de arquivos fonte
set(SOURCES
    src/soma.cpp
)

# Cria a biblioteca
add_library(graphlib ${SOURCES})

# Defina o compilador para a biblioteca
target_compile_features(graphlib PUBLIC cxx_std_17)

# Headers públicos
target_include_directories(graphlib PUBLIC include)

# TESTE
add_executable(test_soma tests/test_soma.cpp)
target_link_libraries(test_soma graphlib)

enable_testing()
add_test(NAME SomaTest COMMAND test_soma)