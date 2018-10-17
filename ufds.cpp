int find(int i) { return (p[i] == i) ? i : (p[i] = find(p[i])); }

int join(int i, int j) {
	int a = find(i), b = find(j);
	if (a != b) {
		if (rank[a] > rank[b]) p[b] = a;
		else { p[a] = b;
			   if (rank[a] == rank[b]) rank[b]++; }
	}
}