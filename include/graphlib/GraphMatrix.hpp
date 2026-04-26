#ifndef GRAPH_MATRIX_HPP
#define GRAPH_MATRIX_HPP

#include <graphlib/IGraph.hpp>
#include <vector>
#include <string>

namespace graphlib {
    class GraphMatrix : public IGraph {
        private:
            std::vector<std::vector<bool>> adjMatrix;

        public:
            GraphMatrix(int vertex);

            int V() const;
            int E() const;

            void addEdge(int v, int w);

            std::vector<bool> adj(int v) const;
            std::string toString() const;
    };
}

#endif