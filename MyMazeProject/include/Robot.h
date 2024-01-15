#ifndef ROBOT_H
#define ROBOT_H

#include "Maze.h"

class Robot {
public:
    Robot(Maze& maze, int startX, int startY);
    bool moveTo(int x, int y);
    void printLocation();
    int getX() const;
    int getY() const;

private:
    Maze& maze_;
    int x_;
    int y_;
};

#endif