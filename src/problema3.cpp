#include <vector>
#include <iostream>
#include "graph.h"
#include "reconfiguration.h"

struct input {
    int n;
    std::vector<edge> existing;
    std::vector<edge> potential;
};

int main() {
    bool hasInput = true;
    std::vector<input> inputs;
    while(hasInput) {
        int n;

        std::cin >> n;
        hasInput = n != -1;
        if(hasInput) {
            input in;
            in.n = n;
            for(int i = 0; i < ((n * (n-1)) / 2); ++i) {
                int c1, c2, e, p;
                std::cin >> c1 >> c2 >> e >> p;
                --c1;
                --c2;
                if(e) {
                    in.existing.push_back({c1, c2, p});
                } else {
                    in.potential.push_back({c1, c2, p});
                }
            }
            inputs.push_back(in);
        }
    }
    std::vector<input>::const_iterator it;
    for(it = inputs.begin(); it != inputs.end(); ++it) {
        int p;
        std::set<edge> edges = rebuildRoads(it->n, p, it->existing, it->potential);

        printf("%d %lu", p, edges.size());

        std::set<edge>::const_iterator e;
        for (e = edges.begin(); e != edges.end(); ++e) {
            printf(" %d %d", e->start + 1, e->end +1);
        }
        printf("\n");
    }
    return 0;
}