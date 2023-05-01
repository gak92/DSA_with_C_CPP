/*
125. Valid Palindrome
Easy
6.6K
6.9K
Companies
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.



Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/

#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

char toLowerCase(char ch)
{
  if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
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
  string temp;
  for (int i = 0; i < s.length(); i++)
  {
    if (isAlphaNumeric(s[i]))
    {
      temp.push_back(s[i]);
    }
  }

  int start = 0;
  int end = temp.size() - 1;

  while (start <= end)
  {
    if (toLowerCase(temp[start]) != toLowerCase(temp[end]))
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
  cout << "A man, a plan, a canal: Panama ---> " << checkPalindrome("A man, a plan, a canal: Panama") << endl;
  cout << "race a car ----> " << checkPalindrome("race a car") << endl;

  return 0;
}