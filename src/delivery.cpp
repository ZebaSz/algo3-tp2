#include "delivery.h"
#include "shortest.h"

void addEdgeToPremiumGraph(int start, int end, int p, int d, int k, int n, std::vector<edge> edges){
    if (p == 1){
        for(int c = 0; c < k - 1; c++){ //Al k-esimo nivel no se le agregan ejes que no haya agregado ya el nivel anterior
            int c1 = start + c*n;
            int c2 = start + c*n;
            edges.push_back({c1, c2 + n, d});
            edges.push_back({c1 + n, c2, d});
        }
    } else {
        for(int c = 0; c < k; c++){
            int c1 = start + c*n;
            int c2 = start + c*n;
            edges.push_back({c1, c2, d});
        }
    }
}

int optimumDelivery(int origin, int destiny, int n, int m, const edge* edges){
    //TODO: Pasarle dijkstra, quedarse con el mejor valor
}