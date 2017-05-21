#include <gtest/gtest.h>
#include "../src/graph.h"
#include "../src/spanning.h"

class KruskalTest : public ::testing::Test {
protected:
    int p;
    int n;
    edgeList edges;
};

TEST_F(KruskalTest, treeSize) {
    edges.push_back({0,1,6});
    edges.push_back({0,2,7});
    edges.push_back({0,3,8});
    edges.push_back({1,2,9});
    edges.push_back({1,3,10});
    edges.push_back({2,3,11});

    n = 4;
    ASSERT_EQ(kruskal(n, p, edges).size(), (size_t)n-1);
}

TEST_F(KruskalTest, k4Ordered) {
    edges.push_back({0,1,6});
    edges.push_back({0,2,7});
    edges.push_back({0,3,8});
    edges.push_back({1,2,9});
    edges.push_back({1,3,10});
    edges.push_back({2,3,11});

    std::set<edge> expected;
    expected.insert(edges[0]);
    expected.insert(edges[1]);
    expected.insert(edges[2]);

    ASSERT_EQ(kruskal(4, p, edges), expected);
}

TEST_F(KruskalTest, k4Unordered) {
    edges.push_back({2,3,11});
    edges.push_back({0,3,8});
    edges.push_back({1,2,9});
    edges.push_back({0,1,6});
    edges.push_back({1,3,10});
    edges.push_back({0,2,7});

    std::set<edge> expected;
    expected.insert(edges[3]);
    expected.insert(edges[5]);
    expected.insert(edges[1]);

    n = 4;
    ASSERT_EQ(kruskal(n, p, edges), expected);
}

TEST_F(KruskalTest, k4Max) {
    edges.push_back({0,1,6});
    edges.push_back({0,2,7});
    edges.push_back({0,3,8});
    edges.push_back({1,2,9});
    edges.push_back({1,3,10});
    edges.push_back({2,3,11});

    std::set<edge> expected;
    expected.insert(edges[2]);
    expected.insert(edges[4]);
    expected.insert(edges[5]);

    n = 4;
    ASSERT_EQ(kruskal(n, p, edges, false), expected);
}

TEST_F(KruskalTest, k4Ds) {
    edges.push_back({0,1,6});
    edges.push_back({0,2,7});
    edges.push_back({0,3,8});
    edges.push_back({1,2,9});
    edges.push_back({1,3,10});
    edges.push_back({2,3,11});

    n = 4;

    disjointSet ds(n);
    ds.join(1, 2);

    std::set<edge> expected;
    expected.insert(edges[0]);
    expected.insert(edges[2]);

    ASSERT_EQ(kruskal(ds, p, edges, true), expected);
}

TEST_F(KruskalTest, k4Weight) {
    edges.push_back({0,1,6});
    edges.push_back({0,2,7});
    edges.push_back({0,3,8});
    edges.push_back({1,2,9});
    edges.push_back({1,3,10});
    edges.push_back({2,3,11});

    n = 4;
    kruskal(n, p, edges);
    ASSERT_EQ(p, 21);
}