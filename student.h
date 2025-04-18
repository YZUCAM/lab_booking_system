#pragma once
#include <iostream>
#include "identity.h"
#include <string>
#include <vector>
#include "lab.h"
#include <fstream>
#include "globalFile.h"
#include "orderMant.h"

using namespace std;

class Student : public Identity
{
public:
    Student();
    Student(int id, string name, string pwd);

    virtual void subMenu();

    void apply_order();
    void show_my_order();
    void show_all_order();
    void cancel_order();

    int m_ID;

    vector<Lab> v_lab;
};