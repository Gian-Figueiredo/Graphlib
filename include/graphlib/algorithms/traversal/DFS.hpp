#ifndef DFS_HPP
#define DFS_HPP

#include <graphlib/common/IBaseGraph.hpp>
#include <vector>

namespace graphlib::algorithms {
    enum class Cor {BRANCO, CINZA, PRETO};

    struct DFSResult {
        std::vector<int> pai;
        std::vector<Cor> cor;
        std::vector<int> dur;
        std::vector<int> fin;
    };

    DFSResult dfs(const IBaseGraph& graph);
}

#endif