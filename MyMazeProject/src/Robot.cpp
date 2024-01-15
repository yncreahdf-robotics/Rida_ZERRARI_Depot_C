#include "../include/Robot.h"
#include "../include/Maze.h"
#include <iostream>

Robot::Robot(Maze& maze, int startX, int startY) : maze_(maze), x_(startX), y_(startY) {}

bool Robot::moveTo(int x, int y) {
    if (x < 0 || x >= maze_.getCols() || y < 0 || y >= maze_.getRows())
        return false;  // Invalid coordinates.

    Node& current = maze_.getNode(x_, y_);
    Node& next = maze_.getNode(x, y);

    if ((current.right == &next && next.left == &current) ||
        (current.left == &next && next.right == &current) ||
        (current.up == &next && next.down == &current) ||
        (current.down == &next && next.up == &current)) {
        x_ = x;
        y_ = y;
        return true;
    }
    std::cout << "Current Node: (" << current.x << ", " << current.y << ")\n";
    std::cout << "Next Node: (" << next.x << ", " << next.y << ")\n";
    return false;  // Nodes are not connected.
}

int Robot::getX() const { return x_; }
int Robot::getY() const { return y_; }

void Robot::printLocation() {
        std::cout << "Robot is at Node (" << x_ << ", " << y_ << ")\n";
    }