#include <bits/stdc++.h>
using namespace std;

void interleaveQueue(queue<int> &q)
{
  stack<int> st;
  int half = q.size() / 2;
  cout << "Half: " << half << endl;

  // get 1st half of queue in stack
  for (int j = 0; j < half; j++)
  {
    st.push(q.front());
    q.pop();
  }

  // push back stack at the end of queue
  while (!st.empty())
  {
    q.push(st.top());
    st.pop();
  }

  // now getting 1st half again at start
  for (int j = 0; j < half; j++)
  {
    q.push(q.front());
    q.pop();
  }

  // push back 1st half again into stack
  for (int j = 0; j < half; j++)
  {
    st.push(q.front());
    q.pop();
  }

  while (!st.empty())
  {
    q.push(st.top());
    st.pop();
    q.push(q.front());
    q.pop();
  }
}

void printQ(queue<int> q)
{
  int length = q.size();
  for (int j = 0; j < length; j++)
  {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}

int main()
{

  queue<int> q;
  q.push(11);
  q.push(12);
  q.push(13);
  q.push(14);
  q.push(15);
  q.push(16);
  q.push(17);
  q.push(18);
  q.push(19);
  q.push(20);

  cout << "before: ";
  printQ(q);

  interleaveQueue(q);
  cout << "after: ";
  printQ(q);

  return 0;
}