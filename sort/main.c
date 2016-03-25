#include <stdio.h>
#include "IntSort.h"
#include "prepareFun.h"

int main()
{
  int arr[] = {56,76,45,83,54,57,63,28,9,7,5,37,87,38,90};
  int len = 15;
  
  printArray(arr,len);
  MergeSort(arr,0,len - 1);
  printArray(arr,len);
  return 0;
}
