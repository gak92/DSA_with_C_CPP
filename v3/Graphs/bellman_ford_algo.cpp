#include <bits/stdc++.h>
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{

  vector<int> distance(n + 1, 1e9);
  distance[src] = 0;

  // n-1 times
  for (int i = 1; i <= n; i++)
  {
    // traverse of edge list
    for (int j = 0; j < m; j++)
    {
      int u = edges[j][0];
      int v = edges[j][1];
      int wt = edges[j][2];

      if (distance[u] != 1e9 && ((distance[u] + wt) < distance[v]))
        distance[v] = distance[u] + wt;
    }
  }

  // check for negative cycle
  bool negativeCycle = 0;
  // traverse of edge list
  for (int j = 0; j < m; j++)
  {
    int u = edges[j][0];
    int v = edges[j][1];
    int wt = edges[j][2];

    if (distance[u] != 1e9 && ((distance[u] + wt) < distance[v]))
      negativeCycle = 1;
  }

  if (!negativeCycle)
    return distance[dest];

  return -1;
}

int main()
{

  return 0;
}