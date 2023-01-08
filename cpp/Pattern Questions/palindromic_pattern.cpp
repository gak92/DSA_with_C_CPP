#include <iostream>
using namespace std;

//         1 
//       2 1 2 
//     3 2 1 2 3 
//   4 3 2 1 2 3 4 
// 5 4 3 2 1 2 3 4 5 

int main()
{
  int num = 5;

  for (int i = 1; i <= num; i++)
  {
    for (int k = 1; k <= (num - i) * 2; k++)
    {
      cout << " ";
    }
    for (int j = i; j >= 1; j--)
    {
      cout << j << " ";
    }
    for (int j = 2; j <= i; j++)
    {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}