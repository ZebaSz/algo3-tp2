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

TEST_F(DeliveryTest, straightPath) {
    n = 11;
    origin = 0;
    destination = 10;

    for (int i = 0; i < 9; i++) {
        edges.clear();
        k = i;
        addEdgeToPremiumGraph(0, 1, 0, 20, k, n, edges);
        addEdgeToPremiumGraph(1, 2, 0, 20, k, n, edges);
        addEdgeToPremiumGraph(2, 3, 0, 20, k, n, edges);
        addEdgeToPremiumGraph(3, 4, 0, 20, k, n, edges);
        addEdgeToPremiumGraph(4, 5, 0, 20, k, n, edges);
        addEdgeToPremiumGraph(5, 6, 0, 20, k, n, edges);
        addEdgeToPremiumGraph(6, 7, 0, 20, k, n, edges);
        addEdgeToPremiumGraph(7, 8, 0, 20, k, n, edges);
        addEdgeToPremiumGraph(8, 9, 0, 20, k, n, edges);
        addEdgeToPremiumGraph(9, 10, 0, 20, k, n, edges); //Camino de 0 a 10, derecho y sin rutas premium

        addEdgeToPremiumGraph(0, 2, 1, 20, k, n, edges);
        addEdgeToPremiumGraph(2, 4, 1, 20, k, n, edges);
        addEdgeToPremiumGraph(4, 6, 1, 20, k, n, edges);
        addEdgeToPremiumGraph(6, 8, 1, 20, k, n, edges);
        addEdgeToPremiumGraph(8, 10, 1, 20, k, n, edges); //Rutas premium que reducen el camino. El mejor camino posible es usando todas.

        int answerWithK;
        if (i <=5){
            answerWithK = 20*10 - 20*i; // Por cada ruta premium se ahorra una ruta de peso 20.
        } else {
            answerWithK = 20*10 - 20*5; // Solo hay 5 rutas premium.
        }

        ASSERT_EQ(optimumDelivery(origin, destination, n, k, edges), answerWithK);
    }
}