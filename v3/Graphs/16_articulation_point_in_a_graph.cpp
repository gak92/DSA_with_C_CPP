/*
  https://www.codingninjas.com/studio/library/articulation-points-in-a-graph
*/
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
         unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ap)
{
  visited[node] = true;
  disc[node] = low[node] = timer++;
  int child = 0;

  for (auto nebor : adj[node])
  {
    if (nebor == parent)
      continue;

    if (!visited[nebor])
    {
      dfs(nebor, node, timer, disc, low, adj, visited, ap);
      low[node] = min(low[node], low[nebor]);

      // check if ap or not
      if (low[nebor] >= disc[node] && parent != -1)
      {
        ap[node] = 1;
      }
      child++;
    }
    else
    {
      low[node] = min(low[node], disc[nebor]);
    }
  }

  if (parent == -1 && child > 1)
  {
    ap[node] = 1;
  }
}

int main()
{
  int n = 5; // number of nodes/vertex
  int e = 5; // number of edges
  vector<pair<int, int>> edges;

  edges.push_back(make_pair(0, 3));
  edges.push_back(make_pair(3, 4));
  edges.push_back(make_pair(0, 4));
  edges.push_back(make_pair(0, 1));
  edges.push_back(make_pair(1, 2));

  // create adjacency list
  unordered_map<int, list<int>> adj;

  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int timer = 0;
  vector<int> disc(n);
  vector<int> low(n);
  unordered_map<int, bool> visited;
  vector<int> ap(n, 0);

  for (int i = 0; i < n; i++)
  {
    disc[i] = -1;
    low[i] = -1;
  }

  // call dfs
  for (int node = 0; node < n; node++)
  {
    if (!visited[node])
    {
      dfs(node, -1, timer, disc, low, adj, visited, ap);
    }
  }

  // print articulation points
  cout << "Articulation points: ";
  for (int node = 0; node < n; node++)
  {
    if (ap[node] != 0)
    {
      cout << node << ", ";
    }
  }
  cout << endl;

  return 0;
}