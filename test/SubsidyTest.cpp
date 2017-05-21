#include <gtest/gtest.h>
#include "../src/graph.h"
#include "../src/subsidy.h"

class SubsidyTest : public ::testing::Test {
protected:
    edgeList edges;
};

TEST_F(SubsidyTest, testCarlos) {
    edges.push_back({2,0,20});
    edges.push_back({0,1,6});
    edges.push_back({1,3,8});
    edges.push_back({3,2,-3}); // FIXME: este test esta mal, no se admiten pesos negativos
    edges.push_back({0,3,7});


    ASSERT_EQ(binarySearchTax(4, 5, edges), 7);
}

TEST_F(SubsidyTest, equalWeightEdges) {
    edges.push_back({2,0,20});
    edges.push_back({0,1,20});
    edges.push_back({1,3,20});
    edges.push_back({3,2,20});
    edges.push_back({0,3,20});

    ASSERT_EQ(binarySearchTax(4, 5, edges), 20);
}


// FIXME: cual es el objetivo de este test? por que no son dos?
TEST_F(SubsidyTest, twoComps) {
    edges.push_back({2,0,20});
    edges.push_back({0,1,20});
    edges.push_back({1,3,20});
    edges.push_back({3,2,20});
    edges.push_back({0,3,20});
    edges.push_back({7,5,20});
    edges.push_back({5,6,6});
    edges.push_back({6,8,8});
    edges.push_back({8,7,-3}); // FIXME: este test esta mal, no se admiten pesos negativos
    edges.push_back({5,8,7});
    ASSERT_EQ(binarySearchTax(9, 10, edges), 7);

    edges.clear();

    edges.push_back({2,0,5});
    edges.push_back({0,1,5});
    edges.push_back({1,3,5});
    edges.push_back({3,2,5});
    edges.push_back({0,3,5});
    edges.push_back({7,5,20});
    edges.push_back({5,6,6});
    edges.push_back({6,8,8});
    edges.push_back({8,7,-3}); // FIXME: este test esta mal, no se admiten pesos negativos
    edges.push_back({5,8,7});
    ASSERT_EQ(binarySearchTax(9, 10, edges), 5);
 }