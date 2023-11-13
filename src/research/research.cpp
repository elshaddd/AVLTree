#include <chrono>
#include <iostream>
#include "../modules/AVLTree/AVLTree.h"
#include <../modules/Random/Random.h>

void benchmarkInsert(AVLTree& tree, int numInsertions) {
    std::vector<int> values;
    for (int i = 0; i < numInsertions; ++i) {
        values.push_back(randomInRange(1, 1000));
    }

    auto start = std::chrono::high_resolution_clock::now();
    for (auto value : values) {
        tree.insert(value);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    std::cout << "Time to insert " << numInsertions << " elements: " << diff.count() << " s\n";
}

int main() {
    AVLTree tree;
    benchmarkInsert(tree, 10000);   // Измеряем время вставки 10000 элементов
    benchmarkInsert(tree, 100000);  // Измеряем время вставки 100000 элементов
    benchmarkInsert(tree, 1000000); // Измеряем время вставки 1000000 элементов
}