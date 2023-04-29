#include <iostream>
#include <stack>
using namespace std;

int main()
{
  stack<string> s;

  s.push("I");
  s.push("love");
  s.push("coding");

  cout << "Size of Stack: " << s.size() << endl;
  cout << "Is stack empty: " << s.empty() << endl;

  cout << "Top element at stack: " << s.top() << endl;
  s.pop();
  cout << "Top element at stack: " << s.top() << endl;

  return 0;
}