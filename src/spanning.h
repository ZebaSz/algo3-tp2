#ifndef ALGO3_TP2_SPANNING_H
#define ALGO3_TP2_SPANNING_H

#include <set>
#include "graph.h"
#include "disjointSet.h"

/**
 * A generic implementation of Kruskal's minimum spanning tree algorithm
 *
 * @param n the number of vertices
 * @param p the sum of the added edges (as output)
 * @param edges the list of edges
 * @return a minimum spanning tree represented by a set of edges
 */
std::set<edge> kruskal(int n, int& p, const edgeList& edges);

/**
 * An implementation of Kruskal's minimum spanning tree algorithm
 * which allows to invert the logic to find maximum spanning trees instead
 *
 * @param n the number of vertices
 * @param p the sum of the added edges (as output)
 * @param edges the list of edges
 * @param min if true, the result will be a min spanning tree, or a max spanning tree otherwise
 * @return a minimum (or maximum) spanning tree represented by a set of edges
 */
std::set<edge> kruskal(int n, int& p, const edgeList& edges, bool min);

/**
 * An implementation of Kruskal's minimum spanning tree algorithm
 * which allows to use a preset disjoint set
 *
 * @param ds a preset disjoint set to be used when creating the tree
 * @param p the sum of the added edges (as output)
 * @param edges the list of edges
 * @param min if true, the result will be a min spanning tree, or a max spanning tree otherwise
 * @return a minimum (or maximum) spanning tree represented by a set of edges
 */
std::set<edge> kruskal(disjointSet& ds, int& p, const edgeList& edges, bool min);

/**
 * Generates a (non-minimum) spanning tree using Kruskal's MST method
 *
 * @param n the number of nodes
 * @param edges the list of edges; the spanning tree will be removed from it
 * @param tree the spanning tree as output
 */
void generateSpanningTree(int n, edgeList &edges, edgeList &tree);

#endif //ALGO3_TP2_SPANNING_H
