//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  string FirstNonRepeating(string A)
  {
    // Code here

    unordered_map<char, int> count;
    queue<int> q;
    string s = "";

    for (int j = 0; j < A.length(); j++)
    {
      char ch = A[j];
      count[ch]++;
      q.push(ch);

      while (!q.empty())
      {
        if (count[q.front()] > 1) // repeatng character
        {
          q.pop();
        }
        else
        {
          s.push_back(q.front());
          break;
        }
      }
      if (q.empty())
      {
        s.push_back('#');
      }
    }

    return s;
  }
};

//{ Driver Code Starts.
int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    string A;
    cin >> A;
    Solution obj;
    string ans = obj.FirstNonRepeating(A);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends