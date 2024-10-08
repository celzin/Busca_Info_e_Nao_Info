#include "include/SearchAlgorithms.hpp"

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


std::vector<std::pair<int, int>> SearchAlgorithms::DFS(const Maze& maze) {
    std::stack<std::pair<int, int>> frontier;
    std::unordered_map<std::pair<int, int>, std::pair<int, int>, pair_hash> cameFrom;

    std::pair<int, int> start = maze.getStart();
    std::pair<int, int> goal = maze.getGoal();

    frontier.push(start);
    cameFrom[start] = start;

    while (!frontier.empty()) {
        std::pair<int, int> current = frontier.top();
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

struct AStarNode {
    std::pair<int, int> position;
    int g_cost; 
    int f_cost; 

    bool operator>(const AStarNode& other) const {
        return f_cost > other.f_cost;
    }
};

int heuristic(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return std::abs(a.first - b.first) + std::abs(a.second - b.second);
}

std::vector<std::pair<int, int>> SearchAlgorithms::AStar(const Maze& maze) {
    std::priority_queue<AStarNode, std::vector<AStarNode>, std::greater<AStarNode>> frontier;
    std::unordered_map<std::pair<int, int>, std::pair<int, int>, pair_hash> cameFrom;
    std::unordered_map<std::pair<int, int>, int, pair_hash> g_cost;

    std::pair<int, int> start = maze.getStart();
    std::pair<int, int> goal = maze.getGoal();

    frontier.push({start, 0, heuristic(start, goal)});
    cameFrom[start] = start;
    g_cost[start] = 0;

    while (!frontier.empty()) {
        AStarNode current = frontier.top();
        frontier.pop();

        if (maze.isGoal(current.position.first, current.position.second)) {
            return reconstructPath(cameFrom, current.position);
        }

        std::vector<std::pair<int, int>> neighbors = {
            {current.position.first + 1, current.position.second},
            {current.position.first - 1, current.position.second}, 
            {current.position.first, current.position.second + 1}, 
            {current.position.first, current.position.second - 1} 
        };

        for (auto& next : neighbors) {
            if (maze.isValid(next.first, next.second)) {
                int new_cost = g_cost[current.position] + 1;
                if (g_cost.find(next) == g_cost.end() || new_cost < g_cost[next]) {
                    g_cost[next] = new_cost;
                    int f_cost = new_cost + heuristic(next, goal);
                    frontier.push({next, new_cost, f_cost});
                    cameFrom[next] = current.position;
                }
            }
        }
    }

    return {};
}

struct GreedyNode {
    std::pair<int, int> position;
    int h_cost; 

    bool operator>(const GreedyNode& other) const {
        return h_cost > other.h_cost;
    }
};

std::vector<std::pair<int, int>> SearchAlgorithms::GreedyBestFirstSearch(const Maze& maze) {
    std::priority_queue<GreedyNode, std::vector<GreedyNode>, std::greater<GreedyNode>> frontier;
    std::unordered_map<std::pair<int, int>, std::pair<int, int>, pair_hash> cameFrom;

    std::pair<int, int> start = maze.getStart();
    std::pair<int, int> goal = maze.getGoal();

    frontier.push({start, heuristic(start, goal)});
    cameFrom[start] = start;

    while (!frontier.empty()) {
        GreedyNode current = frontier.top();
        frontier.pop();

        if (maze.isGoal(current.position.first, current.position.second)) {
            return reconstructPath(cameFrom, current.position);
        }

        std::vector<std::pair<int, int>> neighbors = {
            {current.position.first + 1, current.position.second},
            {current.position.first - 1, current.position.second}, 
            {current.position.first, current.position.second + 1}, 
            {current.position.first, current.position.second - 1}  
        };

        for (auto& next : neighbors) {
            if (maze.isValid(next.first, next.second) && cameFrom.find(next) == cameFrom.end()) {
                frontier.push({next, heuristic(next, goal)});
                cameFrom[next] = current.position;
            }
        }
    }

    return {};
}