#include <iostream>
#include <vector>
#include "Maze.hpp"
#include "SearchAlgorithms.hpp"

int main() {
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 1, 1},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 1, 1},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 0}
    };

    std::pair<int, int> start = {0, 0};
    std::pair<int, int> goal = {9, 9};

    Maze maze(grid, start, goal);

    auto bfs_path = SearchAlgorithms::BFS(maze);
    auto dfs_path = SearchAlgorithms::DFS(maze);

    std::cout << "BFS Path:\n";
    maze.printPath(bfs_path);

    std::cout << "DFS Path:\n";
    maze.printPath(dfs_path);

    // std::string bfs_filename = "dataset/bfs_search.data";
    // maze.savePath(bfs_path, bfs_filename);

    return 0;
}