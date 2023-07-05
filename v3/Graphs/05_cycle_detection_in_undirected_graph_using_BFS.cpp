#include <bits/stdc++.h>
using namespace std;

bool isCyclicBFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node)
{
  unordered_map<int, int> parent;
  parent[node] = -1;
  visited[node] = 1;

  queue<int> q;
  q.push(node);

  while (!q.empty())
  {
    int frontNode = q.front();
    q.pop();

    for (auto nbr : adj[frontNode])
    {
      if (visited[nbr] && nbr != parent[frontNode])
      {
        return true;
      }
      else if (!visited[nbr])
      {
        q.push(nbr);
        visited[nbr] = 1;
        parent[nbr] = frontNode;
      }
    }
  }
  return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
  // Write your code here.
  // create adjacency list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < m; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // call bfs if node not visited & use for loop to handle disconnected component
  unordered_map<int, bool> visited;

  for (int node = 0; node < n; node++)
  {
    if (!visited[node])
    {
      bool res = isCyclicBFS(adj, visited, node);
      if (res)
        return "Yes";
    }
  }

  return "No";
}

int main()
{

  return 0;
}