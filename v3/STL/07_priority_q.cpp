#include <iostream>
#include <queue>
using namespace std;

void printPQ(priority_queue<int> pq)
{
  int n = pq.size();
  for (int i = 0; i < n; i++)
  {
    cout << pq.top() << " ";
    pq.pop();
  }
}

int main()
{
  // Max Heap
  priority_queue<int> maxi;

  // Min Heap
  priority_queue<int, vector<int>, greater<int>> mini;

  // Insert element at Max Heap (PQ)
  maxi.push(19);
  maxi.push(99);
  maxi.push(92);
  maxi.push(27);

  cout << "Size of Max Heap (PQ): " << maxi.size() << endl;
  int n = maxi.size();
  for (int i = 0; i < n; i++)
  {
    cout << maxi.top() << " ";
    maxi.pop();
  }
  cout << endl;
  cout << "Size of Max Heap (PQ): " << maxi.size() << endl;
  cout << "Is empty: " << maxi.empty() << endl;

  // Insert element at Min Heap (PQ)
  mini.push(19);
  mini.push(99);
  mini.push(92);
  mini.push(27);
  mini.push(41);

  cout << "Size of Min Heap (PQ): " << mini.size() << endl;
  int m = mini.size();
  for (int i = 0; i < m; i++)
  {
    cout << mini.top() << " ";
    mini.pop();
  }
  cout << endl;
  cout << "Size of Min Heap (PQ): " << mini.size() << endl;
  cout << "Is empty: " << mini.empty() << endl;

  return 0;
}