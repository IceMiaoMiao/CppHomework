//
// Created by guo23 on 2022/4/26.
//

#include "StudentManager.h"
StudentManager::StudentManager()
{

    cout<<"俺是构造函数"<<endl;
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    //文件流读入文件中的信息
    if (!ifs.is_open())
    {
        //没有文件的初始化操作
        cout<<"我怎么没有新建文件！"<<endl;
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
        //有文件，但文件是空的，此时的初始化操作

        cout<<"文件空空的，比钱包还干净"<<endl;
        this->sumNum = 0;
        this->stuArray = NULL;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }
    int num = this->GetNum();
    //有文件，文件也不是空的，此时的操作
    cout<<"当前有："<<num<<"个学生"<<endl;
    this->sumNum = num;
    //开辟空间
    this->stuArray = new Student*[this->sumNum];
    //初始化数据，添加到数组中
    this->initStu();

}
StudentManager::~StudentManager()
{
    cout<<"俺是析构函数"<<endl;
}

void StudentManager::ShowMenu()
{
    cout<<"----------我是一个快乐的分割线------------"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"------------欢迎使用学生管理系统----------"<<endl;
    cout<<"------------- 点我(0)退出程序------------"<<endl;
    cout<<"------------点我(1)增加学生信息-----------"<<endl;
    cout<<"------------点我(2)显示学生信息-----------"<<endl;
    cout<<"------------点我(3)删除学生信息-----------"<<endl;
    cout<<"------------点我(4)修改学生信息-----------"<<endl;
    cout<<"------------点我(5)查找学生信息-----------"<<endl;
    cout<<"------------点我(6)给大家排序------------"<<endl;
    cout<<"------------点我(7)清空记录-------------"<<endl;
    cout<<"-------俺是一个结束线，看到我程序就结束啦-----"<<endl;
}
void StudentManager::AddStu()
{
    cout<<"请输入添加学生的数量"<<endl;
    int addNum = 0;
    cin>>addNum;
    //添加学生的数量
    if (addNum > 0)
    {
        int newSize = this->sumNum + addNum;
        //当前的数量加上添加的数量
        Student** newSpace = new Student*[newSize];
        //也是二维数组，不过这里是为了进行多态处理
        if (this->sumNum != NULL)
        {
            for (int i = 0; i < this->sumNum; ++i)
            {
                newSpace[i] = this->stuArray[i];
                //把存储的学生信息搬到新数组中
            }
        }
        for (int i = 0; i < addNum; ++i)
        {
            //这里很简单，字面意思
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
            switch (dSelect)
            {
                //基于多态的处理
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
            //把新的学生信息添加到新数组中
        }
        delete[] this->stuArray;
        //删除旧数组
        this->stuArray = newSpace;
        //让旧数组的指针指向新数组
        sumNum = newSize;
        this->Save();
        //别忘了保存文件
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
    //字面意思，退出程序的函数
    cout<<"俺要退出程序啦"<<endl;
    system("pause");
    exit(0);
}
void StudentManager::Save()
{
    //写入文件
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    //把内容写道文件中，方便下次用
    for (int i = 0; i < this->sumNum; ++i) {
        ofs<<this->stuArray[i]->id<<" "
        <<this->stuArray[i]->name<<" "
        <<this->stuArray[i]->depId<<endl;
        //写入文件流的操作
    }
    //关闭文件
    ofs.close();
}
int StudentManager::GetNum()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    //打开文件，读出
    int id;
    string name;
    int did;
    int num = 0;

    while(ifs>>id && ifs>>name && ifs >>did)
    {
        num++;
        //让num加1
        //读取到学生之后，数量++
    }
    return num;
}
void StudentManager::initStu()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    //读取文件，初始化学生
    int id;
    string name;
    int did;
    int index = 0;
    while(ifs>>id && ifs>>name && ifs >>did)
    {
        Student * student = NULL;
        //先让它初始化为空
        //然后和刚才一样，进行多态处理
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
        //让指针指向新对象
        index++;

    }
    ifs.close();
    //关闭文件
}
void StudentManager::ShowStu()
{
    if (this->fileIsEmpty)
    {
        cout<<"我怎么是空的?"<<endl;
    }
    else
    {
        //来，同学们，给大家露个脸
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
        //根据ID索引删除的学生
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
            //保存一下文件
            cout<<"删除成功啦，找不到这位同学了已经"<<endl;
        }
        else
        {
            //找不到学生的情况
            cout<<"没有这个学生啦"<<endl;
        }
    }
    system("pause");
    system("cls");

}
int StudentManager::IsExit(int _id)
{
    //看看学生在不在
    int index = -1;
    for (int i = 0; i < this->sumNum; ++i) {
        if (stuArray[i]->id==_id)
        {
            index = i;
            break;
        }
    }
    return index;
    //在了就返回索引，否则返回-1
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
        //找到要修改同学的索引
        if (ret != -1)
        {
            delete this->stuArray[ret];
            //先删除旧指针
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
            //让旧指针指向新对象，和刚才一样
            cout<<"修改成功啦"<<endl;
            this->Save();
            //保存一下
        }
        else
        {
            cout<<"qaq，俺没有改成功，是不是输入错了呢?"<<endl;
            //你可能输入有误
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
            //按ID查找
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
            //按姓名查找
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
        //根据ID号按升序和降序排序
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
        //很熟悉的排序操作
        cout<<"俺排序完成啦"<<endl;
        this->Save();
        this->ShowStu();
        //让排序完的学生们出来展示展示吧

    }
}
void StudentManager::CleanFile()
{
    //字面意思，清空文件
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
            //删除指针
            stuArray = NULL;
            this->sumNum = 0;
            this->fileIsEmpty = true;

        }
        cout<<"成功全部删除啦"<<endl;
    }
    system("pause");
    system("cls");

}