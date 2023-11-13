#include <chrono>
#include <iostream>
#include "../modules/AVLTree/AVLTree.h"
#include "../modules/Random/Random.h"

void benchmarkInsert(AVLTree &tree, int numInsertions)
{
    std::vector<int> values;
    for (int i = 0; i < numInsertions; ++i)
    {
        values.push_back(randomInRange(1, 1000));
    }

    auto start = std::chrono::high_resolution_clock::now();
    for (auto value : values)
    {
        tree.insert(value);
    }

    auto diff = std::chrono::high_resolution_clock::now() - start;

    std::cout << "Time to insert " << numInsertions << " elements: " << std::chrono::duration_cast<std::chrono::microseconds>(diff).count() << " mcs\n";
    std::cout << "Time to insert " << numInsertions << " elements: " << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count() << " ms\n";
    // std::cout << "Time to insert " << numInsertions << " elements: " << std::chrono::duration_cast<std::chrono::seconds>(diff).count() << " s\n\n";
}

int main()
{
    AVLTree tree;
    benchmarkInsert(tree, 1000);
    benchmarkInsert(tree, 10000);
    benchmarkInsert(tree, 100000);
    benchmarkInsert(tree, 1000000);
    benchmarkInsert(tree, 10000000);
}