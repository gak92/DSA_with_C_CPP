#define MOD 1000000007
#include <bits/stdc++.h>
using namespace;

int solve(int nStairs, int currStair, vector<int> &dp)
{
  // base case
  if (currStair == nStairs)
    return 1;

  if (currStair > nStairs)
    return 0;

  if (dp[currStair] != -1)
    return dp[currStair];

  dp[currStair] = (solve(nStairs, currStair + 1, dp) + solve(nStairs, currStair + 2, dp)) % MOD;
  return dp[currStair];
}

int countDistinctWays(int nStairs)
{
  vector<int> dp(nStairs + 1, -1);
  int res = solve(nStairs, 0, dp);
  return res;
}

int main()
{

  return 0;
}