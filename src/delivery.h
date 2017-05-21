#ifndef ALGO3_TP2_DELIVERY_H
#define ALGO3_TP2_DELIVERY_H

#include "graph.h"
#include <vector>

void addEdgeToPremiumGraph(int start, int end, int p, int d, int k, int n, std::vector<edge>* edges);
int optimumDelivery(int origin, int destiny, int n, int countPremium, int m, int k, const edge* edges);

#endif //ALGO3_TP2_DELIVERY_H
