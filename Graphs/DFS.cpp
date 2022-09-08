#include <stdio.h>
#include <stdlib.h>

// 0 - unvisited, 1 - visited
int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int A[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

// DFS Implementation
void DFS(int i)
{
  int j;
  printf("%d", i);
  visited[i] = 1;
  for (j = 0; j < 7; j++)
  {
    if (A[i][j] == 1 && !visited[j])
    {
      DFS(j);
    }
  }
}

int main()
{
  DFS(0);
  return 0;
}
