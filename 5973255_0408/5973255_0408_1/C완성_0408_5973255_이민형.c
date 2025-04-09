#pragma warning(disable:1996)
#include <stdio.h>
#define MAX_SIZE 20 // 최대 항목 수 정의

// 희소 행렬의 한 항목을 저장하는 구조체 
typedef struct {
    int row; // 행 번호 
    int col; // 열 번호 
    int value; // 해당 위치 값 
} data;

// 희소 행렬 전체를 저장하는 리스트 
typedef struct {
    data arr[MAX_SIZE]; // 데이터 배열
    int size; // 현재 저장된 항목 수
    int max_row; // 입력된 항목중에서 최대 행 번호
    int max_col; // 입력된 항목중에서 최대 열 번호
} list;

// 리스트에 새로운 항목 삽입
void insert(list* l, int r, int c, int v) {
    if (l->size >= MAX_SIZE) return; // 최대 크기 초과 시 삽입 중단

    l->arr[l->size].row = r; // 행(row)
    l->arr[l->size].col = c; // 열(column) 
    l->arr[l->size].value = v; // 값(value) 
    l->size++;

    // 최대 행/열 정보 갱신
    if (r > l->max_row) l->max_row = r;
    if (c > l->max_col) l->max_col = c;
}

// row, column에 해당하는 항목이 있는지 찾음
int find(list* l, int r, int c) {
    for (int i = 0; i < l->size; i++) {
        if (l->arr[i].row == r && l->arr[i].col == c) return i;
    } // 있으면 인덱스를 반환, 없으면 -1 
    return -1;
}

// 행렬 데이터 입력
void input(list* l) {
    int r, c, v;
    printf("행렬을 입력하시오? (-1입력 시 행렬의 입력이 종료됨)\n");
    while (1) {
        scanf("%d", &r);
        if (r == -1) break;
        scanf("%d %d", &c, &v);

        int idx = find(l, r, c);
        if (idx != -1) {
            // 이미 있는 위치라면 값을 누적
            l->arr[idx].value += v;
        }
        else {
            // 새로운 위치라면 삽입
            insert(l, r, c, v);
        }
    }
}

// 행 기준 오름차순 정렬
void sort(list* l) {
    for (int i = 0; i < l->size - 1; i++) {
        for (int j = i + 1; j < l->size; j++) {
            if (l->arr[i].row > l->arr[j].row ||
                (l->arr[i].row == l->arr[j].row && l->arr[i].col > l->arr[j].col)) {
                // 스왑
                data temp = l->arr[i];
                l->arr[i] = l->arr[j];
                l->arr[j] = temp;
            }
        }
    }
}

// 최종 결과를 출력 
void print(list* l) {
    printf("두 행렬의 합\n");
    printf("List:  size = %d, last = %d\n", MAX_SIZE, l->size - 1);
    printf("Items:\n");
    for (int i = 0; i < l->size; i++) {
        printf("    [%d] %d, %d, %d\n", i, l->arr[i].row, l->arr[i].col, l->arr[i].value);
    }
}

int main() {
    // 두 개의 행렬 리스트 생성 및 초기화
    list a = { .size = 0, .max_row = 0, .max_col = 0 };
    list b = { .size = 0, .max_row = 0, .max_col = 0 };

    // 두 행렬 입력
    input(&a);
    input(&b);

    // 행렬 B를 A에 더함 (같은 위치는 값 누적, 없으면 새로 삽입)
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

    // 정렬 후 출력
    sort(&a);
    print(&a);

    return 0;
}
