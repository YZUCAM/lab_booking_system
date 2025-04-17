#include "admin.h"


Admin::Admin()
{}

Admin::Admin(string name, string pwd)
{
    this->m_name = name;
    this->m_pwd = pwd;

    //init vector container and get all student and staff info from files
    this->init_vector(); 
}

void Admin::subMenu()
{
    cout << "==================== Log in Success ====================" << endl;
    cout << endl;
    cout << " ------------------------------------------------------ \n";
    cout << "|                    1. Add Account                    |\n";
    cout << "|                                                      |\n";
    cout << "|                    2. Check Account                  |\n";
    cout << "|                                                      |\n";
    cout << "|                    3. Check Lab Info                 |\n";
    cout << "|                                                      |\n";
    cout << "|                    4. Clear Appointments             |\n";
    cout << "|                                                      |\n";
    cout << "|                    0. Log Out                        |\n";
    cout << " ------------------------------------------------------ \n";
    cout << "Please enter your choice" << endl;

}

void Admin::add_member()
{
    cout << "Please enter the account type: " << endl;
    cout << "1. add student." << endl;
    cout << "2. add staff." << endl; 

    string fileName;
    string tip;     // id for student or id for staff
    string errorTip;

    ofstream ofs;

    int select = 0;
    cin >> select;

    if (select == 1)
    { 
        // student
        fileName = STUDENT_FILE;
        tip = "Please enter your student ID: ";
        errorTip = "Student ID repeated, please re-enter ID: ";
    }
    else
    {
        fileName = STAFF_FILE;
        tip = "Please enter your staff ID: ";
        errorTip = "Staff ID repeated, please re-enter ID: ";
    }

    ofs.open(fileName, ios::out | ios::app);

    int id;
    string name;
    string pwd;

    cout << tip << endl;
    while (true)
    {
        cin >> id;
        bool ret = this->check_repeat(id, select);
        if (ret)    // repeated
        {
            cout << errorTip << endl;
        }
        else
        {
            break;
        }
    }

    cout << "Please enter your name: " << endl;
    cin >> name;
    cout << "Please enter your password: " << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;
    ofs.close();

    this->init_vector();        // immediately reinit vector container. make sure namelist is always upadted.

    cout << "Add success." << endl;
    cout << "Press Enter to continue..." << endl;
    cin.ignore(1, '\n');
    cin.get();
    system("clear"); 
}

void printStu(Student& s)
{
    cout << "Student ID: " << s.m_ID << " name: " << s.m_name << endl;
}

void printSta(Staff& s)
{
    cout << "Staff ID: " << s.m_ID << " name: " << s.m_name << endl;
}

void Admin::show_member()
{
    cout << "Please select the check content: " << endl;
    cout << "1. Check all students. " << endl;
    cout << "2. Check all staffs. " << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        cout << "All student info show below: " << endl;
        for_each(v_stu.begin(),v_stu.end(), printStu);
    }
    else
    {
        cout << "All staff info show below: " << endl;
        for_each(v_sta.begin(),v_sta.end(), printSta);
    }
    cout << "Press Enter to continue..." << endl;
    cin.ignore(1, '\n');
    cin.get();
    system("clear"); 
}

void Admin::show_lab()
{

}

void Admin::clean_file()
{
    
}

void Admin::init_vector()
{
    v_sta.clear();
    v_stu.clear();

    //read file Student
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "Read student file failed." << endl;
        return;
    }

    Student s;
    while (ifs >> s.m_ID && ifs >> s.m_name && ifs >> s.m_pwd)
    {
        v_stu.push_back(s);
    }
    ifs.close();
    cout << "current students: " << v_stu.size() << endl;

    // read file staff
    ifs.open(STAFF_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "Read staff file failed." << endl;
        return;
    }

    Staff t;
    while (ifs >> t.m_ID && ifs >> t.m_name && ifs >> t.m_pwd)
    {
        v_sta.push_back(t);
    }
    ifs.close();
    cout << "current staff: " << v_sta.size() << endl;
}

bool Admin::check_repeat(int id, int type)
{
    if (type==1)
    {
        //student
        for (vector<Student>::iterator it=v_stu.begin(); it!=v_stu.end(); it++)
        {
            if (id == it->m_ID)
            {
                return true;
            }
        }
    }
    else
    {
        for (vector<Staff>::iterator it=v_sta.begin(); it!=v_sta.end(); it++)
        {
            if (id == it->m_ID)
            {
                return true;
            }
        }
    }
    return false;
}