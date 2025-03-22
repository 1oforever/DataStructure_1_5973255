#define _CRT_SECURE_NO_WARNINGS // scanf 사용 시 발생할 수 있는 보안 경고를 무시
#include <stdio.h> // 표준 입출력 함수 사용하기 위한 헤더 파일
#include <stdlib.h> // 표준 라이브러리 함수 사용을 위한 헤더 파일
#include <string.h> // 문자열 처리 함수 사용을 위한 헤더 파일
#include <ctype.h> // 문자 관련 함수 사용을 위한 헤더 파일

// 정수 자료형 k를 정의 
typedef struct {
    int num; // 정수 값을 저장할 변수
} k;

// 두 개의 정수 구조체 k를 더하는 함수
k plus(k a, k b) {
    k resultS = { a.num + b.num }; // a.num과 b.num을 더한 값을 resultS.num에 저장
    return resultS; // 계산된 결과 구조체 resultS를 반환
}

// 두 개의 정수 구조체 k를 빼는 함수
k minus(k a, k b) {
    k resultS = { a.num - b.num }; // a.num에서 b.num을 뺀 값을 resultS.num에 저장
    return resultS; // 계산된 결과 구조체 resultS를 반환
}

// 두 개의 정수 구조체 k를 곱하는 함수
k multiply(k a, k b) {
    k resultS = { a.num * b.num }; // a.num과 b.num을 곱한 값을 resultS.num에 저장
    return resultS; // 계산된 결과 구조체 resultS를 반환
}

// 두 개의 정수 구조체 k를 나누는 함수 (나누는 값이 0이면 오류 메시지 출력 후 종료)
float divide(k a, k b) {
    if (b.num == 0) { // 만약 b.num이 0이면 0으로 나눌 수 없음
        printf("0으로 나눌 수 없습니다.\n"); // 오류 메시지 출력
        exit(1); // 프로그램을 종료
    }
    return (float)a.num / b.num; // a.num을 b.num으로 나눈 결과를 float 형식으로 반환
}

// 실수 자료형 r을 정의함. 이 구조체는 일반적인 실수 값을 저장함.
typedef struct {
    double num; // 실수 값을 저장할 변수
} r;

// 두 개의 실수 구조체 r를 더하는 함수
r r_plus(r a, r b) {
    r resultS = { a.num + b.num }; // a.num과 b.num을 더한 값을 resultS.num에 저장
    return resultS; // 계산된 결과 resultS를 반환
}

// 두 개의 실수 구조체 r를 빼는 함수
r r_minus(r a, r b) {
    r resultS = { a.num - b.num }; // a.num에서 b.num을 뺀 값을 resultS.num에 저장
    return resultS; // 계산된 결과 resultS를 반환
}

// 두 개의 실수 구조체 r를 곱하는 함수
r r_multiply(r a, r b) {
    r resultS = { a.num * b.num }; // a.num과 b.num을 곱한 값을 resultS.num에 저장
    return resultS; // 계산된 결과 resultS를 반환
}

// 두 개의 실수 구조체 r를 나누는 함수 (나누는 값이 0이면 오류 메시지 출력 후 종료)
r r_divide(r a, r b) {
    if (b.num == 0.0) { // 만약 b.num이 0.0이면 0으로 나눌 수 없음
        printf("0으로 나눌 수 없습니다.\n"); // 오류 메시지 출력
        exit(1); // 프로그램을 종료
    }
    r resultS = { a.num / b.num }; // a.num을 b.num으로 나눈 값을 resultS.num에 저장
    return resultS; // 계산된 결과 resultS를 반환
}

// 공백 문자를 건너뛰는 함수: 문자열에서 공백을 만나면 포인터를 다음 문자로 이동
void skipSpace(const char** s) {
    while (isspace(**s)) { // 현재 가리키는 문자가 공백인지 검사
        (*s)++; // 공백이면 포인터 s를 다음 문자로 이동
    }
}

// 문자열에서 실수 형태의 숫자를 읽어 r 구조체로 반환하는 함수
r readNumber(const char** s) {
    skipSpace(s); // 먼저 앞쪽의 공백 문자를 모두 건너뛰기
    r resultS; // 결과를 저장할 r 구조체 변수 선언
    char* endPtr; // 숫자 읽기가 끝난 위치를 저장할 포인터 변수
    resultS.num = strtod(*s, &endPtr); // 문자열 s에서 실수를 읽어 resultS.num에 저장, endPtr은 읽기가 끝난 위치를 가리킴
    if (*s == endPtr) { // 만약 읽은 숫자가 없으면 
        printf("잘못된 수식입니다.\n"); // 오류 메시지 출력
        exit(1); // 프로그램 종료
    }
    *s = endPtr; // 포인터 s를 숫자 읽기가 끝난 위치로 이동
    return resultS; // 읽은 숫자가 들어있는 r 구조체를 반환
}

