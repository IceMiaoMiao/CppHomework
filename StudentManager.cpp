//
// Created by guo23 on 2022/4/26.
//

#include "StudentManager.h"
StudentManager::StudentManager()
{
    cout<<"这是构造函数"<<endl;
    this->sumNum = 0;
    this->stuArray = NULL;
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
void StudentManager::AddStu()
{
    cout<<"请输入添加学生的数量"<<endl;
    int addNum = 0;
    cin>>addNum;
    if (addNum > 0)
    {
        int newSize = this->sumNum + addNum;
        Student** newSpace = new Student*[newSize];
        if (this->sumNum != NULL)
        {
            for (int i = 0; i < this->sumNum; ++i) {
                newSpace[i] = this->stuArray[i];
            }
        }
        for (int i = 0; i < addNum; ++i) {
            int id;
            string name;
            int dSelect;
            cout<<"请输入第 "<<i+1<<" 个新学生的ID"<<endl;
            cin>>id;
            cout<<"请输入第 "<<i+1<<" 个新学生的姓名"<<endl;
            cin>>name;
            cout<<"请输入第 "<<i+1<<" 个新学生的职务"<<endl;
            cout<<"1.平平无奇大学生"<<endl;
            cout<<"2.乐于助人班干部"<<endl;
            cout<<"3.管理班级小能手"<<endl;
            cin>>dSelect;
            Student * student = NULL;
            switch (dSelect) {
                case 1:
                    student = new Common(id,name,dSelect);
                    break;
                case 2:
                    student = new Header(id,name,dSelect);
                    break;
                case 3:
                    student = new Master(id,name,dSelect);
                    break;
                default:
                    break;
            }
            newSpace[this->sumNum+i] = student;
        }
        delete[] this->stuArray;
        this->stuArray = newSpace;
        sumNum = newSize;
        cout<<"成功添加"<<addNum<<"名新同学"<<endl;

    }
    else
    {

    }
}
void StudentManager::ExitSystem()
{
    cout<<"俺要退出程序啦"<<endl;
    system("pause");
    exit(0);
}