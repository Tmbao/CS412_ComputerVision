//
//  mincostflow.h
//  CS412 Bonus Assignment
//
//  Created by Bao Truong on 1/4/17.
//  Copyright © 2017 Bao Truong. All rights reserved.
//

#ifndef mincostflow_h
#define mincostflow_h

#include <vector>
#include <queue>
using namespace std;

#define INF 1e18

struct MinCostFlow {
  int V, E;
  vector<double> cap, cost;
  vector<int> to, prev;
  
  vector<double> dist, pot;
  vector<int> last, path, used;
  
  MinCostFlow(int V, int E) : V(V), E(0), cap(E * 2, 0), cost(E * 2, 0), to(E * 2, 0), prev(E * 2, 0), dist(V, 0), pot(V, 0), last(V, -1), path(V, 0), used(V, 0) {}
  
  void addEdge(int x, int y, double f, double c) {
    cap[E] = f; cost[E] = c; to[E] = y; prev[E] = last[x]; last[x] = E; ++E;
    cap[E] = 0; cost[E] = -c; to[E] = x; prev[E] = last[y]; last[y] = E; ++E;
  }
  
  pair<double, double> search(int s, int t) {
    double ansf = 0, ansc = 0;
    
    for (int i = 0; i < V; ++i) {
      used[i] = false;
      dist[i] = INF;
    }
    
    priority_queue<pair<double, int>> q;
    path[s] = -1;
    q.push(make_pair(dist[s] = 0, s));
    while (!q.empty()) {
      int x = q.top().second; q.pop();
      if (used[x]) {
        continue;
      }
      used[x] = true;
      for (int e = last[x]; e >= 0; e = prev[e]) {
        if (cap[e] > 0) {
          double tmp = dist[x] + cost[e] + pot[x] - pot[to[e]];
          if (tmp < dist[to[e]] && !used[to[e]]) {
            dist[to[e]] = tmp;
            path[to[e]] = e;
            q.push(make_pair(-dist[to[e]], to[e]));
          }
        }
      }
    }
    
    for (int i = 0; i < V; ++i) {
      pot[i] += dist[i];
    }
    
    if (used[t]) {
      ansf = INF;
      for (int e = path[t]; e >= 0; e = path[to[e ^ 1]]) {
        ansf = min(ansf, cap[e]);
      }
      for (int e = path[t]; e >= 0; e = path[to[e ^ 1]]) {
        ansc += cost[e] * ansf;
        cap[e] -= ansf;
        cap[e ^ 1] += ansf;
      }
    }
    
    return {ansf, ansc};
  }
  
  pair<double, double> minCostFlow(int s, int t) {
    double ansf = 0, ansc = 0;
    while (true) {
      auto p = search(s, t);
      if (!used[t]) {
        break;
      }
      ansf += p.first;
      ansc += p.second;
    }
    return {ansf, ansc};
  }
};

#endif /* mincostflow_h */
