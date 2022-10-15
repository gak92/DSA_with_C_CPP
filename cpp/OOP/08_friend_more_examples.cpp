#include <iostream>
using namespace std;

class Y;

class X
{
  int data;
  friend void addXY(X, Y);

public:
  void setData(int val)
  {
    data = val;
  }
};

class Y
{
  int data;
  friend void addXY(X, Y);

public:
  void setData(int val)
  {
    data = val;
  }
};

void addXY(X x, Y y)
{
  cout << "Sum of X and Y is: " << x.data + y.data << endl;
}

int main()
{
  X x1;
  Y y1;
  x1.setData(5);
  y1.setData(6);
  addXY(x1, y1);

  return 0;
}