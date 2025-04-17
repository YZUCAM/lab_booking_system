#include <iostream>
#include "identity.h"
#include <fstream>
#include <string>
#include "globalFile.h"

using namespace std;

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
    }
    else if (type == 2)
    {
        // verify staff
    }
    else if (type == 3)
    {
        // verify admin
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