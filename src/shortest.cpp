#include <climits>
#include "shortest.h"
#include "Utils.h"
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <functional>     // std::greater
#include <list>           // std::list

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

typedef std::pair<int, int> intPair;

void dijkstra (int source, int n, int m, int* distance, const edge* edges) {
    // Step 1: create adjacency struct
    std::list <intPair>* adjacency = new std::list <intPair> [n];

    // Step 2: initialize distances
    for(int v = 0; v < n; v++) {
        distance[v] = INF;
    }
    distance[source] = 0;

    // Step 3: initialize adjacency lists
    for(int e = 0; e < m; e++){
        adjacency[edges[e].start].push_back(std::make_pair(edges[e].end, edges[e].weight));
    }

    // Step 4: initialize priority queue
    std::priority_queue< intPair, std::vector <intPair> , std::greater<intPair> > pq;
    pq.push(std::make_pair(0, source));

    // Step 5: Loop until priority queue becomes empty
    while (!pq.empty())
    {
            // The first vertex in pair is the minimum distance
            // vertex, extract it from priority queue.
            // vertex label is stored in second of pair (it
            // has to be done this way to keep the vertices
            // sorted distance (distance must be first item
            // in pair)
            int u = pq.top().second;
            pq.pop();

            // 'i' is used to get all adjacent vertices of a vertex
            std::list < std::pair<int, int> >::iterator i;
            for (i = adjacency[u].begin(); i != adjacency[u].end(); ++i)
            {
                //relax(prev, cur, edges)
            pq.push(std::make_pair(distance[(*i).first], (*i).first));
            }
        }
    }
}