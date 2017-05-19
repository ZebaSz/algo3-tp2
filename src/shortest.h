#ifndef ALGO3_TP2_SHORTEST_H
#define ALGO3_TP2_SHORTEST_H

#include "graph.h"

bool bellmanFord(int source, int n, int m, int* distance, const edge* edges);
bool bellmanFordWithAdjustment(int n, int m, int c, int *distance, const edge *edges);

void dijkstra(int source, int n, int m, int* distance, const edge* edges);

#endif //ALGO3_TP2_SHORTEST_H
