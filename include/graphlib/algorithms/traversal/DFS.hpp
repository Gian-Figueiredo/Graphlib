#ifndef DFS_HPP
#define DFS_HPP

#include <graphlib/common/IBaseGraph.hpp>
#include <graphlib/common/Repository.hpp>
#include <vector>

namespace graphlib::algorithms {

    struct DFSResult {
        std::vector<int> pai;
        std::vector<Color> cor;
        std::vector<int> dur;
        std::vector<int> fin;
    };

    DFSResult dfs(const IBaseGraph& graph);
}

#endif