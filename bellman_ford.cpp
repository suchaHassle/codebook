// Bellman Ford routine
vi dist(V, INF); dist[s] = 0;
for (int i = 0; i < V - 1; i++)  // relax, overall O(VE)
  for (int u = 0; u < V; u++)    // these two loops = O(E)
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
      ii v = AdjList[u][j];      // we can record SP spanning here
      dist[v.first] = min(dist[v.first], dist[u] + v.second);// relax
    }

bool hasNegativeCycle = false;
for (int u = 0; u < V; u++)  // one more pass to check
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dist[v.first] > dist[u] + v.second) // should be false
      hasNegativeCycle = true; // true: negative cycle exists!
  }