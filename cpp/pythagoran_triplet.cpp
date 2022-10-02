#include <iostream>
using namespace std;

bool is_pythagorian_triplet(int x, int y, int z)
{
  int a = max(x, max(y, z));
  int b, c;

  if (a == x)
  {
    b = y;
    c = z;
  }
  else if (a == y)
  {
    b = x;
    c = z;
  }
  else
  {
    b = x;
    c = y;
  }

  if (a * a == b * b + c * c)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  int x = 3, y = 4, z = 5;

  if (is_pythagorian_triplet(x, y, z))
  {
    cout << "Pythagorian triplet";
  }
  else
  {
    cout << "Not a Pythagorian triplet";
  }

  return 0;
}