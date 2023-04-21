#include <iostream>
#include <climits>
#include <vector>
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
  int s = 5;
  vector<int> arr = {1, 2, 3, 4, 5};
  vector<vector<int>> res;

  for (int i = 0; i < arr.size(); i++)
  {
    for (int j = i + 1; j < arr.size(); j++)
    {
      if (arr[i] + arr[j] == s)
      {
        vector<int> temp;
        temp.push_back(min(arr[i], arr[j]));
        temp.push_back(max(arr[i], arr[j]));
        res.push_back(temp);
      }
    }
  }

  for (int i = 0; i < res.size(); i++)
  {
    print_array(res[i]);
  }

  return 0;
}