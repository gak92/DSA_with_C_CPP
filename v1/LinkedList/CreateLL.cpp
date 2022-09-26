#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void LinkListTraversal(struct Node *ptr)
{
  while (ptr != NULL)
  {
    printf("\nElements: %d", ptr->data);
    ptr = ptr->next;
  }
}

int main()
{
  struct Node *head;
  struct Node *second;
  struct Node *third;

  // Create node and allocate memory in heap
  head = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));

  head->data = 11;
  head->next = second;

  second->data = 19;
  second->next = third;

  third->data = 27;
  third->next = NULL;

  LinkListTraversal(head);

  return 0;
}