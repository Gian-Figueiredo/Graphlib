#ifndef CONNECTED_COMPONENTS_HPP
#define CONNECTED_COMPONENTS_HPP

#include <graphlib/graph/IGraph.hpp>
#include <vector>

namespace graphlib::algorithms {
    std::vector<std::vector<int>> connected_components(const IGraph& graph);
}

#endif