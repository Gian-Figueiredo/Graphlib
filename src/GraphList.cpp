#include <graphlib/GraphList.hpp>
#include <string>
#include <vector>

namespace graphlib {
    GraphList::GraphList(int numVertices) : adjList(numVertices) {}

    int GraphList::V() const {
        return adjList.size();
    }

    int GraphList::E() const {
        int numVertices = adjList.size();
        double numEdge = 0;
        for (int i = 0; i < numVertices; i++) {
            for (const auto j : adjList.at(i)) {
                if (i == j) {
                    numEdge += 1;
                } else {
                    numEdge += 0.5;
                }
            }
        }
        return (int)numEdge;
    }

    void GraphList::addEdge(int v, int w) {
        adjList.at(v).push_back(w);
        adjList.at(w).push_back(v);
    }

    void GraphList::clearEdges() {
        int numVertices = adjList.size();
        for (int c = 0; c < numVertices; c++) {
            adjList.at(c) = std::vector<int>();
        }
    }

    std::vector<int> GraphList::adj(int v) const {
        return adjList.at(v);
    }

    std::string GraphList::toString() const {
        int numVertices = adjList.size();
        if (numVertices == 0) {
            return "Grafo nulo";
        }

        std::string str = "";

        auto toStringList = [&](int index) {
            int size = adjList.at(index).size();
            str += std::to_string(index);
            str += ": {";
            if (size == 0) {
                str += " }";
                return;
            }
            str += std::to_string(adjList.at(index).at(0));
            for (int c = 1; c < size; c++) {
                str += ", ";
                str += std::to_string(adjList.at(index).at(c));
            }
            str += "}";
        };

        toStringList(0);
        for (int i = 1; i < numVertices; i++) {
            str += "\n";
            toStringList(i);
        }
        return str;
    }
}