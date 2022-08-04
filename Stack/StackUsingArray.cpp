#include <stdio.h>
#include <stdlib.h>

struct stack
{
  int size;
  int top;
  int *arr;
};

int isEmpty(struct stack *ptr)
{
  if (ptr->top == -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isFull(struct stack *ptr)
{
  if (ptr->top == ptr->size - 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void display(struct stack *sp)
{
  if (isEmpty(sp))
  {
    printf("\nStack is empty");
  }
  else
  {
    printf("\nStack Elements are: ");
    for (int i = 0; i <= sp->top; i++)
    {
      printf(" %d", sp->arr[i]);
    }
  }
}

void push(struct stack *sp, int val)
{
  if (isFull(sp))
  {
    printf("\nStack is Overflow");
  }
  else
  {
    sp->top++;
    sp->arr[sp->top] = val;
  }
}

int pop(struct stack *sp)
{
  if (isEmpty(sp))
  {
    printf("\nstack is underflow");
    return -1;
  }
  else
  {
    int val = sp->arr[sp->top];
    sp->top--;
    return val;
  }
}

int peek(struct stack *sp, int pos)
{
  int index = sp->top - pos + 1;
  if (index < 0)
  {
    printf("Not a valid position");
    return -1;
  }
  else
  {
    return sp->arr[index];
  }
}

int main()
{
  struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
  sp->size = 7;
  sp->top = -1;
  sp->arr = (int *)malloc(sp->size * sizeof(int));

  display(sp);
  push(sp, 1);
  push(sp, 2);
  push(sp, 3);
  push(sp, 4);
  push(sp, 5);
  push(sp, 6);
  push(sp, 7);
  push(sp, 8);
  display(sp);

  printf("\nPopped element: %d", pop(sp));
  display(sp);

  for (int pos = 1; pos <= sp->top + 1; pos++)
  {
    printf("\nValue at position %d is: %d", pos, peek(sp, pos));
  }

  return 0;
}
