#include <graphlib/graph/GraphList.hpp>
#include <test_utils.hpp>
#include <iostream>

int main() {
    graphlib::GraphList g(5);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    graphlib::test::run_contract_tests(g, 5, 2);
    g.clearEdges();
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    std::cout << g.toString() << "\n";
}