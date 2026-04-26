#include <graphlib/GraphMatrix.hpp>
#include <vector>
#include <string>

namespace graphlib {
    GraphMatrix::GraphMatrix(int numVertices) : adjMatrix(numVertices, std::vector<bool>(numVertices, false)) {}

    int GraphMatrix::V() const {
        return adjMatrix.size();
    }

    int GraphMatrix::E() const {
        int numVertex = adjMatrix.size();
        int edge = 0;
        for (int i = 0; i < numVertex; i++) {
            for (int j = i; j < numVertex; j++) {
                if (adjMatrix.at(i).at(j)) {
                    edge++;
                }
            }
        }
        return edge;
    }

    void GraphMatrix::addEdge(int v, int w) {
        adjMatrix.at(v).at(w) = true;
        adjMatrix.at(w).at(v) = true;
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