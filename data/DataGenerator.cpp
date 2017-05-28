#include <iostream>
#include "grafGen.h"
#include "../src/delivery.h"

#define REPETITIONS (unsigned int)100
#define MAX_N (unsigned int)10
#define MAX_M (unsigned int)30
#define MAX_W (unsigned int)20

#define MAX_P (unsigned int)20
#define MAX_K (unsigned int)20

void getDataDelivery(FILE *data) {
    fprintf(data, "Ciudades,Rutas,Total Premium,Limite Premium,Nanosegundos\n");
    for (unsigned int i = 2; i <= MAX_N; ++i) {
        printf("Running with %d cities for Delivery problem\n", i);
        for (unsigned int j = 1; j <= std::min(MAX_M, (i*(i-1)) >> 1); ++j) {
            printf("Running with %d routes for Delivery problem\n", j);
            for (unsigned int k = 0; k <= std::min(j, MAX_P); ++k) {
                printf("Running with %d premium routes for Delivery problem\n", k);
                edgeList baseGraph;
                genConex(i, j, baseGraph, MAX_W);
                for (unsigned int l = 0; l <= std::min(k, MAX_K); ++l) {
                    edgeList edges(baseGraph.begin(), baseGraph.end());
                    edgeList premiumEdges;
                    getSubgraph(l, edges, premiumEdges);
                    long best = -1;
                    for (unsigned int m = 0; m < REPETITIONS; ++m) {
                        auto begin = std::chrono::high_resolution_clock::now();

                        optimumDelivery(0, 1, i, l, edges, premiumEdges);

                        auto end = std::chrono::high_resolution_clock::now();
                        if(best == -1 || best > std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()) {
                            best = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
                        }
                    }
                    fprintf(data, "%d,%d,%d,%d,%ld\n", i, j, k, l, best);
                }
            }
        }
    }
}

int main() {
    FILE* data;
    remove("delivery.csv");
    data = fopen("delivery.csv", "a");
    getDataDelivery(data);
    fclose(data);
}
