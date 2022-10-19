#include <iostream>
using namespace std;

class BankDeposit
{
  int principalAmount;
  int years;
  float interestRate;
  float returnAmount;

public:
  BankDeposit() {}
  BankDeposit(int p, int y, float r)
  {
    principalAmount = p;
    years = y;
    interestRate = r;
    returnAmount = principalAmount;

    for (int i = 0; i < years; i++)
    {
      returnAmount = returnAmount * (1 + interestRate);
    }
  }
  BankDeposit(int p, int y, int r)
  {
    principalAmount = p;
    years = y;
    interestRate = float(r) / 100;
    returnAmount = principalAmount;

    for (int i = 0; i < years; i++)
    {
      returnAmount = returnAmount * (1 + interestRate);
    }
  }

  void showDetails()
  {
    cout << "Principal Amount: " << principalAmount << endl
         << "Return value after " << years << " years is " << returnAmount << endl;
  }
};

int main()
{
  BankDeposit bd1, bd2, bd3;
  int p = 100, y = 4, r = 5;
  float R = 0.05;

  // cout << "Enter the value of p, y and r" << endl;
  // cin >> p >> y >> r;

  bd1 = BankDeposit(p, y, r);
  bd1.showDetails();

  bd2 = BankDeposit(p, y, R);
  bd2.showDetails();

  return 0;
}