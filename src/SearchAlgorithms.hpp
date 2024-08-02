#ifndef SEARCH_ALGORITHMS_HPP
#define SEARCH_ALGORITHMS_HPP

#include "Maze.hpp"
#include <vector>
#include <utility>

namespace SearchAlgorithms {
    std::vector<std::pair<int, int>> BFS(const Maze& maze);
    std::vector<std::pair<int, int>> DFS(const Maze& maze);
    std::vector<std::pair<int, int>> AStar(const Maze& maze);
    std::vector<std::pair<int, int>> GreedyBestFirstSearch(const Maze& maze);
}

#endif // SEARCH_ALGORITHMS_HPP
