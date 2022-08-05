#include <stdio.h>
#include <stdlib.h>

struct Stack
{
  int size;
  int top;
  char *arr;
};

int isEmpty(struct Stack *sp)
{
  if (sp->top == -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isFull(struct Stack *sp)
{
  if (sp->top == sp->size - 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void display(struct Stack *sp)
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
      printf(" %c", sp->arr[i]);
    }
  }
}

void push(struct Stack *sp, char ch)
{
  if (isFull(sp))
  {
    printf("\nStack is Overflow");
  }
  else
  {
    sp->top++;
    sp->arr[sp->top] = ch;
  }
}

int pop(struct Stack *sp)
{
  if (isEmpty(sp))
  {
    printf("\nstack is underflow");
    return -1;
  }
  else
  {
    char ch = sp->arr[sp->top];
    sp->top--;
    return ch;
  }
}

int peek(struct Stack *sp, int pos)
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

int stackTop(struct Stack *sp)
{
  return sp->arr[sp->top];
}

int stackBottom(struct Stack *sp)
{
  return sp->arr[0];
}

int ParenthesisMatch(char *exp)
{
  struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
  sp->size = 100;
  sp->top = -1;
  sp->arr = (char *)malloc(sp->size * sizeof(char));

  for (int i = 0; exp[i] != '\0'; i++)
  {
    if (exp[i] == '(')
    {
      push(sp, '(');
    }
    else if (exp[i] == ')')
    {
      if (isEmpty(sp))
      {
        return 0;
      }
      else
      {
        pop(sp);
      }
    }
  }

  if (isEmpty(sp))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  char *exp = "((8+9))";

  if (ParenthesisMatch(exp))
  {
    printf("\nThe Parenthesis is matched");
  }
  else
  {
    printf("\nThe Parenthesis is not matched");
  }

  return 0;
}
