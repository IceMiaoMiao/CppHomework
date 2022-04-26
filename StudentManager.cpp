//
// Created by guo23 on 2022/4/26.
//

#include "StudentManager.h"
StudentManager::StudentManager()
{
    cout<<"这是构造函数"<<endl;
}
StudentManager::~StudentManager()
{
    cout<<"这是析构函数"<<endl;
}

void StudentManager::ShowMenu()
{
    cout<<"我是一个分割线"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"-------欢迎使用学生管理系统-------"<<endl;
    cout<<"-------- 点我(0)退出程序------"<<endl;
    cout<<"-------点我(1)增加学生信息------"<<endl;
    cout<<"-------点我(2)显示学生信息------"<<endl;
    cout<<"-------点我(3)删除学生信息------"<<endl;
    cout<<"-------点我(4)修改学生信息------"<<endl;
    cout<<"-------点我(5)查找学生信息------"<<endl;
    cout<<"-------点我(6)给大家排序-------"<<endl;
    cout<<"-------点我(7)清空记录--------"<<endl;
    cout<<"俺是一个结束线"<<endl;
}