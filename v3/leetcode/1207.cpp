/*

1207. Unique Number of Occurrences

Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false

*/

#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

void print_array(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  vector<int> arr = {1, 2, 2, 1, 1, 3};
  map<int, int> mp;
  for (int i = 0; i < arr.size(); i++)
  {
    mp[arr[i]]++;
  }

  for (auto it : mp)
  {
    cout << it.first << "---->" << it.second << endl;
  }

  set<int> st;
  for (auto it : mp)
  {
    st.insert(it.second);
  }

  cout << "Size of map: " << mp.size() << endl;
  cout << "Size of set: " << st.size() << endl;

  if (mp.size() == st.size())
  {
    cout << "True" << endl;
  }
  else
  {
    cout << "False" << endl;
  }

  return 0;
}