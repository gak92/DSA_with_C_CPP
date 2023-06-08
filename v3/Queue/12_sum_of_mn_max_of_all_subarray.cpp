#include <iostream>
#include <queue>
using namespace std;

int solve(int *arr, int n, int k)
{
  deque<int> mx(k);
  deque<int> mn(k);

  // addition of 1st k size window
  for (int j = 0; j < k; j++)
  {
    while (!mx.empty() && arr[mx.back()] <= arr[j])
      mx.pop_back();

    while (!mn.empty() && arr[mn.back()] >= arr[j])
      mn.pop_back();

    mx.push_back(j);
    mn.push_back(j);
  }

  int res = 0;
  for (int j = k; j < n; j++)
  {
    res += arr[mx.front()] + arr[mn.front()];

    // removal
    while (!mx.empty() && j - mx.front() >= k)
      mx.pop_front();

    while (!mn.empty() && j - mn.front() >= k)
      mn.pop_front();

    // add
    while (!mx.empty() && arr[mx.back()] <= arr[j])
      mx.pop_back();

    while (!mn.empty() && arr[mn.back()] >= arr[j])
      mn.pop_back();

    mx.push_back(j);
    mn.push_back(j);
  }

  res += arr[mx.front()] + arr[mn.front()];
  return res;
}

int main()
{
  int n = 7;
  int arr[n] = {2, 5, -1, 7, -3, -1, 2};
  int k = 4;

  cout << "Sum: " << solve(arr, n, k) << endl;

  return 0;
}