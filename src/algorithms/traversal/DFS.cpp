#include "graphlib/common/IBaseGraph.hpp"
#include <graphlib/algorithms/traversal/DFS.hpp>
#include <vector>

namespace graphlib::algorithms {
    static void dfs_visit(const IBaseGraph& graph, int v, int& tempo, DFSResult& result) {
        result.cor.at(v) = Cor::CINZA;
        result.dur.at(v) = ++tempo;
        for (const auto i : graph.adj(v)) {
            if (result.cor.at(i) == Cor::BRANCO) {
                result.pai.at(i) = v;
                dfs_visit(graph, i, tempo, result);
            }
        }
        result.cor.at(v) = Cor::PRETO;
        result.fin.at(v) = ++tempo;
    }

    DFSResult dfs(const IBaseGraph &graph) {
        DFSResult result;
        result.pai = std::vector<int>(graph.V(), -1);
        result.cor = std::vector<Cor>(graph.V(), Cor::BRANCO);
        result.dur = std::vector<int>(graph.V(), -1);
        result.fin = std::vector<int>(graph.V(), -1);

        int tempo = 0;

        for (int v = 0; v < graph.V(); v++) {
            if (result.cor.at(v) == Cor::BRANCO) {
                dfs_visit(graph, v, tempo, result);
            }
        }

        return result;
    }
}