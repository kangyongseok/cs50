#include <stdio.h>
#include <string.h>
#include <ctype.h> // isdigit 함수사용
#include <stdlib.h> // atoi 함수 사용

const int NUMBER_OF_GRADES = 9;
// printGradeTable() 함수를 사용하기 위하여 타입을 char 형태로 통일하기 위해 점수도 스트링 타입으로 입력
const char *GRADE_POINTS[NUMBER_OF_GRADES] = {"95", "90", "85", "80", "75", "70", "65", "60", "0"};
const char *GRADES[NUMBER_OF_GRADES] = {"A+", "A", "B+", "B", "C+", "C", "D+", "D", "F"};

void printGradeTable(char *label, const char *target[]);
int checkNum(char *str);
int resultGradePoint(int numGrade, int length);

int main(void) {
    char strGrade[4];
    printf("학점프로그램\n");
    printf("종료를 원하면 \"999\" 를 입력\n");
    printf("[학점 테이블]\n");
    printGradeTable("점수", GRADE_POINTS);
    printf("\n");
    printGradeTable("학점", GRADES);
    printf("\n");

    int arrNum = sizeof(GRADE_POINTS) / sizeof(GRADE_POINTS[0]);

    while(1) {
        int numGrade;
        printf("성적을 입력하세요 (0 ~ 100) : ");
        scanf("%s", strGrade);
        if (checkNum(strGrade) == -1) {
            printf("숫자가 아닙니다 프로그램을 종료합니다.\n");
            break;
        }

        numGrade = atoi(strGrade); // 문자 정수를 숫자로 변환

        if (numGrade == 999) {
            printf("학점 프로그램을 종료합니다.\n");
            break;
        }
        if(numGrade > 100 || numGrade < 0) {
            printf("** %d 성적을 올바르게 입력하세요! (0 ~ 100)\n", numGrade);
            continue;
        }

        resultGradePoint(numGrade, arrNum);
    }

    return 0;
}

void printGradeTable(char *label, const char *target[]) {
    // 학점 테이블 출력 함수
    printf("%s : ", label);
    for (int i = 0; i < NUMBER_OF_GRADES; i++) {
        printf("%s\t", target[i]);
    }
}

int checkNum(char *str) {
    int const length = strlen(str);
    int result;
    // 문자 정수를 문자배열로 취급하여 숫자인지 아닌지 하나씩 체크 하나라도 숫자가 아니면 -1
    // ex) str = 20 => ["2", "0"] => isdigit() 함수로 문자가 숫자 문자인지 체크(연속된 문자가 아닌 한글자씩만 체크가능)
    for (int i = 0; i < length; i++) {
        if (isdigit(str[i]) == 0) {
            // 숫자가 아님
            result = -1;
            break;
        }
        result = 0;
    }
    return result;
}

int resultGradePoint(int numGrade, int length) {
    for (int j = 0; j < length; j++) {
        if (numGrade == 0) {
            printf("학점은 F 입니다.\n");
            break;
        }
        if (numGrade >= 95) {
            printf("학점은 A+ 입니다.\n");
            break;
        }
        if (atoi(GRADE_POINTS[j]) >= numGrade && atoi(GRADE_POINTS[j + 1]) <= numGrade) {
            printf("학점은 %s 입니다.\n", GRADES[j + 1]);
            break;
        }
    }
    return -1;
}