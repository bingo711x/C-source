#include "OneDirList.h"
#include <stdio.h>
#include <malloc.h>

List initList(void)
{
  List pList = NULL;

  pList = (List)malloc(sizeof(ListData));
  pList -> head = NULL;
  pList -> len = 0;

  return pList;
}

void delList(List list)
{
  if(isNull(list))
    {
      return;
    }
  
  Node pNode = list -> head;
  Node tmp = NULL;

  while(pNode != NULL)
    {
      tmp = pNode;
      pNode = pNode -> pnext;
      free(tmp);
    }
  free(list);
}

bool isNull(List list)
{
  return (list == NULL);
}

int length(List list)
{
  return (list -> len);
}

void append(List list,Node node)
{
  Node pNode = list -> head;
  
  if(pNode == NULL)
    {
      list -> head = node;
      node -> pnext = NULL;
      (list -> len)++;
      return;
    }

  while(pNode -> pnext != NULL)
    {
      pNode = pNode -> pnext;
    }
  pNode -> pnext = node;
  node -> pnext = NULL;
  (list -> len)++;
}

void insNode(List list,int pos,Node node)
{
  if(list == NULL || pos > (list -> len) || node == NULL)
    {
      printf("error occur when insert node\n");
      return; 
    }

  int i = 0;
  Node pNode = list -> head;
  Node tmp = NULL;
  if(pNode == NULL || pos == 0)
    {
      list -> head = node;
      node -> pnext = NULL;
      (list -> len)++;
      return;
    }

  while(i < pos - 1)
    {
      pNode = pNode -> pnext;
      i++;
    };
  node -> pnext = pNode -> pnext;
  pNode -> pnext = node;
  (list -> len)++;
}
/**/
void delNode(List list,int pos)
{
  if(list == NULL || pos >= (list -> len))
    {
      printf("error occur when delete node\n");
      return;
    }
  
  int i = 0;
  Node pNode = list -> head;
  Node tmp;

  if(pos == 0)
    {
      list -> head = pNode -> pnext;
      free(pNode);
      (list -> len)--;
      return;
    }
  while(i < pos - 1)
    {
      pNode = pNode -> pnext;
      i++;
    }
  tmp = pNode -> pnext;
  pNode -> pnext = tmp -> pnext;
  free(tmp);
  (list -> len)--;
}

Node findLast(List list)
{
  Node pNode = list -> head;

  if(list -> len == 0)
    {
      return pNode;
    }
  while(pNode -> pnext != NULL)
    {
      pNode = pNode -> pnext;
    }
  return pNode;
}

Node findValue(List list,int pos)
{
  if(pos >= list -> len)
    {
      return NULL;
    }
  Node pNode = list -> head;
  int i = 0;
  while(i < pos)
    {
      pNode = pNode -> pnext;
      i++;
    }
  return pNode;
}

bool equal(Node a,Node b)
{
  if(a == b || a -> element == b -> element)
    {
      return TRUE;
    }
  else
    {
      return FALSE;
    }
}


void printList(List list)
{
  if(isNull(list))
    {
      return;
    }
  Node pNode = list -> head;
  while(pNode != NULL)
    {
      printNode(pNode);
      pNode = pNode -> pnext;
    }
}

void printNode(Node node)
{
  if(node == NULL)
    {
      return;
    }
  printf("element: %d\n",node -> element);
}
