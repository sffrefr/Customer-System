//
// Created by 柚子噗噗仔 on 2024/7/15.
//结构体之类非函数的数据结构声明使用.h文件

#ifndef C_STRUCT_STU_H
#define C_STRUCT_STU_H

struct stu {
    int num;  //学生编号
    struct stu* next ;  //存放下一个节点（结构体）的地址
};

#endif //C_STRUCT_STU_H
