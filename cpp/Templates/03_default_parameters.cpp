#include<iostream>
using namespace std;

template <class T1=int, class T2=float>
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
  MyClass<> obj(4, 4.2);
  obj.display();

  MyClass<float, char> obj2(4.11, 'z');
  obj2.display();

  return 0;
}
