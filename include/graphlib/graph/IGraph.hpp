#ifndef IGRAPH_HPP
#define IGRAPH_HPP

#include <graphlib/common/IBaseGraph.hpp>

namespace graphlib {
    class IGraph : public IBaseGraph {
        public:
            virtual void addEdge(int v, int w) = 0;

            virtual int degree(int v) const = 0;

            virtual bool hasEdge(int v, int w) const = 0;

            virtual int E() const override {
                int numVertices = V();
                int sumDegree = 0;
                for (int c = 0; c < numVertices; c++) {
                    sumDegree += degree(c);
                }
                return sumDegree / 2;
            }
    };
}

#endif