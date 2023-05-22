#include <iostream>
using namespace std;

int main()
{

  int arr[5] = {1, 2, 3, 4, 5};
  char ch[5] = "abcd";

  // Integer array print address while char array print entire string
  cout << "integer arr: " << arr << endl;
  cout << "Char arr: " << ch << endl;

  int *ptr = &arr[0];
  cout << "ptr ----> " << ptr << endl;

  char *chr = &ch[0];
  cout << "chr ----> " << chr << endl;

  // if not null character then it will print afterword unless found null character
  char temp = 'z';
  char *c = &temp;
  cout << "temp ---> " << temp << endl;
  cout << "temp ---> " << c << endl;

  return 0;
}