#include<iostream>
using namespace std;

class A
{
  int a;
  public:
    void setData(int a)
    {
      this->a = a;
    }
    void getData(void)
    {
      cout << "Value of a: " << a << endl;
    }

};

int main()
{
  // 'this' is a keyword which is a pointer.
  // this point to an object which invokes the member function.
  
  A a;
  a.setData(4);
  a.getData();

  return 0;
}