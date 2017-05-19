#include <gtest/gtest.h>
#include "../src/graph.h"
#include "../src/spanning.h"

TEST(KruskalTest, treeSize) {
    std::vector<edge> edges;
    edges.push_back({0,1,6});
    edges.push_back({0,2,7});
    edges.push_back({0,3,8});
    edges.push_back({1,2,9});
    edges.push_back({1,3,10});
    edges.push_back({2,3,11});

    ASSERT_EQ(kruskal(4, edges).size(), (size_t)3);
}

TEST(KruskalTest, k4Ordered) {
    std::vector<edge> edges;
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

    ASSERT_EQ(kruskal(4, edges), expected);
}

TEST(KruskalTest, k4Unordered) {
    std::vector<edge> edges;
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

    ASSERT_EQ(kruskal(4, edges), expected);
}

TEST(KruskalTest, k4Max) {
    std::vector<edge> edges;
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

    ASSERT_EQ(kruskal(4, edges, false), expected);
}

TEST(KruskalTest, k4Ds) {
    std::vector<edge> edges;
    edges.push_back({0,1,6});
    edges.push_back({0,2,7});
    edges.push_back({0,3,8});
    edges.push_back({1,2,9});
    edges.push_back({1,3,10});
    edges.push_back({2,3,11});

    disjointSet ds(6);
    ds.join(1, 2);

    std::set<edge> expected;
    expected.insert(edges[0]);
    expected.insert(edges[2]);

    ASSERT_EQ(kruskal(ds, edges, true), expected);
}