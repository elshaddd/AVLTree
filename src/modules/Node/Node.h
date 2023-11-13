class Node
{
public:
    int key;

    Node *left;

    Node *right;

    int height;

    Node(int val, Node *left = nullptr, Node *right = nullptr);
};
