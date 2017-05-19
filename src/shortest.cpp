#include <climits>
#include "shortest.h"
#include "Utils.h"
#include <iostream>
#include <queue>
#include <functional>
#include <list>

/**
 * Node distance relaxation
 *
 * @param prev the list of distances before relaxing
 * @param cur the list of distances after relaxing
 * @param u the intermediary node
 * @param v the destination node
 * @param w the weight of the edge (u,v)
 * @return true if the distance was relaxed
 */
bool relax(int *distance, int u, int v, int w) {
    if(distance[u] != INF && distance[u] + w < distance[v]) {
        distance[v] = distance[u] + w;
        return true;
    }
    return false;
}

/**
 * Bellman-Ford-type node distance relaxation
 *
 * @param prev the list of distances before relaxing
 * @param distance the list of distances after relaxing
 * @param e the edge to use when relaxing
 * @return true if the distance was relaxed
 */
bool relax(int *distance, const edge &e) {
    return relax(distance, e.start, e.end, e.weight);
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
    for(int v = 0; v < n; v++) {
        distance[v] = INF;
    }
    distance[source] = 0;

    // Step 2: relax edges repeatedly
    for(int v = 0; v < n; v++) {
        for(int e = 0; e < m; e++) {
            relax(distance, edges[e]);
        }
    }

    // Step 3: check for negative-weight cycles
    for(int e = 0; e < m; e++) {
        if(relax(distance, edges[e])){
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

void dijkstra(int source, int n, int m, int* distance, const edge* edges, bool digraph) {
    // Step 1: create adjacency struct
    std::list <adjacency>* adj = new std::list <adjacency> [n];

    // Step 2: initialize distances
    for(int v = 0; v < n; v++) {
        distance[v] = INF;
    }
    distance[source] = 0;

    // Step 3: initialize adjacency lists
    if (digraph){
        for(int e = 0; e < m; e++) {
            adj[edges[e].start].push_back({edges[e].end, edges[e].weight});
        }
    } else {
        for(int e = 0; e < m; e++) {
            adj[edges[e].start].push_back({edges[e].end, edges[e].weight});
            adj[edges[e].end].push_back({edges[e].start, edges[e].weight});
        }
    }

    // Step 4: initialize priority queue
    std::priority_queue< adjacency, std::vector <adjacency> , std::greater<adjacency> > pq;
    pq.push({source, 0});

    // Step 5: Loop until priority queue becomes empty
    while (!pq.empty()) {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.

        int u = pq.top().node;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        std::list < adjacency >::iterator i;

        // Relax with adjacency nodes
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            if(relax(distance, u, i->node, i->weight)) {
                std::cout << "Pusheo " << i->node << " con distancia " << distance[i->node] << std::endl;
                pq.push({i->node, distance[i->node]});
            }
        }
    }

    delete[] adj; 
}