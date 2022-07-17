#include <stdio.h>
#include <stdlib.h>

struct ArrayADT
{
  int total_size;
  int used_size;
  int *ptr;
};

void createArray(struct ArrayADT *a, int tsize, int usize)
{
  // (*a).total_size = tsize;
  // (*a).used_size = usize;
  // (*a).ptr = (int *)malloc(tsize * sizeof(int));
  a->total_size = tsize;
  a->used_size = usize;
  a->ptr = (int *)malloc(tsize * sizeof(int));
}

void showArray(struct ArrayADT *a)
{
  for (int i = 0; i < a->used_size; i++)
  {
    printf("%d\n", (a->ptr)[i]);
  }
}

void setValue(struct ArrayADT *a)
{
  int n;
  for (int i = 0; i < a->used_size; i++)
  {
    printf("Enter value %d", i);
    scanf("%d", &n);
    (a->ptr)[i] = n;
  }
}

int main()
{
  struct ArrayADT marks;
  createArray(&marks, 10, 4);
  setValue(&marks);
  showArray(&marks);

  return 0;
}