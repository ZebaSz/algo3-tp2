    #include <stdio.h>
    #include "Utils.h"


    struct edge {
        int start;
        int end;
        int weight;
    };

    bool findNegativeCycles(int n, int m, int c, int* distance, edge* edges);
    int binarySearchTax(int n, int m, edge* edges);
    int main() {
        int n = 4;
        int m = 5;
        edge edges[m] = {
                {2,0,20},
                {0,1,6},
                {1,3,8},
                {3,2,-3},
                {0,3,7}
        };

        std::cout << "La maxima reducción de las tarifas es: " << binarySearchTax(n, m, edges) << std::endl;
        return 0;
    }
    int binarySearchTax(int n, int m, edge* edges){
        int c;
        bool detected;
        int low = 0;
        int high = edges[0].weight ;
        for(int e = 0; e < m; e++){
            if(edges[e].weight > high) high = edges[e].weight;
        }
        while(low < high - 1){
            c = (low + high) /2;
            //c++; //we want c to round up
            int distance[n];
            detected = findNegativeCycles(n, m, c, distance, edges);
            if(detected) high = c;
            else low = c;
        }
        return c;
    }

    bool findNegativeCycles(int n, int m, int c, int* distance, edge* edges){
        bool ans = false;
        // Step 1: initialize graph
        int v,e;
        int maxDist = 0;
        for(e = 0; e < m; e++){
            if(edges[e].weight > 0) maxDist += edges[e].weight;
        }
        if(maxDist < 0) std::cout << "Overflow: positive edge sum is too big!" << std::endl;
        for(v = 0; v < n; v++){
            distance[v] = maxDist;
        }
        distance[0] = 0; //source

        // Step 2: relax edges repeatedly
        for(v = 0; v < n; v++){
            for(e = 0; e < m; e++){
                if(distance[edges[e].start] + edges[e].weight - c < distance[edges[e].end] ){ //relax
                    distance[edges[e].end] = distance[edges[e].start] + edges[e].weight - c;
                }
            }
        }
        // Step 3: check for negative-weight cycles
        for(e = 0; e < m; e++) {
            if (distance[edges[e].start] + edges[e].weight - c < distance[edges[e].end]) { //shouldn't be able to relax
                ans = true;
            }
        }
        return ans;
    }