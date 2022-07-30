#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void LinkListTraversal(struct Node *ptr)
{
  printf("Elements are: ");
  while (ptr != NULL)
  {
    printf(" %d", ptr->data);
    ptr = ptr->next;
  }
}

// case 1: Insert at the begining
struct Node *InsertAtBegin(struct Node *head, int data)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = head;

  return new_node;
}

// case 2: Insert in between (at given index)
struct Node *InsertAtIndex(struct Node *head, int data, int index)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  struct Node *ptr = head;
  new_node->data = data;
  int i = 0;

  while (i < index - 1)
  {
    ptr = ptr->next;
    i++;
  }
  new_node->next = ptr->next;
  ptr->next = new_node;

  return head;
}

// case 3: Insert at the end
struct Node *InsertAtEnd(struct Node *head, int data)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = data;
  struct Node *ptr = head;

  while (ptr->next != NULL)
  {
    ptr = ptr->next;
  }
  ptr->next = new_node;
  new_node->next = NULL;

  return head;
}

// case 4: Insert after a Node
struct Node *InsertAfterNode(struct Node *head, struct Node *prev_node, int data)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;

  return head;
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

  printf("\nBefore Insertion, ");
  LinkListTraversal(head);

  printf("\nAfter Insertion at the begining, ");
  head = InsertAtBegin(head, 7);
  LinkListTraversal(head);

  printf("\nAfter Insertion at the end, ");
  head = InsertAtEnd(head, 41);
  LinkListTraversal(head);

  int index = 3;
  printf("\nAfter Insertion at the given index %d, ", index);
  head = InsertAtIndex(head, 21, index);
  LinkListTraversal(head);

  printf("\nAfter Insertion at the given node %d, ", second->data);
  head = InsertAfterNode(head, second, 92);
  LinkListTraversal(head);

  return 0;
}