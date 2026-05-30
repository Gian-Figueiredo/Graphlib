#ifndef DIGRAPH_MATRIX_HPP
#define DIGRAPH_MATRIX_HPP

#include <graphlib/digraph/IDigraph.hpp>
#include <vector>
#include <string>

namespace graphlib {
    class DigraphMatrix : public IDigraph {
        private:
            std::vector<std::vector<bool>> adjMatrix;

        public:
            DigraphMatrix(int numVertices);

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