#include <iostream>
using namespace std;

int main()
{
  int col = 27;
  int row = 3;

  for (int i = 1; i <= row; i++)
  {
    for (int j = 1; j <= col; j++)
    {
      if ((i + j) % 4 == 0 || (i == 2 && j % 4 == 0))
      {
        cout << "* ";
      }
      else
      {
        cout << "  ";
      }
    }
    cout << endl;
  }
  return 0;
}