// 곱셈과 나눗셈 연산을 처리하는 함수 (원래 이름 readTerm -> 변경 후 readRanking)
// 이 함수는 우선순위가 높은 연산을 먼저 처리함
r readRanking(const char** s) {
    r resultS = readNumber(s); // 첫 번째 숫자를 읽어 resultS에 저장
    skipSpace(s); // 연산자 앞뒤의 공백을 건너뛰기
    while (**s == '*' || **s == '/') { // 현재 문자가 '*' 또는 '/'인 동안 반복
        char op = **s; // 현재 연산자를 변수 op에 저장 ('*' 또는 '/')
        (*s)++; // 연산자 다음 문자로 포인터 s를 이동
        r nextNum = readNumber(s); // 다음 숫자를 읽어 nextNum에 저장
        if (op == '*')
            resultS = r_multiply(resultS, nextNum); // '*' 연산이면 두 숫자를 곱함
        else  // op == '/'
            resultS = r_divide(resultS, nextNum);  // '/' 연산이면 두 숫자를 나눔
        skipSpace(s); // 다음 연산 전에 공백 문자 건너뛰기
    }
    return resultS; // 곱셈과 나눗셈 연산 결과를 반환
}

// 덧셈과 뺄셈 연산을 처리하는 함수 (원래 이름 readExpression -> 변경 후 readAll)
// 이 함수는 전체 수식을 처리함
r readAll(const char** s) {
    r resultS = readRanking(s); // 첫 번째 항(곱셈/나눗셈 결과)을 읽어 resultS에 저장
    skipSpace(s); // 공백 문자 건너뛰기
    while (**s == '+' || **s == '-') {  // 현재 문자가 '+' 또는 '-'인 동안 반복
        char op = **s; // 현재 연산자를 변수 op에 저장 ('+' 또는 '-')
        (*s)++; // 연산자 다음 문자로 포인터 s를 이동
        r nextRanking = readRanking(s); // 다음 항(곱셈/나눗셈 결과)을 읽어 nextRanking에 저장
        if (op == '+')
            resultS = r_plus(resultS, nextRanking); // '+' 연산이면 두 항을 더함
        else  // op == '-'
            resultS = r_minus(resultS, nextRanking); // '-' 연산이면 두 항을 뺌
        skipSpace(s); // 다음 연산 전에 공백 문자 건너뛰기
    }
    return resultS; // 전체 수식의 최종 결과를 반환
}

int main() {
    int first, second; // 사용자로부터 입력받을 정수를 저장할 변수들

    // 첫 번째 양의 정수를 입력받음
    printf("첫번째 양의 정수를 입력하세요: ");
    if (scanf("%d", &first) != 1 || first <= 0) { // 입력이 실패하거나 양의 정수가 아니면
        printf("Error: 양의 정수만 입력 가능합니다.\n"); // 오류 메시지 출력
        return 1; // 프로그램을 종료
    }

    // 두 번째 양의 정수를 입력받음
    printf("두번째 양의 정수를 입력하세요: ");
    if (scanf("%d", &second) != 1 || second <= 0) { // 입력이 실패하거나 양의 정수가 아니면
        printf("Error: 양의 정수만 입력 가능합니다.\n"); // 오류 메시지 출력
        return 1; // 프로그램을 종료
    }

    // 버퍼에 남아있는 개행 문자 제거 
    while (getchar() != '\n');

    // 정수 구조체 변수 선언: 사용자로부터 입력받은 값을 구조체 k에 저장
    k num1 = { first }; // 첫 번째 정수를 저장하는 구조체 변수 num1
    k num2 = { second }; // 두 번째 정수를 저장하는 구조체 변수 num2

    // 정수 연산 함수들을 사용하여 계산 
    k addResult = plus(num1, num2); // num1과 num2의 덧셈 결과를 계산
    k subResult = minus(num1, num2); // num1에서 num2를 뺀 결과를 계산
    k mulResult = multiply(num1, num2); // num1과 num2의 곱셈 결과를 계산
    float divResult = divide(num1, num2); // num1을 num2로 나눈 결과를 계산

    // 계산된 정수 연산 결과 출력
    printf("덧셈: %d\n", addResult.num); // 덧셈 결과 출력
    printf("뺄셈: %d\n", subResult.num); // 뺄셈 결과 출력
    printf("곱셈: %d\n", mulResult.num); // 곱셈 결과 출력
    printf("나눗셈: %.2f\n", divResult); // 나눗셈 결과 소수점 둘째 자리까지 출력 

    // 수식 계산을 위한 부분 시작
    char expr[256]; // 수식을 저장할 크기가 256인 문자열 배열 선언
    printf("계산할 수식을 입력하세요 (예: 3+5*2-8/4): "); 
    if (fgets(expr, sizeof(expr), stdin) == NULL) { // 표준 입력으로부터 수식을 읽음 
        printf("입력 오류.\n"); // 오류 메시지 출력
        return 1; // 프로그램 종료
    }

    // 입력받은 문자열에서 개행 문자를 제거 
    expr[strcspn(expr, "\n")] = '\0';

    const char* p = expr;   // 수식 문자열의 시작 주소를 가리키는 포인터 변수 선언
    r result = readAll(&p); // 수식 전체를 파싱하여 계산 결과를 result에 저장

    // 수식을 모두 읽은 후에도 남은 입력이 있다면 오류 처리
    skipSpace(&p); // 남은 공백 문자를 건너뜀
    if (*p != '\0') { 
        printf("잘못된 수식입니다.\n"); // 만약 문자열의 끝에 도달하지 않았다면 오류 메시지 출력
        return 1; // 프로그램 종료
    }

    // 최종 계산 결과 출력
    printf("결과: %lf\n", result.num);

    return 0; // 프로그램을 정상적으로 종료함
}
