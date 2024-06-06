#ifndef _STACK
#define _STACK

#include "compiler_common.h"
#include "linkedList.h"

typedef struct stackNode{
	//用於變數的儲存
	int scopeLevel;
	int index;
	int indexSt;
	//LinkedList* list;	

	//used to message
	const char *msg;

	//used to record tag of address
	int addr;

	struct stackNode *next;
}Stack;

Stack* top(Stack **stack);
bool push(Stack **stack, Stack data);
bool pushAddr(Stack **head, int addr);
int frontAddr(Stack **head);
Stack pop(Stack **stack);

#endif
