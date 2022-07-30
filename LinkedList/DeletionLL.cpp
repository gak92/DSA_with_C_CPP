#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void LinkListTraversal(struct Node *ptr)
{
  printf("\nElements are: ");
  while (ptr != NULL)
  {
    printf(" %d", ptr->data);
    ptr = ptr->next;
  }
}

// Case 01: Delete at the begining (delete first node)
struct Node *DeleteFirst(struct Node *head)
{
  struct Node *ptr = head;
  head = head->next;
  free(ptr);

  return head;
}

// Case 02: Delete at the end (delete last node)
struct Node *DeleteLast(struct Node *head)
{
  struct Node *ptr = head;
  struct Node *q = head->next;

  while (q->next != NULL)
  {
    ptr = ptr->next;
    q = q->next;
  }
  ptr->next = NULL;
  free(q);

  return head;
}

// Case 03: Delete at given index
struct Node *DeleteAtIndex(struct Node *head, int index)
{
  struct Node *ptr = head;
  struct Node *q = head->next;

  for (int i = 0; i < index - 1; i++)
  {
    ptr = ptr->next;
    q = q->next;
  }
  ptr->next = q->next;
  free(q);

  return head;
}

// Case 04: Delete given value (first one)
struct Node *DeleteValue(struct Node *head, int value)
{
  struct Node *ptr = head;
  struct Node *q = head->next;

  while (q->data != value && q->next != NULL)
  {
    ptr = ptr->next;
    q = q->next;
  }

  if (q->data == value)
  {
    ptr->next = q->next;
    free(q);
  }
  return head;
}

int main()
{
  struct Node *head = (struct Node *)malloc(sizeof(struct Node));
  struct Node *second = (struct Node *)malloc(sizeof(struct Node));
  struct Node *third = (struct Node *)malloc(sizeof(struct Node));
  struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
  struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));
  struct Node *sixth = (struct Node *)malloc(sizeof(struct Node));

  head->data = 11;
  head->next = second;

  second->data = 19;
  second->next = third;

  third->data = 27;
  third->next = fourth;

  fourth->data = 41;
  fourth->next = fifth;

  fifth->data = 70;
  fifth->next = sixth;

  sixth->data = 92;
  sixth->next = NULL;

  printf("\nBefore Deletion: ");
  LinkListTraversal(head);

  printf("\nDelete First node: ");
  head = DeleteFirst(head);
  LinkListTraversal(head);

  printf("\nDelete Last node: ");
  head = DeleteLast(head);
  LinkListTraversal(head);

  int index = 2;
  printf("\nDelete at index %d: ", index);
  head = DeleteAtIndex(head, index);
  LinkListTraversal(head);

  int value = 27;
  printf("\nDelete value %d: ", value);
  head = DeleteValue(head, value);
  LinkListTraversal(head);

  return 0;
}