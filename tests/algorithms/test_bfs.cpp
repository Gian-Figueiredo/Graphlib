#include <graphlib/algorithms/traversal/BFS.hpp>
#include <graphlib/graph/GraphList.hpp>
#include <graphlib/graph/GraphMatrix.hpp>
#include <graphlib/digraph/DigraphList.hpp>
#include <graphlib/digraph/DigraphMatrix.hpp>
#include <test_utils.hpp>

using namespace graphlib::algorithms;

void test_graph_list() {
    graphlib::GraphList g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    graphlib::algorithms::BFSResult expected;
    expected.pai = {-1, 0, 0, 1, 1};
    expected.cor = {Color::PRETO, Color::PRETO, Color::PRETO, Color::PRETO, Color::PRETO};
    expected.dist = {0, 1, 1, 2, 2};

    graphlib::test::test_bfs(g, expected);
}

void test_graph_matrix() {
    graphlib::GraphMatrix g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    graphlib::algorithms::BFSResult expected;
    expected.pai = {-1, 0, 0, 1, 1};
    expected.cor = {Color::PRETO, Color::PRETO, Color::PRETO, Color::PRETO, Color::PRETO};
    expected.dist = {0, 1, 1, 2, 2};

    graphlib::test::test_bfs(g, expected);
}

void test_digraph_list() {
    graphlib::DigraphList g(5);
    g.addArc(0, 1);
    g.addArc(0, 2);
    g.addArc(1, 3);
    g.addArc(1, 4);

    graphlib::algorithms::BFSResult expected;
    expected.pai = {-1, 0, 0, 1, 1};
    expected.cor = {Color::PRETO, Color::PRETO, Color::PRETO, Color::PRETO, Color::PRETO};
    expected.dist = {0, 1, 1, 2, 2};

    graphlib::test::test_bfs(g, expected);
}

void test_digraph_matrix() {
    graphlib::DigraphMatrix g(5);
    g.addArc(0, 1);
    g.addArc(0, 2);
    g.addArc(1, 3);
    g.addArc(1, 4);

    graphlib::algorithms::BFSResult expected;
    expected.pai = {-1, 0, 0, 1, 1};
    expected.cor = {Color::PRETO, Color::PRETO, Color::PRETO, Color::PRETO, Color::PRETO};
    expected.dist = {0, 1, 1, 2, 2};

    graphlib::test::test_bfs(g, expected);
}

int main() {
    test_graph_list();
    test_graph_matrix();
    test_digraph_list();
    test_digraph_matrix();

    return 0;
}