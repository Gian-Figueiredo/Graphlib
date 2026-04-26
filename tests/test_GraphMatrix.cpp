#include <graphlib/GraphMatrix.hpp>
#include <graphlib/IGraph.hpp>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
void print(T obj) {
    std::cout << obj << "\n";
}

int main() {
    graphlib::IGraph *graph = new graphlib::GraphMatrix(5);
    print(graph->toString());
    print(graph->V());
    print(graph->E());
    graph->addEdge(0, 4);
    print(graph->E());
    graph->addEdge(4, 2);
    graph->addEdge(3, 2);
    auto adjList = graph->adj(2);
    std::string str;
    int numAdj = adjList.size();
    if (numAdj > 0) {
        str = std::to_string(adjList.at(0));
        for (int c = 1; c < numAdj; c++) {
            str += ", ";
            str += std::to_string(adjList.at(c));
        }
    } else {
        str = "Isolate vertex";
    }
    std::cout << 2 << ": " << str << "\n";
    print(graph->E());
    print(graph->toString());
    delete graph;
}