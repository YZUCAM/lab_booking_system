#pragma once
#include <iostream>
#include <string>

using namespace std;

class Identity
{ 
public:

    virtual void subMenu() = 0;

    string m_name;
    string m_pwd;
};