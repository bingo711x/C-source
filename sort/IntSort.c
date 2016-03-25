/*
 * author : bingo
 * Date : 2016-03-23
 * Description:
 *   This functions sort an array of Int from little to big.
 * functions:
 *   BubbleSort
 *
 */
#include <stdio.h>
#include <malloc.h>

#include "prepareFun.h"

void BubbleSort(int a[],int len)
{
  if(a == NULL && len == 0)
    {
      return;
    }

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
  if(a == NULL && len == 0)
    {
      return;
    }

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
  if(a == NULL && len == 0)
    {
      return;
    }

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
  if(left < len && a[left] > a[maxIndex])
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
  if(a == NULL && len == 0)
    {
      return;
    }

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


void QuickSort(int a[],int start,int end)
{
  if(a == NULL && end <= start)
    {
      return;
    }

  int i = start,j = end;
  int status = a[i];

  if(i >= j)
    {
      return;
    }

  while(i < j)
    {
      while(i<j && a[j] >= status)
	{
	  j--;
	}
      a[i] = a[j];

      while(i < j && a[i] <= status)
	{
	  i++;
	}
      a[j] = a[i];
    }
      a[i] = status;
      QuickSort(a,start,i - 1);
      QuickSort(a,i + 1,end);
 }

void mergeRows(int a[],int start,int middle,int end)
{
  int k = 0;
  int i = start,j = middle + 1;
  int length = end - start +1;

  //printf("\nlength:%d\n",length);

  int *ptmp = (int *)malloc((end - start + 1)*sizeof(int));
  
  while(i <= middle && j <= end)
    {
      if(a[i] < a[j])
	{
	  *(ptmp + k) = a[i];
	  k++;
	  i++;
	}
      else
	{
	  *(ptmp + k) = a[j];
	  k++;
	  j++;
	}
    }
  //printf("start:%d\n",start);
  //printf("i:%d,middle:%d\n",i,middle);
  //printf("j:%d,end:%d\n",j,end);
  //printf("k:%d,length:%d\n",k,length);
  //printArray(ptmp,length);
   
  while(i <= middle)
    {
      *(ptmp + k) = a[i];
      k++;
      i++;
    }
  while(j <= end)
    {
      *(ptmp + k) = a[j];
      k++;
      j++;
    }
  
  for(i = start;i <= end;i++)
    {
      a[i] = *(ptmp + i - start);
    }
  free(ptmp);
}

void MergeSort(int a[],int start,int end)
{
  if((end - start) <= 0)
    {
      return;
    }
  
  int middle = (end + start)/2;
  MergeSort(a,start,middle);
  MergeSort(a,middle + 1,end);
  mergeRows(a,start,middle,end);
}
