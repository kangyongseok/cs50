#include <stdio.h>
#include <string.h>

int main(void){
    char food[7][20] = {"û����", "�����", "�����", "Į����", "�ø�", "�ҺҰ��", "����Ұ��"};
    char day[7][10]={"������", "ȭ����", "������", "�����", "�ݿ���", "�����", "�Ͽ���"};
    char input_day[10] = "0";   //�Է¹��� ���̹Ƿ� �ϴ� �ƹ� ������ �ʱ�ȭ

    printf("Input day : ");
    gets(input_day);
    printf("��¹� : %s\n", input_day);
    
    for (int i=0; i<7; ++i){
        if( strcmp(day[i], input_day) == 0) //�Է¹��� ���ϰ� ��ġ�ϴ� ���� ã��
            {
                printf("%s : %s\n", day[i], food[i]);   //�Է¹��� ���ϰ� �� ���Ͽ� �ش��ϴ� ���� ���
            }
    }
}