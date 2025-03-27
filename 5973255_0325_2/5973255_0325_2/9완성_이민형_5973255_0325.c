/*
시작
	- 정수 n과 크기가 1000인 정수형 배열 arr를 0으로 초기화, 임시 변수 tmp 선언

	- "정수의 개수를 입력하세요:" 출력 후 n 입력받기

	- "n개의 정수를 입력하세요:" 출력
	  for i = 0 to n-1 do
		  입력 arr[i]

	- 버블 정렬을 이용해 오름차순 정렬:
	  for i = 0 to n-1 do
		  for j = 0 to n-2 do
			  if arr[j+1] < arr[j] then
				  tmp = arr[j+1]
				  arr[j+1] = arr[j]
				  arr[j] = tmp

	- "오름차순으로 정렬된 정수들:" 출력
	  for i = 0 to n-1 do
		  출력 arr[i]와 공백
종료
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n, arr[1000] = { 0, };
	int tmp;

	printf("정수의 개수를 입력하세요: ");
	scanf("%d", &n);

	printf("%d개의 정수를 입력하세요: \n", n);
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
	printf("오름차순으로 정렬된 정수들: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}