#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char s[101]; // 배열을 생성합니다 
    printf("문자열을 입력하세요: ");
    fgets(s, sizeof(s), stdin); // 띄어쓰기를 포함안 문자열을 입력받습니다 
    // fgets은 한 줄의 문자열을 입력받으며, 줄바꿈 문자가 나오기 전까지 계속 입력받습니다
    // fgets은 입력된 문자열의 끝에 자동으로 줄바꿈 문자 \n이 포함되므로, 
    // 1을 뺌으로써 정확한 문자열의 길이를 계산합니다


    int length = strlen(s) - 1; // 문자열의 길이를 셉니다. 
    printf("문자열의 길이: %d\n", length);

    for (int i = 0; i < length; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32; // 대문자를 소문자로 바꿉니다
        }
        else if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32; // 소문자를 대문자로 바꿉니다 
        }
    }

    printf("변환된 문자열: %s", s); // 최종적으로 변환된 문자열을 출력합니다 
    return 0;
}
