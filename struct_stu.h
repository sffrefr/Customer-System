//
// Created by 柚子噗噗仔 on 2024/7/16.
//

#ifndef CUSTOM_SYSTEM_STRUCT_STU_H
#define CUSTOM_SYSTEM_STRUCT_STU_H

#define DEBUG 0

struct stu {
    int num;  //学生编号
    struct stu* next ;  //存放下一个节点（结构体）的地址
};

#endif //CUSTOM_SYSTEM_STRUCT_STU_H
