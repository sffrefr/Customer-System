//
// Created by ���������� on 2024/7/16.
//
#include <stdio.h>
#include <stdlib.h>
#include "struct_stu.h"

void read_file_to_link(struct stu **head){  //������һ���汾����Ա��Ϣ
    FILE *fp = fopen("Students_Message.txt" , "rb");
    if(fp == NULL){   //��дr���ļ�������ʱ,prΪNULL
        printf("�ļ���ʧ��\n");
        return;    //void����Ҳ����дreturn ,��ʱreturn��ʾ��ǰ����������û�з���ָ
    }

    struct stu temp;  //�����ļ�����Ϣ�ǽṹ���ʽ������ֻ���ýṹ��������

    while(fread(&temp, sizeof(struct stu) , 1 , fp) > 0){  //fread()�з���ָ�����ǵ�ǰ�����ֽڸ������������ˣ����Ƿ���0
        struct stu *stu = (struct stu *)malloc (sizeof(struct stu));
        stu->next = NULL;  //������temp.next����Ϊ��������һ���汾ʱ����ַ������ĳЩ�������Ѿ��ı��ˣ��൱������next�ܿ�����Ұָ��
        stu->num = temp.num;
#if DEBUG == 1
        printf("---�ļ��л�ȡ��ȡ����-----ѧ�����%d\n", temp.num);
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



void write_link_to_file(struct stu *head){   //����Ա��Ϣд���ļ�
    FILE *fp = fopen("Students_Message.txt" , "wb");

    while(head != NULL){
        fwrite(head,sizeof(struct stu) , 1 , fp);
#if DEBUG == 1
        printf("---------������Ϣ���ļ�-----ѧ�����%d\n", head->num);
#endif
        head = head->next;
    }

    fclose(fp);
}