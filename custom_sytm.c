//
// Created by ���������� on 2024/7/15.
//
/*
����֮��Ա��Ϣϵͳʵ��(��)
*/

#include <stdio.h>
#include "menu.h"
#include "link.h"



int main() {
    printf_menu();      //��ӡ����
    struct stu* head = NULL;

    while (1) {
        printf("----------------------\n");
        printf("��������Ҫ���в����Ĺ������֣�");
        int num;
        scanf("%d", &num);
        switch (num) {
            case 1:
                add_stu(&head);  //���ѧ����Ϣ
                break;
            case 2:
                modify_stu(head);  //�޸�ѧ����Ϣ
                break;
            case 3:
                chaxun_stu(head);  //��ѯѧ����Ϣ
                break;
            case 4:
                delete_stu(&head);   //ɾ��ѧ����Ϣ
                break;
            case 5:
                printf_stu(head);  //��ӡѧ����Ϣ
                break;
            case 6:
                exit_stu(head);   //�˳�ϵͳ
                head = NULL;
                return 0;
            default:
                printf("�Բ���������������������²���\n");
        }
    }

    return 0;
}


