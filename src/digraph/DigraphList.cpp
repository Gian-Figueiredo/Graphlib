#include <graphlib/digraph/DigraphList.hpp>
#include <string>
#include <vector>

namespace graphlib {
    DigraphList::DigraphList(int numVertices) : adjList(numVertices) {}

    int DigraphList::V() const {
        return static_cast<int>(adjList.size());
    }

    void DigraphList::addArc(int v, int w) {
        adjList.at(v).push_back(w);
    }

    void DigraphList::clearEdges() {
        int numVertices = adjList.size();
        for (int c = 0; c < numVertices; c++) {
            adjList.at(c).clear();
        }
    }

    int DigraphList::inDegree(int v) const {
        int degree = 0;
        for (int c = 0; c < V(); c++) {
            for (auto const i : adjList.at(c)) {
                if (i == v) degree++;
            }
        }
        return degree;
    }

    int DigraphList::outDegree(int v) const {
        return static_cast<int>(adjList.at(v).size());
    }

    std::vector<int> DigraphList::adj(int v) const {
        return adjList.at(v);
    }

    std::string DigraphList::toString() const {
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