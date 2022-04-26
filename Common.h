//
// Created by guo23 on 2022/4/26.
//
#include "Student.h"
#ifndef CPPHOMEWORK_COMMON_H
#define CPPHOMEWORK_COMMON_H


class Common :public Student{
public:
    Common(int _id,string _name,int _did);
    void ShowInfo();
    string GetDepName();
};


#endif //CPPHOMEWORK_COMMON_H
