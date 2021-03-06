#include <iostream>
#include "delivery.h"

struct input {
    int n;
    int m;
    int origin;
    int destination;
    int k;
    edgeList edges;
    edgeList premiumEdges;
};

int main() {
    bool hasInput = true;
    std::vector<input> inputs;
    while(hasInput) {
        int n, m;

        std::cin >> n >> m;
        hasInput = (n != -1 || m != -1);
        if(hasInput) {
            input in;
            in.n = n;
            in.m = m;
            std::cin >> in.origin >> in.destination >> in.k;
            --in.origin;
            --in.destination;
            for(int i = 0; i < m; ++i) {
                unsigned int c1, c2;
                int p, d;
                std::cin >> c1 >> c2 >> p >> d;
                --c1;
                --c2;
                edge e = {c1, c2, d};
                if(p) {
                    in.premiumEdges.push_back(e);
                } else {
                    in.edges.push_back(e);
                }
            }
            inputs.push_back(in);
        }
    }
    std::vector<input>::const_iterator it;
    for(it = inputs.begin(); it != inputs.end(); ++it) {
        std::cout << optimumDelivery(it->origin, it->destination, it->n, it->k, it->edges, it->premiumEdges) << std::endl;
    }
    return 0;
}