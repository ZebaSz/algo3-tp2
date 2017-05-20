#include <gtest/gtest.h>
#include "../src/graph.h"
#include "../src/subsidy.h"

class SubsidyTest : public ::testing::Test {
protected:
    edge* edges;

    virtual void SetUp() {
        edges = NULL;
    }

    virtual void TearDown() {
        if(edges != NULL) {
            delete[] edges;
        }
    }
};

TEST_F(SubsidyTest, testCarlos) {
    edges = new edge[5];
    edges[0] = {2,0,20};
    edges[1] = {0,1,6};
    edges[2] = {1,3,8};
    edges[3] = {3,2,-3};
    edges[4] = {0,3,7};


    ASSERT_EQ(binarySearchTax(4, 5, edges),7);


}

TEST_F(SubsidyTest, equalWeightEdges) {
    edges = new edge[5];
    edges[0] = {2,0,20};
    edges[1] = {0,1,20};
    edges[2] = {1,3,20};
    edges[3] = {3,2,20};
    edges[4] = {0,3,20};

    ASSERT_EQ(binarySearchTax(4, 5, edges), 20);
}