#include <gtest/gtest.h>
#include "../src/disjointSet.h"

class DisjointSetTest : public ::testing::Test {
    protected:
    disjointSet* ds;

    virtual void TearDown() {
        if(ds != NULL) {
            delete ds;
        }
    }
};

TEST_F(DisjointSetTest, disjointWhenCreated) {
    ds = new disjointSet(5);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < i; ++j) {
            ASSERT_FALSE(ds->connected(i, j));
        }
    }
}

TEST_F(DisjointSetTest, joinOnce) {
    ds = new disjointSet(5);
    ds->join(0, 1);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < i; ++j) {
            if(i != 1) {
                ASSERT_FALSE(ds->connected(i, j));
            } else {
                ASSERT_TRUE(ds->connected(i, j));
            }
        }
    }
}

TEST_F(DisjointSetTest, joinSeparate) {
    ds = new disjointSet(5);
    ds->join(0, 1);
    ds->join(2, 3);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < i; ++j) {
            if(i != 1 && (i != 3 || j != 2)) {
                ASSERT_FALSE(ds->connected(i, j));
            } else {
                ASSERT_TRUE(ds->connected(i, j));
            }
        }
    }
}

TEST_F(DisjointSetTest, joinTransitive) {
    ds = new disjointSet(5);
    ds->join(0, 1);
    ds->join(2, 3);
    ds->join(1, 2);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < i; ++j) {
            if(i == 4) {
                ASSERT_FALSE(ds->connected(i, j));
            } else {
                ASSERT_TRUE(ds->connected(i, j));
            }
        }
    }
}

TEST_F(DisjointSetTest, ranks) {
    ds = new disjointSet(5);
    ds->join(0, 1);
    ASSERT_EQ(ds->rank[0], 1);
    ds->join(2, 3);
    ASSERT_EQ(ds->rank[2], 1);
    ds->join(1, 2);
    ASSERT_EQ(ds->rank[0], 2);
}

TEST_F(DisjointSetTest, representant) {
    ds = new disjointSet(7);
    ds->join(0, 1);
    ds->join(2, 3);
    ds->join(1, 2);
    ds->join(4,5);
    std::vector<int> v = {0,4,6};
    std::vector<int> r = ds->representants();
    ASSERT_EQ(r.size(), v.size());
    for (size_t i = 0; i < r.size(); ++i) {
        ASSERT_EQ(r[i], v[i]);
    }
}