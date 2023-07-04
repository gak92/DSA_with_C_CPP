#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class graph
{
public:
  unordered_map<int, list<int>> adj;

  void addEdge(int u, int v, int direction)
  {
    // direction: 0 ---> undirected
    // direction: 1 ---> directed

    // create an edge from u to v
    adj[u].push_back(v);
    if (direction == 0)
    {
      adj[v].push_back(u);
    }
  }

  void printAdjList()
  {
    for (auto ele : adj)
    {
      cout << ele.first << " ---> ";
      for (auto val : ele.second)
      {
        cout << val << ", ";
      }
      cout << endl;
    }
  }
};

int main()
{
  int nodes;
  cout << "Enter number of nodes: ";
  cin >> nodes;

  int edges;
  cout << "Enter number of edges: ";
  cin >> edges;

  graph g;

  for (int i = 0; i < edges; i++)
  {
    int u, v;
    cin >> u >> v;

    // creating an undirected graph
    g.addEdge(u, v, 0);
  }

  g.printAdjList();

  return 0;
}