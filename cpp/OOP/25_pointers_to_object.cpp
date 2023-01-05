#include <iostream>
using namespace std;

class Complex
{
  int real, imaginary;
  public:
    void getData()
    {
      cout << "Real part is: " << real << endl;
      cout << "Imaginary part is: " << imaginary << endl;
    }
    void setData(int a, int b)
    {
      real = a;
      imaginary = b;
    }
};

int main()
{
  Complex c1;
  // c1.setData(4,6);
  // c1.getData();
 
  Complex *ptr = &c1;
  (*ptr).setData(5,11);
  (*ptr).getData();

  Complex *ptr2 = new Complex;
  // (*ptr2).setData(19,41);
  ptr2->setData(11,41);
  // (*ptr2).getData();
  ptr2->getData();

  return 0;
}