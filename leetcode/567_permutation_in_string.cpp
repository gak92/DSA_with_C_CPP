/*
567. Permutation in String
Medium
9.7K
311
Companies
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.



Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkEqual(int a[26], int b[26])
{
  for (int i = 0; i < 26; i++)
  {
    if (a[i] != b[i])
      return 0;
  }
  return 1;
}

bool checkInclusion(string s1, string s2)
{
  int count1[26] = {0};
  for (int i = 0; i < s1.length(); i++)
  {
    int index = s1[i] - 'a';
    count1[index]++;
    // cout << i << endl;
  }

  int count2[26] = {0};
  int windowSize = s1.length();
  int i = 0;

  // check for first window
  while (i < windowSize && i < s2.length())
  {
    int index = s2[i] - 'a';
    count2[index]++;
    i++;
  }
  if (checkEqual(count1, count2))
  {
    return true;
  }

  while (i < s2.length())
  {
    char newChar = s2[i];
    int index = newChar - 'a';
    count2[index]++;

    char oldChar = s2[i - windowSize];
    index = oldChar - 'a';
    count2[index]--;

    i++;
    // cout << i << endl;
    if (checkEqual(count1, count2))
    {
      return true;
    }
  }

  return false;
}

int main()
{

  // string s1 = "ab";
  // string s2 = "eidbaooo";

  string s1 = "ab";
  string s2 = "eidboaoo";

  cout
      << "Answer: " << endl;
  if (checkInclusion(s1, s2))
  {
    cout << "S1 is the permutation of S2" << endl;
  }
  else
  {
    cout << "S1 is not the permutation of S2" << endl;
  }

  return 0;
}