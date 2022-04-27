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
    cout<<"----------我是一个分割线------------"<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"-------欢迎使用学生管理系统-------"<<endl;
    cout<<"-------- 点我(0)退出程序------"<<endl;
    cout<<"-------点我(1)增加学生信息------"<<endl;
    cout<<"-------点我(2)显示学生信息------"<<endl;
    cout<<"-------点我(3)删除学生信息------"<<endl;
    cout<<"-------点我(4)修改学生信息------"<<endl;
    cout<<"-------点我(5)查找学生信息------"<<endl;
    cout<<"-------点我(6)给大家排序-------"<<endl;
    cout<<"-------点我(7)清空记录--------"<<endl;
    cout<<"----------俺是一个结束线----------"<<endl;
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
void StudentManager::ShowStu()
{
    if (this->fileIsEmpty)
    {
        cout<<"我怎么是空的?"<<endl;
    }
    else
    {
        for (int i = 0; i < sumNum; ++i) {
            this->stuArray[i]->ShowInfo();
        }
    }
    system("pause");
    system("cls");
}
void StudentManager::DelStu()
{
    if (this->fileIsEmpty)
    {
        cout<<"别看啦，我什么都没有"<<endl;
    }
    else
    {
        cout<<"你想删除哪个呢？输入ID呗"<<endl;
        int id = 0;
        cin>>id;
        int index = this->IsExit(id);
        if (index != -1)
        {
            for (int i = index; i < this->sumNum-1; ++i) {
                this->stuArray[i] = this->stuArray[i+1];

            }
            this->sumNum--;
            this->Save();
            cout<<"删除成功啦，找不到这位同学了已经"<<endl;
        }
        else
        {
            cout<<"没有这个学生啦"<<endl;
        }
    }
    system("pause");
    system("cls");

}
int StudentManager::IsExit(int _id)
{
    int index = -1;
    for (int i = 0; i < this->sumNum; ++i) {
        if (stuArray[i]->id==_id)
        {
            index = i;
            break;
        }
    }
    return index;
}
void StudentManager::ModStu()
{
    if (this->fileIsEmpty)
    {
        cout<<"qaq俺什么都没有"<<endl;
    }
    else
    {
        cout<<"修改哪位同学呢，给我一个ID呗"<<endl;
        int id;
        cin>>id;
        int ret = this->IsExit(id);
        if (ret != -1)
        {
            delete this->stuArray[ret];
            int newId = 0;
            string newName;
            int newdId;
            cout<<"找到这个同学啦"<<endl<<"请输入新id"<<endl;
            cin>>newId;
            cout<<"给这位同学起个新名字呗"<<endl;
            cin>>newName;
            cout<<"新岗位呢"<<endl;
            cin>>newdId;
            Student * student = NULL;
            switch (newdId) {
                case 1:
                    student = new Common(newId,newName,newdId);
                    break;
                case 2:
                    student = new Header(newId,newName,newdId);
                    break;
                case 3:
                    student = new Master(newId,newName,newdId);
                    break;
                default:
                    break;
            }
            this->stuArray[ret] = student;
            cout<<"修改成功啦"<<endl;
             this->Save();
        }
        else
        {
            cout<<"qaq，俺没有改成功，是不是输入错了呢?"<<endl;

        }
    }
    system("pause");
    system("cls");
}
void StudentManager::FindStu()
{
    if (this->fileIsEmpty)
    {
        cout<<"呜呜，我什么都没有"<<endl;

    }
    else
    {
        cout<<"你想怎么查找同学呢?"<<endl
            <<"俺想按照ID查找，点1"<<endl
            <<"俺想按照姓名查找，点2"<<endl;
        int select = 0;
        cin>>select;
        if (select == 1)
        {
            int id ;
            cout<<"查找哪个同学呢?给俺一个ID呗"<<endl;
            cin>>id;
            int ret = IsExit(id);
            if (ret != -1)
            {
                cout<<"找到这位同学啦"<<endl;
                this->stuArray[ret]->ShowInfo();
            }
            else
            {
                cout<<"俺怎么找不到这个人qaq"<<endl;

            }
        }
        else if (select == 2)
        {
            string name;
            cout<<"查找哪个同学呢，给俺一个名字呗"<<endl;
            cin>>name;
            bool flag = false;

            for (int i = 0; i < sumNum; ++i) {
                if (this->stuArray[i]->name == name)
                {
                    cout<<"找到这个同学啦，这位同学编号是"
                    <<this->stuArray[i]->id<<endl;
                    cout<<"他的信息在这里呦"<<endl;

                    flag = true;
                    this->stuArray[i]->ShowInfo();
                }
            }
            if (!flag)
            {
                cout<<"qaq俺怎么没有找到这个同学呢"<<endl;

            }
        }
        else
        {
            cout<<"你想怎么查啦?"<<endl;
        }
    }
    system("pause");
    system("cls");
}
void StudentManager::SortStu()
{
    if (this->fileIsEmpty)
    {
        cout<<"俺这里什么都没有啦"<<endl;
        system("pause");
        system("cls");

    }
    else
    {
        cout<<"怎么排序呢?\n按1升序\n按2降序"<<endl;
        int select = 0;
        cin>>select;
        for (int i = 0; i < sumNum; ++i) {
            int minOrMax = i;
            for (int j = i+1; j < sumNum - i; ++j)
            {
                if (select == 1)
                {
                    if (this->stuArray[minOrMax]->id > this->stuArray[j]->id)
                    {
                        minOrMax = j;
                    }

                }
                else
                {
                    if (this->stuArray[minOrMax]->id < this->stuArray[j]->id)
                    {
                        minOrMax = j;
                    }
                }
            }
            if (i != minOrMax)
            {
                Student * student = this->stuArray[i];
                stuArray[i]= stuArray[minOrMax];
                stuArray[minOrMax] = student;

            }


        }
        cout<<"俺排序完成啦"<<endl;
        this->Save();
        this->ShowStu();

    }
}
void StudentManager::CleanFile()
{
    cout<<"真的要全部清空嘛?\n点1确定\n点2取消"<<endl;
    int select = 0;
    cin>>select;
    if (select==1)
    {
        ofstream ofs(FILENAME,ios::trunc);
        //删除文件后重建
        ofs.close();
        if (this->stuArray != NULL)
        {

            for (int i = 0; i < this->sumNum; ++i) {
                delete this->stuArray[i];
                this->stuArray[i] = NULL;

            }
            delete[] stuArray;
            stuArray = NULL;
            this->sumNum = 0;
            this->fileIsEmpty = true;

        }
        cout<<"成功全部删除啦"<<endl;
    }
    system("pause");
    system("cls");

}