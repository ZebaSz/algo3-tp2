//
// Created by catofthecannals on 21/05/17.
//
#include <iostream>
#include "grafGen.h"

int main(){
    int n = 10;
    int m = 9;
    edgeList edges;
    edgeList tree;
    int maxW = 20;
    //bool digraph = true;
    //genRandomGraph(n, m, edges, maxW, digraph);
    //genRandomTree(n, edges, tree, maxW);
    genConex(n, m, edges, maxW);
    for (size_t i = 0; i < edges.size(); ++i) {
        std::cout << edges[i].start << "," << edges[i].end << "," << edges[i].weight << std::endl;

    }

/*
    for (int i = 0; i < tree.size(); ++i) {
        std::cout << tree[i].start << "," << tree[i].end << "," << tree[i].weight << std::endl;
    }
*/
}
