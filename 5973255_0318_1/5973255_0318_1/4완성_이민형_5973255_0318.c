/*
* 1. 데이터를 읽어들인다. 2. 계산을 수행한다. 3. 결과를 출력한다
* 이러한 다이어그램을 flowchart라고 한다. 
* 문제들을 부 문제들로 분할하고, 각 부 문제들을 해결하고, 해결된 부 문제들을 
* 통합하는 방식으로 전체 문제를 해결하는 방식을 분할과 정복이라고 한다. 
* pseudo code란 알고리즘이 수행되는 각 모듈의 작동 논리를 표현하기 위한 코드이다. 
* flowchart란 프로그램의 실행 흐름을 도식화하여 시각적으로 나타난 다이어그램의 한 종류이다. 

정수형 변수 num, i, j, count=초기화;
정수 입력(num);
for (i >> 1 ~ num-1 만큼 반복)
	for (j >> 1 ~ i 만큼 반복)
		if (i 나누기 j 의 나머지 == 0)
			count = count + 1;
	if (count == 2)
		print(n보다 작은 실수 i);
	count = 초기화
*/

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
int main()
{
	int num, i, j, count = 0;

	printf("숫자를 입력하세요: ");
	scanf("%d", &num);
	printf("%d 이하의 소수: ", num);

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