#define _CRT_SECURE_NO_WARNINGS // Visual Studio의 보안 경고를 무시하기 위한 매크로
#include <stdio.h> // 표준 입출력 함수 사용을 위한 헤더
#include <stdlib.h> // 동적 메모리 할당 함수를 위한 헤더

int main(void)
{
    // 2x2 행렬의 정수 4개 크기만큼 메모리 할당
    int *arr1 = (int*)malloc(4 * sizeof(int)); 
    int *arr2 = (int*)malloc(4 * sizeof(int)); 

    printf("첫 번째 2x2 행렬 입력: \n"); 
    
    // 첫 번째 행렬 입력: 2행 2열 반복
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            scanf("%d", arr1 + i * 2 + j); 
        }
    }

    printf("두 번째 2x2 행렬 입력: \n"); 
    // 두 번째 행렬 입력: 2행 2열 반복
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            scanf("%d", arr2 + i * 2 + j); 
        }
    } 

    printf("행렬 덧셈 결과: \n"); 
    // 각 행렬 원소를 더해 결과 출력
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++)
        {
            int sum = *(arr1 + i * 2 + j) + *(arr2 + i * 2 + j); 
            printf("%d ", sum); 
        }
        printf("\n"); 
    }

    return 0; 
}