#include <iostream>
using namespace std;

//     1 
//    1 2 
//   1 2 3 
//  1 2 3 4 
// 1 2 3 4 5 

int main()
{
  int num = 5;

  for (int i = 1; i <= num; i++)
  {
    for (int k = 1; k <= num - i; k++)
    {
      cout << " ";
    }
    for (int j = 1; j <= i; j++)
    {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}