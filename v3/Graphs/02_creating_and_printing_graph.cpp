#include <bits/stdc++.h>
vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
  // Write your code here.
  vector<int> res[n];
  for (int i = 0; i < m; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];

    res[u].push_back(v);
    res[v].push_back(u);
  }

  vector<vector<int>> adj(n);

  for (int i = 0; i < n; i++)
  {
    adj[i].push_back(i);

    for (int j = 0; j < res[i].size(); j++)
    {
      adj[i].push_back(res[i][j]);
    }
  }

  return adj;
}