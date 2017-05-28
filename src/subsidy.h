#ifndef ALGO3_TP2_SUBSIDY_H
#define ALGO3_TP2_SUBSIDY_H

#include <vector>
#include "graph.h"
#include "spanning.h"
#include <stack>
#include <list>

int binarySearchTax(int n, int m, const edgeList &edges);
bool adjustedBellmanFordToEachComponent(int n, int c, int *distance, const edgeList &edges);
void deleteEdgesThatDontBelongToCicles(int n, edgeList &inputEdges);
void deleteIsolatedNodes(int n, edgeList &inputEdges);
void addIsolatedNodesToStack(std::stack<unsigned int> &stack, std::list<unsigned int> *adj,
                             std::vector<int> &din, int j);

#endif //ALGO3_TP2_SUBSIDY_H
