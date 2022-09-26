#include <stdio.h>
#include <stdlib.h>

struct CircularQueue
{
  int size;
  int front;
  int rear;
  int *arr;
};

int isEmpty(struct CircularQueue *q)
{
  if (q->rear == q->front)
  {
    return 1;
  }
  return 0;
}

int isFull(struct CircularQueue *q)
{
  if ((q->rear + 1) % q->size == q->front)
  {
    return 1;
  }
  return 0;
}

void enqueue(struct CircularQueue *q, int val)
{
  if (isFull(q))
  {
    printf("\nQueue is full");
  }
  else
  {
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = val;
  }
}

int dequeue(struct CircularQueue *q)
{
  int val = -1;
  if (isEmpty(q))
  {
    printf("Circular Queue is empty");
  }
  else
  {
    q->front = (q->front + 1) % q->size;
    val = q->arr[q->front];
  }
  return val;
}

void display(struct CircularQueue *q)
{
  printf("\nq elements are: ");
  for (int i = 0; i < q->size; i++)
  {
    printf("%d, ", q->arr[i]);
  }
}

int main()
{
  struct CircularQueue q;
  q.size = 5;
  q.front = q.rear = 0;
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

  enqueue(&q, 21);
  enqueue(&q, 27);
  display(&q);

  return 0;
}
