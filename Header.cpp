//
// Created by guo23 on 2022/4/26.
//

#include "Header.h"
Header::Header(int _id, string _name, int _did)
{
    this->id = _id;
    this->name = _name;
    this->depId = _did;
}
void Header::ShowInfo()
{
    cout<<"俺的学号是："<<id
        <<"\t名字是："<<name
        <<"\t职务是："<<GetDepName()<<depId
        <<"\t俺的任务是帮助同学们 "<<endl;
}
string Header::GetDepName()
{
    return "俺是乐于帮助同学的班干部";
}