/*
����
	- �� ���� 2x2 ����� 0���� �ʱ�ȭ�Ͽ� ����
	���� matrix1[2][2]�� ���������� 0���� �ʱ�ȭ
	���� matrix2[2][2]�� ���������� 0���� �ʱ�ȭ

	- ù ��° ��� �Է� �ޱ�
	��� "ù ��° 2x2 ��� �Է�:"
	for i = 0 to 1 do
		for j = 0 to 1 do
			�Է� matrix1[i][j]

	- �� ��° ��� �Է� �ޱ�
	��� "�� ��° 2x2 ��� �Է�:"
	for i = 0 to 1 do
		for j = 0 to 1 do
			�Է� matrix2[i][j]

	- �� ����� ���� ��� ���
	��� "��� ���� ���:"
	for i = 0 to 1 do
		for j = 0 to 1 do
			sum = matrix1[i][j] + matrix2[i][j]
			��� sum�� ����
		���
����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr1[2][2] = { 0, };
	int arr2[2][2] = { 0, };

	printf("ù ��° 2x2 ��� �Է�: \n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			scanf("%d", &arr1[i][j]);
	}

	printf("�� ��° 2x2 ��� �Է�: \n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			scanf("%d", &arr2[i][j]);
	}
	printf("��� ���� ���: \n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int sum = arr1[i][j] + arr2[i][j];
			printf("%d ", sum);
		}
		printf("\n");
	}
}
