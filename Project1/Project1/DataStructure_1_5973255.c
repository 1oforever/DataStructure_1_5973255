#include <stdio.h> // printf와 scanf를 사용하기 위한 헤더파일
int main() { // 프로그램 시작부분
    unsigned num = 0; // 부호가 없는 변수 num을 지정합니다 

    printf("숫자를 입력하세요: "); // "숫자를 입력하세요: "라는 글자를 출력합니다 
    scanf_s("%u", &num); // 변수 num의 값을 입력받습니다

    unsigned a = 0x80000000;
    /* 부호가 없는 변수 a에 32비트 정수의 최상위 비트만 설정하고,
    나머지 비트는 0으로 초기화합니다 */

    printf("입력된 정수의 32비트 표현: ");
    // "입력된 정수의 32비트 표현: "이라는 글자를 출력합니다
    for (int i = 0; i < 32; i++) { // 32번 반복하여 각 비트를 확인합니다
        if ((a & num) == a)
            // num의 해당 비트가 1인지 확인합니다 
            // AND를 통해 최상위 비트부터 차례대로 확인합니다 
            printf("1"); // 참이면 1을 출력합니다 
        else
            printf("0"); // 거짓이면 0을 출력합니다 
        a >>= 1; // a를 오른쪽으로 옮겨서 다음비트로 이동합니다 
    }

    return 0;
}