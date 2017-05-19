#include <algorithm>
#include "spanning.h"

std::set<edge> kruskal(int n, int m, const edge *edges) {
    return kruskal(n, m, edges, true);
}

std::set<edge> kruskal(int n, int m, const edge *edges, bool min) {
    disjointSet ds(n);
    return kruskal(ds, m, edges, min);
}

std::set<edge> kruskal(disjointSet &ds, int m, const edge *edges, bool min) {
    std::set<edge> tree;
    edge sortedEdges[m];
    for (int i = 0; i < m; ++i) {
        sortedEdges[i] = edges[i];
    }
    if(min) {
        std::sort(sortedEdges, sortedEdges + m);
    } else {
        std::sort(sortedEdges, sortedEdges + m, std::greater<edge>());
    }

    for (int i = 0; i < m; ++i) {
        int u = sortedEdges[i].start;
        int v = sortedEdges[i].end;
        if(!ds.connected(u, v)) {
            tree.insert(sortedEdges[i]);
            ds.join(u, v);
        }
    }
    return tree;
}

