#include <cstddef>
#include "disjointSet.h"

disjointSet::disjointSet(int n) : cardinal(n), count(n),
                                  id(new int[n]), rank(new int[n]) {
    for(int i = 0; i < n; ++i) {
        id[i] = i;
        rank[i] = 0;
    }
}

disjointSet::~disjointSet() {
    delete[] id;
    delete[] rank;
}

int disjointSet::size() const {
    return count;
}

int disjointSet::find(int n) {
    if(id[n] != n) {
        id[n] = find(id[n]);
    }
    return id[n];
}

int disjointSet::connected(int n, int m) {
    return find(n) == find(m);
}

void disjointSet::join(int n, int m) {
    int rootN = find(n);
    int rootM = find(m);
    if(rootN != rootM) {
        if(rank[rootN] < rank[rootM]) {
            id[rootN] = rootM;
        } else {
            id[rootM] = rootN;
            if(rank[rootN] == rank[rootM]) {
                ++rank[rootN];
            }
        }
        --count;
    }
}

std::vector<int> disjointSet::representants() {
    std::vector<int> res;
    for (int i = 0; i < cardinal; ++i) {
        bool found = false;
        for(size_t j = 0; j < res.size(); ++j){
            if(find(i) == res[j]){
                found = true;
            }
        }
        if(!found){
            res.push_back(find(i));
        }
    }
    return res;
}
