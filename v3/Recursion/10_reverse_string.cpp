#include <iostream>
using namespace std;

void reverseString(string &str, int start, int end)
{
  // base case
  if (start > end)
    return;

  swap(str[start], str[end]);
  start++;
  end--;

  // recursive call
  reverseString(str, start, end);
}

int main()
{
  string str = "Something";

  reverseString(str, 0, str.length() - 1);

  cout << "Reverse of string: " << str << endl;

  return 0;
}