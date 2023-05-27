/*
  https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printSubsequences(vector<string> v)
{
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << ", ";
  }
}

void subsequences(string str, int index, string output, vector<string> &res)
{
  if (index >= str.length())
  {
    if (output.length() > 0)
      res.push_back(output);
    return;
  }

  subsequences(str, index + 1, output, res);
  output.push_back(str[index]);
  subsequences(str, index + 1, output, res);
}

int main()
{
  string str = "abc";

  vector<string> res;
  int index = 0;
  string output = "";

  subsequences(str, index, output, res);
  printSubsequences(res);

  return 0;
}