#include "AbstractGraphTest.h"
#include "../src/subsidy.h"

class SubsidyTest : public AbstractGraphTest {
protected:
    edgeList edges;
};

TEST_F(SubsidyTest, testCarlos) {
    edges.push_back({2,0,20});
    edges.push_back({0,1,6});
    edges.push_back({1,3,8});
    edges.push_back({3,2,-3}); // FIXME: este test esta mal, no se admiten pesos negativos
    edges.push_back({0,3,7});


    ASSERT_EQ(binarySearchTax(4, 5, edges), 7);
}

TEST_F(SubsidyTest, equalWeightEdges) {
    edges.push_back({2,0,20});
    edges.push_back({0,1,20});
    edges.push_back({1,3,20});
    edges.push_back({3,2,20});
    edges.push_back({0,3,20});

    ASSERT_EQ(binarySearchTax(4, 5, edges), 20);
}


// FIXME: cual es el objetivo de este test? por que no son dos?
TEST_F(SubsidyTest, twoComps) {
    edges.push_back({2,0,20});
    edges.push_back({0,1,20});
    edges.push_back({1,3,20});
    edges.push_back({3,2,20});
    edges.push_back({0,3,20});
    edges.push_back({7,5,20});
    edges.push_back({5,6,6});
    edges.push_back({6,8,8});
    edges.push_back({8,7,-3}); // FIXME: este test esta mal, no se admiten pesos negativos
    edges.push_back({5,8,7});
    ASSERT_EQ(binarySearchTax(9, 10, edges), 7);

    edges.clear();

    edges.push_back({2,0,5});
    edges.push_back({0,1,5});
    edges.push_back({1,3,5});
    edges.push_back({3,2,5});
    edges.push_back({0,3,5});
    edges.push_back({7,5,20});
    edges.push_back({5,6,6});
    edges.push_back({6,8,8});
    edges.push_back({8,7,-3}); // FIXME: este test esta mal, no se admiten pesos negativos
    edges.push_back({5,8,7});
    ASSERT_EQ(binarySearchTax(9, 10, edges), 5);
 }

TEST_F(SubsidyTest, findCicles) {

    //las aristas de peso = 5 pertenecen al k3 formado por 0,1,2
    //las aristas de peso = 10 pertenecen al k3 formado por 4,5,6
    //las aristas de peso = 15 pertenecen al k3 formado por 7,8,9
    //las aristas de peso = 20 no pertenecen a ciclos
    edges.push_back({0, 1, 5});
    edges.push_back({1, 2, 5});
    edges.push_back({2, 0, 5});
    edges.push_back({2, 3, 20});
    edges.push_back({4, 5, 10});
    edges.push_back({5, 6, 10});
    edges.push_back({6, 4, 10});
    edges.push_back({6, 3, 20});
    edges.push_back({3, 7, 20});
    edges.push_back({7, 8, 15});
    edges.push_back({8, 9, 15});
    edges.push_back({9, 7, 15});

    deleteEdgesThatDontBelongToCicles(10, edges);
    ASSERT_EQ(edges.size(), (size_t)9);
    for (size_t i = 0; i < edges.size(); ++i) {
        ASSERT_NE(edges[i].weight, 20);
    }

}

TEST_F(SubsidyTest, noUniversalParents) {

    //las aristas de peso = 5 pertenecen al k3 formado por 0,1,2
    //las aristas de peso = 10 pertenecen al k3 formado por 4,5,6
    //las aristas de peso = 15 pertenecen al k3 formado por 7,8,9
    //las aristas de peso = 20 no pertenecen a ciclos
    edges.push_back({0,1,5});
    edges.push_back({1,2,5});
    edges.push_back({2,0,5});
    edges.push_back({2,3,20});
    edges.push_back({4,5,10});
    edges.push_back({5,6,10});
    edges.push_back({6,4,10});
    edges.push_back({6,3,20});
    edges.push_back({3,7,20});
    edges.push_back({7,8,15});
    edges.push_back({8,9,15});
    edges.push_back({9,7,15});
    ASSERT_EQ(binarySearchTax(10, 12, edges), 5);

    edges.clear();

    //ahora el k3 1,2,3 tiene pesos iguales a 10 y el k3 4,5,6 tiene pesos iguales a 5
    //la idea es que este es un grafo conexo, pero no fuertemente conexo
    //el desafio es detectar todos los ciclos diferentes de una componente conexa
    //aun cuando no se puede acceder a ellos desde un solo source
    edges.push_back({0,1,10});
    edges.push_back({1,2,10});
    edges.push_back({2,0,10});
    edges.push_back({2,3,20});
    edges.push_back({4,5,5});
    edges.push_back({5,6,5});
    edges.push_back({6,4,5});
    edges.push_back({6,3,20});
    edges.push_back({3,7,20});
    edges.push_back({7,8,15});
    edges.push_back({8,9,15});
    edges.push_back({9,7,15});
    ASSERT_EQ(binarySearchTax(10, 12, edges), 5);

}