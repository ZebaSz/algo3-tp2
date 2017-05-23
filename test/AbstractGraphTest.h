#include <gtest/gtest.h>
#include "../src/graph.h"

class AbstractGraphTest : public ::testing::Test {
protected:
    edgeList conexGraph; // Grafo que aparece de ejemplo para Dijkstra en la teórica.
        // n = 6
    edgeList anotherConexGraph;
        // n = 8
    edgeList negativeConexGraph; // Grafo que aparece de ejemplo para Ford en la teórica. WARN: ARISTAS NEGATIVAS.
        // n = 6
    edgeList anotherNegativeConexGraph; // Grafo que aparece de ejemplo para Floyd en la teórica. WARN: ARISTAS NEGATIVAS
        // n = 4
    edgeList oneTree;
        // n = 12
    edgeList anotherTree;
        // n = 12
    edgeList treeForest;
        // n = 24
    edgeList relatedComponents;
        // n = 14

    virtual void SetUp() {
        conexGraph.push_back({0,1,4});
        conexGraph.push_back({1,2,3});
        conexGraph.push_back({2,3,1});
        conexGraph.push_back({4,3,4});
        conexGraph.push_back({5,4,3});
        conexGraph.push_back({0,5,3});
        conexGraph.push_back({1,4,1});
        conexGraph.push_back({0,2,7});

        anotherConexGraph.push_back({0,2,2});
        anotherConexGraph.push_back({1,2,1});
        anotherConexGraph.push_back({2,3,9});
        anotherConexGraph.push_back({4,3,3});
        anotherConexGraph.push_back({5,4,1});
        anotherConexGraph.push_back({0,5,5});
        anotherConexGraph.push_back({1,4,12});
        anotherConexGraph.push_back({1,6,9});
        anotherConexGraph.push_back({6,5,5});
        anotherConexGraph.push_back({5,7,1});
        anotherConexGraph.push_back({7,6,1});
        anotherConexGraph.push_back({3,7,7});

        negativeConexGraph.push_back({0,1,4});
        negativeConexGraph.push_back({1,2,3});
        negativeConexGraph.push_back({2,3,1});
        negativeConexGraph.push_back({4,3,4});
        negativeConexGraph.push_back({5,4,3});
        negativeConexGraph.push_back({0,5,3});
        negativeConexGraph.push_back({1,4,1});
        negativeConexGraph.push_back({0,2,7});
        negativeConexGraph.push_back({1,5,-2});

        anotherNegativeConexGraph.push_back({0,1,3});
        anotherNegativeConexGraph.push_back({1,0,2});
        anotherNegativeConexGraph.push_back({1,3,2});
        anotherNegativeConexGraph.push_back({3,1,4});
        anotherNegativeConexGraph.push_back({2,3,1});
        anotherNegativeConexGraph.push_back({3,2,4});
        anotherNegativeConexGraph.push_back({2,1,-2});
        anotherNegativeConexGraph.push_back({0,3,3});
        anotherNegativeConexGraph.push_back({1,2,2});

        oneTree.push_back({0,1,3});
        oneTree.push_back({0,2,5});
        oneTree.push_back({1,3,1});
        oneTree.push_back({1,4,6});
        oneTree.push_back({2,5,9});
        oneTree.push_back({2,6,7});
        oneTree.push_back({3,7,9});
        oneTree.push_back({4,8,3});
        oneTree.push_back({5,9,4});
        oneTree.push_back({5,10,5});
        oneTree.push_back({5,11,1});

        anotherTree.push_back({0,1,11});
        anotherTree.push_back({0,2,9});
        anotherTree.push_back({0,3,3});
        anotherTree.push_back({1,4,4});
        anotherTree.push_back({1,5,1});
        anotherTree.push_back({1,6,3});
        anotherTree.push_back({2,7,5});
        anotherTree.push_back({3,8,2});
        anotherTree.push_back({4,9,3});
        anotherTree.push_back({5,10,7});
        anotherTree.push_back({6,11,1});

        treeForest.push_back({0,1,3});
        treeForest.push_back({0,2,5});
        treeForest.push_back({1,3,1});
        treeForest.push_back({1,4,6});
        treeForest.push_back({2,5,9});
        treeForest.push_back({2,6,7});
        treeForest.push_back({3,7,9});
        treeForest.push_back({4,8,3});
        treeForest.push_back({5,9,4});
        treeForest.push_back({5,10,5});
        treeForest.push_back({5,11,1});

        anotherTree.push_back({12,13,11});
        anotherTree.push_back({12,14,9});
        anotherTree.push_back({12,15,3});
        anotherTree.push_back({13,16,4});
        anotherTree.push_back({13,17,1});
        anotherTree.push_back({13,18,3});
        anotherTree.push_back({14,19,5});
        anotherTree.push_back({15,20,2});
        anotherTree.push_back({16,21,3});
        anotherTree.push_back({17,22,7});
        anotherTree.push_back({18,23,1});

        relatedComponents.push_back({0,1,4});
        relatedComponents.push_back({1,2,3});
        relatedComponents.push_back({2,3,1});
        relatedComponents.push_back({4,3,4});
        relatedComponents.push_back({5,4,3});
        relatedComponents.push_back({0,5,3});
        relatedComponents.push_back({1,4,1});
        relatedComponents.push_back({0,2,7});

        relatedComponents.push_back({6,8,2});
        relatedComponents.push_back({7,8,1});
        relatedComponents.push_back({8,9,9});
        relatedComponents.push_back({10,9,3});
        relatedComponents.push_back({11,10,1});
        relatedComponents.push_back({6,11,5});
        relatedComponents.push_back({7,10,12});
        relatedComponents.push_back({7,12,9});
        relatedComponents.push_back({12,11,5});
        relatedComponents.push_back({11,13,1});
        relatedComponents.push_back({13,12,1});
        relatedComponents.push_back({9,13,7});
    }
};