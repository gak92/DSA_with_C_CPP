/*
231. Power of Two
https://leetcode.com/problems/power-of-two/description/

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.


Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false


Constraints:

-231 <= n <= 231 - 1
*/

/*
Enter n: 4096
4096 is Power of 2: 1
4096 is Power of 2 (Second Approach): 1
*/

#include <iostream>
#include <math.h>
#include <climits>
using namespace std;

bool isPowerOf2(int);
bool isPowerOf2_2(int);

int main()
{
  int n;
  cout << "Enter n: ";
  cin >> n;

  cout << n << " is Power of 2: " << isPowerOf2(n) << endl;
  cout << n << " is Power of 2 (Second Approach): " << isPowerOf2_2(n) << endl;

  return 0;
}

bool isPowerOf2(int n)
{
  for (int i = 0; i <= 30; i++)
  {
    if (n == pow(2, i))
    {
      return true;
    }
  }

  return false;
}

bool isPowerOf2_2(int n)
{
  int ans = 1;
  for (int i = 0; i <= 30; i++)
  {
    if (ans == n)
    {
      return true;
    }
    if (ans < INT_MAX / 2)
    {
      ans = ans * 2;
    }
  }
  return false;
}

// Solution # 02
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n > 0)
        {
            if( (n & (n - 1)) == 0)
                return true;
        }

        return false;
    }
};

