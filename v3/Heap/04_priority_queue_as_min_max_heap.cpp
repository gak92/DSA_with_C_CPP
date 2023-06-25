#include <iostream>
#include <queue>
using namespace std;

int main()
{
  priority_queue<int> maxheap;
  maxheap.push(2);
  maxheap.push(3);
  maxheap.push(4);
  maxheap.push(5);

  cout << "Top of max heap: " << maxheap.top() << endl;
  maxheap.pop();
  cout << "Top of max heap: " << maxheap.top() << endl;
  cout << "Size of max heap: " << maxheap.size() << endl;
  cout << "Is max heap empty: " << maxheap.empty() << endl;

  priority_queue<int, vector<int>, greater<int>> minheap;
  minheap.push(2);
  minheap.push(3);
  minheap.push(4);
  minheap.push(5);

  cout << "Top of min heap: " << minheap.top() << endl;
  minheap.pop();
  cout << "Top of min heap: " << minheap.top() << endl;
  cout << "Size of min heap: " << minheap.size() << endl;
  cout << "Is min heap empty: " << minheap.empty() << endl;
  return 0;
}