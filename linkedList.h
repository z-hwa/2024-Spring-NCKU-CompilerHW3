#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "stack.h"
#include "compiler_common.h"

typedef struct node{
	int scopeLevel;	//表示scope的level
	struct node *list;	//用於儲存變數的第二維度陣列
	int listSize;	//標示第二維度陣列的大小

	//int index;	//第二維度中用於標示該元素的位置
	Object *var;	//第二維度中用於儲存變數

	char* msg;

	struct node *next;
}LinkedList;

LinkedList* getByName(LinkedList **list, char *name, char op);

//插入stack的位置，在連結串列的尾巴
void insertToList(LinkedList **list, LinkedList data);

Object* getByIndex(LinkedList **list, int index);

//回傳指定key的資料
LinkedList* getByKey(LinkedList **list, int key);

void deleteHead(LinkedList **list);

void deleteTail(LinkedList** list);

#endif
