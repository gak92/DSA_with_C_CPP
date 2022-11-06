#include <iostream>
using namespace std;

class Base
{
  int data1; // Private data can't be inderited
public:
  int data2;
  void setData();
  int getData1();
  int getData2();
};

void Base ::setData()
{
  data1 = 10;
  data2 = 20;
}

int Base ::getData1()
{
  return data1;
}

int Base ::getData2()
{
  return data2;
}

// If inherit using private, then can't access setData because it will
// become private in derived class.
class Derived : public Base
{
  int data3;

public:
  void process();
  void display();
};

void Derived ::process()
{
  data3 = data2 * getData1();
}

void Derived ::display()
{
  cout << "data 1: " << getData1() << endl;
  cout << "data 2: " << data2 << endl;
  cout << "data 3: " << data3 << endl;
}

int main()
{
  Derived d;
  d.setData();
  d.process();
  d.display();

  return 0;
}