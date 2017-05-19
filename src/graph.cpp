#include "graph.h"

bool operator<(const edge& e, const edge& f) {
    return e.weight < f.weight;
}