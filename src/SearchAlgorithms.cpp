#include "SearchAlgorithms.hpp"
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_map>
#include <algorithm>

std::vector<std::pair<int, int>> reconstructPath(std::unordered_map<std::pair<int, int>, std::pair<int, int>, pair_hash> cameFrom, std::pair<int, int> current) {
    std::vector<std::pair<int, int>> path;
    while (cameFrom[current] != current) {
        path.push_back(current);
        current = cameFrom[current];
    }
    path.push_back(current);
    std::reverse(path.begin(), path.end());
    return path;
}

std::vector<std::pair<int, int>> SearchAlgorithms::BFS(const Maze& maze) {
    std::queue<std::pair<int, int>> frontier;
    std::unordered_map<std::pair<int, int>, std::pair<int, int>, pair_hash> cameFrom;

    std::pair<int, int> start = maze.getStart();
    std::pair<int, int> goal = maze.getGoal();
    
    frontier.push(start);
    cameFrom[start] = start;

    while (!frontier.empty()) {
        std::pair<int, int> current = frontier.front();
        frontier.pop();

        if (maze.isGoal(current.first, current.second)) {
            return reconstructPath(cameFrom, current);
        }

        std::vector<std::pair<int, int>> neighbors = {
            {current.first + 1, current.second},
            {current.first - 1, current.second},
            {current.first, current.second + 1},
            {current.first, current.second - 1}
        };

        for (auto& next : neighbors) {
            if (maze.isValid(next.first, next.second) && cameFrom.find(next) == cameFrom.end()) {
                frontier.push(next);
                cameFrom[next] = current;
            }
        }
    }

    return {};
}

// std::vector<std::pair<int, int>> SearchAlgorithms::DFS(const Maze& maze) {
//     // DFS implementation
// }

// std::vector<std::pair<int, int>> SearchAlgorithms::AStar(const Maze& maze) {
//     // A* implementation
// }

// std::vector<std::pair<int, int>> SearchAlgorithms::GreedyBestFirstSearch(const Maze& maze) {
//     // Greedy Best-First Search implementation
// }
