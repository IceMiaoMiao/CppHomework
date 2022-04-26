//
// Created by guo23 on 2022/4/26.
//

#include "StudentManager.h"
StudentManager::StudentManager()
{

    cout<<"这是构造函数"<<endl;
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if (!ifs.is_open())
    {
        cout<<"当前不存在文件！"<<endl;
        this->sumNum = 0;
        this->stuArray = NULL;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }
    char ch;
    ifs>>ch;
    if (ifs.eof())
    {
        cout<<"文件空空的，比钱包还干净"<<endl;
        this->sumNum = 0;
        this->stuArray = NULL;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }
    int num = this->GetNum();
    cout<<"当前有："<<num<<"个学生"<<endl;
    this->sumNum = num;
    //开辟空间
    this->stuArray = new Student*[this->sumNum];
    //初始化数据，添加到数组中
    this->initStu();

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
        this->Save();
        fileIsEmpty = false;
        cout<<"成功添加"<<addNum<<"名新同学"<<endl;

    }
    else
    {
        cout<<"你是不是输入有误啊啊"<<endl;
    }
    system("pause");
    system("cls");
}
void StudentManager::ExitSystem()
{
    cout<<"俺要退出程序啦"<<endl;
    system("pause");
    exit(0);
}
void StudentManager::Save()
{
    //写入文件
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    for (int i = 0; i < this->sumNum; ++i) {
        ofs<<this->stuArray[i]->id<<" "
        <<this->stuArray[i]->name<<" "
        <<this->stuArray[i]->depId<<endl;
    }
    //关闭文件
    ofs.close();
}
int StudentManager::GetNum()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int did;
    int num = 0;

    while(ifs>>id && ifs>>name && ifs >>did)
    {
        num++;

    }
    return num;
}
void StudentManager::initStu()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int did;
    int index = 0;
    while(ifs>>id && ifs>>name && ifs >>did)
    {
        Student * student = NULL;
        if (did == 1)
        {
            student = new Common(id,name,did);

        }
        else if (did==2)
        {
            student = new Header(id,name,did);
        }
        else
        {
            student = new Master(id,name,did);
        }
        this->stuArray[index] = student;
        index++;

    }
    ifs.close();
}