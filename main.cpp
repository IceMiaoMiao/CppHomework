#include <iostream>
#include "StudentManager.h"
//#include "Student.h"
#include "Common.h"
#include "Header.h"
#include "Master.h"
int main()
{
    StudentManager sm;
    //先新建一个对象
    /*
     * 我是调试的代码
    Common *cm = NULL;
    cm = new Common(1,"yy",2);
    cm->ShowInfo();
    Header *he = NULL;
    he = new Header(1,"yy",2);
    he->ShowInfo();
    Master * master;
    master = new Master(1,"aa",2);
    master->ShowInfo();
    */

    int choice;
    //接受用户的选择，做出相应的操作
    while(1)
    {
        //死循环，可以一直接受数据
        sm.ShowMenu();
        //让用户看看咱们的菜单，好点菜
        cout<<"请输入您的选择"<<endl;

        cin>>choice;
        //接受用户的选择
        switch (choice) {
            case 0:
                //退出系统，下次再见
                cout<<"tuichu"<<endl;
                sm.ExitSystem();
                break;
            case 1:
                //添加几个同学的信息
                sm.AddStu();
                break;
            case 2:
                //展示当前添加进来的同学们的信息
                sm.ShowStu();
                break;
            case 3:
                //删除一些同学的信息
                sm.DelStu();
                break;
            case 4:
                //修改一些同学的信息
                sm.ModStu();
                break;
            case 5:
                //查找一些同学的信息
                sm.FindStu();
                break;
            case 6:
                //给同学们拍拍序
                sm.SortStu();
                break;
            case 7:
                //清空文件
                sm.CleanFile();
                break;
            default:
                //如果没有输入以上数字。清空重新打印菜单
                system("cls");
                break;
        }
        //break;
    }


    return 0;
}
