/*
509. Fibonacci Number
Easy
6.7K
314
Companies
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).



Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
*/

#include <iostream>
using namespace std;

int fibbonacci(int num)
{
  if (num == 0)
    return 0;
  if (num == 1)
    return 1;

  return fibbonacci(num - 1) + fibbonacci(num - 2);
}

int main()
{

  int num;
  cout << "Enter number to find fibbonacci number: ";
  cin >> num;

  int res = fibbonacci(num);
  cout << "Fibbonacci number is: " << res << endl;

  return 0;
}
