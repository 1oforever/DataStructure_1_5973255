#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"

linkedList_h* createCLinkedList(void) {
	linkedList_h* L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	L->tail = NULL;
	return L;
}

void insertFirstNode(linkedList_h* L, elementType item) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;

	if (L->head == NULL) {
		L->head = newNode;
		L->tail = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = L->head;
		L->tail->link = newNode;
		L->head = newNode;
	}
}

void insertLastNode(linkedList_h* L, elementType item) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;

	if (L->head == NULL) {
		L->head = newNode;
		L->tail = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = L->head;
		L->tail->link = newNode;
		L->tail = newNode;
	}
}

void insertMiddleNode(linkedList_h* L, elementType target, elementType item) {
	if (L->head == NULL) return;
	listNode* curr = L->head;
	do {
		if (curr->data == target) {
			listNode* newNode = (listNode*)malloc(sizeof(listNode));
			newNode->data = item;
			newNode->link = curr->link;
			curr->link = newNode;
			if (curr == L->tail) L->tail = newNode;
			return;
		}
		curr = curr->link;
	} while (curr != L->head);
}

void insertNthNode(linkedList_h* L, int n, elementType item) {
	if (n < 0) return;
	if (n == 0) {
		insertFirstNode(L, item);
		return;
	}

	listNode* prev = L->head;
	for (int i = 0; i < n - 1 && prev->link != L->head; i++) {
		prev = prev->link;
	}
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = prev->link;
	prev->link = newNode;
	if (prev == L->tail) L->tail = newNode;
}

void deleteNode(linkedList_h* L, elementType item) {
	if (L->head == NULL) return;
	listNode* curr = L->head;
	listNode* prev = L->tail;
	do {
		if (curr->data == item) {
			if (curr == L->head) L->head = curr->link;
			if (curr == L->tail) L->tail = prev;
			prev->link = curr->link;
			free(curr);
			if (L->head == L->tail && L->head->data == item) {
				L->head = NULL;
				L->tail = NULL;
			}
			return;
		}
		prev = curr;
		curr = curr->link;
	} while (curr != L->head);
}

void printList(linkedList_h* L) {
	if (L->head == NULL) {
		printf("입력된 값이 없습니다. \n");
		return;
	}
	listNode* curr = L->head;
	printf("원형 리스트: ");
	do {
		printf("[%d] ", curr->data);
		curr = curr->link;
	} while (curr != L->head);
	printf("\n");
}

void printHeadTail(linkedList_h* L) {
	if (L->head != NULL && L->tail != NULL) {
		printf("Head: %d, Tail: %d\n", L->head->data, L->tail->data);
	}
	else {
		printf("입력된 값이 없습니다. \n");
	}
}

void destroyCLinkedList(linkedList_h* L) {
	if (L->head == NULL) {
		free(L);
		return;
	}
	listNode* curr = L->head->link;
	listNode* temp;
	while (curr != L->head) {
		temp = curr;
		curr = curr->link;
		free(temp);
	}
	free(L->head);
	free(L);
}