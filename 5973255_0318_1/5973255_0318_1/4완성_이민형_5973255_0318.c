/*
* 1. �����͸� �о���δ�. 2. ����� �����Ѵ�. 3. ����� ����Ѵ�
* �̷��� ���̾�׷��� flowchart��� �Ѵ�. 
* �������� �� ������� �����ϰ�, �� �� �������� �ذ��ϰ�, �ذ�� �� �������� 
* �����ϴ� ������� ��ü ������ �ذ��ϴ� ����� ���Ұ� �����̶�� �Ѵ�. 
* pseudo code�� �˰����� ����Ǵ� �� ����� �۵� ���� ǥ���ϱ� ���� �ڵ��̴�. 
* flowchart�� ���α׷��� ���� �帧�� ����ȭ�Ͽ� �ð������� ��Ÿ�� ���̾�׷��� �� �����̴�. 

������ ���� num, i, j, count=�ʱ�ȭ;
���� �Է�(num);
for (i >> 1 ~ num-1 ��ŭ �ݺ�)
	for (j >> 1 ~ i ��ŭ �ݺ�)
		if (i ������ j �� ������ == 0)
			count = count + 1;
	if (count == 2)
		print(n���� ���� �Ǽ� i);
	count = �ʱ�ȭ
*/

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
int main()
{
	int num, i, j, count = 0;

	printf("���ڸ� �Է��ϼ���: ");
	scanf("%d", &num);
	printf("%d ������ �Ҽ�: ", num);

	for (i = 1; i < num; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				count += 1;
			}
		}
		if (count == 2)
		{
			printf("%d ", i);
		}
		count = 0;
	}

	return 0;
}