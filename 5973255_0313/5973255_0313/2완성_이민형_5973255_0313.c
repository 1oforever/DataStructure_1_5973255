#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    float k; // �Ǽ��� ������ ���� ����
    printf("�Ǽ��� �Է��ϼ���: "); 
    scanf("%f", &k);

    unsigned int ieee754; 
    // �ε��Ҽ��� ���ڸ� �����ϱ� ���� ���� ����
    // 32��Ʈ �ε��Ҽ��� ���� �����ϴµ� ���
    unsigned int* ptr = (unsigned int*) & k; 
    // k �޸� �ּҸ� unsigned int�� �����ͷ� ��ȯ�Ͽ� ptr�� ���� 
    // >> k�� ��Ʈ���� ����
    ieee754 = *ptr;
    // ������ptr�� ����Ű�� ��ġ ��(k�� ��Ʈ����)�� ieee754�� ����

    unsigned int bu = (ieee754 >> 31) & 1;
    // ��ȣ ��Ʈ�� ����
    
    unsigned int ji = (ieee754 >> 23) & 0xFF;
    // ���� ��Ʈ�� ���� 
    
    unsigned int ga = ieee754 & 0x7FFFFF;
    // ���� ��Ʈ�� ����

    // ��ȣ 1��Ʈ ���
    printf("��ȣ(1��Ʈ): ");
    for (int i = 0; i < 1; i++) {
        printf("%d", (bu >> (1 - 1 - i)) & 1);
    }
    printf("\n");

    // ���� 8��Ʈ ���
    printf("����(8��Ʈ): ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (ji >> i) & 1);
    }
    printf("\n");

    // ���� 23��Ʈ ���
    printf("����(23��Ʈ): ");
    for (int i = 22; i >= 0; i--) {
        printf("%d", (ga >> i) & 1);
    }
    printf("\n");

    return 0;
}
