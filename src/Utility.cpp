#include "include/Utility.hpp"
#include "include/SearchAlgorithms.hpp"
#include <iostream>
#include <chrono>

void measurePerformance(const Maze& maze) {
    // BFS
    auto start = std::chrono::high_resolution_clock::now();
    auto bfs_path = SearchAlgorithms::BFS(maze);
    auto end = std::chrono::high_resolution_clock::now();
    auto bfs_duration = std::chrono::duration<double, std::milli>(end - start);
    std::cout << "\nBFS Path:\n";
    maze.printPath(bfs_path);
    std::cout << "\nBFS Execution Time: " << bfs_duration.count() << " ms\n";
    std::cout << "BFS Memory Usage: " << sizeof(bfs_path) + (bfs_path.capacity() * sizeof(std::pair<int, int>)) << " bytes\n";
    std::cout << "BFS Path Length: " << bfs_path.size() << "\n";
    std::cout << "BFS Completeness: " << (bfs_path.empty() ? "No" : "Yes") << "\n";
    std::cout << "BFS Optimality: " << (bfs_path.size() - 1) << "\n\n"; // Path length minus start point

    // DFS
    start = std::chrono::high_resolution_clock::now();
    auto dfs_path = SearchAlgorithms::DFS(maze);
    end = std::chrono::high_resolution_clock::now();
    auto dfs_duration = std::chrono::duration<double, std::milli>(end - start);
    std::cout << "\nDFS Path:\n";
    maze.printPath(dfs_path);
    std::cout << "\nDFS Execution Time: " << dfs_duration.count() << " ms\n";
    std::cout << "DFS Memory Usage: " << sizeof(dfs_path) + (dfs_path.capacity() * sizeof(std::pair<int, int>)) << " bytes\n";
    std::cout << "DFS Path Length: " << dfs_path.size() << "\n";
    std::cout << "DFS Completeness: " << (dfs_path.empty() ? "No" : "Yes") << "\n";
    std::cout << "DFS Optimality: " << (dfs_path.size() - 1) << "\n\n"; // Path length minus start point

    // A*
    start = std::chrono::high_resolution_clock::now();
    auto astar_path = SearchAlgorithms::AStar(maze);
    end = std::chrono::high_resolution_clock::now();
    auto astar_duration = std::chrono::duration<double, std::milli>(end - start);
    std::cout << "\nA* Path:\n";
    maze.printPath(astar_path);
    std::cout << "\nA* Execution Time: " << astar_duration.count() << " ms\n";
    std::cout << "A* Memory Usage: " << sizeof(astar_path) + (astar_path.capacity() * sizeof(std::pair<int, int>)) << " bytes\n";
    std::cout << "A* Path Length: " << astar_path.size() << "\n";
    std::cout << "A* Completeness: " << (astar_path.empty() ? "No" : "Yes") << "\n";
    std::cout << "A* Optimality: " << (astar_path.size() - 1) << "\n\n"; // Path length minus start point

    // Greedy Best-First Search
    start = std::chrono::high_resolution_clock::now();
    auto greedy_path = SearchAlgorithms::GreedyBestFirstSearch(maze);
    end = std::chrono::high_resolution_clock::now();
    auto greedy_duration = std::chrono::duration<double, std::milli>(end - start);
    std::cout << "\nGreedy Best-First Search Path:\n";
    maze.printPath(greedy_path);
    std::cout << "\nGBFS Execution Time: " << greedy_duration.count() << " ms\n";
    std::cout << "GBFS Memory Usage: " << sizeof(greedy_path) + (greedy_path.capacity() * sizeof(std::pair<int, int>)) << " bytes\n";
    std::cout << "GBFS Path Length: " << greedy_path.size() << "\n";
    std::cout << "GBFS Completeness: " << (greedy_path.empty() ? "No" : "Yes") << "\n";
    std::cout << "GBFS Optimality: " << (greedy_path.size() - 1) << "\n\n"; // Path length minus start point
}