/*
https://leetcode.com/problems/count-and-say/description/
*/
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string countAndSay(int n)
  {
    if (n == 1)
      return "1";

    string say = countAndSay(n - 1);

    // processing
    string res = "";
    for (int i = 0; i < say.length(); i++)
    {
      char ch = say[i];
      int count = 1;
      while (i < say.length() - 1 && say[i] == say[i + 1])
      {
        count++;
        i++;
      }
      res += to_string(count) + string(1, ch);
    }

    return res;
  }
};

int main()
{
  Solution s;
  string res = s.countAndSay(4);
  cout << res << endl;
  return 0;
}