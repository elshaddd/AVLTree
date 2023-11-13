#include <gtest/gtest.h>
#include <algorithm>
#include <../modules/Random/Random.h>
#include <../modules/AVLTree/AVLTree.h>

TEST(AVLTreeTest, InsertAndInOrderTest) {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    std::vector<int> result = tree.inOrder();
    std::vector<int> expected = {10, 20, 30, 40, 50};
    ASSERT_EQ(result, expected);
}

TEST(AVLTreeTest, RemoveTest) {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    tree.remove(30);
    std::vector<int> result = tree.inOrder();
    std::vector<int> expected = {10, 20, 40, 50};
    ASSERT_EQ(result, expected);
}

TEST(AVLTreeTest, BalanceTest) {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    ASSERT_TRUE(tree.isBalanced());
}

TEST(AVLTreeTest, IsBalancedAfterInsertions) {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    ASSERT_TRUE(tree.isBalanced());
}

TEST(AVLTreeTest, IsBalancedAfterDeletions) {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    tree.remove(50);
    tree.remove(40);

    ASSERT_TRUE(tree.isBalanced());
}

TEST(AVLTreeTest, FindMin) {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    ASSERT_EQ(tree.findMin(), 10);
}

TEST(AVLTreeTest, RemoveMin) {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    tree.removeMin();

    std::vector<int> result = tree.inOrder();
    std::vector<int> expected = {20, 30, 40, 50};
    ASSERT_EQ(result, expected);
}

TEST(AVLTreeTest, EmptyTree) {
    AVLTree tree;
    ASSERT_TRUE(tree.isBalanced());
}

TEST(AVLTreeTest, RandomInsertAndInOrderTest) {
    AVLTree tree;
    std::vector<int> expected;
    for (int i = 0; i < 100; ++i) {
        int value = randomInRange(1, 1000);
        tree.insert(value);
        expected.push_back(value);
    }

    std::sort(expected.begin(), expected.end());
    std::vector<int> result = tree.inOrder();
    ASSERT_EQ(result, expected);
}

TEST(AVLTreeTest, RandomRemoveTest) {
    AVLTree tree;
    std::vector<int> values;
    for (int i = 0; i < 100; ++i) {
        int value = randomInRange(1, 1000);
        tree.insert(value);
        values.push_back(value);
    }

    // Удаляем случайное значение из дерева и вектора значений
    int indexToRemove = randomInRange(0, values.size() - 1);
    tree.remove(values[indexToRemove]);
    values.erase(values.begin() + indexToRemove);

    std::sort(values.begin(), values.end());
    std::vector<int> result = tree.inOrder();
    ASSERT_EQ(result, values);
}