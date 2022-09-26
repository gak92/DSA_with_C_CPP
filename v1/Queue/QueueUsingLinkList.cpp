#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *front;
struct Node *rear;

void LinkListTraversal(struct Node *ptr)
{
  printf("\nQueue elements are: ");
  while (ptr != NULL)
  {
    printf(" %d", ptr->data);
    ptr = ptr->next;
  }
}

void enqueue(int val)
{
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  if (node == NULL)
  {
    printf("Queue is full");
  }
  else
  {
    node->data = val;
    node->next = NULL;

    if (front == NULL)
    {
      front = node;
      rear = node;
    }
    else
    {
      rear->next = node;
      rear = node;
    }
  }
}

int dequeue()
{
  int val = -1;
  struct Node *ptr = front;
  if (front == NULL)
  {
    printf("Queue is empty");
  }
  else
  {
    front = front->next;
    val = ptr->data;
    free(ptr);
  }

  return val;
}

int main()
{
  LinkListTraversal(front);
  enqueue(4);
  enqueue(7);
  enqueue(11);
  LinkListTraversal(front);

  dequeue();
  LinkListTraversal(front);
  dequeue();
  dequeue();
  LinkListTraversal(front);

  return 0;
}
