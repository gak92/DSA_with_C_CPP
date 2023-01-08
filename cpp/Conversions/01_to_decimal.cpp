#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binaryToDecimal(int n)
{
  int res = 0;
  int lastdigit;
  int base = 1;

  while(n > 0)
  {
    lastdigit = n %10;
    res += base * lastdigit;
    base *= 2;
    n /= 10;
  }

  return res;
}

int octaToDecimal(int n)
{
  int res = 0;
  int lastdigit;
  int base = 1;

  while(n > 0)
  {
    lastdigit = n %10;
    res += base * lastdigit;
    base *= 8;
    n /= 10;
  }

  return res;
}

int hexaToDecimal(string s)
{
  int res = 0;
  int base = 1;
  int size = s.size();
  
  for(int i=size-1; i>=0; i--)
  {
    if(s[i] >= '0' && s[i] <= '9')
      res += base * (s[i] - '0');
    else if(s[i] >= 'A' && s[i] <= 'F')
      res += base * (s[i] - 'A' + 10);

    base *= 16;
  }

  return res;
}

int main()
{
  int n;
  cout << "Enter a binary number: ";
  cin >> n;
  cout << "Decimal is: " << binaryToDecimal(n) << endl;

  cout << "Enter a octa number: ";
  cin >> n;
  cout << "Decimal is: " << octaToDecimal(n) << endl;

  string s;
  cout << "Enter a hexadecimal number: ";
  cin >> s;
  cout << "HexaDecimal is: " << hexaToDecimal(s) << endl;

  return 0;
}