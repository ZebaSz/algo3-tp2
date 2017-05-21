#include "AbstractGraphTest.h"
#include "../src/reconfiguration.h"

class ReconfigurationTest : public AbstractGraphTest {
protected:
    int p;
    edgeList existing;
    edgeList potential;
};

TEST_F(ReconfigurationTest, isTree) {
    existing.push_back({0, 1, 9});
    existing.push_back({1, 2, 7});
    existing.push_back({0, 2, 2});
    existing.push_back({4, 1, 12});
    existing.push_back({4, 2, 8});

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

    ASSERT_EQ(rebuildRoads(5, p, existing, potential), expected);
}

TEST_F(ReconfigurationTest, cost) {
    existing.push_back({0, 1, 9});
    existing.push_back({1, 2, 7});
    existing.push_back({0, 2, 2});
    existing.push_back({4, 1, 12});
    existing.push_back({4, 2, 8});

    potential.push_back({0, 3, 12});
    potential.push_back({0, 4, 3});
    potential.push_back({1, 3, 1});
    potential.push_back({2, 3, 2});
    potential.push_back({4, 3, 6});

    rebuildRoads(5, p, existing, potential);

    ASSERT_EQ(p, 10);
}