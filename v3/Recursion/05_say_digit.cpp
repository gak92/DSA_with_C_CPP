#include <iostream>
using namespace std;

void sayDigit(int num, string arr[])
{
  // base case
  if (num == 0)
    return;

  // processing
  int digit = num % 10;
  num = num / 10;

  // recursive relation
  sayDigit(num, arr);

  cout << arr[digit] << " ";
}

int main()
{
  string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  int num;

  cout << "Enter digit: ";
  cin >> num;

  cout << endl;
  sayDigit(num, arr);
  cout << endl;

  return 0;
}