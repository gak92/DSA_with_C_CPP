#include <iostream>
using namespace std;

int count = 0;

class Num
{
public:
  Num()
  {
    count++;
    cout << "This is the time when constructor is called for object " << count << endl;
  }

  ~Num()
  {
    cout << "This is the time when destructor is called for object " << count << endl;
    count--;
  }
};

int main()
{
  cout << "We are in main function" << endl;
  cout << "Creating first object..." << endl;
  Num n1;

  {
    cout << "Entering the block... " << endl;
    cout << "Creating two more objects " << endl;
    Num n2, n3;

    cout << "Exiting the block... " << endl;
  }

  cout << "Back to main function" << endl;

  return 0;
}