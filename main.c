//
// Created by ���������� on 2024/7/16.
//
/*
����֮��Ա��Ϣϵͳʵ��(��)
*/

#include <stdio.h>
#include "menu.h"
#include "link.h"
#include "file.h"

int main() {
    struct stu* head = NULL;

    read_file_to_link(&head);

    printf_menu();      //��ӡ����


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
                write_link_to_file(head);  //�����˳�ʱ��ѧ����Ϣ
                exit_stu(head);   //�˳�ϵͳ
                head = NULL;
                return 0;
            default:
                printf("�Բ���������������������²���\n");
        }
    }

    return 0;
}