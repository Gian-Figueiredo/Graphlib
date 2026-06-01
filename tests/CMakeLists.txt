# Biblioteca auxiliar para testes
add_library(graph_test_utils INTERFACE)

target_include_directories(graph_test_utils INTERFACE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/tests/helpers
)

# Função para criar testes
function(add_graph_test test_name test_target source_file)
    add_executable(${test_target} ${source_file})

    target_link_libraries(${test_target}
        PRIVATE
        graphlib
        graph_test_utils
    )

    add_test(NAME ${test_name} COMMAND ${test_target})
endfunction()

# Testes
add_graph_test(TestGraphMatrix test_graph_matrix graphs/test_GraphMatrix.cpp)
add_graph_test(TestGraphList test_graph_list graphs/test_GraphList.cpp)
add_graph_test(TestDigraphList test_digraph_list digraphs/test_DigraphList.cpp)
add_graph_test(TestDigraphMatrix test_digraph_matrix digraphs/test_DigraphMatrix.cpp)
add_graph_test(TestDFS test_dfs algorithms/test_dfs.cpp)
add_graph_test(TestBFS test_bfs algorithms/test_bfs.cpp)