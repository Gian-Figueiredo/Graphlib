#ifndef DIGRAPH_LIST_HPP
#define DIGRAPH_LIST_HPP

#include <graphlib/digraph/IDigraph.hpp>
#include <vector>
#include <string>

namespace graphlib {
    class DigraphList : public IDigraph {
        private:
            std::vector<std::vector<int>> adjList;

        public:
            DigraphList(int numVertices);

            int V() const override;

            void addArc(int v, int w) override;
            void clearEdges() override;

            int inDegree(int v) const override;
            int outDegree(int v) const override;

            std::vector<int> adj(int v) const override;
            std::string toString() const override;
    };
}

#endif