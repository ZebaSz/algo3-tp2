#include <algorithm>
#include <vector>
#include <cstddef>
#include "spanning.h"

std::set<edge> kruskal(int n, const std::vector<edge>& edges) {
    return kruskal(n, edges, true);
}

std::set<edge> kruskal(int n, const std::vector<edge>& edges, bool min) {
    disjointSet ds(n);
    return kruskal(ds, edges, min);
}

std::set<edge> kruskal(disjointSet &ds, const std::vector<edge>& edges, bool min) {
    std::set<edge> tree;
    std::vector<edge> sortedEdges(edges);
    if(min) {
        std::sort(sortedEdges.begin(), sortedEdges.end());
    } else {
        std::sort(sortedEdges.begin(), sortedEdges.end(), std::greater<edge>());
    }

    for (size_t i = 0; i < sortedEdges.size(); ++i) {
        int u = sortedEdges[i].start;
        int v = sortedEdges[i].end;
        if(!ds.connected(u, v)) {
            tree.insert(sortedEdges[i]);
            ds.join(u, v);
        }
    }
    return tree;
}

