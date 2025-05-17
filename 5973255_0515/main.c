#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"

int main() {
	linkedList_h* myList = createCLinkedList();
	int menu, value, pos, target;

	while (1) {
		printf("======= 연결 리스트 메뉴 =======\n");
		printf("1) insertFirst (리스트의 제일 앞에 삽입) \n");
		printf("2) insertLast (리스트의 제일 뒤에 삽입) \n");
		printf("3) insertMiddle (특정 값 뒤에 삽입) \n");
		printf("4) insertNthNode (N번째 위치 삽입) \n");
		printf("5) deleteNode (특정 값 삭제) \n");
		printf("6) pirnt Head/Tail \n");
		printf("0) Program Stop \n");
		printf("Select menu ▶ ");
		scanf("%d", &menu);

		switch (menu) {
		case 1:
			printf("제일 앞에 삽입할 값을 입력하세요: ");
			scanf("%d", &value);
			insertFirstNode(myList, value);
			break;
		case 2:
			printf("제일 뒤에 삽입할 값을 입력하세요: ");
			scanf("%d", &value);
			insertLastNode(myList, value);
			break;
		case 3:
			printf("기준 값과 삽입할 값을 입력하세요 (위치, 값): ");
			scanf("%d %d", &target, &value);
			insertMiddleNode(myList, target, value);
			break;
		case 4:
			printf("삽입할 값과 위치를 입력하세요 (예: 값 위치): ");
			scanf("%d %d", &value, &pos);
			insertNthNode(myList, pos, value);
			break;
		case 5:
			printf("삭제할 값을 입력하세요: ");
			scanf("%d", &value);
			deleteNode(myList, value);
			break;
		case 6:
			printHeadTail(myList);
			break;
		case 0:
			destroyCLinkedList(myList);
			return 0;
		default:
			printf("잘못 입력하였습니다. 다시 입력해주세요. \n");
		}

		printList(myList);
	}
	return 0;
}