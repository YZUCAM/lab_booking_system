#include "student.h"

Student::Student(){}

Student::Student(int id, string name, string pwd)
{
    this->m_ID = id;
    this->m_name = name;
    this->m_pwd = pwd;

    // init lab info
    ifstream ifs;
    ifs.open(LAB_FILE, ios::in);

    Lab lb;

    while (ifs >> lb.labroom_ID && ifs >> lb.labroom_capacity)
    {
        v_lab.push_back(lb);
    }
    ifs.close();
}

void Student::subMenu()
{
    cout << "==================== Log in Success ====================" << endl;
    cout << endl;
    cout << " ------------------------------------------------------ \n";
    cout << "|                 1. Make an appointment               |\n";
    cout << "|                                                      |\n";
    cout << "|                 2. Check my appointment              |\n";
    cout << "|                                                      |\n";
    cout << "|                 3. Check all appointment             |\n";
    cout << "|                                                      |\n";
    cout << "|                 4. Cancel Appointments               |\n";
    cout << "|                                                      |\n";
    cout << "|                 0. Log Out                           |\n";
    cout << " ------------------------------------------------------ \n";
    cout << "Please enter your choice" << endl;

}

void Student::apply_order()
{
    cout << "Lab room open weekdays." << endl;
    cout << "Please enter appointment date: " << endl;
    cout << "1 -> Monday" << endl;
    cout << "2 -> Tuesday" << endl;
    cout << "3 -> Wednesday" << endl;
    cout << "4 -> Thursday" << endl;
    cout << "5 -> Friday" << endl;

    int date = 0;
    int interval = 0;
    int roomid = 0;

    while (true)
    {
        cin >> date;
        if (date >=1 && date <=5)
        {
            break;
        }
        cout << "Invalid date, please re-enter: ";
    }

    cout << "Please enter appointment period: " << endl;
    cout << "1 -> Morning " << endl;
    cout << "2 -> Afternoon " << endl;
    while (true)
    {
        cin >> interval;
        if (interval >=1 && interval <=2)
        {
            break;
        }
        cout << "Invalid date, please re-enter: ";
    }

    cout << "Please enter lab room: " << endl;
    for (int i = 0; i < v_lab.size(); i++)
    {
        cout << "Lab room " << v_lab[i].labroom_ID << "     Capacity: " << v_lab[i].labroom_capacity << endl;
    }

    while (true)
    {
        cin >> roomid;
        if (roomid >=1 && roomid <= v_lab.size())
        {
            break;
        }
        cout << "Invalid date, please re-enter: ";
    }

    cout << "Making appointments success." << endl;

    ofstream ofs;
    ofs.open(ORDER_FILE, ios::app);
    ofs << "Date:" << date << " ";                      // no white space, as ifs sep is white space
    ofs << "Period:" << interval << " ";
    ofs << "Student_ID:" << this->m_ID << " ";
    ofs << "Student_name:" << this->m_name << " ";
    ofs << "Room_No:" << roomid << " ";
    ofs << "Status:" << 1 << endl;

    ofs.close();

    cout << "Press Enter to continue..." << endl;
    cin.ignore(1, '\n');
    cin.get();
    system("clear"); 
}

void Student::show_my_order()
{
    map<string, string> weekday;
    weekday.insert(make_pair("1", "Monday"));
    weekday.insert(make_pair("2", "Tuesday"));
    weekday.insert(make_pair("3", "Wednesday"));
    weekday.insert(make_pair("4", "Thursday"));
    weekday.insert(make_pair("5", "Friday"));

    map<string, string> status_info;
    status_info.insert(make_pair("1", "Review"));
    status_info.insert(make_pair("2", "Success"));
    status_info.insert(make_pair("3", "Failed"));
    status_info.insert(make_pair("4", "Canceled"));

    OrderMant om;
    if (om.m_size == 0)
    {
        cout << "No appointment records" << endl;
        cout << "Press Enter to continue..." << endl;
        cin.ignore(1, '\n');
        cin.get();
        system("clear");
        return;
    } 

    for (int i = 0; i < om.m_size; i++)
    {
        if (this->m_ID == atoi(om.m_orderDict[i]["Student_ID"].c_str()))
        {
            // find my own appointment
            cout << "Appointment date: " << weekday[om.m_orderDict[i]["Date"]];
            cout << "   Time: " << (om.m_orderDict[i]["Period"] == "1" ? "Moring":"Afternoon");
            cout << "   Lab Room No: " << om.m_orderDict[i]["Room_No"];
            cout << "   Status: " << status_info[om.m_orderDict[i]["Status"]] << endl;
        }
    }
    cout << "Press Enter to continue..." << endl;
    cin.ignore(1, '\n');
    cin.get();
    system("clear");
}

void Student::show_all_order()
{
    map<string, string> weekday;
    weekday.insert(make_pair("1", "Monday"));
    weekday.insert(make_pair("2", "Tuesday"));
    weekday.insert(make_pair("3", "Wednesday"));
    weekday.insert(make_pair("4", "Thursday"));
    weekday.insert(make_pair("5", "Friday"));

    map<string, string> status_info;
    status_info.insert(make_pair("1", "Review"));
    status_info.insert(make_pair("2", "Success"));
    status_info.insert(make_pair("3", "Failed"));
    status_info.insert(make_pair("4", "Canceled"));

    OrderMant om;
    if (om.m_size == 0)
    {
        cout << "No appointment records" << endl;
        cout << "Press Enter to continue..." << endl;
        cin.ignore(1, '\n');
        cin.get();
        system("clear");
        return;
    } 

    for (int i = 0; i < om.m_size; i++)
    {
        cout << i+1 << ". ";
        cout << "Appointment date: " << weekday[om.m_orderDict[i]["Date"]];
        cout << "   Time: " << (om.m_orderDict[i]["Period"] == "1" ? "Moring":"Afternoon");
        cout << "   Student_ID: " << om.m_orderDict[i]["Student_ID"];
        cout << "   Student_name: " << om.m_orderDict[i]["Student_name"];
        cout << "   Lab Room No: " << om.m_orderDict[i]["Room_No"];
        cout << "   Status: " << status_info[om.m_orderDict[i]["Status"]] << endl;
    }
    cout << "Press Enter to continue..." << endl;
    cin.ignore(1, '\n');
    cin.get();
    system("clear");
}

void Student::cancel_order()
{
    OrderMant om;
    if (om.m_size == 0)
    {
        cout << "No appointment records" << endl;
        cout << "Press Enter to continue..." << endl;
        cin.ignore(1, '\n');
        cin.get();
        system("clear");
        return;
    } 







    
}