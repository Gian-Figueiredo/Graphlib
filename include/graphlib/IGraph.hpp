#ifndef IGRAPH_HPP
#define IGRAPH_HPP

#include <string>
#include <vector>

namespace graphlib {
    class IGraph {
        public:
            virtual int V() const = 0;
            virtual int E() const = 0;

            virtual void addEdge(int v, int w) = 0;
            virtual void clearEdges() = 0;

            virtual std::vector<int> adj(int v) const = 0;
            virtual std::string toString() const = 0;

            virtual ~IGraph() = default;
    };
}

#endif