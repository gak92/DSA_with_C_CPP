/*
  Maximum Occurring character
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char getMaxOccurCharacter(string s)
{
  int arr[26] = {0};
  for (int i = 0; i < s.length(); i++)
  {
    char ch = s[i];
    int index = 0;
    if (ch >= 'a' && ch <= 'z')
    {
      index = ch - 'a';
    }
    else
    {
      index = ch - 'A';
    }
    arr[index]++;
  }

  int max = -1, res = 0;

  for (int i = 0; i < 26; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
      res = i;
    }
  }
  return 'a' + res;
}

int main()
{
  string s;
  cout << "Enter string: ";
  cin >> s;

  cout << "Maximum occurring character is: " << getMaxOccurCharacter(s) << endl;

  return 0;
}