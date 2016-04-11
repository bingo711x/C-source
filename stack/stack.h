#ifndef STACK_H
#define STACK_H
/*
 *this is a stack .h file
 */
#define dataType int
#define bool unsigned char
#define TRUE 1
#define FALSE 0
#define NULL (void *)0

typedef struct node *Node;
typedef struct node NodeData;
typedef struct stack *Stack;
typedef struct stack StackData;

struct node
{
  dataType element;
  Node pnext;
}

struct stack
{
  Node head;
};

Stack initStack(void);
void delStack(Stack stack);

bool isNull(Stack stack);
Node pop(Stack stack);
Node top(Stack stack);
void push(Stack stack);

#endif
