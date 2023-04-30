#include <iostream>
using namespace std;

int getLength(char name[])
{
  int count;
  for (int i = 0; name[i] != '\0'; i++)
  {
    count++;
  }

  return count;
}

void reverseString(char name[], int n)
{
  int start = 0;
  int end = n - 1;

  while (start <= end)
  {
    swap(name[start++], name[end--]);
  }
}

int main()
{
  char name[20];

  cout << "Enter your name: ";
  cin >> name;
  cout << "Your name is " << name << endl;

  int length = getLength(name);
  cout << "Your name length is: " << length << endl;

  reverseString(name, length);
  cout << "Reverse name is " << name << endl;

  return 0;
}