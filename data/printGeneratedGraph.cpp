//
// Created by catofthecannals on 21/05/17.
//
#include <iostream>
#include "grafGen.h"

int main(){
    int n = 10;
    int m = 30;
    edgeList edges;
    int maxW = 20;
    bool digraph = true;
    genRandomGraph(n, m, edges, maxW, digraph);

    for (int i = 0; i < edges.size(); ++i) {
        std::cout << edges[i].start << "," << edges[i].end << "," << edges[i].weight << std::endl;
    }
}
