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
    //字面意思，就不解释啦
    cout<<"俺的学号是："<<id
    <<"\t 名字是："<<name
    <<"\t 职务是："<<GetDepName()
    <<"\t 俺的任务是好好学习 "<<endl;
}
string Common::GetDepName()
{
    return "俺是平平无奇大学生";
    //大声告诉别人，你是干嘛的
}