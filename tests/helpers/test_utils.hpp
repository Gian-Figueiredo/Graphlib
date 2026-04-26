#ifndef GRAPH_TEST_HPP
#define GRAPH_TEST_HPP

#include <graphlib/Graph.hpp>
#include <cassert>
#include <vector>
#include <algorithm>

namespace graphlib::test {
    inline void test_V(graphlib::Graph& g, int expectedV) {
        assert(g.V() == expectedV);
    }

    inline void test_E(graphlib::Graph& g, int expectedE) {
        assert(g.E() == expectedE);
    }

    inline void test_addEdge(graphlib::Graph& g) {
        assert(g.E() == 0);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(0, 3);

        assert(g.E() == 3);
    }

    inline void test_adj(graphlib::Graph& g) {
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

    inline void run_contract_tests(graphlib::Graph& g) {
        test_V(g, 5);
        test_E(g, 0);
        test_addEdge(g);
        test_adj(g);
    }

} // namespace graphlib::test

#endif