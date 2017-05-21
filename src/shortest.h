#ifndef ALGO3_TP2_SHORTEST_H
#define ALGO3_TP2_SHORTEST_H

#include "graph.h"

bool bellmanFord(int source, int n, int *distance, const edgeList &edges);
bool bellmanFordWithAdjustment(int source, int n, int c, int *distance, const edgeList &edges);

void dijkstra(int source, int n, int *distance, const edgeList &edges, bool digraph);

#endif //ALGO3_TP2_SHORTEST_H
