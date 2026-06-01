#ifndef BFS_HPP
#define BFS_HPP

#include <graphlib/common/IBaseGraph.hpp>
#include <graphlib/common/Repository.hpp>
#include <vector>

namespace graphlib::algorithms {

    struct BFSResult {
        std::vector<int> pai;
        std::vector<Cor> cor;
        std::vector<int> dist;
    };

    BFSResult bfs(const IBaseGraph& graph, int source);
}

#endif