//
//  earthmover.h
//  CS412 Bonus Assignment
//
//  Created by Bao Truong on 1/4/17.
//  Copyright © 2017 Bao Truong. All rights reserved.
//

#ifndef earthmover_h
#define earthmover_h

#include <fstream>

#include "mincostflow.h"

#define sqr(x) (x) * (x)

struct Cluster {
  vector<int> id;
  double weight;
};

typedef vector<Cluster> Collection;

double flow(const Cluster &x, const Cluster &y) { // Flow between clusters
  return min(x.weight, y.weight);
}

double distance(const Cluster &x, const Cluster &y) { // Euclidean distance between clusters
  double sqrDist = 0;
  for (int i = 0; i < x.id.size(); ++i) {
    sqrDist += sqr(x.id[i] - y.id[i]);
  }
  return sqrt(sqrDist);
}

Collection readCollection(string fileName) { // Read a collection from file
  Collection ret;
  
  ifstream input(fileName);
  int nCluster, dimension;
  input >> nCluster >> dimension;
  for (int i = 0; i < nCluster; ++i) {
    ret.push_back(Cluster());
    for (int j = 0; j < dimension; ++j) {
      int x;
      input >> x;
      ret.back().id.push_back(x);
    }
    input >> ret.back().weight;
  }
  input.close();
  
  return ret;
}

double earthMoversDistance(const Collection &p, const Collection &q) {
  MinCostFlow flowHelper((int)p.size() + (int)q.size() + 2,
                         (int)p.size() * (int)q.size() + (int)p.size() + (int)q.size());
  
  // Construct a flow graph
  int source = 0;
  int sink = flowHelper.V - 1;
  for (int i = 0; i < p.size(); ++i) {
    flowHelper.addEdge(source, 1 + i, p[i].weight, 0);
  }
  for (int i = 0; i < q.size(); ++i) {
    flowHelper.addEdge(1 + (int)p.size() + i, sink, q[i].weight, 0);
  }
  for (int i = 0; i < p.size(); ++i) {
    for (int j = 0; j < q.size(); ++j) {
      flowHelper.addEdge(1 + i, 1 + (int)p.size() + j, flow(p[i], q[j]), distance(p[i], q[j]));
    }
  }
  
  // Compute EMD
  auto result = flowHelper.minCostFlow(source, sink);
  return result.second / result.first;
}

#endif /* earthmover_h */
