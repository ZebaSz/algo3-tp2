#include <cmath>
#include "subsidy.h"
#include "shortest.h"

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
        int distance[n];
        bool detected = bellmanFordWithAdjustment(n, m, c, distance, edges);
        if(detected) {
            high = c - 1;
        } else {
            low = c;
        }
    }
    return low;
}