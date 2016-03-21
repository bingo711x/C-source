#include "prepareFun.h"

void BubbleSort(int a[],int len)
{
  int i,j;
  for(i = 0; i < len-1; i++)
    {
      for(j = 0; j < len-1-i; j++)
	{
	  if(a[j] > a[j+1])
	    {
	      swap(a+j,a+j+1);
	    }
	}
    }
}

