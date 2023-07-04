#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n)
{
  if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] != 1 && arr[x][y] == 1)
  {
    return true;
  }
  return false;
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &res,
           vector<vector<bool>> &visited, string path)
{
  // base case
  if (x == n - 1 && y == n - 1)
  {
    res.push_back(path);
    return;
  }

  visited[x][y] = 1;
  // 4 movement

  // Down
  if (isSafe(x + 1, y, visited, arr, n))
    solve(x + 1, y, arr, n, res, visited, path + 'D');

  // Left
  if (isSafe(x, y - 1, visited, arr, n))
    solve(x, y - 1, arr, n, res, visited, path + 'L');

  // Right
  if (isSafe(x, y + 1, visited, arr, n))
    solve(x, y + 1, arr, n, res, visited, path + 'R');

  // Up
  if (isSafe(x - 1, y, visited, arr, n))
    solve(x - 1, y, arr, n, res, visited, path + 'U');

  visited[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
  // Write your code here.
  vector<string> res;
  if (arr[0][0] == 0)
    return res;

  vector<vector<bool>> visited(n, vector<bool>(n, 0));
  string path = "";

  solve(0, 0, arr, n, res, visited, path);
  return res;
}

int main()
{

  return 0;
}