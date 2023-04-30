/*
344. Reverse String
Easy
7.2K
1.1K
Companies
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.



Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<char> reverseString(vector<char> s)
{
  int start = 0;
  int end = s.size() - 1;

  while (start <= end)
  {
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    start++;
    end--;
  }

  return s;
}
int main()
{
  // vector<char> s{"h", "e", "l", "l", "o"};
  vector<char> s{'h', 'e', 'l', 'l', 'o'};

  vector<char> reverse = reverseString(s);

  for (int i = 0; i < reverse.size(); i++)
  {
    cout << reverse[i] << " ";
  }

  cout << endl;

  return 0;
}