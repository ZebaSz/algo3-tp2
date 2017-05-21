#include <climits>
#include <list>
#include <functional>
#include <queue>
#include "shortest.h"
#include "Utils.h"

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
 * @param distance the list of distances to output
 * @param edges the list of edges
 *
 * @return true if a negative cycle has been found; minimum distances otherwise
 */
bool bellmanFord(int source, int n, int *distance, const edgeList &edges) {
    for(int v = 0; v < n; v++) {
        distance[v] = INF;
    }
    distance[source] = 0;

    // Step 2: relax edges repeatedly
    for(int v = 0; v < n; v++) {
        edgeList::const_iterator it;
        for(it = edges.begin(); it != edges.end(); ++it){
            relax(distance, *it);
        }
    }

    // Step 3: check for negative-weight cycles
    edgeList::const_iterator it;
    for(it = edges.begin(); it != edges.end(); ++it){
        if(relax(distance, *it)){
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
 * @param c a number that will be subtracted from all weights
 * @param distance the list of distances to output
 * @param edges the list of edges
 *
 * @return true if a negative cycle has been found; minimum distances otherwise
 */
bool bellmanFordWithAdjustment(int source, int n, int c, int *distance, const edgeList &edges) {
    edgeList adjustedEdges(edges.begin(), edges.end());
    edgeList::iterator it;
    for(it = adjustedEdges.begin(); it != adjustedEdges.end(); ++it){
        it->weight -= c;
    }
    bool res = bellmanFord(source, n, distance, adjustedEdges);
    return res;
}

/**
 * A generic implementation of Dijkstra shortest path algorithm for regular graph and digraph
 *
 * @param source the source node
 * @param n the number of nodes
 * @param m the number of edges
 * @param distance the list of distances to output
 * @param edges the list of edges
 * @param digraph true if it is a digraph
 *
 */

void dijkstra(int source, int n, int *distance, const edgeList &edges, bool digraph) {
    // Step 1: create adjacency struct
    std::list<adjacency>* adj = new std::list<adjacency>[n];

    // Step 2: initialize distances
    for(int v = 0; v < n; v++) {
        distance[v] = INF;
    }
    distance[source] = 0;

    // Step 3: initialize adjacency lists
    if (digraph){
        edgeList::const_iterator it;
        for(it = edges.begin(); it != edges.end(); ++it) {
            adj[it->start].push_back({it->end, it->weight});
        }
    } else {
        edgeList::const_iterator it;
        for(it = edges.begin(); it != edges.end(); ++it) {
            adj[it->start].push_back({it->end, it->weight});
            adj[it->end].push_back({it->start, it->weight});
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
                Utils::log(DEBUG, "Pusheo %d con distancia %d", i->node, distance[i->node]);
                pq.push({i->node, distance[i->node]});
            }
        }
    }

    delete[] adj; 
}