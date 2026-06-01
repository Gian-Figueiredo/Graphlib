#include <graphlib/algorithms/connectivity/ConnectedComponents.hpp>
#include <graphlib/common/Repository.hpp>

namespace graphlib::algorithms {

    static void dfs_visit(const IGraph& graph, int v, std::vector<int>& component, std::vector<graphlib::algorithms::Color>& cor) {
        component.push_back(v);
        for (const auto i : graph.adj(v)) {
            if (cor.at(i) == Color::BRANCO) {
                cor.at(i) = Color::CINZA;
                dfs_visit(graph, i, component, cor);
            }
        }
        cor.at(v) = Color::PRETO;
    }

    std::vector<std::vector<int>> connectedComponents(const IGraph& graph) {
        std::vector<std::vector<int>> components;
        std::vector<graphlib::algorithms::Color> cor(graph.V(), Color::BRANCO);

        for (int v = 0; v < graph.V(); v++) {
            if (cor.at(v) == Color::BRANCO) {
                components.push_back(std::vector<int>());
                dfs_visit(graph, v, components.back(), cor);
            }
        }

        return components;
    }
}