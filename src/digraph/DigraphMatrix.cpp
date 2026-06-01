#include <graphlib/digraph/DigraphMatrix.hpp>
#include <vector>
#include <string>

namespace graphlib {
    DigraphMatrix::DigraphMatrix(int numVertices) : adjMatrix(numVertices, std::vector<bool>(numVertices, false)) {}

    int DigraphMatrix::V() const {
        return static_cast<int>(adjMatrix.size());
    }

    void DigraphMatrix::addArc(int v, int w) {
        adjMatrix.at(v).at(w) = true;
    }

    void DigraphMatrix::clearArcs() {
        int numVertices = adjMatrix.size();
        for (int c = 0; c < numVertices; c++) {
            adjMatrix.at(c) = std::vector<bool>(numVertices, false);
        }
    }

    int DigraphMatrix::inDegree(int v) const {
        int degree = 0;
        for (int c = 0; c < V(); c++) {
            if (adjMatrix.at(c).at(v)) {
                degree += 1;
            }
        }
        return degree;
    }

    int DigraphMatrix::outDegree(int v) const {
        int degree = 0;
        for (int c = 0; c < V(); c++) {
            if (adjMatrix.at(v).at(c)) {
                degree += 1;
            }
        }
        return  degree;
    }

    std::vector<int> DigraphMatrix::adj(int v) const {
        std::vector<bool> row = adjMatrix.at(v);
        std::vector<int> adjList = {};
        for (int c = 0; c < (int)row.size(); c++) {
            if (row.at(c)) {
                adjList.push_back(c);
            }
        }
        return adjList;
    }

    std::string DigraphMatrix::toString() const {
        int numVertex = adjMatrix.size();
        if (numVertex <= 0) {
            return "Null Digraph";
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