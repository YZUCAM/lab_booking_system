#pragma once
#include <iostream>
#include "identity.h"
#include <string>
#include <fstream>
#include "globalFile.h"
#include <vector>
#include "student.h"
#include "staff.h"
#include "lab.h"
#include <algorithm>

using namespace std;

class Admin : public Identity
{
public:
    Admin();
    Admin(string name, string pwd);

    virtual void subMenu();
    void add_member();
    void show_member();
    void show_lab();
    void clean_file();

    // init container 
    void init_vector();

    bool check_repeat(int id, int type);    //type 1 student 2 staff

    vector<Student> v_stu;
    vector<Staff> v_sta;
    vector<Lab> v_lab;
};