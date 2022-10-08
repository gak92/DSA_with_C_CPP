#include <iostream>
using namespace std;

class Employee
{
  int empId;
  static int count;

public:
  void setData(int id)
  {
    empId = id;
    count++;
  }
  void getData() { cout << "\nEmployee id is: " << empId; }
  void static getCount() { cout << "\nValue of count is: " << count; }
};

// count is static data member of Employee
int Employee ::count; // Default value is 0

int main()
{
  Employee emp1, emp2, emp3;
  emp1.setData(101);
  emp1.getData();

  emp2.setData(102);
  emp2.getData();

  emp3.setData(103);
  emp3.getData();

  Employee::getCount();

  return 0;
}