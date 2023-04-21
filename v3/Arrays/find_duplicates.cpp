#include <iostream>
using namespace std;

/*

*/

int find_duplicate(int arr[], int size)
{
  int res = 0;
  // XOR all elements in an array
  for (int i = 0; i < size; i++)
  {
    res = res ^ arr[i];
  }

  // XOR 1 to n-1
  for (int i = 1; i < size; i++)
  {
    res = res ^ i;
  }
  return res;
}

/*
Duplicate element in an array: 2
Duplicate element in an array: 7
*/

int main()
{
  int arr[6] = {5, 1, 2, 3, 4, 2};
  int brr[9] = {8, 7, 2, 5, 4, 7, 1, 3, 6};

  cout << "Duplicate element in an array: " << find_duplicate(arr, 6) << endl;
  cout << "Duplicate element in an array: " << find_duplicate(brr, 9) << endl;

  return 0;
}