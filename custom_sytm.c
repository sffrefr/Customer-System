//
// Created by 柚子噗噗仔 on 2024/7/15.
//
/*
链表之人员信息系统实操(二)
*/

#include <stdio.h>
#include "menu.h"
#include "link.h"



int main() {
    printf_menu();      //打印功能
    struct stu* head = NULL;

    while (1) {
        printf("----------------------\n");
        printf("请输入您要进行操作的功能数字：");
        int num;
        scanf("%d", &num);
        switch (num) {
            case 1:
                add_stu(&head);  //添加学生信息
                break;
            case 2:
                modify_stu(head);  //修改学生信息
                break;
            case 3:
                chaxun_stu(head);  //查询学生信息
                break;
            case 4:
                delete_stu(&head);   //删除学生信息
                break;
            case 5:
                printf_stu(head);  //打印学生信息
                break;
            case 6:
                exit_stu(head);   //退出系统
                head = NULL;
                return 0;
            default:
                printf("对不起，输入的数字有误，请重新操作\n");
        }
    }

    return 0;
}


