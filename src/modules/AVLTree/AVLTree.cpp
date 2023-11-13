#include "AVLTree.h"

AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::height(Node *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

int AVLTree::getBalance(Node *node)
{
    if (node == nullptr)
        return 0;
    return height(node->right) - height(node->left);
}

void AVLTree::fixHeight(Node *node)
{
    unsigned char hl = height(node->left);
    unsigned char hr = height(node->right);
    node->height = (hl > hr ? hl : hr) + 1;
}

// void AVLTree::bigRotateLeft(Node *a)
// {
//     rotateRight(a->right);
//     rotateLeft(a);
// }

// void AVLTree::bigRotateRight(Node *a)
// {
//     rotateLeft(a->left);
//     rotateRight(a);
// }

Node *AVLTree::rotateLeft(Node *node)
{
    Node *nodeRight = node->right;
    node->right = nodeRight->left;
    nodeRight->left = node;

    fixHeight(node);
    fixHeight(nodeRight);

    return nodeRight;
}

Node *AVLTree::rotateRight(Node *node)
{
    Node *nodeLeft = node->left;
    node->left = nodeLeft->right;
    nodeLeft->right = node;

    fixHeight(node);
    fixHeight(nodeLeft);

    return nodeLeft;
}

Node *AVLTree::balance(Node *node)
{
    fixHeight(node);
    if (getBalance(node) == 2)
    {
        if (getBalance(node->right) < 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    if (getBalance(node) == -2)
    {
        if (getBalance(node->left) > 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    return node;
}

Node *AVLTree::insert(Node *node, int k)
{
    if (!node)
        return new Node(k);
    if (k < node->key)
        node->left = insert(node->left, k);
    else
        node->right = insert(node->right, k);
    return balance(node);
}

void AVLTree::insert(int k)
{
    root = insert(root, k);
}

Node *AVLTree::findMin(Node *node)
{
    return node->left ? findMin(node->left) : node;
}

Node *AVLTree::findMin()
{
    return root = findMin(root);
}

Node *AVLTree::removeMin(Node *node)
{
    if (!node->left)
        return node->right;
    node->left = removeMin(node->left);
    return balance(node);
}

void AVLTree::removeMin()
{
    root = removeMin(root);
}

Node *AVLTree::remove(Node *node, int k)
{
    if (!node)
        return nullptr;
    if (k < node->key)
        node->left = remove(node->left, k);
    else if (k > node->key)
        node->right = remove(node->right, k);
    else //  k == node->key
    {
        Node *nLeft = node->left;
        Node *nRight = node->right;
        delete node;
        if (!nRight)
            return nLeft;
        Node *min = findMin(nRight);
        min->right = removeMin(nRight);
        min->left = nLeft;
        return balance(min);
    }
    return balance(node);
}

void AVLTree::remove(int k)
{
    root = remove(root, k);
}

void AVLTree::inOrder(Node *node)
{
    if (node != nullptr)
    {
        inOrder(node->left);
        std::cout << node->key << " ";
        inOrder(node->right);
    }
}

void AVLTree::inOrder()
{
    inOrder(root);
    std::cout << std::endl;
}

std::vector<int> AVLTree::inOrderVec(Node *node)
{
    std::vector<int> res;
    if (node != nullptr)
    {
        std::vector<int> left = inOrderVec(node->left);
        res.insert(res.end(), left.begin(), left.end());
        res.push_back(node->key);
        std::vector<int> right = inOrderVec(node->right);
        res.insert(res.end(), right.begin(), right.end());
    }
    return res;
}

std::vector<int> AVLTree::inOrderVec()
{
    std::vector<int> res = inOrderVec(root);
    return res;
}

bool AVLTree::check(Node *node)
{
    if (node == nullptr)
        return true;

    int balance = getBalance(node);
    if (abs(balance) > 1)
        return false;

    return check(node->left) && check(node->right);
}

bool AVLTree::check()
{
    return check(root);
}