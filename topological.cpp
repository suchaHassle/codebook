vi ts;

void dfs2(int u) {
	dfs_num[u] = VISITED;
	for (int j = 0; j < (int) AdjList[u].size(); j++) {
		pair<int,int> v = AdjList[u][j];
		if (dfs_num[v.first] == UNVISITED) dfs2(v.first);
	}
	ts.push_back(u); }

// Inside int main()
ts.clear();
memset(dfs_num, UNVISITED, sizeof dfs_num);
for (int i = 0; i < V; i++)
	if (dfs_num[i] == UNVISITED) dfs2(i);

for (int i = (int)tx.size() - 1; i >= 0; i--)
	printf(" %d" ts[i]);