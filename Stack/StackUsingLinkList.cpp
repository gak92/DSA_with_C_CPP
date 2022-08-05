#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *top = NULL;

int isEmpty()
{
  if (top == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isFull()
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  if (temp == NULL)
  {
    return 1;
  }
  else
  {
    free(temp);
    return 0;
  }
}

void StackTraversal(struct Node *ptr)
{
  while (ptr != NULL)
  {
    printf("\nStack Elements: %d", ptr->data);
    ptr = ptr->next;
  }
}

void push(struct Node *ptr, int val)
{
  if (isFull())
  {
    printf("Stack is Overflow");
  }
  else
  {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = ptr;
    top = temp;
  }
}

int pop(struct Node *ptr)
{
  if (isEmpty())
  {
    printf("Stack is underflow");
  }
  else
  {
    int value = ptr->data;
    top = ptr->next;
    free(ptr);
    return value;
  }
}

int peek(struct Node *ptr, int pos)
{
  for (int i = 1; (i < pos && ptr != NULL); i++)
  {
    ptr = ptr->next;
  }
  if (ptr == NULL)
  {
    return -1;
  }
  else
  {
    return ptr->data;
  }
}

int main()
{
  int popped_element;

  push(top, 4);
  push(top, 7);
  push(top, 11);
  StackTraversal(top);

  popped_element = pop(top);
  printf("\nPopped Element is: %d", popped_element);
  StackTraversal(top);

  int position = 2;
  int element = peek(top, position);
  printf("\nElement at position %d is %d", position, element);
  StackTraversal(top);

  return 0;
}