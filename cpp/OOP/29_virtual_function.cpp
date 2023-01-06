#include<iostream>
using namespace std;

class Base
{
  public:
    int var_base;
    virtual void display(void)
    {
      cout << "Value of var_base: " << var_base << endl;
    }
};

class Derived : public Base
{
  public:
  int var_derived;
  void display(void)
  {
    cout << "Value of var_base: " << var_base << endl;
    cout << "Value of var_derived: " << var_derived << endl;
  }
};

int main()
{
  Base base_obj;
  Derived derived_obj;

  Base *base_ptr;
  base_ptr = &derived_obj;

  base_ptr->var_base = 34;
  base_ptr->display();

  // Derived *derived_ptr;
  // derived_ptr = &derived_obj;
  // derived_ptr->var_base = 19;
  // derived_ptr->var_derived = 41;
  // derived_ptr->display();


  return 0;
}