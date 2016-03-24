#include <stdio.h>
#include "prepareFun.h"

void printArray(int *a,int len)
{
  int i;
  for(i = 0; i < len; i++)
    {
      printf("%d, ",*(a+i));
    }
  printf("\n");
}

void swap(int *a,int *b)
{
  if(*a != *b)
    {
      *a ^= *b;
      *b ^= *a;
      *a ^= *b;
    }
}
