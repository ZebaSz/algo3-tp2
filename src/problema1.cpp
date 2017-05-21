#include <stdio.h>
#include <iostream>
#include <vector>
#include "Utils.h"
#include "graph.h"
#include "delivery.h"

struct input {
    int n;
    int m;
    int origin;
    int destiny;
    int k;
    int countEdges;
    std::vector<edge> edges;
};

int main() {
    bool hasInput = true;
    std::vector<input> inputs;
    while(hasInput) {
        int n, m, origin, destiny, k;

        std::cin >> n >> m;
        std::cin >> origin >> destiny >> k;
        hasInput = (n != -1 || m != -1 || origin != -1 || destiny != -1 || k != -1);
        if(hasInput) {
            input in;
            in.n = n;
            in.m = m;
            in.origin = origin;
            in.destiny = destiny;
            in.k = k;
            in.countEdges = 0;
            for(int i = 0; i < m; ++i) {
                int c1, c2, p, d;
                std::cin >> c1 >> c2 >> p >> d;
                --c1;
                --c2;
                addEdgeToPremiumGraph(c1, c2, p, d, k, n, &in.edges);
            }
            inputs.push_back(in);
        }
    }
    std::vector<input>::const_iterator it;
    for(it = inputs.begin(); it != inputs.end(); ++it) {
        std::cout << optimumDelivery(it->origin, it->destiny, it->countEdges, it->m, it->k, &(it->edges)[0]) << std::endl;
    }
    return 0;
}