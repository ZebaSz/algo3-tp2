#include <climits>
#include "shortest.h"
#include "Utils.h"

/**
 * Bellman-Ford-type node distance relaxation
 *
 * @param prev the list of distances before relaxing
 * @param cur the list of distances after relaxing
 * @param e the edge to use when relaxing
 * @return true if the distance was relaxed
 */
bool relax(int* prev, int* cur, const edge& e) {
    if(prev[e.start] != INF && prev[e.start] + e.weight < prev[e.end]) {
        cur[e.end] = prev[e.start] + e.weight;
        return true;
    } else {
        cur[e.end] = prev[e.end];
    }
    return false;
}

/**
 * A generic implementation of Bellman-Ford shortest path algorithm
 *
 * @param source the source node
 * @param n the number of nodes
 * @param m the number of edges
 * @param distance the list of distances to output
 * @param edges the list of edges
 *
 * @return true if a negative cycle has been found; minimum distances otherwise
 */
bool bellmanFord(int source, int n, int m, int* distance, const edge* edges) {
    // Step 1: initialize distances
    // the dist array works as 2 different arrays,
    // allowing us to switch between them per iteraton
    int dist[n * 2];

    for(int v = 0; v < n; v++) {
        dist[v] = INF;
    }
    dist[source] = 0;

    // Step 2: relax edges repeatedly
    for(int v = 0; v < n; v++) {
        for(int e = 0; e < m; e++) {
            relax(&dist[n * (v % 2)], &dist[n * (1 - v%2)], edges[e]);
        }
    }

    for(int v = 0; v < n; v++) {
        distance[v] = dist[v + n * (n % 2)];
    }

    // Step 3: check for negative-weight cycles
    for(int e = 0; e < m; e++) {
        if(relax(distance, distance, edges[e])){
            Utils::log(DEBUG, "Found negative-weight cycle");
            return true;
        };
    }
    return false;
}

/**
 * An implementation of Bellman-Ford shortest path algorithm
 * with an extra adjustment parameter
 *
 * @param n the number of nodes
 * @param m the number of edges
 * @param c a number that will be subtracted from all weights
 * @param distance the list of distances to output
 * @param edges the list of edges
 *
 * @return true if a negative cycle has been found; minimum distances otherwise
 */
bool bellmanFordWithAdjustment(int n, int m, int c, int *distance, const edge *edges) {
    edge adjustedEdges[m];
    for(int e = 0; e < m; e++){
        adjustedEdges[e] = edges[e];
        adjustedEdges[e].weight -= c;
    }
    return bellmanFord(0, n, m, distance, adjustedEdges);
}