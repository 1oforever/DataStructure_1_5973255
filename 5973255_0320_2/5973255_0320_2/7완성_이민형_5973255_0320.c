#define _CRT_SECURE_NO_WARNINGS // scanf ��� �� �߻��� �� �ִ� ���� ��� ����
#include <stdio.h> // ǥ�� ����� �Լ� ����ϱ� ���� ��� ����
#include <stdlib.h> // ǥ�� ���̺귯�� �Լ� ����� ���� ��� ����
#include <string.h> // ���ڿ� ó�� �Լ� ����� ���� ��� ����
#include <ctype.h> // ���� ���� �Լ� ����� ���� ��� ����

// ���� �ڷ��� k�� ���� 
typedef struct {
    int num; // ���� ���� ������ ����
} k;

// �� ���� ���� ����ü k�� ���ϴ� �Լ�
k plus(k a, k b) {
    k resultS = { a.num + b.num }; // a.num�� b.num�� ���� ���� resultS.num�� ����
    return resultS; // ���� ��� ����ü resultS�� ��ȯ
}

// �� ���� ���� ����ü k�� ���� �Լ�
k minus(k a, k b) {
    k resultS = { a.num - b.num }; // a.num���� b.num�� �� ���� resultS.num�� ����
    return resultS; // ���� ��� ����ü resultS�� ��ȯ
}

// �� ���� ���� ����ü k�� ���ϴ� �Լ�
k multiply(k a, k b) {
    k resultS = { a.num * b.num }; // a.num�� b.num�� ���� ���� resultS.num�� ����
    return resultS; // ���� ��� ����ü resultS�� ��ȯ
}

// �� ���� ���� ����ü k�� ������ �Լ� (������ ���� 0�̸� ���� �޽��� ��� �� ����)
float divide(k a, k b) {
    if (b.num == 0) { // ���� b.num�� 0�̸� 0���� ���� �� ����
        printf("0���� ���� �� �����ϴ�.\n"); // ���� �޽��� ���
        exit(1); // ���α׷��� ����
    }
    return (float)a.num / b.num; // a.num�� b.num���� ���� ����� float �������� ��ȯ
}

// �Ǽ� �ڷ��� r�� ������. �� ����ü�� �Ϲ����� �Ǽ� ���� ������.
typedef struct {
    double num; // �Ǽ� ���� ������ ����
} r;

// �� ���� �Ǽ� ����ü r�� ���ϴ� �Լ�
r r_plus(r a, r b) {
    r resultS = { a.num + b.num }; // a.num�� b.num�� ���� ���� resultS.num�� ����
    return resultS; // ���� ��� resultS�� ��ȯ
}

// �� ���� �Ǽ� ����ü r�� ���� �Լ�
r r_minus(r a, r b) {
    r resultS = { a.num - b.num }; // a.num���� b.num�� �� ���� resultS.num�� ����
    return resultS; // ���� ��� resultS�� ��ȯ
}

// �� ���� �Ǽ� ����ü r�� ���ϴ� �Լ�
r r_multiply(r a, r b) {
    r resultS = { a.num * b.num }; // a.num�� b.num�� ���� ���� resultS.num�� ����
    return resultS; // ���� ��� resultS�� ��ȯ
}

// �� ���� �Ǽ� ����ü r�� ������ �Լ� (������ ���� 0�̸� ���� �޽��� ��� �� ����)
r r_divide(r a, r b) {
    if (b.num == 0.0) { // ���� b.num�� 0.0�̸� 0���� ���� �� ����
        printf("0���� ���� �� �����ϴ�.\n"); // ���� �޽��� ���
        exit(1); // ���α׷��� ����
    }
    r resultS = { a.num / b.num }; // a.num�� b.num���� ���� ���� resultS.num�� ����
    return resultS; // ���� ��� resultS�� ��ȯ
}

// ���� ���ڸ� �ǳʶٴ� �Լ�: ���ڿ����� ������ ������ �����͸� ���� ���ڷ� �̵�
void skipSpace(const char** s) {
    while (isspace(**s)) { // ���� ����Ű�� ���ڰ� �������� �˻�
        (*s)++; // �����̸� ������ s�� ���� ���ڷ� �̵�
    }
}

// ���ڿ����� �Ǽ� ������ ���ڸ� �о� r ����ü�� ��ȯ�ϴ� �Լ�
r readNumber(const char** s) {
    skipSpace(s); // ���� ������ ���� ���ڸ� ��� �ǳʶٱ�
    r resultS; // ����� ������ r ����ü ���� ����
    char* endPtr; // ���� �бⰡ ���� ��ġ�� ������ ������ ����
    resultS.num = strtod(*s, &endPtr); // ���ڿ� s���� �Ǽ��� �о� resultS.num�� ����, endPtr�� �бⰡ ���� ��ġ�� ����Ŵ
    if (*s == endPtr) { // ���� ���� ���ڰ� ������ 
        printf("�߸��� �����Դϴ�.\n"); // ���� �޽��� ���
        exit(1); // ���α׷� ����
    }
    *s = endPtr; // ������ s�� ���� �бⰡ ���� ��ġ�� �̵�
    return resultS; // ���� ���ڰ� ����ִ� r ����ü�� ��ȯ
}

