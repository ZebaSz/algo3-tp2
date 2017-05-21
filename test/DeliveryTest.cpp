#include <gtest/gtest.h>
#include "../src/graph.h"
#include "../src/delivery.h"

class DeliveryTest : public ::testing::Test {
protected:
    int n;
    int origin;
    int destination;
    int k;
    edgeList edges;
};

TEST_F(DeliveryTest, fewEdges) {
    n = 4;
    origin = 2;
    destination = 0;
    k = 1;
    addEdgeToPremiumGraph(2, 0, 0, 20, k, n, edges);
    addEdgeToPremiumGraph(1, 0, 1, 6, k, n, edges);
    addEdgeToPremiumGraph(1, 3, 0, 8, k, n, edges);
    addEdgeToPremiumGraph(0, 3, 0, 7, k, n, edges);
    addEdgeToPremiumGraph(2, 3, 1, 2, k, n, edges);
    addEdgeToPremiumGraph(2, 1, 1, 3, k, n, edges);

    ASSERT_EQ(optimumDelivery(origin, destination, n, k, edges), 9);
}