#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
  unordered_map<int, list<pair<int, int>>> adj;

  void addEdge(int u, int v, int weight)
  {
    pair<int, int> p = make_pair(v, weight);
    adj[u].push_back(p);
  }

  void printAdjList()
  {
    for (auto ele : adj)
    {
      cout << ele.first << " ---> ";
      for (auto nebor : ele.second)
      {
        cout << "(" << nebor.first << ", " << nebor.second << "), ";
      }
      cout << endl;
    }
  }

  void dfs(unordered_map<int, bool> &visited, stack<int> &st, int node)
  {
    visited[node] = 1;

    for (auto nebor : adj[node])
    {
      if (!visited[nebor.first])
      {
        dfs(visited, st, nebor.first);
      }
    }
    st.push(node);
  }

  void getShortestPath(int source, vector<int> &distance, stack<int> &st)
  {
    distance[source] = 0;

    while (!st.empty())
    {
      int topNode = st.top();
      st.pop();

      if (distance[topNode] != INT_MAX)
      {
        for (auto nebor : adj[topNode])
        {
          if (distance[topNode] + nebor.second < distance[nebor.first])
            distance[nebor.first] = distance[topNode] + nebor.second;
        }
      }
    }
  }
};

int main()
{
  Graph g;
  g.addEdge(0, 1, 5);
  g.addEdge(0, 2, 3);
  g.addEdge(1, 2, 2);
  g.addEdge(1, 3, 6);
  g.addEdge(2, 3, 7);
  g.addEdge(2, 4, 4);
  g.addEdge(2, 5, 2);
  g.addEdge(3, 4, -1);
  g.addEdge(4, 5, -2);

  g.printAdjList();

  int n = 6;

  // topological sort
  unordered_map<int, bool> visited;
  stack<int> st;
  for (int node = 0; node < n; node++)
  {
    if (!visited[node])
    {
      g.dfs(visited, st, node);
    }
  }

  int source = 1;
  vector<int> distance(n);
  for (int node = 0; node < n; node++)
    distance[node] = INT_MAX;

  g.getShortestPath(source, distance, st);

  cout << "Result is: " << endl;

  for (int node = 0; node < distance.size(); node++)
  {
    cout << distance[node] << " ";
  }
  cout << endl;

  return 0;
}