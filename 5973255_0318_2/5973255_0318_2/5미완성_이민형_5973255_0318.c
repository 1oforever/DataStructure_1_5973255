#define _CRT_SECURE_NO_WARNINGS  // scanf ���� ��� ����
#include <stdio.h> // ����� �Լ��� ����ϱ� ���� �������
#include <stdlib.h> // exit �Լ��� ����ϱ� ���� �������

// ���� ������ ���� ��Ģ���� �߻� �ڷ��� ����
typedef struct { 
    int value; // ���� ������ �����ϴ� ����ü 
} k;

// ���ϱ�
k plus(k a, k b) {
    k result = { a.value + b.value }; // �� ���� ���� ����� ����
    return result; // ��� ��ȯ 
}

// ����
k minus(k a, k b) {
    k result = { a.value - b.value }; // �� ���� �� ����� ����
    return result; // ��� ��ȯ 
}

// ���ϱ�
k multiply(k a, k b) {
    k result = { a.value * b.value }; // �� ���� ���� ����� ����
    return result; // ��� ��ȯ 
}

// ������ 
k divide(k a, k b) {
    if (b.value == 0) { // ������ ���� 0�̸� ���� ó�� 
        printf("0���� ���� �� �����ϴ� \n"); // ���� �޽��� ��� 
        exit(1); // ���α׷� ���� 
    }
    k result = { a.value / b.value };  // �� ���� ���� ����� ���� 
    return result; // ��� ��ȯ 
}

int main() {
    int num1, num2; // ������ �Է¹��� ������ ���� 
    char c; // �����ڸ� ������ ������ ���� 

    // ����� �Է� 
    printf("���� �Է��ϼ���: "); // �Է¸޽��� ���
    if (scanf("%d%c%d", &num1, &c, &num2) != 3) { 
        printf("Error: �߸��� �Է� �����Դϴ� \n"); // ������ �߸��Ǿ��� �� ���� �޽��� ��� 
        return 1; // ���α׷��� ���� 
    }

    if (num1 <= 0 || num2 <= 0) { // �Էµ� ���ڰ� 0 ���϶�� ���� �޽��� ��� 
        printf("Error: ���� ������ �Է� �����մϴ� \n");
        return 1; // ���α׷��� ���� 
    }

    k a = { num1 }; // ù��° ���� ������ ����ü�� ����
    k b = { num2 }; // �ι�° ���� ������ ����ü�� ���� 
    k result; // ����� ������ ����ü ���� 

    // ó��
    switch (c) { 
    case '+': result = plus(a, b); break; // ���ϱ� ��� 
    case '-': result = minus(a, b); break; // ���� ��� 
    case '*': result = multiply(a, b); break; // ���ϱ� ��� 
    case '/': result = divide(a, b); break; // ������ ��� 
    default:
        printf("Error: �������� �ʴ� �������Դϴ� \n");
        return 1; // �߸��� ������ �Է� �ÿ� �����޽����� ����ϰ� ���α׷� ���� 
    }

    // ��� ���
    printf("���: %d\n", result.value); // ��� ����� ����Ѵ� 
    return 0; // ���α׷��� ����
}