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

vector<int> find_intersection1(vector<int> arr1, vector<int> arr2)
{
  vector<int> res;
  for (int i = 0; i < arr1.size(); i++)
  {
    int element = arr1[i];
    for (int j = 0; j < arr2.size(); j++)
    {
      if (element == arr2[j])
      {
        res.push_back(element);
        arr2[j] = INT_MIN;
        break;
      }
    }
  }

  return res;
}

vector<int> find_intersection2(vector<int> arr1, vector<int> arr2)
{
  vector<int> res;
  int i = 0, j = 0;

  while (i < arr1.size() && j < arr2.size())
  {
    if (arr1[i] == arr2[j])
    {
      res.push_back(arr1[i]);
      i++;
      j++;
    }
    else if (arr1[i] < arr2[j])
    {
      i++;
    }
    else
    {
      j++;
    }
  }

  return res;
}

int main()
{
  vector<int> arr1 = {1, 2, 2, 2, 3, 4};
  vector<int> arr2 = {2, 2, 3, 3};
  vector<int> res;

  cout << "Intersection of two Array (Brute Force): ";
  res = find_intersection1(arr1, arr2);
  print_array(res);

  cout << "Intersection of two Array (Optimized): ";
  res = find_intersection2(arr1, arr2);
  print_array(res);

  return 0;
}