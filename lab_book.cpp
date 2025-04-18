#include <iostream>
#include "identity.h"
#include <fstream>
#include <string>
#include "globalFile.h"
#include "student.h"
#include "staff.h"
#include "admin.h"

using namespace std;

// student subMenu
void studentMenu(Identity* & student)
{
    while(true)
    {
        student->subMenu();
        Student* stu =(Student*) student;

        int select = 0;
        cin >> select;

        if (select == 1)
        {
            // make an appointment
            stu->apply_order();
        }
        else if (select == 2)
        {
            // check own appointment
            stu->show_my_order();
        }
        else if (select == 3)
        {
            // check all appointment
            stu->show_all_order();
        }
        else if (select == 4)
        {
            // cancel appointment
            stu->cancel_order();
        }
        else
        {
            // Log out
            delete student;
            cout << "Log out." << endl;
            cout << "Press Enter to continue..." << endl;
            cin.ignore(1, '\n');
            cin.get();
            system("clear"); 
            return;
        }
    }
}




// enter admin subMenu
void adminMenu(Identity* &admin)
{
    while(true)
    {
        admin->subMenu();
        // convert base ptr to subclass ptr
        Admin* man = (Admin*) admin;

        int select = 0;
        cin >> select;

        if (select == 1)    // add account
        {
            // cout << "Add account." << endl;
            man->add_member();
        }
        else if (select == 2)   //check account
        {
            // cout << "Check accounts." << endl;
            man->show_member();
        }
        else if(select == 3)    //check lab info
        {
            // cout << "Check lab info." << endl;
            man->show_lab();
        }
        else if (select == 4)   //clear appointment
        {
            // cout << "Clear appointments." << endl;
            man->clean_file();
        }
        else
        {
            delete admin;
            cout << "Log out." << endl;
            cout << "Press Enter to continue..." << endl;
            cin.ignore(1, '\n');
            cin.get();
            system("clear"); 
            return;
        }
    }
}

// enter staff submenu
void staffMenu(Identity* &staff)
{
    while (true)
    {
        staff->subMenu();

        Staff* teacher = (Staff*)staff;

        int select = 0;

        cin >> select;

        if (select == 1)    // check all appointment
        {
            teacher->show_all_order();
        }
        else if (select == 2)   // review all appointment
        {
            teacher->review_order();
        }
        else
        {
            delete teacher;
            cout << "Log out." << endl;
            cout << "Press Enter to continue..." << endl;
            cin.ignore(1, '\n');
            cin.get();
            system("clear"); 
            return;
        }
    }
}



void login(string fileName, int type)
{
    Identity* person = NULL;

    ifstream ifs;
    ifs.open(fileName, ios::in);
    if (!ifs.is_open())
    {
        cout << "File does not exist." << endl;
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd; 

    //check identity type
    if (type==1)    // student
    {
        cout << "Please enter your student id: " << endl;
        cin >> id;
    }
    else if (type == 2) // staff
    {
        cout << "Please enter your staff id: " << endl;
        cin >> id;
    }

    cout << "Please enter your user name: " << endl;
    cin >> name;

    cout << "Please enter your user password: " << endl;
    cin >> pwd;

    if (type == 1)
    {
        // verify student
        int fid;
        string fname;
        string fpwd;
        while (ifs >> fid && ifs >> fname && ifs >> fpwd)
        {
            if (fid == id && fname == name && fpwd ==pwd)
            {
                cout << "Student login success." << endl;
                cout << "Press Enter to continue..." << endl;
                cin.ignore(1, '\n');
                cin.get();
                system("clear"); 

                person = new Student(id, name, pwd);
                // enter student submenu
                studentMenu(person);
                return;
            }
        }

    }
    else if (type == 2)
    {
        // verify staff
        int fid;
        string fname;
        string fpwd;
        while (ifs >> fid && ifs >> fname && ifs >> fpwd)
        {
            if (fid == id && fname == name && fpwd ==pwd)
            {
                cout << "Staff login success." << endl;
                cout << "Press Enter to continue..." << endl;
                cin.ignore(1, '\n');
                cin.get();
                system("clear"); 

                person = new Staff(id, name, pwd);
                // enter staff submenu
                staffMenu(person);
                return;
            }
        }
    }
    else if (type == 3)
    {
        // verify admin
        string fname;
        string fpwd;
        while (ifs >> fname && ifs >> fpwd)
        {
            if (fname == name && fpwd ==pwd)
            {
                cout << "Admin login success." << endl;
                cout << "Press Enter to continue..." << endl;
                cin.ignore(1, '\n');
                cin.get();
                system("clear"); 

                person = new Admin(name, pwd);
                // enter admin submenu
                adminMenu(person);
                return;
            } 
        }
    }
    cout << "Login Failed." << endl;
    cout << "Press Enter to continue..." << endl;
    cin.ignore(1, '\n');
    cin.get();
    system("clear"); 
    return;
}
 


int main()
{
    int select = 0;
     
    while (true)
    {
        cout << "==================== Welcome to Lab ====================" << endl;
        cout << endl;
        cout << " ------------------------------------------------------ \n";
        cout << "|                    1. Student                        |\n";
        cout << "|                                                      |\n";
        cout << "|                    2. Staff                          |\n";
        cout << "|                                                      |\n";
        cout << "|                    3. Admin                          |\n";
        cout << "|                                                      |\n";
        cout << "|                    0. Exit                           |\n";
        cout << " ------------------------------------------------------ \n";
        cout << "Please enter your identity" << endl;

        cin >> select;

        switch(select)
        {
        case 1:     // student
            login(STUDENT_FILE, 1);
            break;
        case 2:     // staff
            login(STAFF_FILE, 2);
            break;
        case 3:     // ad min
            login(ADMIN_FILE, 3);
            break;
        case 0:     // exit
            cout << "Welcome you back next tme." << endl;
            cout << "Press Enter to continue..." << endl;
            cin.ignore(1, '\n');
            return 0;
            break;
        default:
            cout << "Invalid input, please enter again: " << endl;
            cout << "Press Enter to continue..." << endl;
            cin.ignore(1, '\n');
            cin.get();
            system("clear"); 
            break; 
        }

    }

    // cin.ignore(1, '\n');
    // cin.get();
    // system("clear"); 
    cin.get();
    return 0;
}