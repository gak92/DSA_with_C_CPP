#include <iostream>
using namespace std;

// Base Class
class Employee
{

public:
  int id;
  float salary;

  Employee() {}
  Employee(int inpId)
  {
    id = inpId;
    salary = 34.0;
  }
};

// Derived Class
// Default visibility mode is private
// Public visibility mode: public member of base class becomes public member of the derived class
// Private visibility mode: public member of base class becomes private member of the derived class
// Private member of base class can't be inherited
class Programmer : Employee
{
public:
  int languageCode;
  Programmer(int inpId)
  {
    id = inpId;
    languageCode = 9;
  }

  void getData()
  {
    cout << id << endl;
  }
};

int main()
{
  Employee e1(1), e2(2);
  cout << e1.salary << endl;
  cout << e2.salary << endl;

  Programmer pg1(3);
  cout << pg1.languageCode << endl;
  pg1.getData();

  return 0;
}