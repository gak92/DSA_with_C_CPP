#include <iostream>
using namespace std;

class binary
{
  string s;

public:
  void read_binary(void);
  void check_binary(void);
};

void binary ::read_binary(void)
{
  // cout << "Enter a binary number: ";
  cin >> s;
}

void binary ::check_binary(void)
{
  for (int i = 0; i < s.length(); i++)
  {
    if (s.at(i) != '0' && s.at(i) != '1')
    {
      cout << "Not a binary number";
      exit(0);
    }
  }
  cout << "a binary number";
}

int main()
{

  binary b;
  b.read_binary();
  b.check_binary();

  return 0;
}