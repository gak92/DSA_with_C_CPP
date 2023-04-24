#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
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
  int K = 12;
  vector<int> arr = {10, 5, 5, 5, 2};
  sort(arr.begin(), arr.end());
  int n = arr.size();
  cout << "Size of an array: " << n << endl;

  vector<vector<int>> res;

  for (int i = 0; i < n - 2; i++)
  {
    if (arr[i] != arr[i - 1] || arr[i - 1] != arr[i - 2])
    {
      for (int j = i + 1; j < n - 1; j++)
      {
        if (arr[j] != arr[j - 1])
        {

          for (int k = j + 1; k < n; k++)
          {
            // if (arr[k] != arr[k - 1])
            // {

            if (arr[i] + arr[j] + arr[k] == K)
            {
              vector<int> temp;
              temp.push_back(arr[i]);
              temp.push_back(arr[j]);
              temp.push_back(arr[k]);
              res.push_back(temp);
              // cout << "3Sum is: " << arr[i] << " " << arr[j] << " " << arr[k] << endl;
            }
            // }
          }
        }
      }
    }
  }

  for (int i = 0; i < res.size(); i++)
  {
    print_array(res[i]);
  }

  return 0;
}