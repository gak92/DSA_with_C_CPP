#include <bits/stdc++.h>
using namespace std;

int main()
{
  /*
   *  Write your code here.
   *  Read input as specified in the question.
   *  Print output as specified in the question.
   */

  int n;
  cin >> n;

  // step 1
  vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;

  for (int i = 2; i <= n; i++)
    dp[i] = dp[i - 1] + dp[i - 2];

  cout << dp[n] << endl;

  /*
    optimized:

    int prev2 = 0;
        int prev1 = 1;
        int curr;

        for(int i=2; i<=n; i++)
        {
                curr = prev1 + prev2;
                prev2 = prev1;
                prev1 = curr;
        }

        cout << prev1 << endl;


  */

  return 0;
}