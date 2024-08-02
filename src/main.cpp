#include <iostream>
#include <vector>
#include <chrono>
#include <utility>
#include "Maze.hpp"
#include "SearchAlgorithms.hpp"

void measurePerformance(const Maze& maze) {
    // BFS
    auto start = std::chrono::high_resolution_clock::now();
    auto bfs_path = SearchAlgorithms::BFS(maze);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> bfs_duration = end - start;
    std::cout << "BFS Path:\n";
    maze.printPath(bfs_path);
    std::cout << "BFS Execution Time: " << bfs_duration.count() << " seconds\n";
    std::cout << "BFS Memory Usage: " << sizeof(bfs_path) + (bfs_path.capacity() * sizeof(std::pair<int, int>)) << " bytes\n";
    std::cout << "BFS Path Length: " << bfs_path.size() << "\n";
    std::cout << "BFS Completeness: " << (bfs_path.empty() ? "No" : "Yes") << "\n";
    std::cout << "BFS Optimality: " << (bfs_path.size() - 1) << "\n"; // Path length minus start point

    // DFS
    start = std::chrono::high_resolution_clock::now();
    auto dfs_path = SearchAlgorithms::DFS(maze);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> dfs_duration = end - start;
    std::cout << "DFS Path:\n";
    maze.printPath(dfs_path);
    std::cout << "DFS Execution Time: " << dfs_duration.count() << " seconds\n";
    std::cout << "DFS Memory Usage: " << sizeof(dfs_path) + (dfs_path.capacity() * sizeof(std::pair<int, int>)) << " bytes\n";
    std::cout << "DFS Path Length: " << dfs_path.size() << "\n";
    std::cout << "DFS Completeness: " << (dfs_path.empty() ? "No" : "Yes") << "\n";
    std::cout << "DFS Optimality: " << (dfs_path.size() - 1) << "\n"; // Path length minus start point

    // A*
    start = std::chrono::high_resolution_clock::now();
    auto astar_path = SearchAlgorithms::AStar(maze);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> astar_duration = end - start;
    std::cout << "A* Path:\n";
    maze.printPath(astar_path);
    std::cout << "A* Execution Time: " << astar_duration.count() << " seconds\n";
    std::cout << "A* Memory Usage: " << sizeof(astar_path) + (astar_path.capacity() * sizeof(std::pair<int, int>)) << " bytes\n";
    std::cout << "A* Path Length: " << astar_path.size() << "\n";
    std::cout << "A* Completeness: " << (astar_path.empty() ? "No" : "Yes") << "\n";
    std::cout << "A* Optimality: " << (astar_path.size() - 1) << "\n"; // Path length minus start point

    // Greedy Best-First Search
    start = std::chrono::high_resolution_clock::now();
    auto greedy_path = SearchAlgorithms::GreedyBestFirstSearch(maze);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> greedy_duration = end - start;
    std::cout << "Greedy Best-First Search Path:\n";
    maze.printPath(greedy_path);
    std::cout << "Greedy Best-First Search Execution Time: " << greedy_duration.count() << " seconds\n";
    std::cout << "Greedy Best-First Search Memory Usage: " << sizeof(greedy_path) + (greedy_path.capacity() * sizeof(std::pair<int, int>)) << " bytes\n";
    std::cout << "Greedy Best-First Search Path Length: " << greedy_path.size() << "\n";
    std::cout << "Greedy Best-First Search Completeness: " << (greedy_path.empty() ? "No" : "Yes") << "\n";
    std::cout << "Greedy Best-First Search Optimality: " << (greedy_path.size() - 1) << "\n"; // Path length minus start point
}

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

    measurePerformance(maze);

    return 0;
}