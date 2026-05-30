#include <graphlib/graph/GraphMatrix.hpp>
#include <vector>
#include <string>

namespace graphlib {
    GraphMatrix::GraphMatrix(int numVertices) : adjMatrix(numVertices, std::vector<bool>(numVertices, false)) {}

    int GraphMatrix::V() const {
        return static_cast<int>(adjMatrix.size());
    }

    void GraphMatrix::addEdge(int v, int w) {
        adjMatrix.at(v).at(w) = true;
        adjMatrix.at(w).at(v) = true;
    }

    void GraphMatrix::clearEdges() {
        int numVertices = adjMatrix.size();
        for (int c = 0; c < numVertices; c++) {
            adjMatrix.at(c) = std::vector<bool>(numVertices, false);
        }
    }

    int GraphMatrix::degree(int v) const {
        int degree = 0;
        for (int c = 0; c < adjMatrix.size(); c++) {
            if (adjMatrix.at(v).at(c)) {
                if (c == v) {
                    degree += 2;
                } else {
                    degree += 1;
                }
            }
        }
        return degree;
    }

    bool GraphMatrix::hasEdge(int v, int w) const {
        return adjMatrix.at(v).at(w);
    }

    std::vector<int> GraphMatrix::adj(int v) const {
        std::vector<bool> row = adjMatrix.at(v);
        std::vector<int> adjList = {};
        for (int c = 0; c < (int)row.size(); c++) {
            if (row.at(c)) {
                adjList.push_back(c);
            }
        }
        return adjList;
    }

    std::string GraphMatrix::toString() const {
        int numVertex = adjMatrix.size();
        if (numVertex <= 0) {
            return "Null Graph";
        }

        std::string str = "| ";

        auto rowToString = [&](int row) {
            str += std::to_string(adjMatrix.at(row).at(0));
            for (int c = 1; c < numVertex; c++) {
                str += ", ";
                str += std::to_string(adjMatrix.at(row).at(c));
            }
            str += " |";
        };

        rowToString(0);
        for (int i = 1; i < numVertex; i++) {
            str += "\n| ";
            rowToString(i);
        }

        return str;
    }
}