//
// Created by 柚子噗噗仔 on 2024/7/15.
//

#ifndef C_LINK_H
#define C_LINK_H
#include "struct_stu.h"

//函数的声明
void add_stu(struct stu **head);

void modify_stu(struct stu *head);

void chaxun_stu(struct stu *head);

void delete_stu(struct stu **head);

void printf_stu(struct stu *head);

void exit_stu(struct stu *head);

#endif //C_LINK_H
