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

char toLowerCase(char ch)
{
  if (ch >= 'a' && ch <= 'z')
  {
    return ch;
  }
  else
  {
    char temp = ch - 'A' + 'a';
    return temp;
  }
}

bool isPalindrome(char str[], int n)
{
  int start = 0;
  int end = n - 1;

  while (start <= end)
  {
    if (toLowerCase(str[start]) != toLowerCase(str[end]))
    {
      return false;
    }
    start++;
    end--;
  }
  return true;
}

int main()
{
  char str[20];

  cout << "Enter string: ";
  cin >> str;
  cout << "Your str is " << str << endl;

  int length = getLength(str);
  cout << "Your string length is: " << length << endl;

  reverseString(str, length);
  cout << "Reverse string is " << str << endl;

  if (isPalindrome(str, length))
  {
    cout << "Yes, It is Palindrome.";
  }
  else
  {
    cout << "No, It is not Palindrome.";
  }
  cout << endl;

  return 0;
}