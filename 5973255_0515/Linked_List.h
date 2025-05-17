#pragma once

typedef int elementType;

typedef struct ListNode {
	elementType data;
	struct ListNode* link;
} listNode;

typedef struct {
	listNode* head;
	listNode* tail; 
} linkedList_h;

linkedList_h* createCLinkedList(void);
void insertFirstNode(linkedList_h* L, elementType item);
void insertLastNode(linkedList_h* L, elementType item);
void insertMiddleNode(linkedList_h* L, elementType target, elementType item); 
void insertNthNode(linkedList_h* L, int n, elementType item); 
void deleteNode(linkedList_h* L, elementType item);
void printList(linkedList_h* L);
void printHeadTail(linkedList_h* L); 
void destroyCLinkedList(linkedList_h* L);