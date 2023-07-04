#include <bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>> &board, vector<vector<int>> &res, int n)
{
  vector<int> temp;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      temp.push_back(board[i][j]);
    }
  }
  res.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
  int x = row;
  int y = col;

  // check for same row
  while (y >= 0)
  {
    if (board[x][y] == 1)
      return false;
    y--;
  }

  // check for upper left diagonal
  x = row;
  y = col;
  while (x >= 0 && y >= 0)
  {
    if (board[x][y] == 1)
      return false;
    x--;
    y--;
  }

  // check for bottom left diagonal
  x = row;
  y = col;
  while (x < n && y >= 0)
  {
    if (board[x][y] == 1)
      return false;
    x++;
    y--;
  }

  return true;
}

void solve(int col, vector<vector<int>> &res, vector<vector<int>> &board, int n)
{
  // base case
  if (col == n)
  {
    addSolution(board, res, n);
    return;
  }

  // sovle 1 case
  for (int row = 0; row < n; row++)
  {
    if (isSafe(row, col, board, n))
    {
      board[row][col] = 1;           // placing Queen
      solve(col + 1, res, board, n); // call for next column
      board[row][col] = 0;           // backtracking
    }
  }
}

vector<vector<int>> nQueens(int n)
{
  // Write your code here
  vector<vector<int>> board(n, vector<int>(n, 0));
  vector<vector<int>> res;

  solve(0, res, board, n);

  return res;
}

int main()
{

  return 0;
}