#include <stdio.h>

int main()
{
  int a[] = {4,6,9,12,13,18,27,33,34,36,37,41,48,49,77};
  int b[] = {5,14,17,18,35,42,49,50,63,65,70,78,90,91,103};
  int alen = 15;
  int blen = 15;

  int i,j;
  i=j=0;
  while(i < alen && j < blen)
    {
      while(a[i] < b[j])
	{
	  if(a[i] + 1 == b[j])
	    {
	      printf("{%d, %d}\n",a[i],b[j]);
	      i++;
	      j++;
	    }
	  i++;
	}
      j++;
    }
  return 0;
}
