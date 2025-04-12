#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linearList.h"

void delSpace(char* str) { // ���� ���ִ� �Լ�
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

void makeList(char* str, listType* poly) { // ���׽� ���ڿ� ����Ʈ�� �ֱ� 
    int coef = 0, expo = 0; 
    char* ptr = str; 
     
    while (*ptr) { 
        int sign = 1; 
         
        // ��ȣ ó�� 
        if (*ptr == '-') { 
            sign = -1; 
            ptr++; 
        }
        else if (*ptr == '+') { 
            ptr++; 
        } 
         
        // ��� �б� 
        coef = 0; 
        while (isdigit(*ptr)) { 
            coef = coef * 10 + (*ptr - '0'); 
            ptr++; 
        } 
        if (coef == 0) coef = 1; // ������ ��� ó�� 
        coef *= sign; 
         
        // ���� �б� 
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
                expo = 1; // x�� ������ ������ 1 
            } 
        } 
        else { 
            expo = 0; // x�� ������ ����� 
        } 
         
        ordered_insertItem(poly, (elementType) { coef, expo }); 
    }
}

// ���� ���� ������ ��� ���ϰ�, ������ ���� 
void addTerm(listType* poly, elementType term) { 
    for (int i = 0; i <= poly->last; i++) { 
        if (poly->array[i].expo == term.expo) { 
            poly->array[i].coef += term.coef; 
            return; 
        }
    }
    ordered_insertItem(poly, term); 
}

// �� ���׽� ���� ���� �Լ� 
listType* multiply(listType* a, listType* b) { 
    listType* result = createList(100); 

    for (int i = 0; i <= a->last; i++) { 
        elementType left = readItem(a, i); 
        for (int j = 0; j <= b->last; j++) { 
            elementType right = readItem(b, j); 
            elementType tmp; 
            tmp.coef = left.coef * right.coef; 
            tmp.expo = left.expo + right.expo; 
            addTerm(result, tmp); // ������ �� �߰�
        }
    }

    return result;
}


void printPoly(listType* poly) { // ��� ��� �Լ� 
    printf("[���� ���]\n"); 
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

    // ���׽� ������ ����Ʈ ���� 
    listType* first = createList(50); 
    listType* second = createList(50); 

    // ù ��° ���׽� �Է� 
    printf("ù ��° ���׽��� �Է��ϼ��� (��: 3x^2+4x+1): "); 
    fgets(input1, sizeof(input1), stdin); 
    input1[strcspn(input1, "\n")] = '\0'; // �ٹٲ� ���� 
    delSpace(input1); // ���� ���� 
    makeList(input1, first); // ����Ʈ�� ���� 

    // �� ��° ���׽� �Է� 
    printf("�� ��° ���׽��� �Է��ϼ��� (��: 2x^2+5x+3): "); 
    fgets(input2, sizeof(input2), stdin); 
    input2[strcspn(input2, "\n")] = '\0'; 
    delSpace(input2); 
    makeList(input2, second); 

    // ���� ���� 
    listType* result = multiply(first, second); 
    printPoly(result); // ��� ��� 

    // �޸� ����
    destroyList(first); 
    destroyList(second); 
    destroyList(result); 

    return 0; 
}
