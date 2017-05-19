#ifndef ALGO3_TP2_GRAPH_H
#define ALGO3_TP2_GRAPH_H

#define INF INT_MAX

struct edge {
    int start;
    int end;
    int weight;
};

bool operator<(const edge&, const edge&);
bool operator>(const edge&, const edge&);
bool operator==(const edge&, const edge&);
bool operator!=(const edge&, const edge&);

struct adjacency {
    int node;
    int weight;
};

bool operator<(const adjacency&, const adjacency&);
bool operator>(const adjacency&, const adjacency&);
bool operator==(const adjacency&, const adjacency&);
bool operator!=(const adjacency&, const adjacency&);

#endif //ALGO3_TP2_GRAPH_H
