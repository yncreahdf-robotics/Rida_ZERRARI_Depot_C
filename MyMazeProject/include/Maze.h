#ifndef MAZE_H
#define MAZE_H

#include "Node.h"
#include <vector>
class Robot;
class Maze {
public:
    Maze(int rows, int cols);
    void createMaze();
    Node& getNode(int x, int y);
    int getCols() const;
    int getRows() const;
    std::vector<Node*> getNeighbors(const Node& node);
    std::vector<Node*> findPath(int startX, int startY, int endX, int endY);
    //void printMazeWithRobot(const Robot& robot);
    void printMazeWithRobot(int robotX, int robotY);
    void printMaze();
    void printNode(int x, int y);

private:
    int rows_;
    int cols_;
    std::vector<Node> nodes_;
};

#endif
