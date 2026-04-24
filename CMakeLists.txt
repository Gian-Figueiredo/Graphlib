# Define a versão mínima do Cmake
cmake_minimum_required(VERSION 3.10)

# Define a varável $PROJECT_NAME nas versão X usando as linguagens CXX
project(grafos_teste VERSION 1.0 LANGUAGES CXX)

# Seta o compilador padrão e ativa como principal e mínimo
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Seta para lançar o executável no pasta bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Procura todos os arquivos .cpp dentro de src de forma recursiva
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Cria o executável usando o $PROJECT_NAME
add_executable(${PROJECT_NAME} ${SOURCES})

# Seta um diretório como o diretório principal para os includes
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Flags de compilação (opcional, mas útil)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
