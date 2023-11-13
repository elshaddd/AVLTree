#include "../node/Node.h"
#include <vector>
#include <iostream>

class AVLTree
{
    Node *root;

    void inOrder(Node *node);

    std::vector<int> inOrderVec(Node *node);

    bool check(Node *node);

public:
    AVLTree();

    int height(Node *node);

    int getBalance(Node *node);

    void fixHeight(Node *node);

    // void bigRotateLeft(Node *a)
    // {
    //     rotateRight(a->right);
    //     rotateLeft(a);
    // }

    // void bigRotateRight(Node *a)
    // {
    //     rotateLeft(a->left);
    //     rotateRight(a);
    // }

    Node *rotateLeft(Node *node);

    Node *rotateRight(Node *node);

    Node *balance(Node *node);

    Node *insert(Node *node, int k);

    void insert(int k);

    Node *findMin(Node *node);

    Node *removeMin(Node *node);

    Node *remove(Node *node, int k);

    void inOrder();

    std::vector<int> inOrderVec();

    bool check();
};