#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "linkedList.h"

void insertToList(LinkedList **list, LinkedList nodeData) {
	// 建立新節點
    LinkedList *newNode = (LinkedList *)malloc(sizeof(LinkedList));
	
    newNode->scopeLevel = nodeData.scopeLevel;
	newNode->list = nodeData.list;
	newNode->listSize = nodeData.listSize;
	
	//newNode->index = nodeData.index;
	newNode->var = nodeData.var;
	newNode->msg = nodeData.msg;
	
	newNode->next = NULL;

    // 如果連結串列是空的，則將新節點設置為頭部
    if (*list == NULL) {
        *list = newNode;
        return;
    }

    // 否則找到最後一個節點，並將新節點連結到它後面
    LinkedList *lastNode = *list;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
	}
	
    lastNode->next = newNode;	
}

//根據變數名稱在linkedlist中獲得儲存變數的東東
LinkedList* getByName(LinkedList **list, char* name, char op) {
	if(*list == NULL) {
		printf("this is a empty list");
		return NULL;
	}

	//using pointer to find the stack
	LinkedList *pointer = *list;
	bool find = false;

	while(pointer != NULL) {
		Object *var = pointer->var;
		SymbolData *sym = var->symbol;
		char *id = sym->name;

		if(strcmp(id, name) == 0){
			if(op == 'f' && var->type == OBJECT_TYPE_FUNCTION) {
				find = true;
				break;
			} else if(op == 'v' && var->type != OBJECT_TYPE_FUNCTION) {
				find = true;
				break;
			}
		}	

		pointer = pointer->next;
	}

	if(find == true) return pointer;
	else return NULL;
	
}

Object* getByIndex(LinkedList **list, int index) {
	if(*list == NULL) {
		printf("empty list\n");
	}

	LinkedList *lp = *list;
	while(lp != NULL && index > 0) {
		lp = lp->next;
		index--;
	}

	return lp->var;
}

LinkedList* getByKey(LinkedList **list, int _key) {
	if(*list == NULL) {
		printf("this is a empty list");
		return NULL;
	}

	//using pointer to find the stack
	LinkedList *pointer = *list;
	bool find = false;
	//int key = pointer->scopeLevel;

	while(pointer != NULL) {
		//if(type == 'v') key = pointer->index;
		//else if (type == 's') key = pointer->scopeLevel;
		if(pointer->scopeLevel == _key) {
			find = true;
			break;
		}	

		pointer = pointer->next;
	}

	if(find == true) return pointer;
	else return NULL;
}


void deleteHead(LinkedList **list) {
	if(*list == NULL) return ;
	
	LinkedList *lp = *list;
	*list = (*list)->next;
	free(lp);
}

void deleteTail(LinkedList **list) {
	if(*list == NULL) return;

	LinkedList *lp = *list, *pr = *list;
	while(lp->next != NULL) {
		pr = lp;
		lp = lp->next;
	}

	pr->next = NULL;
	free(lp);
}
