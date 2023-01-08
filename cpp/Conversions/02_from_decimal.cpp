#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int decimalToBinary(int n)
{
  int res = 0;
  int base = 1;
  int lastdigit;

  while(base <= n)
    base *= 2;
  base /=2;

  while(base > 0)
  {
    lastdigit = n / base;
    n -= lastdigit * base;
    base /= 2;
    res = res * 10 + lastdigit;
  }

  return res;
}

int decimalToOctal(int n)
{
  int res = 0;
  int base = 1;
  int lastdigit;

  while(base <= n)
    base *= 8;
  base /=8;

  while(base > 0)
  {
    lastdigit = n / base;
    n -= lastdigit * base;
    base /= 8;
    res = res * 10 + lastdigit;
  }

  return res;
}

string decimalTohexa(int n)
{
  int base = 1;
  string res = "";
  int lastdigit;

  while(base <= n)
    base *= 16;
  base /=16;

  while(base > 0)
  {
    lastdigit = n / base;
    n -= lastdigit * base;
    base /= 16;

    if(lastdigit <= 9)
      res = res + to_string(lastdigit);
    else
    {
      char c = 'A' + lastdigit -10;
      res.push_back(c);
    }
  }

  return res;
}

int main()
{
  int n;
  cout << "Enter a decimal number: ";
  cin >> n;
  cout << "Binary is: " << decimalToBinary(n) << endl;

  cout << "Enter a decimal number: ";
  cin >> n;
  cout << "Octal is: " << decimalToOctal(n) << endl;

  cout << "Enter a decimal number: ";
  cin >> n;
  cout << "HexaDecimal is: " << decimalTohexa(n) << endl;

  return 0;
}