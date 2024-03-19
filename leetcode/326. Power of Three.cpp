/*
https://leetcode.com/problems/power-of-three/description/
*/

#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isPowerOfThree(int n)
  {

    while (n >= 3)
    {
      if (n % 3 != 0)
        return false;
      n = n / 3;
    }

    return (n == 1);
  }
};

int main()
{
  Solution s;
  cout << s.isPowerOfThree(27) << endl;
  cout << s.isPowerOfThree(0) << endl;

  return 0;
}
