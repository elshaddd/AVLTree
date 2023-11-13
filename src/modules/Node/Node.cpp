#include "Node.h"
Node::Node(int val, Node *left = nullptr, Node *right = nullptr) : key(val), left(left), right(right), height(1) {}