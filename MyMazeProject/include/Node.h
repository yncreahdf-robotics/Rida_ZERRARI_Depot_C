#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
public:
    int x, y;
    Node* up;
    Node* down;
    Node* left;
    Node* right;
    bool visited;
    bool path;
    double g;  // Cost from the start node to this node
    double h;  // Heuristic (estimated cost to the end node)
    Node* parent;

    Node(int x, int y);
    void printNode();
    double calculateHeuristic(const Node& endNode);

    struct CompareNodes {
        bool operator()(Node* a, Node* b);
    };
};

#endif