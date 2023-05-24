#include <iostream>
using namespace std;

bool checkPalindrome(string &str, int start, int end)
{
  // base case
  if (start > end)
    return true;

  if (str[start] != str[end])
    return false;
  else
    return checkPalindrome(str, start + 1, end - 1);
}

int main()
{
  string str = "abbcacbba";

  bool res = checkPalindrome(str, 0, str.length() - 1);

  if (res)
  {
    cout << "Yes, It's a palindrome" << endl;
  }
  else
  {
    cout << "No, It's not a palindrome" << endl;
  }

  return 0;
}