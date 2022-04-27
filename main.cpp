#include <iostream>
#include "StudentManager.h"
//#include "Student.h"
#include "Common.h"
#include "Header.h"
#include "Master.h"
int main()
{
    StudentManager sm;
    /*
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

    while(1)
    {
        sm.ShowMenu();
        cout<<"请输入您的选择"<<endl;
        cin>>choice;
        switch (choice) {
            case 0:
                cout<<"tuichu"<<endl;
                sm.ExitSystem();
                break;
            case 1:
                sm.AddStu();
                break;
            case 2:
                sm.ShowStu();
                break;
            case 3:
                sm.DelStu();
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                system("cls");
                break;
        }
        //break;
    }


    return 0;
}