// ������ ������ ������ ó���ϴ� �Լ� (���� �̸� readTerm -> ���� �� readRanking)
// �� �Լ��� �켱������ ���� ������ ���� ó����
r readRanking(const char** s) {
    r resultS = readNumber(s); // ù ��° ���ڸ� �о� resultS�� ����
    skipSpace(s); // ������ �յ��� ������ �ǳʶٱ�
    while (**s == '*' || **s == '/') { // ���� ���ڰ� '*' �Ǵ� '/'�� ���� �ݺ�
        char op = **s; // ���� �����ڸ� ���� op�� ���� ('*' �Ǵ� '/')
        (*s)++; // ������ ���� ���ڷ� ������ s�� �̵�
        r nextNum = readNumber(s); // ���� ���ڸ� �о� nextNum�� ����
        if (op == '*')
            resultS = r_multiply(resultS, nextNum); // '*' �����̸� �� ���ڸ� ����
        else  // op == '/'
            resultS = r_divide(resultS, nextNum);  // '/' �����̸� �� ���ڸ� ����
        skipSpace(s); // ���� ���� ���� ���� ���� �ǳʶٱ�
    }
    return resultS; // ������ ������ ���� ����� ��ȯ
}

// ������ ���� ������ ó���ϴ� �Լ� (���� �̸� readExpression -> ���� �� readAll)
// �� �Լ��� ��ü ������ ó����
r readAll(const char** s) {
    r resultS = readRanking(s); // ù ��° ��(����/������ ���)�� �о� resultS�� ����
    skipSpace(s); // ���� ���� �ǳʶٱ�
    while (**s == '+' || **s == '-') {  // ���� ���ڰ� '+' �Ǵ� '-'�� ���� �ݺ�
        char op = **s; // ���� �����ڸ� ���� op�� ���� ('+' �Ǵ� '-')
        (*s)++; // ������ ���� ���ڷ� ������ s�� �̵�
        r nextRanking = readRanking(s); // ���� ��(����/������ ���)�� �о� nextRanking�� ����
        if (op == '+')
            resultS = r_plus(resultS, nextRanking); // '+' �����̸� �� ���� ����
        else  // op == '-'
            resultS = r_minus(resultS, nextRanking); // '-' �����̸� �� ���� ��
        skipSpace(s); // ���� ���� ���� ���� ���� �ǳʶٱ�
    }
    return resultS; // ��ü ������ ���� ����� ��ȯ
}

int main() {
    int first, second; // ����ڷκ��� �Է¹��� ������ ������ ������

    // ù ��° ���� ������ �Է¹���
    printf("ù��° ���� ������ �Է��ϼ���: ");
    if (scanf("%d", &first) != 1 || first <= 0) { // �Է��� �����ϰų� ���� ������ �ƴϸ�
        printf("Error: ���� ������ �Է� �����մϴ�.\n"); // ���� �޽��� ���
        return 1; // ���α׷��� ����
    }

    // �� ��° ���� ������ �Է¹���
    printf("�ι�° ���� ������ �Է��ϼ���: ");
    if (scanf("%d", &second) != 1 || second <= 0) { // �Է��� �����ϰų� ���� ������ �ƴϸ�
        printf("Error: ���� ������ �Է� �����մϴ�.\n"); // ���� �޽��� ���
        return 1; // ���α׷��� ����
    }

    // ���ۿ� �����ִ� ���� ���� ���� 
    while (getchar() != '\n');

    // ���� ����ü ���� ����: ����ڷκ��� �Է¹��� ���� ����ü k�� ����
    k num1 = { first }; // ù ��° ������ �����ϴ� ����ü ���� num1
    k num2 = { second }; // �� ��° ������ �����ϴ� ����ü ���� num2

    // ���� ���� �Լ����� ����Ͽ� ��� 
    k addResult = plus(num1, num2); // num1�� num2�� ���� ����� ���
    k subResult = minus(num1, num2); // num1���� num2�� �� ����� ���
    k mulResult = multiply(num1, num2); // num1�� num2�� ���� ����� ���
    float divResult = divide(num1, num2); // num1�� num2�� ���� ����� ���

    // ���� ���� ���� ��� ���
    printf("����: %d\n", addResult.num); // ���� ��� ���
    printf("����: %d\n", subResult.num); // ���� ��� ���
    printf("����: %d\n", mulResult.num); // ���� ��� ���
    printf("������: %.2f\n", divResult); // ������ ��� �Ҽ��� ��° �ڸ����� ��� 

    // ���� ����� ���� �κ� ����
    char expr[256]; // ������ ������ ũ�Ⱑ 256�� ���ڿ� �迭 ����
    printf("����� ������ �Է��ϼ��� (��: 3+5*2-8/4): "); 
    if (fgets(expr, sizeof(expr), stdin) == NULL) { // ǥ�� �Է����κ��� ������ ���� 
        printf("�Է� ����.\n"); // ���� �޽��� ���
        return 1; // ���α׷� ����
    }

    // �Է¹��� ���ڿ����� ���� ���ڸ� ���� 
    expr[strcspn(expr, "\n")] = '\0';

    const char* p = expr;   // ���� ���ڿ��� ���� �ּҸ� ����Ű�� ������ ���� ����
    r result = readAll(&p); // ���� ��ü�� �Ľ��Ͽ� ��� ����� result�� ����

    // ������ ��� ���� �Ŀ��� ���� �Է��� �ִٸ� ���� ó��
    skipSpace(&p); // ���� ���� ���ڸ� �ǳʶ�
    if (*p != '\0') { 
        printf("�߸��� �����Դϴ�.\n"); // ���� ���ڿ��� ���� �������� �ʾҴٸ� ���� �޽��� ���
        return 1; // ���α׷� ����
    }

    // ���� ��� ��� ���
    printf("���: %lf\n", result.num);

    return 0; // ���α׷��� ���������� ������
}
