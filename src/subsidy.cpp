#include <cmath>
#include <cstddef>
#include "subsidy.h"
#include "shortest.h"
#include "disjointSet.h"

int binarySearchTax(int n, int m, const edge* edges) {
    int low = 0;
    int high = edges[0].weight;
    for(int e = 0; e < m; e++) {
        if(edges[e].weight > high) {
            high = edges[e].weight;
        }
    }
    while(low < high) {
        int c = (int)std::ceil((float)(low + high)/2);
        bool detected = adjustedBellmanFordToEachComponent(n, m, c, edges);
        if(detected) {
            high = c - 1;
        } else {
            low = c;
        }
    }
    return low;
}

bool adjustedBellmanFordToEachComponent(int n, int m, int c, const edge *edges){
    disjointSet ds = disjointSet(n);
    for(int e = 0; e < m; e++){
        ds.join(edges[e].start, edges[e].end);
    }
    std::vector<int> r = ds.representants();
    bool detected = false;
    for(size_t i = 0; i < r.size(); i++){
        int distance[n];
        if(bellmanFordWithAdjustment(r[i], n, m, c, distance, edges)) {
            detected = true;
        }
    }
    return detected;
}