#include <gtest/gtest.h>
#include <algorithm>
#include <../modules/Random/Random.h>
#include <../modules/AVLTree/AVLTree.h>

TEST(AVLTreeTest, InsertTest)
{
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    std::vector<int> result = tree.inOrderVec();
    std::vector<int> expected = {10, 20, 30, 40, 50};
    ASSERT_EQ(result, expected);
}

TEST(AVLTreeTest, RemoveTest)
{
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    tree.remove(30);
    std::vector<int> result = tree.inOrderVec();
    std::vector<int> expected = {10, 20, 40, 50};
    ASSERT_EQ(result, expected);
}

TEST(AVLTreeTest, BalanceTest)
{
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    ASSERT_TRUE(tree.check());
}

TEST(AVLTreeTest, IsBalancedAfterInsertionsTest)
{
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    ASSERT_TRUE(tree.check());
}

TEST(AVLTreeTest, IsBalancedAfterDeletionsTest)
{
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    tree.remove(50);
    tree.remove(40);

    ASSERT_TRUE(tree.check());
}

TEST(AVLTreeTest, FindMinTest)
{
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    ASSERT_EQ(tree.findMin()->key, 10);
}

TEST(AVLTreeTest, RemoveMinTest)
{
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    tree.removeMin();

    std::vector<int> result = tree.inOrderVec();
    std::vector<int> expected = {20, 30, 40, 50};
    ASSERT_EQ(result, expected);
}

TEST(AVLTreeTest, EmptyTreeTest)
{
    AVLTree tree;
    ASSERT_TRUE(tree.check());
}

TEST(AVLTreeTest, RandomInsertTest)
{
    AVLTree tree;
    std::vector<int> expected;
    for (int i = 0; i < 1000; ++i)
    {
        int value = randomInRange(1, 1000);
        tree.insert(value);
        expected.push_back(value);
    }

    std::sort(expected.begin(), expected.end());
    std::vector<int> result = tree.inOrderVec();
    ASSERT_EQ(result, expected);
}

TEST(AVLTreeTest, RandomRemoveTest)
{
    AVLTree tree;
    std::vector<int> values;
    for (int i = 0; i < 1000; ++i)
    {
        int value = randomInRange(1, 1000);
        tree.insert(value);
        values.push_back(value);
    }

    int indexToRemove;
    indexToRemove = randomInRange(0, values.size() - 1);
    tree.remove(values[indexToRemove]);
    values.erase(values.begin() + indexToRemove);
    indexToRemove = randomInRange(0, values.size() - 1);
    tree.remove(values[indexToRemove]);
    values.erase(values.begin() + indexToRemove);
    indexToRemove = randomInRange(0, values.size() - 1);
    tree.remove(values[indexToRemove]);
    values.erase(values.begin() + indexToRemove);

    std::sort(values.begin(), values.end());
    std::vector<int> result = tree.inOrderVec();
    ASSERT_EQ(result, values);
}

TEST(AVLTreeTest, RandomFindMinTest)
{
    AVLTree tree;
    std::vector<int> values;
    for (int i = 0; i < 1000; ++i)
    {
        int value = randomInRange(1, 1000);
        tree.insert(value);
        values.push_back(value);
    }

    std::sort(values.begin(), values.end());
    std::vector<int> result = tree.inOrderVec();
    int min = values[0];

    ASSERT_EQ(tree.findMin()->key, min);
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}