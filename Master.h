//
// Created by guo23 on 2022/4/26.
//
#include "Student.h"
#ifndef CPPHOMEWORK_MASTER_H
#define CPPHOMEWORK_MASTER_H


class Master :public Student{
public:
    Master(int _id,string _name,int _did);
    void ShowInfo();
    string GetDepName();
};


#endif //CPPHOMEWORK_MASTER_H
