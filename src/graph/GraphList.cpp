#include <graphlib/graph/GraphList.hpp>
#include <string>
#include <vector>

namespace graphlib {
    GraphList::GraphList(int numVertices) : adjList(numVertices) {}

    int GraphList::V() const {
        return static_cast<int>(adjList.size());
    }

    void GraphList::addEdge(int v, int w) {
        adjList.at(v).push_back(w);
        adjList.at(w).push_back(v);
    }

    void GraphList::clearEdges() {
        int numVertices = adjList.size();
        for (int c = 0; c < numVertices; c++) {
            adjList.at(c).clear();
        }
    }

    int GraphList::degree(int v) const {
        int degree = 0;
        for (const auto i : adjList.at(v)) {
            if (i == v) {
                degree += 2;
            } else {
                degree += 1;
            }
        }
        return degree;
    }

    bool GraphList::hasEdge(int v, int w) const {
        for (auto const i : adjList.at(v)) {
            if (i == w) return true;
        }
        return false;
    }

    std::vector<int> GraphList::adj(int v) const {
        return adjList.at(v);
    }

    std::string GraphList::toString() const {
        int numVertices = adjList.size();
        if (numVertices == 0) {
            return "Null Graph";
        }

        std::string str;

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