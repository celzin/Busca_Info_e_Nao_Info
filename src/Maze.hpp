#ifndef MAZE_HPP
#define MAZE_HPP

#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <iostream>

class Maze {
public:
    Maze(const std::vector<std::vector<int>>& grid, std::pair<int, int> start, std::pair<int, int> goal);
    bool isValid(int x, int y) const;
    bool isGoal(int x, int y) const;
    std::pair<int, int> getStart() const;
    std::pair<int, int> getGoal() const;
    void printPath(const std::vector<std::pair<int, int>>& path) const;
    // void savePath(const std::vector<std::pair<int, int>>& path, const std::string& filename) const;

private:
    std::vector<std::vector<int>> grid;
    std::pair<int, int> start;
    std::pair<int, int> goal;
};

#endif // MAZE_HPP