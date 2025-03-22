/*
Pseudo code는 알고리즘의 기본 흐름과 각 모듈의 작동 원리를 실제 프로그래밍 언어의 문법에 구애받지 않고
자유롭게 기술한 것으로, 문제를 해결하는 단계별 접근 방법(분할과 정복 등)을 쉽게 이해할 수 있도록 도와줍니다.
*/

/*
1. 정수형 변수 선언: num, i, j, count를 0으로 초기화;
2. "숫자를 입력하세요: " 출력;
3. 사용자로부터 정수 num 입력 받기;
4. num 이하의 소수를 출력할 메시지 출력;
5. for (i를 2부터 num까지 반복) {      // 1은 소수가 아니므로 2부터 시작
      - count를 0으로 초기화;
      - for (j를 1부터 i까지 반복) {
            만약 i를 j로 나눴을 때 나머지가 0이면 count 증가;
      }
      - 만약 count가 2이면 (약수가 1과 i밖에 없으면) i를 소수로 출력;
   }


외부 for문은 약 O(n) 번 실행된다 
내부 for문은 각 i에 대해 최대 O(n) 번 실행된다 
따라서 전체 시간 복잡도는 O(n^2)이다 
*/
#define _CRT_SECURE_NO_WARNINGS // scanf 사용 시 보안 경고 무시
#pragma warning(disable:4996) // 특정 경고 무시

#include <stdio.h> // 표준 입출력 함수들을 사용하기 위한 헤더
#include <stdlib.h> // exit 함수 등을 사용하기 위한 헤더
#include <string.h> // 문자열 관련 함수들을 사용하기 위한 헤더
#include <ctype.h> // 문자 관련 함수들을 사용하기 위한 헤더

int main() {
    int num, i, j, count; // 변수 선언

    // 사용자로부터 정수를 입력받음
    printf("숫자를 입력하세요: ");
    if (scanf("%d", &num) != 1) {
        printf("입력 오류.\n");
        return 1;
    }

    // 입력받은 num 이하의 소수를 출력
    printf("%d 이하의 소수: ", num);

    // 1은 소수가 아니므로 2부터 num까지 검사
    for (i = 2; i <= num; i++) {
        count = 0; // 각 숫자 i마다 약수 개수를 0으로 초기화
        // i의 약수를 찾기 위한 반복문
        for (j = 1; j <= i; j++) {
            if (i % j == 0) {
                count++; // 나누어 떨어지면 약수 count 증가
            }
        }
        // 약수가 1과 자신뿐이면 count는 2가 됨 >> 소수
        if (count == 2) {
            printf("%d ", i);
        }
    }

    return 0; // 프로그램 종료
}
