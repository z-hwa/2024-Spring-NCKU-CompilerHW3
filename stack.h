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

	struct stackNode *next;
}Stack;

Stack* top(Stack **stack);
bool push(Stack **stack, Stack data);
Stack pop(Stack **stack);

#endif
