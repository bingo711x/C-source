/*
 * author : bingo
 * Date : 2016-03-23
 * Description:
 *   This functions sort an array of Int from little to big.
 * functions:
 *   BubbleSort
 *
 */

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

void InsertSort(int a[],int len)
{
  int i,j;

  for(i = 1;i < len; i++)
    {
      for(j = i-1;j >= 0 && a[j] > a[j+1]; j--)
	{
	  swap(a+j,a+j+1);
	}
    }
}

void SelectSort(int a[],int len)
{
  int i,j;
  int minIndex;

  for(i = 0;i < len-1; i++)
    {
      minIndex = i;
      for(j = i+1;j < len;j++)
	{
	  if(a[j] < a[minIndex])
	    {
	      minIndex = j;
	    }
	}
      if(minIndex != i)
	swap(a+i,a+minIndex);
    }
}
void buildHeap(int a[],int i)
{
  if(a[i] < a[2*i+1] || a[i] < a[2*i+2])
    {
      if(a[i] < a[2*i+1])
	{
	  swap(a+i,a+2*i+1);
	}
      else
	{
	  swap(a+i,a+2*i+2);
	}
    }
  buildHeap(a,2*i+1);
  buildHeap(a,2*i+2);
}
void HeapSort(int a[],int len)
{
  
}




