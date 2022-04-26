#include <iostream>
#include "StudentManager.h"
//#include "Student.h"
#include "Common.h"
#include "Header.h"
int main()
{
    StudentManager sm;
    Common *cm = NULL;
    cm = new Common(1,"yy",2);
    cm->ShowInfo();
    Header *he = NULL;
    he = new Header(1,"yy",2);
    he->ShowInfo();
    /*
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
                break;
            case 2:
                break;
            case 3:
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
        break;
    }
    */

    return 0;
}
