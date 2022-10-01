#include <iostream>
using namespace std;

int main()
{

  int num = 5;
  // cin >> num;

  // Inverted Half Pyramid
  for (int i = 0; i < num; i++)
  {
    for (int j = num - i; j > 0; j--)
    {
      cout << "*";
    }
    cout << "\n";
  }

  return 0;
}
