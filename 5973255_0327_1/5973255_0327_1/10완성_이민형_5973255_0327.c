#define _CRT_SECURE_NO_WARNINGS // Visual Studio�� ���� ��� �����ϱ� ���� ��ũ��
#include <stdio.h> // ǥ�� ����� �Լ� ����� ���� ���
#include <stdlib.h> // ���� �޸� �Ҵ� �Լ��� ���� ���

int main(void)
{
    // 2x2 ����� ���� 4�� ũ�⸸ŭ �޸� �Ҵ�
    int *arr1 = (int*)malloc(4 * sizeof(int)); 
    int *arr2 = (int*)malloc(4 * sizeof(int)); 

    printf("ù ��° 2x2 ��� �Է�: \n"); 
    
    // ù ��° ��� �Է�: 2�� 2�� �ݺ�
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            scanf("%d", arr1 + i * 2 + j); 
        }
    }

    printf("�� ��° 2x2 ��� �Է�: \n"); 
    // �� ��° ��� �Է�: 2�� 2�� �ݺ�
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            scanf("%d", arr2 + i * 2 + j); 
        }
    } 

    printf("��� ���� ���: \n"); 
    // �� ��� ���Ҹ� ���� ��� ���
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