// main()
vector< pair<int, ii> > EdgeList;
for (int i = 0; i < E; i++) {
	scanf("%d %d %d", &u, &v, &w);
	EdgeList.push_back(make_pair(w, ii(u,v))); }
sort(EdgeList.begin(), EdgeList.end());

int mst_cost = 0;
UnionFind UF(V);

for (int i = 0; i < E; i++) {
	pair<int, ii> front = EdgeList[i];
	if (!UF.isSameSet(front.second.first, front.second.second)) {
		mst_cost += front.first;
		UF.unionSet(front.second.first, front.second.second);
}	}