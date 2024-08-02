#include <iostream>
#include <vector>
#include "Maze.hpp"
#include "SearchAlgorithms.hpp"

int main() {
    std::vector<std::vector<int>> grid = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 1, 0}
    };

    std::pair<int, int> start = {0, 0};
    std::pair<int, int> goal = {9, 9};

    Maze maze(grid, start, goal);

    auto bfs_path = SearchAlgorithms::BFS(maze);

    std::cout << "BFS Path: ";
    maze.printPath(bfs_path);

    return 0;
}
