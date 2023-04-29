#include <iostream>
#include <array>
using namespace std;

int main()
{
  int basic[3] = {1, 2, 3};
  array<int, 4> arr = {11, 12, 13, 14};

  int size = arr.size();
  cout << "Array elements: ";
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  cout << "Element at 2nd index: " << arr.at(2) << endl;

  cout << "Array empty or not: " << arr.empty() << endl;
  cout << "First element: " << arr.front() << endl;
  cout << "Last element: " << arr.back() << endl;

  return 0;
}