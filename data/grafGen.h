#ifndef ALGO3_TP2_GRAFGEN_H
#define ALGO3_TP2_GRAFGEN_H

#include <chrono>
#include <random>
#include "../src/graph.h"
#include "../src/spanning.h"

void genKGraph(int n, edgeList &edges, int maxW, bool digraph);
void shuffleEdgeList(edgeList &edges);
void genRandomGraph(int n, int m, edgeList &edges, int maxW, bool digraph);
void genRandomTree(int n, edgeList &edges, edgeList &tree, int maxW);
void genConex(int n, int m, edgeList &edges, int maxW);
void getSubgraph(int m, edgeList &base, edgeList &subgraph);

#endif //ALGO3_TP2_GRAFGEN_H
