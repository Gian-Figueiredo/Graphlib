#ifndef GRAPH_LIST_HPP
#define GRAPH_LIST_HPP

#include <graphlib/Graph.hpp>
#include <vector>
#include <string>

namespace graphlib {
    class GraphList : public IGraph {
        private:
            std::vector<std::vector<int>> adjList;

        public:
            GraphList(int numVertices);

            int V() const;
            int E() const;

            void addEdge(int v, int w);
            void clearEdges();

            std::vector<int> adj(int v) const;
            std::string toString() const;
    };
}

#endif