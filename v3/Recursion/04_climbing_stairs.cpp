#include <iostream>
using namespace std;

int countDisticntWays(int nStairs)
{
  if (nStairs < 0)
    return 0;
  if (nStairs == 0)
    return 1;

  return countDisticntWays(nStairs - 1) + countDisticntWays(nStairs - 2);
}

int main()
{

  int nStairs;
  cout << "Enter the nth Stairs: ";
  cin >> nStairs;

  int res = countDisticntWays(nStairs);
  cout << "Ways to reach on stairs is: " << res << endl;

  return 0;
}