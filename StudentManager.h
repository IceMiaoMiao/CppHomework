//
// Created by guo23 on 2022/4/26.
//
#include<iostream>
#include "Student.h"
#include "Common.h"
#include "Header.h"
#include "Master.h"
#include "fstream"
//使用文件流，导入头文件
#define FILENAME "stuFile.txt"
//新建一个文件存储学生们的信息
using namespace std;
#ifndef CPPHOMEWORK_STUDENTMANAGER_H
#define CPPHOMEWORK_STUDENTMANAGER_H


class StudentManager {
public:
    StudentManager();
    ~StudentManager();
    void ShowMenu();
    void ExitSystem();
    int sumNum;
    //统计学生总数
    Student** stuArray;
    //二维指针，创建学生对象数组
    void AddStu();
    void Save();
    bool fileIsEmpty;
    //判断文件夹是否为空
    int GetNum();
    //得到学生总数
    void initStu();
    //根据文件初始化程序
    void ShowStu();

    void DelStu();
    int IsExit(int _id);
    //判断学生是否存在
    void ModStu();
    void FindStu();
    void SortStu();
    void CleanFile();

};


#endif //CPPHOMEWORK_STUDENTMANAGER_H
