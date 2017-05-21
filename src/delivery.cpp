#include "delivery.h"
#include "shortest.h"
#include <climits>
#include "Utils.h"


void addEdgeToPremiumGraph(int start, int end, int p, int d, int k, int n, std::vector<edge>* edges){
    //Vamos a agregar el eje a todos los niveles y si es premium lo conectamos con el nivel de arriba
    if (p == 1){
        for(int c = 0; c < k; c++){
            //c representa el nivel y c*n es el offset del nivel
            int c1 = start + c*n;
            int c2 = end + c*n;
            edges->push_back({c1, c2 + n, d});//Sumamos + n para conectar al nivel siguiente mediante esta ruta premium
            edges->push_back({c2, c1 + n, d});//Como las rutas son doblemano y nosotros estamos representandolo con un digrafo hay que hacer ambos sentidos
        }
    } else {
        for(int c = 0; c < k; c++){
            int c1 = start + c*n;
            int c2 = end + c*n;
            edges->push_back({c1, c2, d});
            edges->push_back({c2, c1, d});
        }
    }
}

int optimumDelivery(int origin, int destiny, int n, int m, int k, const edge* edges){
    int distance[(k+1)*n];
    dijkstra(origin, (k+1)*n, m*k, distance, edges, true);
    int answer = INF;
    for(int i = 0; i < k+1; i++){
        Utils::log(DELIVERY, "Resultado posible %d", distance[destiny + i*n]);
        if (distance[destiny + i*n] < answer){
            answer = distance[destiny + i*n];
        }
    }
    return answer;
}