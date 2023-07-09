#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
         unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited,
         vector<vector<int>> &res)
{
  visited[node] = true;
  disc[node] = low[node] = timer++;

  for (auto nebor : adj[node])
  {
    if (nebor == parent)
      continue;

    if (!visited[nebor])
    {
      dfs(nebor, node, timer, disc, low, adj, visited, res);
      low[node] = min(low[node], low[nebor]);

      // check if edge is bridge
      if (low[nebor] > disc[node])
      {
        vector<int> temp;
        temp.push_back(node);
        temp.push_back(nebor);
        res.push_back(temp);
      }
    }
    else
    {
      // node already visited and not the parent
      // back edge
      low[node] = min(low[node], disc[nebor]);
    }
  }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
  // create adjacency list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int timer = 0;
  vector<int> disc(v);
  vector<int> low(v);
  int parent = -1;
  unordered_map<int, bool> visited;

  for (int i = 0; i < v; i++)
  {
    disc[i] = -1;
    low[i] = -1;
  }

  vector<vector<int>> res;

  for (int node = 0; node < v; node++)
  {
    if (!visited[node])
    {
      dfs(node, parent, timer, disc, low, adj, visited, res);
    }
  }

  return res;
}

int main()
{

  return 0;
}