#include <algorithm>
#include <vector>
#include <cstddef>
#include "spanning.h"

std::set<edge> kruskal(int n, int& p, const edgeList& edges) {
    return kruskal(n, p, edges, true);
}

std::set<edge> kruskal(int n, int& p, const edgeList& edges, bool min) {
    disjointSet ds(n);
    return kruskal(ds, p, edges, min);
}

std::set<edge> kruskal(disjointSet &ds, int& p, const edgeList& edges, bool min) {
    std::set<edge> tree;
    edgeList sortedEdges(edges);
    if(min) {
        std::sort(sortedEdges.begin(), sortedEdges.end());
    } else {
        std::sort(sortedEdges.begin(), sortedEdges.end(), std::greater<edge>());
    }

    p = 0;
    for (size_t i = 0; i < sortedEdges.size(); ++i) {
        int u = sortedEdges[i].start;
        int v = sortedEdges[i].end;
        if(!ds.connected(u, v)) {
            tree.insert(sortedEdges[i]);
            p += sortedEdges[i].weight;
            ds.join(u, v);
        }
    }
    return tree;
}

void kruskaLists(int n, edgeList &edges, edgeList &tree) {
    disjointSet ds(n);
    std::sort(edges.begin(), edges.end());
    edgeList::const_iterator it;
    for(it = edges.begin(); it != edges.end(); ){
        int u = it->start;
        int v = it->end;
        if(!ds.connected(u, v)){
            tree.push_back(*it);
            ds.join(u, v);
            it = edges.erase(it);
        } else {
            it++;
        }
    }
}

