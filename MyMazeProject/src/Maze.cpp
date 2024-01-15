#include "../include/Maze.h"
#include "../include/Robot.h"
#include <algorithm>
#include <iostream>

Maze::Maze(int rows, int cols) : rows_(rows), cols_(cols) {
    createMaze();
}

void Maze::createMaze() {
    // Create nodes and connect them to form a grid.
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                nodes_.push_back(Node(j, i));
            }
        }

        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                Node& current = getNode(j, i);

                if (i > 0) {
                    current.up = &getNode(j, i - 1);
                }
                if (i < rows_ - 1) {
                    current.down = &getNode(j, i + 1);
                }
                if (j > 0) {
                    current.left = &getNode(j - 1, i);
                }
                if (j < cols_ - 1) {
                    current.right = &getNode(j + 1, i);
                }
            }
        }
    }


Node& Maze::getNode(int x, int y) {
    return nodes_[y * cols_ + x];
}

int Maze::getCols() const {
    return cols_;
}

int Maze::getRows() const {
    return rows_;
}

std::vector<Node*> Maze::getNeighbors(const Node& node) {
     std::vector<Node*> neighbors;

        if (node.up) {
            neighbors.push_back(node.up);
        }
        if (node.down) {
            neighbors.push_back(node.down);
        }
        if (node.left) {
            neighbors.push_back(node.left);
        }
        if (node.right) {
            neighbors.push_back(node.right);
        }

        return neighbors;
    }

std::vector<Node*> Maze::findPath(int startX, int startY, int endX, int endY) {
     Node& startNode = getNode(startX, startY);
    Node& endNode = getNode(endX, endY);

    std::vector<Node*> openSet;
    std::vector<Node*> closedSet;

    openSet.push_back(&startNode);

    while (!openSet.empty()) {
        // Find the element with the lowest f = g + h
        Node* current = openSet[0];
        for (Node* node : openSet) {
            if (node->g + node->h < current->g + current->h) {
                current = node;
            }
        }

        if (current == &endNode) {
            std::vector<Node*> path;
            Node* node = current;
            while (node) {
                path.push_back(node);
                node->path = true;
                node = node->parent;
            }
            return path;
        }

        // Remove current from the open set
        openSet.erase(std::remove(openSet.begin(), openSet.end(), current), openSet.end());
        closedSet.push_back(current);

        for (Node* neighbor : getNeighbors(*current)) {
            if (std::find(closedSet.begin(), closedSet.end(), neighbor) != closedSet.end()) {
                continue;
            }

            double tentativeGScore = current->g + 1;

            if (std::find(openSet.begin(), openSet.end(), neighbor) == openSet.end() || tentativeGScore < neighbor->g) {
                neighbor->parent = current;
                neighbor->g = tentativeGScore;
                neighbor->h = neighbor->calculateHeuristic(endNode);
                if (std::find(openSet.begin(), openSet.end(), neighbor) == openSet.end()) {
                    openSet.push_back(neighbor);
                }
            }
        }
    }

    return {};
}

void Maze::printMazeWithRobot(int robotX, int robotY) {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            Node& current = getNode(j, i);
            std::cout << "+";
            if (current.down == nullptr)
                std::cout << "---";
            else
                std::cout << "   ";
        }
        std::cout << "+" << std::endl;
        for (int j = 0; j < cols_; ++j) {
            Node& current = getNode(j, i);
            if (current.left == nullptr)
                std::cout << "|";
            else
                std::cout << " ";

            // Check if this is the robot's current position and print 'R' to represent the robot.
            if (j == robotX && i == robotY) {
                std::cout << " R ";
            } else {
                std::cout << "   ";
            }

            if (j == cols_ - 1)
                std::cout << "|";
        }
        std::cout << std::endl;
    }

    for (int j = 0; j < cols_; ++j) {
        std::cout << "+---";
    }
    std::cout << "+" << std::endl;
}
        
void Maze::printMaze() {
   for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                Node& current = getNode(j, i);
                std::cout << "+";
                if (current.down == nullptr)
                    std::cout << "---";
                else
                    std::cout << "   ";
            }
            std::cout << "+" << std::endl;
            for (int j = 0; j < cols_; ++j) {
                Node& current = getNode(j, i);
                if (current.left == nullptr)
                    std::cout << "|";
                else
                    std::cout << " ";
                std::cout << "   ";
                if (j == cols_ - 1)
                    std::cout << "|";
            }
            std::cout << std::endl;
        }

        for (int j = 0; j < cols_; ++j) {
            std::cout << "+---";
        }
        std::cout << "+" << std::endl;
    }


void Maze::printNode(int x, int y) {
     if (x >= 0 && x < cols_ && y >= 0 && y < rows_) {
            Node& node = getNode(x, y);
            node.printNode();
        } else {
            std::cout << "Invalid node coordinates.\n";
        }
    }

