#include <gtest/gtest.h>
#include "../src/graph.h"
#include "../src/spanning.h"

class KruskalTest : public ::testing::Test {
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

TEST_F(KruskalTest, treeSize) {
    edges = new edge[6];
    edges[0] = {0,1,6};
    edges[1] = {0,2,7};
    edges[2] = {0,3,8};
    edges[3] = {1,2,9};
    edges[4] = {1,3,10};
    edges[5] = {2,3,11};

    ASSERT_EQ(kruskal(4, 6, edges).size(), (size_t)3);
}

TEST_F(KruskalTest, k4Ordered) {
    edges = new edge[6];
    edges[0] = {0,1,6};
    edges[1] = {0,2,7};
    edges[2] = {0,3,8};
    edges[3] = {1,2,9};
    edges[4] = {1,3,10};
    edges[5] = {2,3,11};

    std::set<edge> expected;
    expected.insert(edges[0]);
    expected.insert(edges[1]);
    expected.insert(edges[2]);

    ASSERT_EQ(kruskal(4, 6, edges), expected);
}

TEST_F(KruskalTest, k4Unordered) {
    edges = new edge[6];
    edges[3] = {0,1,6};
    edges[5] = {0,2,7};
    edges[1] = {0,3,8};
    edges[2] = {1,2,9};
    edges[4] = {1,3,10};
    edges[0] = {2,3,11};

    std::set<edge> expected;
    expected.insert(edges[3]);
    expected.insert(edges[5]);
    expected.insert(edges[1]);

    ASSERT_EQ(kruskal(4, 6, edges), expected);
}

TEST_F(KruskalTest, k4Max) {
    edges = new edge[6];
    edges[0] = {0,1,6};
    edges[1] = {0,2,7};
    edges[2] = {0,3,8};
    edges[3] = {1,2,9};
    edges[4] = {1,3,10};
    edges[5] = {2,3,11};

    std::set<edge> expected;
    expected.insert(edges[2]);
    expected.insert(edges[4]);
    expected.insert(edges[5]);

    ASSERT_EQ(kruskal(4, 6, edges, false), expected);
}

TEST_F(KruskalTest, k4Ds) {
    edges = new edge[6];
    edges[0] = {0,1,6};
    edges[1] = {0,2,7};
    edges[2] = {0,3,8};
    edges[3] = {1,2,9};
    edges[4] = {1,3,10};
    edges[5] = {2,3,11};

    disjointSet ds(6);
    ds.join(1, 2);

    std::set<edge> expected;
    expected.insert(edges[0]);
    expected.insert(edges[2]);

    ASSERT_EQ(kruskal(ds, 6, edges, true), expected);
}