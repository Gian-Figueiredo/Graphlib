# Biblioteca auxiliar para testes
add_library(graph_test_utils INTERFACE)

target_include_directories(graph_test_utils INTERFACE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/tests/helpers
)

# Teste GraphMatrix
add_executable(test_graph_matrix test_GraphMatrix.cpp)
target_link_libraries(test_graph_matrix PRIVATE graphlib graph_test_utils)

add_test(NAME TestGraphMatrix COMMAND test_graph_matrix)

# Teste GraphList
add_executable(test_graph_list test_GraphList.cpp)
target_link_libraries(test_graph_list PRIVATE graphlib graph_test_utils)

add_test(NAME TestGraphList COMMAND test_graph_list)

