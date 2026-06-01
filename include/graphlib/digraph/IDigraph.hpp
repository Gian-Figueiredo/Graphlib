#ifndef IDIGRAPH_HPP
#define IDIGRAPH_HPP

#include <graphlib/common/IBaseGraph.hpp>

namespace graphlib {
    class IDigraph : public IBaseGraph {
        public:
            virtual void addArc(int v, int w) = 0;
            virtual void clearArcs() = 0;

            virtual int inDegree(int v) const = 0;
            virtual int outDegree(int v) const = 0;

            virtual int E() const override {
                int sumDegree = 0;
                for (int c = 0; c < V(); c++) {
                    sumDegree += inDegree(c);
                }
                return sumDegree;
            }
    };
}

#endif

/*
virtual int E() const override {
                int numVertices = V();
                int sumDegree = 0;
                for (int c = 0; c < numVertices; c++) {
                    sumDegree += degree(c);
                }
                return sumDegree / 2;
            }
*/