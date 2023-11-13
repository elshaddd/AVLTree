#include "Node.h"

Node::Node(int val, Node *left, Node *right) : key(val), left(left), right(right), height(1) {}