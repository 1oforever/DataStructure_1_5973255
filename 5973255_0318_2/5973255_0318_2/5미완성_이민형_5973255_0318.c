#define _CRT_SECURE_NO_WARNINGS  // scanf 보안 경고 방지
#include <stdio.h> // 입출력 함수를 사용하기 위한 헤더파일
#include <stdlib.h> // exit 함수를 사용하기 위한 헤더파일

// 양의 정수에 대한 사칙연산 추상 자료형 정의
typedef struct { 
    int value; // 양의 정수를 저장하는 구조체 
} k;

// 더하기
k plus(k a, k b) {
    k result = { a.value + b.value }; // 두 값을 더한 결과를 저장
    return result; // 결과 반환 
}

// 뺴기
k minus(k a, k b) {
    k result = { a.value - b.value }; // 두 값을 뺀 결과를 저장
    return result; // 결과 반환 
}

// 곱하기
k multiply(k a, k b) {
    k result = { a.value * b.value }; // 두 값을 곱한 결과를 저장
    return result; // 결과 반환 
}

// 나누기 
k divide(k a, k b) {
    if (b.value == 0) { // 나누는 값이 0이면 오류 처리 
        printf("0으로 나눌 수 없습니다 \n"); // 오류 메시지 출력 
        exit(1); // 프로그램 종료 
    }
    k result = { a.value / b.value };  // 두 값을 나눈 결과를 저장 
    return result; // 결과 반환 
}

int main() {
    int num1, num2; // 정수를 입력받을 정수형 변수 
    char c; // 연산자를 저장할 문자형 변수 

    // 사용자 입력 
    printf("식을 입력하세요: "); // 입력메시지 출력
    if (scanf("%d%c%d", &num1, &c, &num2) != 3) { 
        printf("Error: 잘못된 입력 형식입니다 \n"); // 형식이 잘못되었을 때 오류 메시지 출력 
        return 1; // 프로그램을 종료 
    }

    if (num1 <= 0 || num2 <= 0) { // 입력된 숫자가 0 이하라면 오류 메시지 출력 
        printf("Error: 양의 정수만 입력 가능합니다 \n");
        return 1; // 프로그램을 종료 
    }

    k a = { num1 }; // 첫번째 양의 정수를 구조체에 저장
    k b = { num2 }; // 두번째 양의 정수를 구조체에 저장 
    k result; // 결과를 저장할 구조체 변수 

    // 처리
    switch (c) { 
    case '+': result = plus(a, b); break; // 더하기 계산 
    case '-': result = minus(a, b); break; // 빼기 계산 
    case '*': result = multiply(a, b); break; // 곱하기 계산 
    case '/': result = divide(a, b); break; // 나누기 계산 
    default:
        printf("Error: 지원되지 않는 연산자입니다 \n");
        return 1; // 잘못된 연산자 입력 시에 오류메시지를 출력하고 프로그램 종료 
    }

    // 결과 출력
    printf("결과: %d\n", result.value); // 계산 결과를 출력한다 
    return 0; // 프로그램을 종료
}