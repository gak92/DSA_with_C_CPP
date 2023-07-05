#include <bits/stdc++.h>
using namespace std;

bool isCyclicDFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited,
                 unordered_map<int, bool> &dfsVisited, int node)
{
  visited[node] = true;
  dfsVisited[node] = true;

  for (auto nbr : adj[node])
  {
    if (!visited[nbr])
    {
      bool cycleDetected = isCyclicDFS(adj, visited, dfsVisited, nbr);
      if (cycleDetected)
        return true;
    }
    else if (dfsVisited[nbr])
    {
      return true;
    }
  }

  dfsVisited[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
  // Write your code here.
  // create adjacency list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  // call dfs for each node that not visited
  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsVisited;

  for (int node = 0; node < n; node++)
  {
    if (!visited[node])
    {
      bool cycleDetected = isCyclicDFS(adj, visited, dfsVisited, node);
      if (cycleDetected)
        return true;
    }
  }

  return false;
}

int main()
{

  return 0;
}