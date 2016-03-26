#ifndef ONE_DIR_LIST_H
#define ONE_DIR_LIST_H

#define dataType int
#define bool unsigned char
#define TRUE 1
#define FALSE 0
#define NULL (void *)0

typedef struct node *Node;
typedef struct node NodeData;
typedef struct list *List;
typedef struct list ListData;

struct node
{
  dataType element;
  Node pnext;
};

struct list
{
  Node head;
  int len;
};

//fuction for this
List initList(void);
void delList(List list);

bool isNull(List list);
int length(List list);
void append(List list,Node node);

/*from 0 and not from 1*/
void insNode(List list,int pos,Node node);
void delNode(List list,int pos);

/*return the pointer to the right Node*/
Node findLast(List list);
Node findValue(List list,int pos);
int findIndex(List list,Node node);

bool equal(Node a,Node b);

void printList(List list);
void printNode(Node node);

#endif

