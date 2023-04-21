#include <iostream>
using namespace std;

/*
  a ^ a = 0 (XOR any number with itself return 0)
  0 ^ a = a (XOR any number with zero return that number)
*/

int find_uniq(int arr[], int size)
{
  int res = 0;
  for (int i = 0; i < size; i++)
  {
    res = res ^ arr[i];
  }
  return res;
}

int main()
{
  int arr[7] = {6, 2, 3, 3, 2, 1, 1};

  cout << "Uniq element in an array: " << find_uniq(arr, 7) << endl;

  return 0;
}