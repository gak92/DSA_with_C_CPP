#include<iostream>
using namespace std;

template <class T>
class A
{
  public:
    T data;
    A(T d)
    {
      data = d;
    }
    void display();
};

template <class T>
void A<T> :: display()
{
  cout << "Data is: " << data << endl;
}

void func(int a)
{
  cout << "I am first function: " << a << endl;
}

template <class T>
void func(T a)
{
  cout << "I am templatized funtion: " << a << endl;
}

int main()
{
  func(4);

  A<int> a(11);
  a.display();
  

  return 0;
}
