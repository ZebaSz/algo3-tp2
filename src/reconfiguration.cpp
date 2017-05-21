#include "reconfiguration.h"
#include "disjointSet.h"
#include "spanning.h"

std::set<edge> rebuildRoads(int n, int& p, const edgeList &existing, const edgeList &potential) {
    disjointSet ds(n);
    std::set<edge> edges = kruskal(ds, p, existing, false);

    int cost = 0;
    edgeList::const_iterator it;
    for (it = existing.begin(); it != existing.end(); ++it) {
        cost += it->weight;
    }
    cost -= p;

    std::set<edge> moreEdges = kruskal(ds, p, potential, true);
    edges.insert(moreEdges.begin(), moreEdges.end());

    p += cost;

    return edges;
}
