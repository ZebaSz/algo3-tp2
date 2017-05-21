#include <gtest/gtest.h>
#include "../src/graph.h"

class AbstractGraphTest : public ::testing::Test {
protected:
    edgeList firstGraph; // Grafo que aparece de ejemplo para Dijkstra en la teórica.
        // n = 6
    edgeList secondGraph; // Grafo que aparece de ejemplo para Ford en la teórica. WARN: ARISTAS NEGATIVAS.
        // n = 6
    edgeList thirdGraph; // Grafo que aparece de ejemplo para Floyd en la teórica. WARN: ARISTAS NEGATIVAS
        // n = 4

    virtual void SetUp() {
        firstGraph.push_back({0,1,4});
        firstGraph.push_back({1,2,3});
        firstGraph.push_back({2,3,1});
        firstGraph.push_back({4,3,4});
        firstGraph.push_back({5,4,3});
        firstGraph.push_back({0,5,3});
        firstGraph.push_back({1,4,1});
        firstGraph.push_back({0,2,7});

        secondGraph.push_back({0,1,4});
        secondGraph.push_back({1,2,3});
        secondGraph.push_back({2,3,1});
        secondGraph.push_back({4,3,4});
        secondGraph.push_back({5,4,3});
        secondGraph.push_back({0,5,3});
        secondGraph.push_back({1,4,1});
        secondGraph.push_back({0,2,7});
        secondGraph.push_back({1,5,-2});

        thirdGraph.push_back({0,1,3});
        thirdGraph.push_back({1,0,2});
        thirdGraph.push_back({1,3,2});
        thirdGraph.push_back({3,1,4});
        thirdGraph.push_back({2,3,1});
        thirdGraph.push_back({3,2,4});
        thirdGraph.push_back({2,1,-2});
        thirdGraph.push_back({0,3,3});
        thirdGraph.push_back({1,2,2});
    }
};