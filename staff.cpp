#include "staff.h"


Staff::Staff()
{

}


Staff::Staff(int id, string name, string pwd)
{
    this->m_ID = id;
    this->m_name = name;
    this->m_pwd = pwd;
}


void Staff::subMenu()
{
    cout << "==================== Log in Success ====================" << endl;
    cout << endl;
    cout << " ------------------------------------------------------ \n";
    cout << "|                 1. Check all appointment             |\n";
    cout << "|                                                      |\n";
    cout << "|                 2. Review Appointments               |\n";
    cout << "|                                                      |\n";
    cout << "|                 0. Log Out                           |\n";
    cout << " ------------------------------------------------------ \n";
    cout << "Please enter your choice" << endl;
}

void Staff::show_all_order()
{
    map<string, string> weekday;
    weekday.insert(make_pair("1", "Monday"));
    weekday.insert(make_pair("2", "Tuesday"));
    weekday.insert(make_pair("3", "Wednesday"));
    weekday.insert(make_pair("4", "Thursday"));
    weekday.insert(make_pair("5", "Friday"));

    map<string, string> status_info;
    status_info.insert(make_pair("1", "Pending"));
    status_info.insert(make_pair("2", "Success"));
    status_info.insert(make_pair("3", "Failed"));
    status_info.insert(make_pair("4", "Cancelled"));

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
        cout << "   Time: " << (om.m_orderDict[i]["Period"] == "1" ? "Morning":"Afternoon");
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


void Staff::review_order()
{
    map<string, string> weekday;
    weekday.insert(make_pair("1", "Monday"));
    weekday.insert(make_pair("2", "Tuesday"));
    weekday.insert(make_pair("3", "Wednesday"));
    weekday.insert(make_pair("4", "Thursday"));
    weekday.insert(make_pair("5", "Friday"));

    map<string, string> status_info;
    status_info.insert(make_pair("1", "Pending"));
    status_info.insert(make_pair("2", "Success"));
    status_info.insert(make_pair("3", "Failed"));
    status_info.insert(make_pair("4", "Cancelled"));

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

    cout << "Pending appointments listed below: "  << endl;

    int index = 0;
    vector<int> v; // store the index in the m_orderDict

    for (int i = 0; i < om.m_size; i++)
    {
        // filter status
        if (om.m_orderDict[i]["Status"] == "1" )
        {
            v.push_back(i);
            cout << ++index << ". ";
            cout << "Appointment date: " << weekday[om.m_orderDict[i]["Date"]];
            cout << "   Time: " << (om.m_orderDict[i]["Period"] == "1" ? "Morning":"Afternoon");
            cout << "   Student_ID: " << om.m_orderDict[i]["Student_ID"];
            cout << "   Student_name: " << om.m_orderDict[i]["Student_name"];
            cout << "   Lab Room No: " << om.m_orderDict[i]["Room_No"];
            cout << "   Status: " << status_info[om.m_orderDict[i]["Status"]] << endl;
        }
    }

    cout << "Please enter record No to review, or enter 0 to return." << endl;
    
    int select = 0;
    int ret = 0;

    while (true)
    {
        cin >> select;

        if (select >=0 && select <= v.size())
        {
            if (select == 0)
            {
                break;
            }
            else
            {
                cout << "Please input review results: " << endl;
                cout << "1. Accept. " << endl;
                cout << "2. Reject. " << endl;
                cin >> ret;

                if (ret == 1)
                {
                    om.m_orderDict[v[select-1]]["Status"] = "2";
                }
                else
                {
                    om.m_orderDict[v[select-1]]["Status"] = "3";
                }
                om.updateOrder();
                cout << "Review completed." << endl;
                break;
            }
        }
        cout << "Invalid input, please re-enter." << endl;
    }
    cout << "Press Enter to continue..." << endl;
    cin.ignore(1, '\n');
    cin.get();
    system("clear");
}