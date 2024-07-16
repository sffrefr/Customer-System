//
// Created by 柚子噗噗仔 on 2024/7/16.
//
#include <stdio.h>
#include <stdlib.h>
#include "struct_stu.h"

void read_file_to_link(struct stu **head){  //重置上一个版本的人员信息
    FILE *fp = fopen("Students_Message.txt" , "rb");
    if(fp == NULL){   //当写r且文件不存在时,pr为NULL
        printf("文件打开失败\n");
        return;    //void函数也可以写return ,此时return表示当前函数结束，没有返回指
    }

    struct stu temp;  //由于文件中信息是结构体格式，所以只能用结构体来接收

    while(fread(&temp, sizeof(struct stu) , 1 , fp) > 0){  //fread()有返回指，就是当前读的字节个数，当读完了，就是返回0
        struct stu *stu = (struct stu *)malloc (sizeof(struct stu));
        stu->next = NULL;  //不能用temp.next。因为在重置上一个版本时，地址可能在某些操作中已经改变了，相当于这是next很可能是野指针
        stu->num = temp.num;
#if DEBUG == 1
        printf("---文件中获取读取数据-----学生编号%d\n", temp.num);
#endif
        if((*head) == NULL){
            *head = stu;
        }
        else{
            struct stu *p = *head;
            while(p->next != NULL){
                p = p ->next;
            }
            p->next = stu;
        }
    }
    fclose(fp);
}



void write_link_to_file(struct stu *head){   //将人员信息写入文件
    FILE *fp = fopen("Students_Message.txt" , "wb");

    while(head != NULL){
        fwrite(head,sizeof(struct stu) , 1 , fp);
#if DEBUG == 1
        printf("---------保存信息到文件-----学生编号%d\n", head->num);
#endif
        head = head->next;
    }

    fclose(fp);
}