cmake_minimum_required(VERSION 3.10)
project(GraphLib)

# Lista de arquivos fonte
set(SOURCES
    src/GraphMatrix.cpp
)

# Cria a biblioteca
add_library(graphlib ${SOURCES})

# Defina o compilador para a biblioteca
target_compile_features(graphlib PUBLIC cxx_std_17)

# Headers públicos
target_include_directories(graphlib PUBLIC include)

#Testes
enable_testing()
add_executable(test_graph tests/test_GraphMatrix.cpp)
target_link_libraries(test_graph PRIVATE graphlib)
add_test(NAME TestGraphMatrix COMMAND test_graph)