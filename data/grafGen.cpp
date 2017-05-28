#include "grafGen.h"

/**
 * Generates a complete graph
 *
 * @param n the amount of nodes
 * @param edges the list of edges to output
 * @param maxW the maximum weight
 * @param digraph true if the graph to be generated is a digraph
 */
void genKGraph(int n, edgeList &edges, int maxW, bool digraph){
    long seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, maxW);
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            edges.push_back({i, j, distribution(generator)});
            if(digraph) {
                edges.push_back({j, i, distribution(generator)});
            }
        }
    }
}

void shuffleEdgeList(edgeList &edges) {
    long seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    for (size_t i = 0; i < edges.size(); ++i) {
        std::uniform_int_distribution<size_t> distribution(i, edges.size() - 1);
        std::swap(edges[i], edges[distribution(generator)]);
    }
}

/**
 * Generates a random graph which may or may not be connected
 *
 * @param n
 * @param m
 * @param edges
 * @param maxW
 * @param digraph
 */
void genRandomGraph(int n, int m, edgeList &edges, int maxW, bool digraph) {
    genKGraph(n, edges, maxW, digraph);
    shuffleEdgeList(edges);
    int amountOfEdgesToErase = n*(n-1) - m;
    for (int i = 0; i < amountOfEdgesToErase; ++i) {
        edges.pop_back();
    }

}

/**
 * Generates a random tree
 *
 * @param n
 * @param edges
 * @param tree
 * @param maxW
 */
void genRandomTree(int n, edgeList &edges, edgeList &tree, int maxW) {
    genKGraph(n, edges, maxW, false);
    shuffleEdgeList(edges);
    kruskaLists(n, edges, tree);
}

/**
 * Generates a conected graph
 *
 * @param n
 * @param m
 * @param tree
 * @param maxW
 */
void genConex(int n, int m, edgeList &tree, int maxW) {
    edgeList edges;
    genRandomTree(n, edges, tree, maxW);
    edgeList::const_iterator it = edges.begin();
    int edgesToAdd = m -(n-1);
    for (int i = 0; i < edgesToAdd; ++i) {
        tree.push_back(*it);
        it = edges.erase(it);
    }
}

void getSubgraph(int m, edgeList &base, edgeList &subgraph) {
    shuffleEdgeList(base);
    edgeList::const_iterator it = base.begin();
    for (int i = 0; i < m; ++i) {
        subgraph.push_back(*it);
        it = base.erase(it);
    }
}

