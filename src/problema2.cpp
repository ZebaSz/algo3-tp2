#include <stdio.h>
#include <iostream>
#include <vector>
#include "Utils.h"
#include "graph.h"
#include "subsidy.h"

struct input {
    int n;
    int m;
    std::vector<edge> edges;
};

int main() {
    bool hasInput = true;
    std::vector<input> inputs;
    while(hasInput) {
        int n, m;

        std::cin >> n >> m;
        hasInput = n != -1 || m != -1;
        if(hasInput) {
            input in;
            in.n = n;
            in.m = m;
            for(int i = 0; i < m; ++i) {
                int c1, c2, p;
                std::cin >> c1 >> c2 >> p;
                --c1;
                --c2;
                in.edges.push_back({c1, c2, p});
            }
            inputs.push_back(in);
        }
    }
    std::vector<input>::const_iterator it;
    for(it = inputs.begin(); it != inputs.end(); ++it) {
        std::cout << binarySearchTax(it->n, it->m, &(it->edges)[0]) << std::endl;
    }
    return 0;
}