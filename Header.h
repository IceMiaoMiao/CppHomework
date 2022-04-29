//
// Created by guo23 on 2022/4/26.
//
#include "Student.h"
#ifndef CPPHOMEWORK_HEADER_H
#define CPPHOMEWORK_HEADER_H

//做一下班里的头头的类
class Header :public Student{
public:
    Header(int _id,string _name,int _did);
    void ShowInfo();
    string GetDepName();
};


#endif //CPPHOMEWORK_HEADER_H
