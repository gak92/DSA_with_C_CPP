#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
  int top;
  int size;
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

void push(struct Stack *sp, char ch)
{
  if (isFull(sp))
  {
    printf("stack is overflow");
  }
  else
  {
    sp->top++;
    sp->arr[sp->top] = ch;
  }
}

char pop(struct Stack *sp)
{
  if (isEmpty(sp))
  {
    printf("Stack is underflow");
    return -1;
  }
  else
  {
    char ch = sp->arr[sp->top];
    sp->top--;
    return ch;
  }
}

int stackTop(struct Stack *sp)
{
  return sp->arr[sp->top];
}

int isoperator(char ch)
{
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int precedence(char ch)
{
  if (ch == '/' || ch == '*')
  {
    return 3;
  }
  if (ch == '+' || ch == '-')
  {
    return 2;
  }
  return 0;
}

char *infix_to_postfix(char *infix)
{
  struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
  sp->size = 10;
  sp->top = -1;
  sp->arr = (char *)malloc(sp->size * sizeof(char));
  char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
  int i = 0, j = 0;

  while (infix[i] != '\0')
  {
    if (!isoperator(infix[i]))
    {
      postfix[j] = infix[i];
      i++;
      j++;
    }
    else
    {
      if (precedence(infix[i]) > precedence(stackTop(sp)))
      {
        push(sp, infix[i]);
        i++;
      }
      else
      {
        postfix[j] = pop(sp);
        j++;
      }
    }
  }

  while (!isEmpty(sp))
  {
    postfix[j] = pop(sp);
    j++;
  }
  postfix[j] = '\0';
  return postfix;
}

int main()
{
  char *infix = (char *)"x-y/z-k*d";
  printf("Postfix is: %s", infix_to_postfix(infix));

  return 0;
}