//
// Created by 柚子噗噗仔 on 2024/7/15.
//链表操作的函数的定义

#include <stdio.h>
#include <stdlib.h>
#include "struct_stu.h"

void add_stu(struct stu **head) {

    printf("请输入您要添加的学生编号信息：");
    int num;
    scanf("%d", &num);

    //申请一块内存，装入这个学生信息（结构体）
    struct stu *stu = (struct stu *)malloc(sizeof(struct stu));

    //将学生信息存在结构体中
    stu->num = num;

    stu->next = NULL;

    struct stu* p = *head;

    if (p == NULL) {  //链表中没有一个学生
        *head = stu;
    }
    else {   //链表中至少有一个学生
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = stu;
    }
    printf("编号%d添加成功\n", num);
}

void modify_stu(struct stu *head) {
    printf("请输入您要修改的学生编号：\n");
    int num;
    scanf("%d", &num);
    int flag = 0;
    while (head != NULL) {  //当前指针指向了一个空间
        if (head->num == num) {
            flag = 1;
            printf("OK，找到了要修改的学生编号%d\n", num);
            printf("请输入新的学生编号：");
            int num;
            scanf("%d", &num);
            head->num = num;
            printf("修改成功！\n");
            break;  //退出循环
        }
        else {
            head = head->next;
        }
    }
    if (!flag) {
        printf("sorry，未找到学生编号%d\n", num);
    }
}

void chaxun_stu(struct stu *head) {
    printf("请输入您要查询的学生编号：");
    int num;
    scanf("%d", &num);
    int flag = 0;
    while (head != NULL) {
        if (head->num == num) {
            flag = 1;
            printf("OK，已查询到%d编号信息\n", num);
            break;
        }
        else {
            head = head->next;
        }
    }
    if (!flag) {
        printf("sorry，未查询到%d编号信息\n", num);
    }
}

void delete_stu(struct stu **head) {
    struct stu* p = *head;
    printf("请输入您要删除的学生编号：");
    int num;
    scanf("%d", &num);
    struct stu* p2 = NULL;
    int flag = 0;
    while (p != NULL) {
        if (p->num == num) {
            flag = 1;
            //此时要删除的节点位置有三种
            if (p->next == NULL) { //删除链表最后一个节点
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
                if (p2 == NULL) {  //删除链表第一个节点
                    *head = p->next;
                    free(p);
                    p = NULL;
                }
                else {   //删除链表的中间某一个节点
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
        printf("sorry，未找到%d学生编号\n", num);
    }
}

void printf_stu(struct stu *head) {
    while (head != NULL) {
        printf("学生编号%d\n", head->num);
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