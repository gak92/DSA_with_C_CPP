#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited,
         vector<int> &component, int node)

{
  component.push_back(node);
  visited[node] = 1;

  for (auto nbr : adjList[node])
  {
    if (!visited[nbr])
    {
      dfs(adjList, visited, component, nbr);
    }
  }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
  // Write your code here
  // create adjacency List
  unordered_map<int, list<int>> adjList;
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];

    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  vector<vector<int>> res;
  unordered_map<int, bool> visited;

  // for all nodes call dfs if not visited
  for (int node = 0; node < V; node++)
  {
    if (!visited[node])
    {
      vector<int> component;
      dfs(adjList, visited, component, node);
      res.push_back(component);
    }
  }

  return res;
}

int main()
{

  return 0;
}