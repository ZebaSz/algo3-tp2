#include <cmath>
#include <cstddef>
#include "subsidy.h"
#include "shortest.h"
#include "disjointSet.h"

int binarySearchTax(int n, int m, edgeList &edges) {
    deleteEdgesThatDontBelongToCicles(n, edges);
    int low = 0;
    int high = edges[0].weight;
    for(int e = 0; e < m; e++) {
        if(edges[e].weight > high) {
            high = edges[e].weight;
        }
    }
    int* distance = new int[n];
    while(low < high) {
        int c = (int)std::ceil((float)(low + high)/2);
        bool detected = adjustedBellmanFordToEachComponent(n, c, distance, edges);
        if(detected) {
            high = c - 1;
        } else {
            low = c;
        }
    }
    delete[] distance;
    return low;
}

bool adjustedBellmanFordToEachComponent(int n, int c, int *distance, const edgeList &edges) {
    disjointSet ds = disjointSet(n);
    edgeList::const_iterator it;
    for (it = edges.begin(); it != edges.end(); ++it) {
        ds.join(it->start, it->end);
    }
    std::vector<int> r = ds.representants();
    bool detected = false;
    for(size_t i = 0; i < r.size(); i++) {
        if(bellmanFordWithAdjustment(r[i], n, c, distance, edges)) {
            detected = true;
        }
    }
    return detected;
}

void deleteEdgesThatDontBelongToCicles(int n, edgeList &inputEdges) {
    bool changesMade = true;
    edgeList edgesToUse;
    kruskaLists(n, inputEdges, edgesToUse);
    while(changesMade){
        changesMade = false;
        disjointSet ds(n);
        for (size_t i = 0; i < inputEdges.size() ; ++i) {
            ds.join(inputEdges[i].start, inputEdges[i].end);
        }
        edgeList::const_iterator it;
        for (it = edgesToUse.begin(); it != edgesToUse.end(); ) {
            int u = it->start;
            int v = it->end;
            if(ds.connected(u, v)){
                inputEdges.push_back(*it);
                edgesToUse.erase(it);
                changesMade = true;
            } else {
                ds.join(u,v);
                it++;
            }
        }
    }
}

