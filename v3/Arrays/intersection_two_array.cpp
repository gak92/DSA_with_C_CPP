#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main()
{
  vector<int> arr1 = {1, 2, 2, 2, 3, 4};
  vector<int> arr2 = {2, 2, 3, 3};
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

  cout << "Intersection of two Array: ";
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
  cout << endl;

  return 0;
}