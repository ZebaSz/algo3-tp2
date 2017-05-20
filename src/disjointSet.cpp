#include <cstddef>
#include "disjointSet.h"

disjointSet::disjointSet(int n) : cardinal(n),count(n), id(NULL) {
    id = new int[n];
    for(int i = 0; i < n; ++i) {
        id[i] = i;
    }
}

disjointSet::~disjointSet() {
    delete[] id;
}

int disjointSet::size() const {
    return count;
}

int disjointSet::find(int n) {
    int root = id[n];
    if(root != n) {
        root = find(root);
        id[n] = root;
    }
    return root;
}

int disjointSet::connected(int n, int m) {
    return find(n) == find(m);
}

void disjointSet::join(int n, int m) {
    int rootN = find(n);
    int rootM = find(m);
    if(rootN != rootM) {
        id[rootN] = rootM;
        --count;
    }
}

std::vector<int> disjointSet::representants() {
    std::vector<int> res;
    for (int i = 0; i < cardinal; ++i) {
        bool found = false;
        for(int j = 0; j < res.size(); ++j){
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
