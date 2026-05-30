#ifndef IDIGRAPH_HPP
#define IDIGRAPH_HPP

#include <graphlib/common/IBaseGraph.hpp>

namespace graphlib {
    class IDigraph : public IBaseGraph {
        virtual void addArc(int v, int w) = 0;

        virtual int inDegree(int v) const = 0;
        virtual int outDegree(int v) const = 0;
    };
}

#endif