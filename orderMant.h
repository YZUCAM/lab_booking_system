#pragma once
#include <iostream>
#include <map>
#include "globalFile.h"
#include <fstream>
#include <string>

using namespace std;

class OrderMant
{
public:

    OrderMant();

    void updateOrder();

    int m_size;

    map<int, map<string, string>> m_orderDict;



};