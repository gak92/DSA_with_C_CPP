#include <stdio.h>
#include <stdlib.h>

struct Queue
{
  int size;
  int front;
  int rear;
  int *arr;
};

int isEmpty(struct Queue *q)
{
  if (q->rear == q->front)
  {
    return 1;
  }
  return 0;
}

int isFull(struct Queue *q)
{
  if (q->rear == q->size - 1)
  {
    return 1;
  }
  return 0;
}

void enqueue(struct Queue *q, int val)
{
  if (isFull(q))
  {
    printf("\nQueue is full");
  }
  else
  {
    q->rear++;
    q->arr[q->rear] = val;
  }
}

int dequeue(struct Queue *q)
{
  int val = -1;
  if (isEmpty(q))
  {
    printf("Queue is empty");
  }
  else
  {
    q->front++;
    val = q->arr[q->front];
  }
  return val;
}

void display(struct Queue *q)
{
  int strt = q->front + 1;
  printf("\nq elements are: ");
  for (int i = strt; i <= q->rear; i++)
  {
    printf("%d, ", q->arr[i]);
  }
}

int main()
{
  struct Queue q;
  q.size = 20;
  q.front = q.rear = 0;
  q.arr = (int *)malloc(q.size * sizeof(int));

  // BFS Implementation
  int node;
  int i = 0; // starting node
  // 0 - unvisited, 1 - visited
  int visited[7] = {0, 0, 0, 0, 0, 0, 0};
  int a[7][7] = {
      {0, 1, 1, 1, 0, 0, 0},
      {1, 0, 1, 0, 0, 0, 0},
      {1, 1, 0, 1, 1, 0, 0},
      {1, 0, 1, 0, 1, 0, 0},
      {0, 0, 1, 1, 0, 1, 1},
      {0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 1, 0, 0}};

  printf("%d ", i);
  visited[i] = 1;
  enqueue(&q, i);

  while (!isEmpty(&q))
  {
    int node = dequeue(&q);
    for (int j = 0; j < 7; j++)
    {
      if (a[node][j] == 1 && visited[j] == 0)
      {
        printf("%d ", j);
        visited[j] = 1;
        enqueue(&q, j);
      }
    }
  }

  return 0;
}
