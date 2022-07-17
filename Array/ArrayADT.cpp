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

int main()
{
  struct ArrayADT marks;
  createArray(&marks, 10, 4);
  showArray(&marks);

  return 0;
}