#ifndef ALGO3_TP2_DELIVERY_H
#define ALGO3_TP2_DELIVERY_H

#include "graph.h"

void addEdgeToPremiumGraph(int start, int end, int p, int d, int k, int n, edgeList& edges);
int optimumDelivery(int origin, int destiny, int n, int k, const edgeList &edges);

#endif //ALGO3_TP2_DELIVERY_H
