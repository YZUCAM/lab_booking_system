#pragma once
#include <iostream>
#include "identity.h"
#include <string>

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

};