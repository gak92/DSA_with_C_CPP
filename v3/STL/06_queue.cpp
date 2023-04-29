#include <iostream>
#include <queue>
using namespace std;

int main()
{
  queue<string> q;

  q.push("I");
  q.push("love");
  q.push("coding");

  cout << "Size of Queue: " << q.size() << endl;
  cout << "Is Queue empty: " << q.empty() << endl;

  cout << "First element at queue: " << q.front() << endl;
  q.pop();
  cout << "First element at queue: " << q.front() << endl;

  return 0;
}