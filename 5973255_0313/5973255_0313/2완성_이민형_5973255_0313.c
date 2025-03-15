#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    float k; // 실수를 저장할 변수 선언
    printf("실수를 입력하세요: "); 
    scanf("%f", &k);

    unsigned int ieee754; 
    // 부동소수점 숫자를 저장하기 위한 변수 선언
    // 32비트 부동소수점 수를 저장하는데 사용
    unsigned int* ptr = (unsigned int*) & k; 
    // k 메모리 주소를 unsigned int형 포인터로 변환하여 ptr에 저장 
    // >> k의 비트패턴 접근
    ieee754 = *ptr;
    // 포인터ptr이 가르키는 위치 값(k의 비트패턴)을 ieee754에 저장

    unsigned int bu = (ieee754 >> 31) & 1;
    // 부호 비트만 추출
    
    unsigned int ji = (ieee754 >> 23) & 0xFF;
    // 지수 비트만 추출 
    
    unsigned int ga = ieee754 & 0x7FFFFF;
    // 가수 비트만 추출

    // 부호 1비트 출력
    printf("부호(1비트): ");
    for (int i = 0; i < 1; i++) {
        printf("%d", (bu >> (1 - 1 - i)) & 1);
    }
    printf("\n");

    // 지수 8비트 출력
    printf("지수(8비트): ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (ji >> i) & 1);
    }
    printf("\n");

    // 가수 23비트 출력
    printf("가수(23비트): ");
    for (int i = 22; i >= 0; i--) {
        printf("%d", (ga >> i) & 1);
    }
    printf("\n");

    return 0;
}
