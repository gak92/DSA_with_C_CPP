/*
https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1},
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at
(3, 3) from (0, 0) by two paths - DRDDRR
and DDRDRR, when printed in sorted order
we get DDRDRR DRDDRR.

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &m, int n, int x, int y, vector<vector<int>> visited)
{
  if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
  {
    return true;
  }
  return false;
}

void findPath(vector<vector<int>> &m, int n, int x, int y, vector<vector<int>> visited, string path, vector<string> &res)
{
  if (x == n - 1 && y == n - 1)
  {
    res.push_back(path);
    return;
  }

  // mark visited
  visited[x][y] = 1;

  // 4 choices - D L R U
  // Down
  int newx = x + 1;
  int newy = y;
  if (isSafe(m, n, newx, newy, visited))
  {
    path.push_back('D');
    findPath(m, n, newx, newy, visited, path, res);
    path.pop_back();
  }

  // Left
  newx = x;
  newy = y - 1;
  if (isSafe(m, n, newx, newy, visited))
  {
    path.push_back('L');
    findPath(m, n, newx, newy, visited, path, res);
    path.pop_back();
  }

  // Right
  newx = x;
  newy = y + 1;
  if (isSafe(m, n, newx, newy, visited))
  {
    path.push_back('R');
    findPath(m, n, newx, newy, visited, path, res);
    path.pop_back();
  }

  // Up
  newx = x - 1;
  newy = y;
  if (isSafe(m, n, newx, newy, visited))
  {
    path.push_back('U');
    findPath(m, n, newx, newy, visited, path, res);
    path.pop_back();
  }

  visited[x][y] = 0;
}

void printVector(vector<string> v)
{
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  // input
  int n = 4;
  vector<vector<int>> m{
      {1, 0, 0, 0},
      {1, 1, 0, 1},
      {1, 1, 0, 0},
      {0, 1, 1, 1}};

  // output
  vector<string> res;

  // create visited matrix to keep track
  vector<vector<int>> visited = m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      visited[i][j] = 0;
    }
  }

  int srcx = 0;
  int srcy = 0;
  string path = "";

  findPath(m, n, srcx, srcy, visited, path, res);
  sort(res.begin(), res.end());
  printVector(res);

  return 0;
}
