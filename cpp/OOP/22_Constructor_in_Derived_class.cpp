#include <iostream>
using namespace std;

/*
case # 01
class B : public A {
  // order of execution of constructor --> first A(), then B()
}

case # 02
class A : public B, public C {
  // order of execution of constructor --> first B(), then C(), then A()
}

case # 03
class A : public B, virtual public C {
  // order of execution of constructor --> first C(), then B(), then A()
}

*/

class Base1
{
  int data1;
  public:
    Base1(int i)
    {
      data1 = i;
      cout << "Base1 class constructor called" << endl;
    }
    void printDataBase1(void)
    {
      cout << "The value of data is: " << data1 << endl;
    }
};

class Base2
{
  int data2;
  public:
    Base2(int i)
    {
      data2 = i;
      cout << "Base2 class constructor called" << endl;
    }
    void printDataBase2(void)
    {
      cout << "The value of data is: " << data2 << endl;
    }
};

class Derived : public Base1, public Base2
{
  int d1, d2;
  public:
    Derived(int a, int b, int c, int d): Base1(a), Base2(b)
    {
      d1 = c;
      d2 = d;
      cout << "Derived class constructor called" << endl;
    }
    void printDataDerived(void)
    {
      cout << "Value of d1 and d2: " << d1 << d2 << endl;
    }
};

int main()
{
  cout << "Constructor in derived class:" << endl;
  Derived derive(1,2,3,4);
  derive.printDataBase1();
  return 0;
}