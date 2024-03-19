/*
https://leetcode.com/problems/power-of-four/description/
*/

#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isPowerOfFour(int n)
  {

    while (n >= 4)
    {
      if ((n % 4) != 0)
        return false;
      n = n / 4;
    }

    return (n == 1);
  }
};

int main()
{
  Solution s;
  cout << s.isPowerOfFour(16) << endl;
  cout << s.isPowerOfFour(5) << endl;

  return 0;
}