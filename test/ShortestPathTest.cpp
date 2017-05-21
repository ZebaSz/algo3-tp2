#include <gtest/gtest.h>
#include "../src/graph.h"
#include "../src/shortest.h"

class ShortestPathTest : public ::testing::Test {
protected:
    edgeList edges;
};

TEST_F(ShortestPathTest, dijkstra) {
    edges.push_back({2,0,20});
    edges.push_back({0,1,6});
    edges.push_back({1,3,8});
    edges.push_back({3,2,3});
    edges.push_back({0,3,7});

    int distance[4];

    dijkstra(3, 4, distance, edges, false);

    ASSERT_EQ(distance[0], 7);

    dijkstra(3, 4, distance, edges, true);

    ASSERT_EQ(distance[0], 23);
}

TEST_F(ShortestPathTest, bellmanFord) {
    edges.push_back({2,0,20});
    edges.push_back({0,1,6});
    edges.push_back({1,3,8});
    edges.push_back({3,2,-3});
    edges.push_back({0,3,7});

    int distance[4];

    bellmanFord(1, 4, distance, edges);

    ASSERT_EQ(distance[2], 5);
}