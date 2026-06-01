#include <graphlib/common/IBaseGraph.hpp>
#include <graphlib/algorithms/traversal/BFS.hpp>
#include <vector>
#include <queue>
#include <stdexcept>

namespace graphlib::algorithms {
    BFSResult bfs(const IBaseGraph& graph, int source) {
        if (source < 0 || source >= graph.V()) {
            throw std::out_of_range("Vertex out of range");
        }

        BFSResult result;
        result.pai = std::vector<int>(graph.V(), -1);
        result.cor = std::vector<Color>(graph.V(), Color::BRANCO);
        result.dist = std::vector<int>(graph.V(), -1);
        
        result.cor[source] = Color::CINZA;
        result.dist[source] = 0;
        result.pai[source] = -1;

        std::queue<int> Q;
        Q.push(source);

        while (!Q.empty()) {
            int vertex = Q.front();
            Q.pop();
            
            for (const auto i : graph.adj(vertex)) {
                if (result.cor[i] == Color::BRANCO) {
                    result.cor[i] = Color::CINZA;
                    result.dist[i] = result.dist[vertex] + 1;
                    result.pai[i] = vertex;
                    Q.push(i);
                }
            }

            result.cor[vertex] = Color::PRETO;
        }

        return result;
    }
}