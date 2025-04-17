#pragma once
#include <iostream>
#include "identity.h"
#include <string>

using namespace std;

class Staff : public Identity
{
public:
    Staff();
    Staff(int id, string name, string pwd);

    virtual void subMenu();

    void show_all_order();
    void review_order();

    int m_ID;
};