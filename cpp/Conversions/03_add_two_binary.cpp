#include<iostream>
using namespace std;

int reverse(int n)
{
  int res=0;
  while(n > 0)
  {
    int lastdigit = n % 10;
    res = res * 10 + lastdigit;
    n /= 10;
  }
  return res;
}

int addBinary(int bin1, int bin2)
{
  int res = 0;
  int prevCarry = 0;

  while(bin1 > 0 && bin2 > 0)
  {
    // case 1
    if(bin1%2 == 0 && bin2%2 == 0)
    {
      res = res * 10 + prevCarry;
      prevCarry = 0;
    }
    // case 2
    else if((bin1%2 == 0 && bin2%2 == 1) || (bin1%2 == 1 && bin2%2 == 0))
    {
      if(prevCarry = 1)
      {
        res = res * 10 + 0;
        prevCarry = 1;
      }
      else
      {
        res = res * 10 + 1;
        prevCarry = 0;
      }
    }
    // case 3
    else
    {
      res = res * 10 + prevCarry;
      prevCarry = 1;
    }
    bin1 /= 10;
    bin2 /= 10;
  }

  while(bin1 > 0)
  {
    if(prevCarry == 1)
    {
      if(bin1%2 == 1)
      {
        res = res * 10 + 0;
        prevCarry = 1;
      }
      else
      {
        res = res * 10 + 1;
        prevCarry = 0;
      }
    }
    else
      res = res * 10 + (bin1%2);
    bin1 /= 10;
  }

  while(bin2 > 0)
  {
    if(prevCarry == 1)
    {
      if(bin2%2 == 1)
      {
        res = res * 10 + 0;
        prevCarry = 1;
      }
      else
      {
        res = res * 10 + 1;
        prevCarry = 0;
      }
    }
    else
      res = res * 10 + (bin2%2);
    bin2 /= 10;
  }

  if(prevCarry == 1)
    res = res * 10 + 1;

  res = reverse(res);
  return res;
}

int main()
{
  int bin1, bin2;
  cout << "Enter first binary: ";
  cin >> bin1;

  cout << "Enter second binary: ";
  cin >> bin2;

  cout << "Addition of two binary: " << addBinary(bin1, bin2);

  return 0;
}