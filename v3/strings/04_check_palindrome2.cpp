#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

char toLowerCase(char ch)
{
  if (ch >= 'a' && ch <= 'z')
  {
    return ch;
  }
  return ch - 'A' + 'a';
}

bool isAlphaNumeric(char ch)
{
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
  {
    return true;
  }
  return false;
}

bool checkPalindrome(string s)
{
  int start = 0;
  int end = s.size() - 1;

  while (start <= end)
  {
    while (!isAlphaNumeric(s[start]))
    {
      start++;
    }
    while (!isAlphaNumeric(s[end]))
    {
      end--;
    }

    if (toLowerCase(s[start]) != toLowerCase(s[end]))
    {
      return false;
    }
    start++;
    end--;
  }
  return true;
}

int main()
{
  string s = "f";

  cout << "f ----> " << checkPalindrome(s) << endl;
  cout << "@ ----> " << checkPalindrome("@") << endl;

  return 0;
}