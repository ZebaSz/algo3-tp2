#include <climits>
#include <list>
#include <functional>
#include <queue>
#include "shortest.h"
#include "Utils.h"
#include "boost/heap/fibonacci_heap.hpp"

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

// Comparison function for making the boost heap a min heap, boost.heap implements priority queues as max-heaps to be consistent with the STL heap functions.
struct compareMin {
    bool operator()(const adjacency& n1, const adjacency& n2) const {
        return n1.weight > n2.weight;
    }
};

typedef boost::heap::fibonacci_heap<adjacency, boost::heap::compare<compareMin>> minQueue;

typedef minQueue::handle_type queueNode;

/**
 * A implementation of Dijkstra shortest path algorithm for graphs, with Fibonacci Heaps and Adjency Lists
 *
 * @param source the source node
 * @param n the number of nodes
 * @param m the number of edges
 * @param distance the list of distances to output
 * @param edges the list of edges
 *
 * Running Time: O(|E|+|V|*log(|V|))
 *
 */

void dijkstra(int source, int n, int *distance, const edgeList &edges) {

    //Create adjacency list
    std::list<adjacency>* adjacencyList = new std::list<adjacency>[n];
    for(edgeList::const_iterator it = edges.begin(); it != edges.end(); ++it) {
        adjacencyList[it->start].push_back({(int) it->end, it->weight});
    }

    distance[source] = 0;

    //Initialize distance and priority queue
    minQueue queue;
    queueNode* nodesOnQueue = new queueNode[n];
    for (int i = 0; i < n; i++){
        if (i != source) {
            distance[i] = INF;
        }
        nodesOnQueue[i] = queue.push({i, distance[i]});
    }

    while (!queue.empty()) {
        //Get and remove the best vertex from the queue
        adjacency min = queue.top();
        queue.pop();
        for (std::list<adjacency>::iterator it = adjacencyList[min.node].begin(); it != adjacencyList[min.node].end(); ++it) {
            if (distance[min.node] != INF) { //Compare with infinity because if we sum INF with a positive number we get a negative weight
                int dist = distance[min.node] + it->weight;
                if (dist < distance[it->node]) {
                    distance[it->node] = dist;
                    queue.increase(nodesOnQueue[it->node], {it->node, dist}); //Update the queue
                }
            }
        }
    }
    //Remove from memory auxiliary data
    delete[] adjacencyList;
    delete[] nodesOnQueue;
 }