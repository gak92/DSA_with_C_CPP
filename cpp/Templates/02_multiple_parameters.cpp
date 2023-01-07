#include<iostream>
using namespace std;

template <class T1,class T2>
class MyClass
{
  public:
    T1 data1;
    T2 data2;
    MyClass(T1 a, T2 b)
    {
      data1 = a;
      data2 = b;
    }
    void display()
    {
      cout << "Data1: " << data1 << endl;
      cout << "Data2: " << data2 << endl;
    }
};

int main()
{
  MyClass<int, float> obj(4, 4.2);
  obj.display();

  return 0;
}
