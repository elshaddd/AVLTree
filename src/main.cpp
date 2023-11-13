#include "modules/AVLTree/AVLTree.h"

int main()
{
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.inOrder();
    std::cout << tree.check();
}
