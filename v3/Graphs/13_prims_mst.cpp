#include <bits/stdc++.h>
#include <list>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
  // create adjacency list
  unordered_map<int, list<pair<int, int>>> adj;
  for (int i = 0; i < g.size(); i++)
  {
    int u = g[i].first.first;
    int v = g[i].first.second;
    int w = g[i].second;

    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  // create data sets and initialize
  vector<int> key(n + 1);
  vector<bool> mst(n + 1);
  vector<int> parent(n + 1);

  for (int i = 0; i <= n; i++)
  {
    key[i] = INT_MAX;
    mst[i] = false;
    parent[i] = -1;
  }

  // start the algo
  key[1] = 0;
  parent[1] = -1;

  for (int i = 1; i < n; i++)
  {
    int mini = INT_MAX;
    int u;

    // 1- find u (minimum in the key array)
    for (int v = 1; v <= n; v++)
    {
      if (mst[v] == false && key[v] < mini)
      {
        mini = key[v];
        u = v;
      }
    }

    // 2- mark min node a true
    mst[u] = true;

    // 3- check it adjacent node
    for (auto nebor : adj[u])
    {
      int v = nebor.first;
      int w = nebor.second;

      if (mst[v] == false && w < key[v])
      {
        key[v] = w;
        parent[v] = u;
      }
    }
  }

  vector<pair<pair<int, int>, int>> res;

  for (int i = 2; i <= n; i++)
  {
    res.push_back({{parent[i], i}, key[i]});
  }

  return res;
}

int main()
{

  return 0;
}