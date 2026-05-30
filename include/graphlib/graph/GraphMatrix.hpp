#ifndef GRAPH_MATRIX_HPP
#define GRAPH_MATRIX_HPP

#include <graphlib/graph/IGraph.hpp>
#include <vector>
#include <string>

namespace graphlib {
    class GraphMatrix : public IGraph {
        private:
            std::vector<std::vector<bool>> adjMatrix;

        public:
            GraphMatrix(int numVertices);

            int V() const override;

            void addEdge(int v, int w) override;
            void clearEdges() override;

            int degree(int v) const override;
            bool hasEdge(int v, int w) const override;

            std::vector<int> adj(int v) const override;
            std::string toString() const override;
    };
}

#endif