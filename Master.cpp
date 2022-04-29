//
// Created by guo23 on 2022/4/26.
//
//做一下班里老大的类
#include "Master.h"
Master::Master(int _id,string _name,int _did)
{
    this->id = _id;
    this->name = _name;
    this->depId = _did;
}
void Master::ShowInfo()
{
    //字面意思，展示一下信息
    cout<<"俺的学号是："<<id
        <<"\t名字是："<<name
        <<"\t职务是："<<GetDepName()<<depId
        <<"\t 俺的任务是管理班级 "<<endl;

}
string Master::GetDepName()
{
    return "俺是班里面的老大 ";
    //你是干啥的
}