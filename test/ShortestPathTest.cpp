#include <gtest/gtest.h>
#include "../src/graph.h"
#include "../src/shortest.h"

class ShortestPathTest : public ::testing::Test {
protected:

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

TEST_F(ShortestPathTest, dijkstra) {
    edge edges[5];
    edges[0] = {2,0,20};
    edges[1] = {0,1,6};
    edges[2] = {1,3,8};
    edges[3] = {3,2,3};
    edges[4] = {0,3,7};

    int distance[4];

    dijkstra(3, 4, 5, distance, edges, false);

    ASSERT_EQ(distance[0], 7);

    dijkstra(3, 4, 5, distance, edges, true);

    ASSERT_EQ(distance[0], 23);
}

TEST_F(ShortestPathTest, bellmanFord) {
    edge edges[5];
    edges[0] = {2,0,20};
    edges[1] = {0,1,6};
    edges[2] = {1,3,8};
    edges[3] = {3,2,-3};
    edges[4] = {0,3,7};

    int distance[4];

    bellmanFord(1, 4, 5, distance, edges);

    ASSERT_EQ(distance[2], 5);
}