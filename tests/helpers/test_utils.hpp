#ifndef GRAPH_TEST_HPP
#define GRAPH_TEST_HPP

#include <graphlib/graph/IGraph.hpp>
#include <graphlib/digraph/IDigraph.hpp>
#include <graphlib/common/IBaseGraph.hpp>
#include <cassert>
#include <vector>
#include <algorithm>

namespace graphlib::test {
    inline void test_V(graphlib::IBaseGraph& g, int expectedV) {
        assert(g.V() == expectedV);
    }

    inline void test_E(graphlib::IBaseGraph& g, int expectedE) {
        assert(g.E() == expectedE);
    }

    inline void test_clearEdge(graphlib::IGraph& g) {
        assert(g.V() > 0);
        g.addEdge(0, g.V()-1);
        assert(g.E() > 0);
        g.clearEdges();
        assert(g.E() == 0);
    }

    inline void test_addEdge(graphlib::IGraph& g) {
        g.clearEdges();
        assert(g.E() == 0);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(0, 3);

        assert(g.E() == 3);
    }

    inline void test_degree(graphlib::IGraph& g) {
        g.clearEdges();
        assert(g.E() == 0);

        for (int c = 1; c < g.V(); c++) {
            g.addEdge(0, c);
        }

        assert(g.degree(0)==g.V()-1);
        g.addEdge(0, 0);
        assert(g.degree(0)==g.V()+1);
    }

    inline void test_hasEdge(graphlib::IGraph& g) {
        g.clearEdges();
        assert(g.E() == 0);

        g.addEdge(0, g.V()-1);
        assert(g.hasEdge(0, g.V()-1));
        assert(g.hasEdge(g.V()-1, 0));
    }

    inline void test_graph_adj(graphlib::IGraph& g) {
        g.clearEdges();
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(0, 3);

        auto adjList = g.adj(0);
        std::vector<int> expected = {1, 2, 3};

        assert(adjList.size() == expected.size());

        for (int v : expected)
            assert(std::find(adjList.begin(), adjList.end(), v) != adjList.end());

        for (int v : adjList)
            assert(std::find(expected.begin(), expected.end(), v) != expected.end());
    }

    inline void run_graph_contract_tests(graphlib::IGraph& g, int numVertices, int numEdges) {
        test_V(g, numVertices);
        test_E(g, numEdges);
        test_addEdge(g);
        test_graph_adj(g);
        test_hasEdge(g);
        test_degree(g);
    }

    inline void test_clearArc(graphlib::IDigraph& d) {
        assert(d.E() > 0);
        d.clearArcs();
        assert(d.E() == 0);
    }

    inline void test_addArc(graphlib::IDigraph& d) {
        d.clearArcs();
        assert(d.E() == 0);
    }

    inline void test_digraph_adj(graphlib::IDigraph& d) {
        d.clearArcs();
        d.addArc(0, 1);
        d.addArc(0, 2);
        d.addArc(0, 3);

        auto adjList = d.adj(0);
        std::vector<int> expected = {1, 2, 3};

        assert(adjList.size() == expected.size());

        for (int v : expected)
            assert(std::find(adjList.begin(), adjList.end(), v) != adjList.end());

        for (int v : adjList)
            assert(std::find(expected.begin(), expected.end(), v) != expected.end());
    }

    inline void run_digraph_contract_test(graphlib::IDigraph& d, int numVertices, int numEdges) {
        test_V(d, numVertices);
        test_E(d, numEdges);
        test_addArc(d);
        test_digraph_adj(d);
    }

} // namespace graphlib::test

#endif