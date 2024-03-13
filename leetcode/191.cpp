/*
191. Number of 1 Bits

Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.


Example 1:

Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
*/

#include <iostream>
using namespace std;

int main()
{

  uint32_t n;
  cout << "Enter n: ";
  cin >> n;

  int count = 0;

  while (n != 0)
  {
    if (n & 1)
    {
      count++;
    }
    n = n >> 1;
  }

  cout << "Number of 1 bits: " << count << endl;

  return 0;
}