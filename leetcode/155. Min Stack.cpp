/*

https://leetcode.com/problems/min-stack/description/
*/

#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
  stack<int> originalStack;
  stack<int> minStack;

public:
  MinStack()
  {
  }

  void push(int val)
  {
    if (minStack.empty() || val <= minStack.top())
      minStack.push(val);
    originalStack.push(val);
  }

  void pop()
  {
    if (originalStack.top() == minStack.top())
      minStack.pop();
    originalStack.pop();
  }

  int top()
  {
    return originalStack.top();
  }

  int getMin()
  {
    return minStack.top();
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
  MinStack *obj = new MinStack();
  obj->push(-2);
  obj->push(0);
  obj->push(-3);
  cout << obj->getMin() << endl; // return -3
  obj->pop();
  cout << obj->top() << endl;    // return 0
  cout << obj->getMin() << endl; // return -2
  return 0;
}
