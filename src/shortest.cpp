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
    if(distance[u] != INF && w != INF && distance[u] + w < distance[v]) {
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
bool bellmanFordWithAdjustment(int n, int c, int *distance, const edgeList &edges) {
    edgeList adjustedEdges(edges.begin(), edges.end());
    edgeList::iterator it;
    for(it = adjustedEdges.begin(); it != adjustedEdges.end(); ++it){
        it->weight -= c;
    }

    for (unsigned int i = 0; i < (unsigned int)n; i++){
        adjustedEdges.push_back({(unsigned int)n, i, 0});
    }
    bool res = bellmanFord(n, n+1, distance, adjustedEdges);
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

    // Step 1: create adjacency matrix and boolean struct
    bool* visiteNodes = new bool[n];
    int** adjacencyMatrix = new int*[n];

    // Step 2: initialize values from both structures
    for (int i = 0; i < n; i++){
        visiteNodes[i] = false;
        adjacencyMatrix[i] = new int[n];
        for (int j = 0; j < n; j++){
            adjacencyMatrix[i][j] = INF;
        }
    }

    // Step 3: initialize distances
    for(int v = 0; v < n; v++) {
        distance[v] = INF;
    }
    distance[source] = 0;

    // Step 4: initialize adjacency matrix values
    if (digraph){
        edgeList::const_iterator it;
        for(it = edges.begin(); it != edges.end(); ++it) {
            adjacencyMatrix[it->start][it->end] = it->weight;
        }
    } else {
        edgeList::const_iterator it;
        for(it = edges.begin(); it != edges.end(); ++it) {
            adjacencyMatrix[it->start][it->end] = it->weight;
            adjacencyMatrix[it->end][it->start] = it->weight;
        }
    }

    // Step 5: Loop until every node has been visited
    int nextVisitedNode = source;
    while (nextVisitedNode != INF) {
        visiteNodes[nextVisitedNode] = true;
        int myNode = nextVisitedNode;
        nextVisitedNode = INF;
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        for (int v = 0; v < n; v++){
            if (!visiteNodes[v]){
                relax(distance, myNode, v, adjacencyMatrix[myNode][v]);
                if (nextVisitedNode == INF) nextVisitedNode = v;
                if (distance[nextVisitedNode] > distance[v]) nextVisitedNode = v;
            }
        }
    }


    // Step 6: Delete dynamic variables
    delete[] visiteNodes;
    for (int i = 0; i < n; i++){
        delete[] adjacencyMatrix[i];
    }
    delete[] adjacencyMatrix;
}