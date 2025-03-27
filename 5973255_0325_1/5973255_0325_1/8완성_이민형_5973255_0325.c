/*
시작
	- 두 개의 2x2 행렬을 0으로 초기화하여 선언
	선언 matrix1[2][2]를 정수형으로 0으로 초기화
	선언 matrix2[2][2]를 정수형으로 0으로 초기화

	- 첫 번째 행렬 입력 받기
	출력 "첫 번째 2x2 행렬 입력:"
	for i = 0 to 1 do
		for j = 0 to 1 do
			입력 matrix1[i][j]

	- 두 번째 행렬 입력 받기
	출력 "두 번째 2x2 행렬 입력:"
	for i = 0 to 1 do
		for j = 0 to 1 do
			입력 matrix2[i][j]

	- 두 행렬의 덧셈 결과 출력
	출력 "행렬 덧셈 결과:"
	for i = 0 to 1 do
		for j = 0 to 1 do
			sum = matrix1[i][j] + matrix2[i][j]
			출력 sum와 공백
		출력
종료
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr1[2][2] = { 0, };
	int arr2[2][2] = { 0, };

	printf("첫 번째 2x2 행렬 입력: \n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			scanf("%d", &arr1[i][j]);
	}

	printf("두 번째 2x2 행렬 입력: \n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			scanf("%d", &arr2[i][j]);
	}
	printf("행렬 덧셈 결과: \n");
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
