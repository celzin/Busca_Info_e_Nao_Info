#include "Maze.hpp"
#include <iostream>

Maze::Maze(const std::vector<std::vector<int>>& grid, std::pair<int, int> start, std::pair<int, int> goal)
    : grid(grid), start(start), goal(goal) {}

bool Maze::isValid(int x, int y) const {
    return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 0;
}

bool Maze::isGoal(int x, int y) const {
    return x == goal.first && y == goal.second;
}

std::pair<int, int> Maze::getStart() const {
    return start;
}

std::pair<int, int> Maze::getGoal() const {
    return goal;
}

void Maze::printPath(const std::vector<std::pair<int, int>>& path) const {
    for (const auto& step : path) {
        std::cout << "(" << step.first << ", " << step.second << ") ";
    }
    std::cout << std::endl;
}
