vi dist(V, INF); dist[s] = 0;
pq<ii, vector<ii>, greater<ii> > pq;pq.push(ii(0, s));

while (!pq.empty()) {
	ii front = pq.top(); pq.pop();
	int d = front.first, u = front.second;
	for (int j = 0; j < (int) AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		if (dist[u] + v.second < dist[v.first]) {
			dist[v.first] = dist[u] + v.second;
			pq.push(ii(dist[v.first], v.first));
}}}