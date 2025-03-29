#define _CRT_SECURE_NO_WARNINGS // 보안 경고를 무시하기 위한 매크로 정의
#include <stdio.h> // 표준 입출력 함수 사용을 위한 헤더 파일
#include <stdlib.h> // 동적 메모리 할당 및 기타 표준 함수 사용을 위한 헤더 파일

int main(void) // 프로그램의 시작점
{
    // 구조체 선언
    // 학생 정보를 저장할 구조체 정의: 이름, 학번, 점수, 다음 학생을 가리키는 포인터
    struct Student {
        char* name; // 학생의 이름을 저장할 포인터 
        int id; // 학생의 학번을 저장할 정수
        int score; // 학생의 점수를 저장할 정수 
        struct Student* next; // 다음 학생의 주소를 저장할 포인터 
    };

    int n; // 입력받을 학생 수를 저장할 변수
    printf("몇 명의 학생 정보를 입력하시나요? "); // 학생 수 입력을 요청하는 메시지 출력
    scanf("%d", &n); // 사용자로부터 학생 수 입력 받기

    struct Student* head = NULL; // 연결 리스트의 시작을 나타내는 포인터를 NULL로 초기화

    // 학생 정보를 입력받아 연결 리스트에 추가 
    for (int i = 1; i <= n; i++) { // 1부터 n까지 반복하여 각 학생 정보를 입력받음
        // 새로운 학생 정보를 저장하기 위해 동적으로 메모리 할당
        struct Student* s = (struct Student*)malloc(sizeof(struct Student));
        if (s == NULL) { 
            return 1;                // 에러 발생 시 프로그램 종료
        }
        // 학생의 이름을 저장할 공간을 동적으로 할당
        s->name = (char*)malloc(50 * sizeof(char));
        if (s->name == NULL) { 
            return 1;                // 에러 발생 시 프로그램 종료
        }

        printf("[%d] 학생의 정보를 입력하세요(이름 학번 점수): ", i);
        // 이름, 학번, 점수를 입력받아 저장
        scanf("%s %d %d", s->name, &s->id, &s->score);
        s->next = head; // 새로 입력받은 학생의 next 필드를 현재 head로 설정
        head = s; // head를 새 학생으로 저장
    }

    // 학번 검색: 사용자가 0을 입력할 때까지 학번을 입력받아 해당 학생 정보를 찾음
    while (1) {
        printf("학번을 입력하세요(0이면 종료)? "); // 학번 입력을 요청하는 메시지 출력
        {
            int id; // 검색할 학번을 저장할 변수 선언
            scanf("%d", &id); // 학번 입력
            if (id == 0) // 입력받은 학번이 0이면 종료
                break; 
            struct Student* p = head; // 연결 리스트 순회를 위한 포인터 p를 head로 초기화
            int found = 0; // 해당 학번의 학생을 찾았는지 여부를 저장하는 변수 
            while (p != NULL) { // 리스트 끝에 도달할 때까지 반복
                if (p->id == id) { 
                    printf("%s %d %d\n", p->name, p->id, p->score); // 일치하면 학생 정보를 출력
                    found = 1; // 학생을 찾았음을 표시
                    break; 
                }
                p = p->next; // 다음 학생으로 이동
            }
            if (!found) // 리스트 전체를 탐색했지만 일치하는 학생이 없는 경우
                printf("해당 학번의 학생이 없습니다.\n"); // 일치하는 학생이 없음을 출력 
        } 
    }

    while (head != NULL) { // 모든 노드를 돌음 
        struct Student* temp = head; // 현재 노드를 변수에 저장
        head = head->next; // head를 다음 노드로 이동
        free(temp->name); // 학생 이름에 할당된 메모리 해제
        free(temp); // 학생 구조체에 할당된 메모리 해제
    }

    return 0; // 프로그램 종료
}
