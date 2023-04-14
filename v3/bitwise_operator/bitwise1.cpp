#include <iostream>
using namespace std;

int main()
{
  int a = 4;
  int b = 6;

  cout << "a&b: " << (a & b) << endl;
  /*
    4 =>    1 0 0
    6 =>    1 1 0
    & =>    1 0 0   ====> 4
  */

  cout << "a|b: " << (a | b) << endl;
  /*
    4 =>    1 0 0
    6 =>    1 1 0
    | =>    1 1 0   ====> 6
  */

  cout << "~b: " << (~a) << endl;
  /*
    4     =>    1 0 0
                0 0 .... 1 0 0
    ~     =>    1 1 .... 0 1 1

    TO PRINT ~a:
    1's   =>    1(-ve) 0 ...  1 0 0
    2's   =>           0 ...  1 0 1
    Hence, -5 will be print
  */
  cout << "a^b: " << (a ^ b) << endl;
  /*
    4 =>    1 0 0
    6 =>    1 1 0
    ^ =>    0 1 0   ====> 2
  */

  return 0;
}