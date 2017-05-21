#ifndef ALGO3_TP2_RECONFIGURATION_H
#define ALGO3_TP2_RECONFIGURATION_H

#include <vector>
#include <set>
#include "graph.h"

std::set<edge> rebuildRoads(int n, int& p, const std::vector<edge>& existing, const std::vector<edge>& potential);

#endif //ALGO3_TP2_RECONFIGURATION_H
