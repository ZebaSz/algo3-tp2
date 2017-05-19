#include <gtest/gtest.h>
#include "../src/graph.h"
#include "../src/shortest.h"
#include "../src/reconfiguration.h"

class ReconfigurationTest : public ::testing::Test {
protected:

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

TEST_F(ReconfigurationTest, isTree) {
    std::vector<edge> existing;
    existing.push_back({0, 1, 9});
    existing.push_back({1, 2, 7});
    existing.push_back({0, 2, 2});
    existing.push_back({4, 1, 12});
    existing.push_back({4, 2, 8});

    std::vector<edge> potential;
    potential.push_back({0, 3, 12});
    potential.push_back({0, 4, 3});
    potential.push_back({1, 3, 1});
    potential.push_back({2, 3, 2});
    potential.push_back({4, 3, 6});

    std::set<edge> expected;
    expected.insert(existing[0]);
    expected.insert(existing[3]);
    expected.insert(existing[4]);
    expected.insert(potential[2]);

    ASSERT_EQ(rebuildRoads(5, existing, potential), expected);
}

TEST_F(ReconfigurationTest, sample) {
    std::vector<edge> existing;
    existing.push_back({0, 1, 9});
    existing.push_back({1, 2, 7});
    existing.push_back({0, 2, 2});
    existing.push_back({4, 1, 12});
    existing.push_back({4, 2, 8});

    std::vector<edge> potential;
    potential.push_back({0, 3, 12});
    potential.push_back({0, 4, 3});
    potential.push_back({1, 3, 1});
    potential.push_back({2, 3, 2});
    potential.push_back({4, 3, 6});

    std::set<edge> expected;
    expected.insert(existing[0]);
    expected.insert(existing[3]);
    expected.insert(existing[4]);
    expected.insert(potential[2]);

    ASSERT_EQ(rebuildRoads(5, existing, potential), expected);
}