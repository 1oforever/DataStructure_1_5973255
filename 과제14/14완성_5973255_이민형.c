#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linearList.h"

void delSpace(char* str) { // 공백 없애는 함수
    char* read = str;
    char* write = str; 
    while (*read) { 
        if (*read != ' ') { 
            *write = *read; 
            write++; 
        } 
        read++; 
    }
    *write = '\0'; 
}

void makeList(char* str, listType* poly) { // 다항식 문자열 리스트에 넣기 
    int coef = 0, expo = 0; 
    char* ptr = str; 
     
    while (*ptr) { 
        int sign = 1; 
         
        // 부호 처리 
        if (*ptr == '-') { 
            sign = -1; 
            ptr++; 
        }
        else if (*ptr == '+') { 
            ptr++; 
        } 
         
        // 계수 읽기 
        coef = 0; 
        while (isdigit(*ptr)) { 
            coef = coef * 10 + (*ptr - '0'); 
            ptr++; 
        } 
        if (coef == 0) coef = 1; // 생략된 계수 처리 
        coef *= sign; 
         
        // 차수 읽기 
        if (*ptr == 'x' || *ptr == 'X') { 
            ptr++; 
            if (*ptr == '^') { 
                ptr++; 
                expo = 0; 
                while (isdigit(*ptr)) { 
                    expo = expo * 10 + (*ptr - '0'); 
                    ptr++; 
                } 
            } 
            else { 
                expo = 1; // x만 있으면 차수는 1 
            } 
        } 
        else { 
            expo = 0; // x가 없으면 상수항 
        } 
         
        ordered_insertItem(poly, (elementType) { coef, expo }); 
    }
}

// 같은 차수 있으면 계수 더하고, 없으면 삽입 
void addTerm(listType* poly, elementType term) { 
    for (int i = 0; i <= poly->last; i++) { 
        if (poly->array[i].expo == term.expo) { 
            poly->array[i].coef += term.coef; 
            return; 
        }
    }
    ordered_insertItem(poly, term); 
}

// 두 다항식 곱셈 수행 함수 
listType* multiply(listType* a, listType* b) { 
    listType* result = createList(100); 

    for (int i = 0; i <= a->last; i++) { 
        elementType left = readItem(a, i); 
        for (int j = 0; j <= b->last; j++) { 
            elementType right = readItem(b, j); 
            elementType tmp; 
            tmp.coef = left.coef * right.coef; 
            tmp.expo = left.expo + right.expo; 
            addTerm(result, tmp); // 곱셈한 항 추가
        }
    }

    return result;
}


void printPoly(listType* poly) { // 결과 출력 함수 
    printf("[곱셈 결과]\n"); 
    printf("List: size = %d, last = %d, move = %d\n", poly->size, poly->last, poly->move); 
    printf("Items: P(x) = "); 
    for (int i = poly->last; i >= 0; i--) { 
        printf("%d", poly->array[i].coef); 
        if (poly->array[i].expo != 0) { 
            printf("X^%d", poly->array[i].expo); 
        }
        if (i != 0) printf("+"); 
    }
    printf("\n"); 
}

int main() { 
    char input1[100], input2[100]; 

    // 다항식 저장할 리스트 생성 
    listType* first = createList(50); 
    listType* second = createList(50); 

    // 첫 번째 다항식 입력 
    printf("첫 번째 다항식을 입력하세요 (예: 3x^2+4x+1): "); 
    fgets(input1, sizeof(input1), stdin); 
    input1[strcspn(input1, "\n")] = '\0'; // 줄바꿈 제거 
    delSpace(input1); // 공백 제거 
    makeList(input1, first); // 리스트에 저장 

    // 두 번째 다항식 입력 
    printf("두 번째 다항식을 입력하세요 (예: 2x^2+5x+3): "); 
    fgets(input2, sizeof(input2), stdin); 
    input2[strcspn(input2, "\n")] = '\0'; 
    delSpace(input2); 
    makeList(input2, second); 

    // 곱셈 수행 
    listType* result = multiply(first, second); 
    printPoly(result); // 결과 출력 

    // 메모리 정리
    destroyList(first); 
    destroyList(second); 
    destroyList(result); 

    return 0; 
}
