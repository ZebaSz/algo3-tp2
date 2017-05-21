#ifndef ALGO3_TP2_SUBSIDY_H
#define ALGO3_TP2_SUBSIDY_H

#include <vector>
#include "graph.h"

int binarySearchTax(int n, int m, const edgeList &edges);
bool adjustedBellmanFordToEachComponent(int n, int c, int *distance, const edgeList &edges);

#endif //ALGO3_TP2_SUBSIDY_H
