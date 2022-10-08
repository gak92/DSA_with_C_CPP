#include <iostream>
using namespace std;

class binary
{
  // private:
  string s;
  void check_binary(void);

public:
  void read_binary(void);
  void ones_complement(void);
  void display(void);
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

void binary ::ones_complement(void)
{
  check_binary();
  for (int i = 0; i < s.length(); i++)
  {
    if (s.at(i) == '0')
      s.at(i) = '1';
    else
      s.at(i) = '0';
  }
}

void binary ::display(void)
{
  for (int i = 0; i < s.length(); i++)
  {
    cout << s.at(i);
  }
  cout << "" << endl;
}

int main()
{

  binary b;
  b.read_binary();

  cout << "\nBinary number: ";
  b.display();
  b.ones_complement();
  cout << "\nOnes complement: ";
  b.display();

  return 0;
}