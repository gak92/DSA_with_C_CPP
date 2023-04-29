#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> v = {1, 7, 11, 19, 27, 41, 92, 99};

  cout << "Finding 70: " << binary_search(v.begin(), v.end(), 70) << endl;
  cout << "Finding 92: " << binary_search(v.begin(), v.end(), 92) << endl;

  cout << "Lower Bound: " << lower_bound(v.begin(), v.end(), 41) - v.begin() << endl;
  cout << "Upper Bound: " << upper_bound(v.begin(), v.end(), 41) - v.begin() << endl;

  int a = 5;
  int b = 6;
  cout << "a and b: " << a << " " << b << endl;
  cout << "Max of a and b: " << max(a, b) << endl;
  cout << "Min of a and b: " << min(a, b) << endl;
  swap(a, b);
  cout << "After swap a and b: " << a << " " << b << endl;

  // Reverse String
  string str = "abcde";
  reverse(str.begin(), str.end());
  cout << "Reverse string: " << str << endl;

  // Rotate
  vector<int> v2 = {1, 3, 6, 7};
  rotate(v2.begin(), v2.begin() + 1, v2.end());
  cout << "After rotate: ";
  for (auto ele : v2)
  {
    cout << ele << " ";
  }
  cout << endl;

  // Sorting (used combination of Quick sort, heap sort, insertion sort)
  sort(v2.begin(), v2.end());
  cout << "After Sorting";
  for (auto ele : v2)
  {
    cout << ele << " ";
  }
  cout << endl;

  return 0;
}