#include <iostream>
using namespace std;

int update(int **p2)
{
  // No change
  // p2 = p2 + 1;

  // Yes - change the value of p
  // *p2 = *p2 + 1;

  // Yes - change the value
  **p2 = **p2 + 1;
}

int main()
{
  int i = 5;
  int *p = &i;
  int **p2 = &p;

  // value of i
  cout << "value of i:  " << i << endl;
  cout << "value of i:  " << *p << endl;
  cout << "value of i:  " << **p2 << endl;

  // addres of i
  cout << "Address of i:  " << &i << endl;
  cout << "Address of i:  " << p << endl;
  cout << "Address of i:  " << *p2 << endl;

  // address of p
  cout << "Address of p:  " << &p << endl;
  cout << "Address of p:  " << p2 << endl;

  // address of p2
  cout << "Address of p2:  " << &p2 << endl;

  cout << "\nBefore change: " << endl;
  cout << "i ---> " << i << endl;
  cout << "p ---> " << p << endl;
  cout << "p2 ---> " << p2 << endl;

  update(p2);

  cout << "\nAfter change: " << endl;
  cout << "i ---> " << i << endl;
  cout << "p ---> " << p << endl;
  cout << "p2 ---> " << p2 << endl;

  return 0;
}