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
  q.size = 5;
  q.front = q.rear = -1;
  q.arr = (int *)malloc(q.size * sizeof(int));

  printf("\nIs q empty: %d", isEmpty(&q));
  printf("\nIs q full: %d", isFull(&q));

  printf("\nq size: %d", q.size);
  enqueue(&q, 4);
  enqueue(&q, 7);
  enqueue(&q, 11);
  enqueue(&q, 19);
  enqueue(&q, 21);
  enqueue(&q, 27);

  display(&q);

  printf("\nIs q empty: %d", isEmpty(&q));
  printf("\nIs q full: %d", isFull(&q));

  dequeue(&q);
  dequeue(&q);
  display(&q);

  return 0;
}
