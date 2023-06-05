//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    queue<int> q;
    int n, var;
    cin >> n;
    while (n--)
    {
      cin >> var;
      q.push(var);
    }
    queue<int> a = rev(q);
    while (!a.empty())
    {
      cout << a.front() << " ";
      a.pop();
    }
    cout << endl;
  }
}
// } Driver Code Ends

// function Template for C++

// Function to reverse the queue.

void reverseQ(queue<int> &q)
{
  if (q.empty())
    return;

  int element = q.front();
  q.pop();
  reverseQ(q);
  q.push(element);
}

queue<int> rev(queue<int> q)
{
  // add code here.
  // Solution # 2 - using recursion
  reverseQ(q);
  return q;

  // Solution # 1 - using stack
  // stack<int> s;

  // while(!q.empty())
  // {
  //     s.push(q.front());
  //     q.pop();
  // }

  // while(!s.empty())
  // {
  //     q.push(s.top() );
  //     s.pop();
  // }

  // return q;
}