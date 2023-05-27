/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

17. Letter Combinations of a Phone Number
Medium
15.1K
842
Companies
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVectorString(vector<string> v)
{
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << ", ";
  }
  cout << endl;
}

void combinations(string digits, string mappings[], int index, string output, vector<string> &res)
{
  if (index >= digits.length())
  {
    res.push_back(output);
    return;
  }

  int number = digits[index] - '0';
  string str = mappings[number];

  for (int i = 0; i < str.length(); i++)
  {
    output.push_back(str[i]);
    combinations(digits, mappings, index + 1, output, res);
    output.pop_back();
  }
}

int main()
{
  string digits = "23";

  string mappings[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

  int index = 0;
  string output = "";
  vector<string> res;

  combinations(digits, mappings, index, output, res);

  printVectorString(res);

  return 0;
}
