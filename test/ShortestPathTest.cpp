#include <gtest/gtest.h>
#include "../src/graph.h"
#include "../src/shortest.h"
#include "../data/grafGen.h"

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
    edges.push_back({3,2,3});
    edges.push_back({0,3,7});

    int distance[4];

    bellmanFord(3, 4, distance, edges);

    ASSERT_EQ(distance[0], 23);

}

TEST_F(ShortestPathTest, coincidence) {
    int n = 10;
    int m = 45;
    genConex(n, m, edges, 40);

    int* dijDist = new int[n];
    int* bellDist = new int[n];
    for (int i = 0; i < n; ++i) { //check every possible source
        dijkstra(i, n, dijDist, edges, true);
        bellmanFord(i, n, bellDist, edges);
        for (int j = 0; j < n; ++j) { //check every possible destiny
            ASSERT_EQ(dijDist[j], bellDist[j]);
        }
    }
    delete[] dijDist;
    delete[] bellDist;
}

TEST_F(ShortestPathTest, notStronglyConex) {
    edges.push_back({0,1,-1});
    edges.push_back({1,2,-1});
    edges.push_back({2,0,-1});
    edges.push_back({2,3,1});
    edges.push_back({3,4,1});
    edges.push_back({4,5,1});
    edges.push_back({5,3,1});

    int distance[6];



    ASSERT_TRUE(bellmanFord(5, 6, distance, edges));

}