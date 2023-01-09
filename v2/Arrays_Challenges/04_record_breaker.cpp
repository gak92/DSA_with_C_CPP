#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Recor Breaker

Isyana is given the number of visitors at her local theme park on N consecutive
days. The number of visitors on the i-th day is Vi.

A day is record breaking if it satisfies both of the following conditions:
● The number of visitors on the day is strictly larger than the number of
  visitors on each of the previous days.
● Either it is the last day, or the number of visitors on the day is strictly larger
  than the number of visitors on the following day.

Note that the very first day could be a record breaking day!
Please help Isyana find out the number of record breaking days.

Enter the size of the array: 8
Enter the element of the array: 1 2 0 7 2 0 2 2
Total number of record breaking day: 2

*/

int main()
{
  int size;
  cout << "Enter the size of the array: ";
  cin >> size;

  int arr[size+1];
  cout << "Enter the element of the array: ";
  for(int i=0; i<size; i++)
  {
    cin >> arr[i];
  }

  arr[size] = -1;
  if(size == 1)
  {
    cout << "1" << endl;
    return 0;
  }

  int res = 0;
  int maximum = -1;

  for(int i=0; i<size; i++)
  {
    if(arr[i] > maximum && arr[i] > arr[i+1])
    {
      res++;
    }
    maximum = max(maximum, arr[i]);
  }

  cout << "Total number of record breaking day: " << res << endl;

  return 0;
}