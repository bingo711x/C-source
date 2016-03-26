#include "OneDirList.h"
#include <stdio.h>
#include <malloc.h>

int main()
{
  List list;
  Node node;
  bool isempty;
  int i;

  list = initList();
  isempty = isNull(list);
  printf("the list is %d\n",isempty);

  for(i = 0;i < 100;i++)
    {
      node = (Node)malloc(sizeof(NodeData));
      node -> element = i;
      node -> pnext = NULL;
      // append(list,node);
      insNode(list,i,node);
    }
  delNode(list,0);
  delNode(list,67);
  
  printList(list);
  printf("the list length : %d\n",list -> len);
  printNode(findLast(list));
  return 0;
}
