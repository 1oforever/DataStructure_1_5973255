/*
����
	- ���� n�� ũ�Ⱑ 1000�� ������ �迭 arr�� 0���� �ʱ�ȭ, �ӽ� ���� tmp ����

	- "������ ������ �Է��ϼ���:" ��� �� n �Է¹ޱ�

	- "n���� ������ �Է��ϼ���:" ���
	  for i = 0 to n-1 do
		  �Է� arr[i]

	- ���� ������ �̿��� �������� ����:
	  for i = 0 to n-1 do
		  for j = 0 to n-2 do
			  if arr[j+1] < arr[j] then
				  tmp = arr[j+1]
				  arr[j+1] = arr[j]
				  arr[j] = tmp

	- "������������ ���ĵ� ������:" ���
	  for i = 0 to n-1 do
		  ��� arr[i]�� ����
����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n, arr[1000] = { 0, };
	int tmp;

	printf("������ ������ �Է��ϼ���: ");
	scanf("%d", &n);

	printf("%d���� ������ �Է��ϼ���: \n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	printf("������������ ���ĵ� ������: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}