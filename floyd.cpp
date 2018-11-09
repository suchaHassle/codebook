for (int i = 0; i < V; i++) {
  for (int j = 0; j < V; j++)
    AdjMatrix[i][j] = INF;
  AdjMatrix[i][i] = 0;
}

for (int i = 0; i < E; i++) {
  scanf("%d %d %d", &u, &v, &w);
  AdjMatrix[u][v] = w; // directed graph
}

for (int k = 0; k < V; k++)
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      AdjMatrix[i][j] = min(AdjMatrix[i][j],
          AdjMatrix[i][k] + AdjMatrix[k][j]);