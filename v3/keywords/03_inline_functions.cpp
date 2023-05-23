#include <iostream>
using namespace std;

// Inline functions - Used to reduce the function calls overhead
inline int getMax(int a, int b)
{
  return (a > b) ? a : b;
}

int main()
{
  int a = 1, b = 2;
  int res = 0;

  res = getMax(a, b);
  cout << "Max is: " << res << endl;

  a += 11;
  b += 7;

  res = getMax(a, b);
  cout << "Max is: " << res << endl;

  return 0;
}