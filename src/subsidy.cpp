#include <cmath>
#include <cstddef>
#include <iostream>
#include "subsidy.h"
#include "shortest.h"
int binarySearchTax(int n, int m, const edgeList &edges) {
    int low = 0;
    int high = edges[0].weight;
    for(int e = 0; e < m; e++) {
        if(edges[e].weight > high) {
            high = edges[e].weight;
        }
    }
    int* distance = new int[n+1];
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
    bool detected = false;
    if(bellmanFordWithAdjustment(n, c, distance, edges)) {
            detected = true;
    }
    return detected;
}
