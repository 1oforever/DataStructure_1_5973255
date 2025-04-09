#pragma warning(disable:1996)
#include <stdio.h>
#define MAX_SIZE 20 // �ִ� �׸� �� ����

// ��� ����� �� �׸��� �����ϴ� ����ü 
typedef struct {
    int row; // �� ��ȣ 
    int col; // �� ��ȣ 
    int value; // �ش� ��ġ �� 
} data;

// ��� ��� ��ü�� �����ϴ� ����Ʈ 
typedef struct {
    data arr[MAX_SIZE]; // ������ �迭
    int size; // ���� ����� �׸� ��
    int max_row; // �Էµ� �׸��߿��� �ִ� �� ��ȣ
    int max_col; // �Էµ� �׸��߿��� �ִ� �� ��ȣ
} list;

// ����Ʈ�� ���ο� �׸� ����
void insert(list* l, int r, int c, int v) {
    if (l->size >= MAX_SIZE) return; // �ִ� ũ�� �ʰ� �� ���� �ߴ�

    l->arr[l->size].row = r; // ��(row)
    l->arr[l->size].col = c; // ��(column) 
    l->arr[l->size].value = v; // ��(value) 
    l->size++;

    // �ִ� ��/�� ���� ����
    if (r > l->max_row) l->max_row = r;
    if (c > l->max_col) l->max_col = c;
}

// row, column�� �ش��ϴ� �׸��� �ִ��� ã��
int find(list* l, int r, int c) {
    for (int i = 0; i < l->size; i++) {
        if (l->arr[i].row == r && l->arr[i].col == c) return i;
    } // ������ �ε����� ��ȯ, ������ -1 
    return -1;
}

// ��� ������ �Է�
void input(list* l) {
    int r, c, v;
    printf("����� �Է��Ͻÿ�? (-1�Է� �� ����� �Է��� �����)\n");
    while (1) {
        scanf("%d", &r);
        if (r == -1) break;
        scanf("%d %d", &c, &v);

        int idx = find(l, r, c);
        if (idx != -1) {
            // �̹� �ִ� ��ġ��� ���� ����
            l->arr[idx].value += v;
        }
        else {
            // ���ο� ��ġ��� ����
            insert(l, r, c, v);
        }
    }
}

// �� ���� �������� ����
void sort(list* l) {
    for (int i = 0; i < l->size - 1; i++) {
        for (int j = i + 1; j < l->size; j++) {
            if (l->arr[i].row > l->arr[j].row ||
                (l->arr[i].row == l->arr[j].row && l->arr[i].col > l->arr[j].col)) {
                // ����
                data temp = l->arr[i];
                l->arr[i] = l->arr[j];
                l->arr[j] = temp;
            }
        }
    }
}

// ���� ����� ��� 
void print(list* l) {
    printf("�� ����� ��\n");
    printf("List:  size = %d, last = %d\n", MAX_SIZE, l->size - 1);
    printf("Items:\n");
    for (int i = 0; i < l->size; i++) {
        printf("    [%d] %d, %d, %d\n", i, l->arr[i].row, l->arr[i].col, l->arr[i].value);
    }
}

int main() {
    // �� ���� ��� ����Ʈ ���� �� �ʱ�ȭ
    list a = { .size = 0, .max_row = 0, .max_col = 0 };
    list b = { .size = 0, .max_row = 0, .max_col = 0 };

    // �� ��� �Է�
    input(&a);
    input(&b);

    // ��� B�� A�� ���� (���� ��ġ�� �� ����, ������ ���� ����)
    for (int i = 0; i < b.size; i++) {
        int r = b.arr[i].row;
        int c = b.arr[i].col;
        int v = b.arr[i].value;

        int idx = find(&a, r, c);
        if (idx != -1) {
            a.arr[idx].value += v;
        }
        else {
            insert(&a, r, c, v);
        }
    }

    // ���� �� ���
    sort(&a);
    print(&a);

    return 0;
}
