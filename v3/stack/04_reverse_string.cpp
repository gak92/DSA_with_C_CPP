#include <iostream>
#include <stack>
using namespace std;

int main()
{
  string str = "coding";
  stack<char> st;

  for (int i = 0; i < str.length(); i++)
  {
    st.push(str[i]);
  }

  string res = "";
  while (!st.empty())
  {
    res.push_back(st.top());
    st.pop();
  }

  cout << "Reverse of string is: " << res << endl;

  return 0;
}