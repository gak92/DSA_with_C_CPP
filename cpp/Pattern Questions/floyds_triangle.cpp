#include <iostream>
using namespace std;

int main()
{
  int num = 5;
  int count = 1;

  for (int i = 1; i <= num; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << count << " ";
      count++;
    }
    cout << endl;
  }

  return 0;
}