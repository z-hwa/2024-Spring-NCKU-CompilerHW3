#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 

#include "stack.h"

/*typedef struct node{
    int value;
    struct node *next;
} node;*/

Stack* top(Stack **head) {
	if(*head == NULL) {
		//printf("this stack is empty\n");
		return NULL;
	}

	return *head;
}

Stack* getByLevel(Stack **stack, int key) {
	if(*stack == NULL) {
		printf("empty stack\n");
		return NULL;
	}

	Stack *sp = *stack;
	int nowLevel = sp->scopeLevel;

	while(sp != NULL && nowLevel > key) {
		sp = sp->next;
		nowLevel--;
	}

	if(nowLevel == key) return sp;
	else return NULL;	
}

bool push(Stack **head, Stack nodeData){
	Stack *newnode = (Stack *)malloc(sizeof(Stack));
	
	newnode->scopeLevel = nodeData.scopeLevel;
	newnode->msg = nodeData.msg;

	newnode->index = nodeData.index;
	newnode->indexSt = nodeData.indexSt;
	newnode->addr = nodeData.addr;

    newnode->next = (*head);
    (*head) = newnode;
    return true;
}

bool pushAddr(Stack **head, int addr) {
	Stack data;
	data.addr = addr;
	push(head, data);
	return true;
}

int frontAddr(Stack **head){
    if((*head) == NULL) {
        return -1;
	}

	int addr = (*head)->addr;
	pop(head);
	return addr;
}

Stack pop(Stack **head){
    if((*head) == NULL) {
		Stack empty;
        return empty;
	}

	Stack result;
	//result.value = (*head)->value;
	result.scopeLevel = (*head)->scopeLevel;
	result.msg = (*head)->msg;

    Stack *temp = (*head);
    (*head) = (*head)->next;
    free(temp);
    return result;
}