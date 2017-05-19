#include "reconfiguration.h"
#include "disjointSet.h"
#include "spanning.h"

std::set<edge> rebuildRoads(int n, const std::vector<edge> &existing, const std::vector<edge> &potential) {
    disjointSet ds(n);
    std::set<edge> edges = kruskal(ds, existing, false);

    std::set<edge> moreEdges = kruskal(ds, potential, true);
    edges.insert(moreEdges.begin(), moreEdges.end());
    return edges;
}
