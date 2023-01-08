#include<iostream>
#include<functional>
#include<string>
using namespace std;

/*
Function Object (Functor)
  function wrapped in a class so that it available like an object
*/

int main()
{
  int arr[] = {11, 4, 99, 92, 71, 41, 27, 21};
  // sort(arr, arr+8);
  sort(arr, arr+8, greater<int>());

  for(int i=0; i<8; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}