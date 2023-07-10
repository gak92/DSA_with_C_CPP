#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(vector<int> &cost, int n)
  {
    if (n == 0)
      return cost[0];
    if (n == 1)
      return cost[1];

    int res = cost[n] + min(solve(cost, n - 1), solve(cost, n - 2));
    return res;
  }

  int solve2(vector<int> &cost, int n, vector<int> &dp)
  {
    if (n == 0)
      return cost[0];
    if (n == 1)
      return cost[1];

    // step 3 - if already calculated just returned from DP
    if (dp[n] != -1)
      return dp[n];

    // step 2 - call recursively and save result into dp
    dp[n] = cost[n] + min(solve2(cost, n - 1, dp), solve2(cost, n - 2, dp));
    return dp[n];
  }

  int minCostClimbingStairs(vector<int> &cost)
  {

    // solution # 1 (without DP, it gives TLE)
    // int n = cost.size();
    // int res = min(solve(cost, n-1), solve(cost, n-2) );
    // return res;

    // solution # 2 (with DP)
    int n = cost.size();
    // step 1 - create DP array
    vector<int> dp(n + 1, -1);

    int res = min(solve2(cost, n - 1, dp), solve2(cost, n - 2, dp));
    return res;
  }
};

int main()
{

  return 0;
}