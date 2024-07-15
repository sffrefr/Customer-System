//
// Created by ���������� on 2024/7/15.
//��������ĺ����Ķ���

#include <stdio.h>
#include <stdlib.h>
#include "struct_stu.h"

void add_stu(struct stu **head) {

    printf("��������Ҫ��ӵ�ѧ�������Ϣ��");
    int num;
    scanf("%d", &num);

    //����һ���ڴ棬װ�����ѧ����Ϣ���ṹ�壩
    struct stu *stu = (struct stu *)malloc(sizeof(struct stu));

    //��ѧ����Ϣ���ڽṹ����
    stu->num = num;

    stu->next = NULL;

    struct stu* p = *head;

    if (p == NULL) {  //������û��һ��ѧ��
        *head = stu;
    }
    else {   //������������һ��ѧ��
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = stu;
    }
    printf("���%d��ӳɹ�\n", num);
}

void modify_stu(struct stu *head) {
    printf("��������Ҫ�޸ĵ�ѧ����ţ�\n");
    int num;
    scanf("%d", &num);
    int flag = 0;
    while (head != NULL) {  //��ǰָ��ָ����һ���ռ�
        if (head->num == num) {
            flag = 1;
            printf("OK���ҵ���Ҫ�޸ĵ�ѧ�����%d\n", num);
            printf("�������µ�ѧ����ţ�");
            int num;
            scanf("%d", &num);
            head->num = num;
            printf("�޸ĳɹ���\n");
            break;  //�˳�ѭ��
        }
        else {
            head = head->next;
        }
    }
    if (!flag) {
        printf("sorry��δ�ҵ�ѧ�����%d\n", num);
    }
}

void chaxun_stu(struct stu *head) {
    printf("��������Ҫ��ѯ��ѧ����ţ�");
    int num;
    scanf("%d", &num);
    int flag = 0;
    while (head != NULL) {
        if (head->num == num) {
            flag = 1;
            printf("OK���Ѳ�ѯ��%d�����Ϣ\n", num);
            break;
        }
        else {
            head = head->next;
        }
    }
    if (!flag) {
        printf("sorry��δ��ѯ��%d�����Ϣ\n", num);
    }
}

void delete_stu(struct stu **head) {
    struct stu* p = *head;
    printf("��������Ҫɾ����ѧ����ţ�");
    int num;
    scanf("%d", &num);
    struct stu* p2 = NULL;
    int flag = 0;
    while (p != NULL) {
        if (p->num == num) {
            flag = 1;
            //��ʱҪɾ���Ľڵ�λ��������
            if (p->next == NULL) { //ɾ���������һ���ڵ�
                if (p2 == NULL) {
                    *head = p->next;
                    free(p);
                    p = NULL;
                }
                else {
                    p2->next = NULL;
                    free(p);
                    p = NULL;
                }
            }
            else {
                if (p2 == NULL) {  //ɾ�������һ���ڵ�
                    *head = p->next;
                    free(p);
                    p = NULL;
                }
                else {   //ɾ��������м�ĳһ���ڵ�
                    p2->next = p->next;
                    free(p);
                    p = NULL;
                }
            }
        }
        else {
            p2 = p;
            p = p->next;
        }
    }
    if (!flag) {
        printf("sorry��δ�ҵ�%dѧ�����\n", num);
    }
}

void printf_stu(struct stu *head) {
    while (head != NULL) {
        printf("ѧ�����%d\n", head->num);
        head = head->next;
    }
}

void exit_stu(struct stu *head) {
    struct stu*  temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}