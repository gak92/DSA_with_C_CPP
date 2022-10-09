#include <iostream>
using namespace std;

class Employee
{
  int id;
  int salary;

public:
  void setId(int empid)
  {
    id = empid;
    salary = 111;
  }

  void getId(void)
  {
    cout << "The id of employee: " << id << endl;
  }
};

int main()
{
  Employee fb[4];

  for (int i = 0; i < 4; i++)
  {
    fb[i].setId(i);
    fb[i].getId();
  }

  return 0;
}