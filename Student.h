//
// Created by guo23 on 2022/4/26.
//
#pragma once
#include<iostream>
using namespace std;
#ifndef CPPHOMEWORK_STUDENT_H
#define CPPHOMEWORK_STUDENT_H


class Student {
public:
    virtual void ShowInfo() = 0;
    virtual string GetDepName() = 0;
    //虚函数，不做实现，相信后来人的智慧
    int id;
    string name;
    int depId;
};


#endif //CPPHOMEWORK_STUDENT_H
