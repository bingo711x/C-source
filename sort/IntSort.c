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

//maintain a maxheap structure
void buildHeap(int a[],int i,int len)
{
  int left = 2*i+1,right = 2*i+2;
  int maxIndex = i;
  
  if(right < len && a[right] > a[maxIndex])
    {
     	maxIndex = right;
    }
  if(left < len && a[left] > a[maxIndex)
    {
    	maxIndex = left;
    }

  if(maxIndex != i)
    {
      swap(a+i,a+maxIndex);
      buildHeap(a,maxIndex,len);
    }
}

void HeapSort(int a[],int len)
{
  int i;
  for(i = (len - 1)/2;i >= 0;i--)
    {
      buildHeap(a,i,len);
    }
  for(i = len-1;i > 0;i--)
    {
      swap(a,a+i);
      buildHeap(a,0,i);
    }
}




