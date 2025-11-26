#include <stdio.h>
#include <string.h>

#define MAX_STUDENT 100

typedef struct {
    char name[50];
    int kor, eng, math;
    float avg;
    char bestSub[20];
    char worstSub[20];
} Student;

Student stu[MAX_STUDENT];
int count = 0;

void registerStudent() {
    if (count >= MAX_STUDENT) {
        printf("등록 불가: 최대 학생 수를 초과했습니다.\n");
        return;
    }

    printf("\n[학생 등록]\n");

    printf("이름 입력: ");
    scanf("%s", stu[count].name);

    printf("국어 점수: ");
    scanf("%d", &stu[count].kor);

    printf("영어 점수: ");
    scanf("%d", &stu[count].eng);

    printf("수학 점수: ");
    scanf("%d", &stu[count].math);

     stu[count].avg = (stu[count].kor + stu[count].eng + stu[count].math) / 3.0f;

     int max = stu[count].kor;
    strcpy(stu[count].bestSub, "국어");

    if (stu[count].eng > max) {
        max = stu[count].eng;
        strcpy(stu[count].bestSub, "영어");
    }
    if (stu[count].math > max) {
        max = stu[count].math;
        strcpy(stu[count].bestSub, "수학");
    }

     int min = stu[count].kor;
    strcpy(stu[count].worstSub, "국어");

    if (stu[count].eng < min) {
        min = stu[count].eng;
        strcpy(stu[count].worstSub, "영어");
    }
    if (stu[count].math < min) {
        min = stu[count].math;
        strcpy(stu[count].worstSub, "수학");
    }

    count++;
    printf("학생 등록이 완료되었습니다!\n\n");
}

void searchStudent() {
    if (count == 0) {
        printf("조회할 학생이 없습니다.\n");
        return;
    }

    char searchName[50];
    printf("\n[학생 조회]\n");
    printf("조회할 학생 이름 입력: ");
    scanf("%s", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(searchName, stu[i].name) == 0) {
            printf("\n===== 학생 성적 정보 =====\n");
            printf("이름: %s\n", stu[i].name);
            printf("국어: %d\n", stu[i].kor);
            printf("영어: %d\n", stu[i].eng);
            printf("수학: %d\n", stu[i].math);
            printf("평균: %.2f\n", stu[i].avg);

            // 칭찬/꾸중 출력
            printf("칭찬: %s 과목 점수가 가장 높아요! 잘했습니다!\n", stu[i].bestSub);
            printf("꾸중: %s 과목 점수가 가장 낮아요. 더 노력해봐요!\n", stu[i].worstSub);

            printf("==========================\n\n");
            return;
        }
    }

    printf("해당 학생을 찾을 수 없습니다.\n");
}
int main() {
    int menu;

    printf("지필고사 치느라고 고생했다!\n");

    while (1) {
        printf("\n===== 메뉴 =====\n");
        printf("1. 학생 등록\n");
        printf("2. 학생 조회\n");
        printf("0. 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &menu);

        if (menu == 1)
            registerStudent();
        else if (menu == 2)
            searchStudent();
        else if (menu == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else
            printf("잘못된 입력입니다. 다시 선택하세요.\n");
    }

    return 0;
}