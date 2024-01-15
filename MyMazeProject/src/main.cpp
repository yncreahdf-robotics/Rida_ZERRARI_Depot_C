#include "../include/Maze.h"
#include "../include/Robot.h"
#include <iostream>

int main() {
    int rows = 10;
    int cols = 10;

    Maze maze(rows, cols);

    Node& startNode = maze.getNode(0, 0);
    Node& endNode = maze.getNode(cols - 1, rows - 1);

    Robot robot(maze, 0, 0);

    while (true) {
        int robotX = robot.getX();
        int robotY = robot.getY();

        maze.printMazeWithRobot(robotX, robotY); // Pass robot's X and Y coordinates
        robot.printLocation();

        int destinationX, destinationY;
        std::cout << "Enter the X and Y coordinates for the destination node (e.g., 4 4): ";
        std::cin >> destinationX >> destinationY;

        std::vector<Node*> path = maze.findPath(robotX, robotY, destinationX, destinationY);

        if (!path.empty()) {
            std::cout << "Path found!\n";

            for (Node* node : path) {
                std::cout << "Moving to (" << node->x << ", " << node->y << ")\n";
                robot.moveTo(node->x, node->y);
            }
        } else {
            std::cout << "No path found.\n";
        }
    }

    return 0;
}
