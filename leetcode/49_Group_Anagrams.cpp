/*
https://leetcode.com/problems/group-anagrams/description/

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> hashmap;

    for (int i = 0; i < strs.size(); i++)
    {
      string s = strs[i];
      sort(s.begin(), s.end());
      hashmap[s].push_back(strs[i]);
    }

    for (const auto &pair : hashmap)
    {
      res.push_back(pair.second);
    }

    for (const auto &strgroup : res)
    {
      for (const auto &s : strgroup)
      {
        cout << s << ", ";
      }
      cout << endl;
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  s.groupAnagrams(strs);
  return 0;
}