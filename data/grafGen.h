#ifndef ALGO3_TP2_GRAFGEN_H
#define ALGO3_TP2_GRAFGEN_H

#include "../src/graph.h"
#include "../src/spanning.h"

void genKGraph(unsigned int n, edgeList &edges, int maxW, bool digraph);
void shuffleEdgeList(edgeList &edges);
void genRandomSemiconnectedDigraph(unsigned int n, unsigned int m, edgeList &edges, int maxW);
void genRandomTree(unsigned int n, edgeList &edges, edgeList &tree, int maxW);
void genConex(unsigned int n, unsigned int m, edgeList &edges, int maxW);
void getSubgraph(unsigned int m, edgeList &base, edgeList &subgraph);

#endif //ALGO3_TP2_GRAFGEN_H
