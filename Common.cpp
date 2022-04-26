//
// Created by guo23 on 2022/4/26.
//

#include "Common.h"
Common::Common(int _id,string _name,int _did)
{
    this->id = _id;
    this->name = _name;
    this->depId = _did;
}
void Common::ShowInfo()
{
    cout<<"俺的学号是："<<id
    <<"\t名字是："<<name
    <<"\t职务是："<<GetDepName()<<depId
    <<"\t俺的任务是好好学习 "<<endl;
}
string Common::GetDepName()
{
    return "俺是平平无奇大学生";
}