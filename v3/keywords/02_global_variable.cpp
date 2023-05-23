#include <iostream>
using namespace std;

// Dont use gloable variables
// Its a BAD practice
int score = 5;

// Always use reference variable to share it

void a()
{
  cout << "Score inside a function: " << score << endl;
}

void b()
{
  cout << "Score inside b function: " << score << endl;
}

int main()
{

  cout << "Score inside main function: " << score << endl;
  a();

  return 0;
}