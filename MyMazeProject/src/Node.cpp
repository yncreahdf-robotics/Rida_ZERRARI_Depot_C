#include "../include/Node.h"
#include <cmath>

Node::Node(int x, int y) : x(x), y(y), up(nullptr), down(nullptr), left(nullptr), right(nullptr), visited(false), path(false), g(0), h(0), parent(nullptr) {}

void Node::printNode() {
    std::cout << "Node (" << x << ", " << y << ")\n";
        if (up) std::cout << "Up: (" << up->x << ", " << up->y << ")\n";
        if (down) std::cout << "Down: (" << down->x << ", " << down->y << ")\n";
        if (left) std::cout << "Left: (" << left->x << ", " << left->y << ")\n";
        if (right) std::cout << "Right: (" << right->x << ", " << right->y << ")\n";
}

double Node::calculateHeuristic(const Node& endNode) {
    return std::abs(endNode.x - x) + std::abs(endNode.y - y);
}

bool Node::CompareNodes::operator()(Node* a, Node* b) {
    return (a->g + a->h) > (b->g + b->h);
}