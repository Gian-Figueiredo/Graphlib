#include <test_utils.hpp>
#include <graphlib/graph/GraphMatrix.hpp>
#include <graphlib/graph/GraphList.hpp>

void test_connected_components_graph_matrix() {
    graphlib::GraphMatrix g(7);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(1, 6);

    std::vector<std::vector<int>> expected = {{0, 2, 3, 4, 5}, {1, 6}};
    graphlib::test::test_connected_components(g, expected);
}

void test_connected_components_graph_list() {
    graphlib::GraphList g(7);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(1, 6);

    std::vector<std::vector<int>> expected = {{0, 2, 3, 4, 5}, {1, 6}};
    graphlib::test::test_connected_components(g, expected);
}

int main() {
    test_connected_components_graph_matrix();
    test_connected_components_graph_list();
    return 0;
}