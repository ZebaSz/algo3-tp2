#include "delivery.h"
#include "shortest.h"
#include <climits>
#include "Utils.h"

void addRegularEdge(const edge &e, int n, int k, edgeList &superGraph) {
    for (int c = 0; c <= k; ++c) {
        unsigned int c1 = e.start + c * n;
        unsigned int c2 = e.end + c * n;
        //Si la ruta no es premium conectamos ida y vuelta los del mismo nivel
        superGraph.push_back({c1, c2, e.weight});
        superGraph.push_back({c2, c1, e.weight});
    }
}

void addPremiumEdge(const edge &e, int n, int k, edgeList &superGraph) {
    for (int c = 0; c < k; ++c) {
        //c representa el nivel y c*n es el offset del nivel
        unsigned int c1 = e.start + c * n;
        unsigned int c2 = e.end + c * n;
        //Sumamos + n para conectar al nivel siguiente mediante esta ruta premium
        superGraph.push_back({c1, c2 + n, e.weight});
        //Como las rutas son doblemano y nosotros estamos representandolo con un digrafo hay que hacer ambos sentidos
        superGraph.push_back({c2, c1 + n, e.weight});
    }
}

int optimumDelivery(int origin, int destination, int n, int k,
                    const edgeList &edges, const edgeList &premiumEdges) {
    int premiumGraphNodes = (k + 1) * n;
    int* distance = new int[(k + 1) * n];

    edgeList superGraph;
    edgeList::const_iterator it;
    for (it = edges.begin(); it != edges.end(); ++it) {
        addRegularEdge(*it, n, k, superGraph);
    }
    for (it = premiumEdges.begin(); it != premiumEdges.end(); ++it) {
        addPremiumEdge(*it, n, k, superGraph);
    }
    
    dijkstra(origin, premiumGraphNodes, distance, superGraph);
    int answer = INF;
    for (int i = 0; i <= k; i++) {
        Utils::log(DEBUG, "Resultado posible %d", distance[destination + i * n]);
        if (distance[destination + i * n] < answer) {
            answer = distance[destination + i * n];
        }
    }
    delete[] distance;
    if (answer == INF){
        return -1;
    } else {
        return answer;
    }
}
