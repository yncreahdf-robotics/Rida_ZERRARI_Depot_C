#include <iostream>
#include <vector>

class Node {
public:
    int x, y;
    Node* up;
    Node* down;
    Node* left;
    Node* right;
    bool visited;

    Node(int x, int y) : x(x), y(y), up(nullptr), down(nullptr), left(nullptr), right(nullptr), visited(false) {}

    void printNode() {
        std::cout << "Node (" << x << ", " << y << ")\n";
        if (up) std::cout << "Up: (" << up->x << ", " << up->y << ")\n";
        if (down) std::cout << "Down: (" << down->x << ", " << down->y << ")\n";
        if (left) std::cout << "Left: (" << left->x << ", " << left->y << ")\n";
        if (right) std::cout << "Right: (" << right->x << ", " << right->y << ")\n";
    }
};

class Maze {
public:
    Maze(int rows, int cols) : rows_(rows), cols_(cols) {
        createMaze();
    }

    void createMaze() {
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

    Node& getNode(int x, int y) {
        return nodes_[y * cols_ + x];
    }

    void printMaze() {
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

    void printNode(int x, int y) {
        if (x >= 0 && x < cols_ && y >= 0 && y < rows_) {
            Node& node = getNode(x, y);
            node.printNode();
        } else {
            std::cout << "Invalid node coordinates.\n";
        }
    }

private:
    int rows_;
    int cols_;
    std::vector<Node> nodes_;
};

int main() {
    int rows = 10;
    int cols = 10;

    Maze maze(rows, cols);

    maze.printMaze();
    
    Node& startNode = maze.getNode(0, 0);
    Node& endNode = maze.getNode(cols - 1, rows - 1);
    maze.printNode(9,9);
//std::cout<<maze.getNode(5,5)<<std::endl;

    return 0;
}
