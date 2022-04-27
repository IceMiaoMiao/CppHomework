//
// Created by guo23 on 2022/4/26.
//
#include<iostream>
#include "Student.h"
#include "Common.h"
#include "Header.h"
#include "Master.h"
#include "fstream"
#define FILENAME "stuFile.txt"
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
    Student** stuArray;
    void AddStu();
    void Save();
    bool fileIsEmpty;
    int GetNum();
    void initStu();
    void ShowStu();
};


#endif //CPPHOMEWORK_STUDENTMANAGER_H
