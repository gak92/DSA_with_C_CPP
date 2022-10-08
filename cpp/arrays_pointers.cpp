#include <iostream>
using namespace std;

int main()
{
  int marks[4] = {70, 80, 90, 92};
  int length = sizeof(marks) / sizeof(marks[0]);
  int *p = marks;

  for (int i = 0; i < length; i++)
  {
    cout << *(p + i) << endl;
  }

  cout << "Value at *p: " << *p << endl;
  // cout << "Value at *(p+1): " << *(p + 1) << endl;
  cout << "Value at *(++p): " << *(++p) << endl;
  cout << "Value at *(++p): " << *(++p) << endl;
  cout << "Value at *(++p): " << *(++p) << endl;

  return 0;
}