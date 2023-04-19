#include <iostream>
using namespace std;

int main()
{
  int amount;
  cout << "Enter amount: ";
  cin >> amount;

  switch (1)
  {
  case 1:
    cout << "No. of hundred rupee notes: " << amount / 100 << endl;
    amount = amount % 100;

  case 2:
    cout << "No. of fifty rupee notes: " << amount / 50 << endl;
    amount = amount % 50;

  case 3:
    cout << "No. of twenty rupee notes: " << amount / 20 << endl;
    amount = amount % 20;

  case 4:
    cout << "No. of one rupee notes: " << amount / 1 << endl;
    amount = amount % 1;

  default:
    break;
  }

  return 0;
}