#include "reconfiguration.h"
#include "disjointSet.h"
#include "spanning.h"

std::set<edge> rebuildRoads(int n, int& p, const std::vector<edge> &existing, const std::vector<edge> &potential) {
    disjointSet ds(n);
    std::set<edge> edges = kruskal(ds, p, existing, false);

    int cost = 0;
    std::vector<edge>::const_iterator it;
    for (it = existing.begin(); it != existing.end(); ++it) {
        cost += it->weight;
    }
    cost -= p;

    std::set<edge> moreEdges = kruskal(ds, p, potential, true);
    edges.insert(moreEdges.begin(), moreEdges.end());

    p += cost;

    return edges;
}
