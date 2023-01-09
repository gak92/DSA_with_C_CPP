#include<iostream>
#include<climits>
using namespace std;

/*
Maximum Till ith index

Enter the size of the array: 6
Enter the element of the array: 0 -9 1 3 -4 5
Maximum till index 0 is: 0
Maximum till index 1 is: 0
Maximum till index 2 is: 1
Maximum till index 3 is: 3
Maximum till index 4 is: 3
Maximum till index 5 is: 5
*/

int main()
{
  int size;
  cout << "Enter the size of the array: ";
  cin >> size;

  int arr[size];
  cout << "Enter the element of the array: ";
  for(int i=0; i<size; i++)
  {
    cin >> arr[i];
  }

  int maximum = INT_MIN;
  for(int i=0; i<size; i++)
  {
    maximum = max(maximum, arr[i]);
    cout << "Maximum till index " << i << " is: " << maximum << endl;
  }

  return 0;
}