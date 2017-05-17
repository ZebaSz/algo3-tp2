#include <cmath>
#include "subsidy.h"
#include "shortest.h"

int binarySearchTax(int n, int m, const edge* edges) {
    int c = 0;
    bool detected;
    int low = 0;
    int high = edges[0].weight;
    for(int e = 0; e < m; e++) {
        if(edges[e].weight > high) {
            high = edges[e].weight;
        }
    }
    while(low < high - 1) {
        c = (int)std::ceil((low + high)/2);
        int distance[n];
        detected = bellmanFordWithAdjustment(n, m, c, distance, edges);
        if(detected) {
            high = c;
        } else {
            low = c;
        }
    }
    return c;
}