#include<iostream>
using namespace std;

template <class T1, class T2>
float average(T1 a, T2 b)
{
  float avg;
  avg = (a+b) / 2.0;

  return avg;
} 

int main()
{
  float res;
  res = average(5,2);
  cout << "Result is: " << res << endl;

  res = average(5.7,2.4);
  cout << "Result is: " << res << endl;

  return 0;
}
