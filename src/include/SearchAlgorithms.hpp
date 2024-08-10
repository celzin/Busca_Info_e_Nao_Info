#ifndef SEARCH_ALGORITHMS_HPP
#define SEARCH_ALGORITHMS_HPP

#include "Maze.hpp"
#include <vector>
#include <utility>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <algorithm>

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2> &pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);
        return hash1 ^ hash2;
    }
};

std::vector<std::pair<int, int>> reconstructPath(std::unordered_map<std::pair<int, int>, std::pair<int, int>, pair_hash> cameFrom, std::pair<int, int> current);

namespace SearchAlgorithms {
    std::vector<std::pair<int, int>> BFS(const Maze& maze);
    std::vector<std::pair<int, int>> DFS(const Maze& maze);
    std::vector<std::pair<int, int>> AStar(const Maze& maze);
    std::vector<std::pair<int, int>> GreedyBestFirstSearch(const Maze& maze);
}

#endif
