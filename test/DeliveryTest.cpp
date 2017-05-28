#include "AbstractGraphTest.h"
#include "../src/delivery.h"
#include "../src/Utils.h"

class DeliveryTest : public AbstractGraphTest {
protected:
    int n;
    int origin;
    int destination;
    int k;
    edgeList edges;
    edgeList premiumEdges;
};

TEST_F(DeliveryTest, fewEdges) {
    n = 4;
    origin = 2;
    destination = 0;
    k = 1;
    edges.push_back({2,0,20});
    edges.push_back({1,3,8});
    edges.push_back({0,3,7});

    premiumEdges.push_back({1,0,6});
    premiumEdges.push_back({2,3,2});
    premiumEdges.push_back({2,1,3});

    ASSERT_EQ(optimumDelivery(origin, destination, n, k, edges, premiumEdges), 9);
}

TEST_F(DeliveryTest, straightPath) {
    n = 11;
    origin = 0;
    destination = 10;

    for (int i = 0; i < 9; i++) {
        edges.clear();
        k = i;

        //Camino de 0 a 10, derecho y sin rutas premium
        edges.push_back({0,1,20});
        edges.push_back({1,2,20});
        edges.push_back({2,3,20});
        edges.push_back({3,4,20});
        edges.push_back({4,5,20});
        edges.push_back({5,6,20});
        edges.push_back({6,7,20});
        edges.push_back({7,8,20});
        edges.push_back({8,9,20});
        edges.push_back({9,10,20});

        //Rutas premium que reducen el camino. El mejor camino posible es usando todas.
        premiumEdges.push_back({0,2,20});
        premiumEdges.push_back({2,4,20});
        premiumEdges.push_back({4,6,20});
        premiumEdges.push_back({6,8,20});
        premiumEdges.push_back({8,10,20});

        int answerWithK;
        if (i <=5) {
            // Por cada ruta premium se ahorra una ruta de peso 20.
            answerWithK = 20*10 - 20*i;
        } else {
            // Solo hay 5 rutas premium.
            answerWithK = 20*10 - 20*5;
        }
        Utils::log(DEBUG, "Hasta aca llegue %d", i);

        ASSERT_EQ(optimumDelivery(origin, destination, n, k, edges, premiumEdges), answerWithK);
    }
}