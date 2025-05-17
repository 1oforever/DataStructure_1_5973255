#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"

int main() {
	linkedList_h* myList = createCLinkedList();
	int menu, value, pos, target;

	while (1) {
		printf("======= ���� ����Ʈ �޴� =======\n");
		printf("1) insertFirst (����Ʈ�� ���� �տ� ����) \n");
		printf("2) insertLast (����Ʈ�� ���� �ڿ� ����) \n");
		printf("3) insertMiddle (Ư�� �� �ڿ� ����) \n");
		printf("4) insertNthNode (N��° ��ġ ����) \n");
		printf("5) deleteNode (Ư�� �� ����) \n");
		printf("6) pirnt Head/Tail \n");
		printf("0) Program Stop \n");
		printf("Select menu �� ");
		scanf("%d", &menu);

		switch (menu) {
		case 1:
			printf("���� �տ� ������ ���� �Է��ϼ���: ");
			scanf("%d", &value);
			insertFirstNode(myList, value);
			break;
		case 2:
			printf("���� �ڿ� ������ ���� �Է��ϼ���: ");
			scanf("%d", &value);
			insertLastNode(myList, value);
			break;
		case 3:
			printf("���� ���� ������ ���� �Է��ϼ��� (��ġ, ��): ");
			scanf("%d %d", &target, &value);
			insertMiddleNode(myList, target, value);
			break;
		case 4:
			printf("������ ���� ��ġ�� �Է��ϼ��� (��: �� ��ġ): ");
			scanf("%d %d", &value, &pos);
			insertNthNode(myList, pos, value);
			break;
		case 5:
			printf("������ ���� �Է��ϼ���: ");
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
			printf("�߸� �Է��Ͽ����ϴ�. �ٽ� �Է����ּ���. \n");
		}

		printList(myList);
	}
	return 0;
}