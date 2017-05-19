#include "graph.h"

bool operator<(const edge& e, const edge& f) {
    return e.weight < f.weight;
}

bool operator>(const edge& e, const edge& f) {
    return f < e;
}

bool operator==(const edge& e, const edge& f) {
    return e.start == f.start && e.end == f.end && e.weight == f.weight;
}

bool operator!=(const edge& e, const edge& f) {
    return !(e == f);
}