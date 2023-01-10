#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
First Missing Element

Find the smallest positive missing number in the given array.
Example: [0, -10, 1, 3, -20], Ans = 2.

Enter the size of the array: 6
Enter the element of the array: 0 -9 1 3 -4 5
First Missing Element: 2

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

  const int N = 1e6 + 2;
  bool check[N];
  for(int i=0; i<N; i++)
  {
    check[i] = false;
  }


  for(int i=0; i<size; i++)
  {
    if(arr[i] > 0)
    {
      check[arr[i]] = true;
    }
  }
  
  int firstMissing = -1;
  for(int i=1; i<N; i++)
  {
    if(check[i] == false)
    {
      firstMissing = i;
      break;
    }
  }

  cout << "First Missing Element: " << firstMissing << endl;

  return 0;
}