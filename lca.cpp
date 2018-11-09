vector< vector<int> > children;
int L[2*MAX_N], E[2*MAX_N], H[MAX_N], idx;

void dfs(int cur, int depth) {
  H[cur] = idx;
  E[idx] = cur;
  L[idx++] = depth;
  for (int i = 0; i < children[cur].size(); i++) {
    dfs(children[cur][i], depth+1);
    E[idx] = cur; // backtrack to current node
    L[idx++] = depth;
  }
}

int LCA(int u, v) {
  if (H[u] > H[v]) {
    swap(u, v); }
  int ind = rmq(H[u], H[v]);
  return E[ind];
}

int dist(int u, int v) {
  int a = H[u], b = H[v];
  int ind = LCA(u,v);
  return abs(L[H[ind]] - L[a]) + abs(L[H[ind]] - L[b]);
}

void buildRMQ() {
  idx = 0;
  memset(H, -1, sizeof H);
  dfs(0, 0); // we assume that the root is at index 0
}