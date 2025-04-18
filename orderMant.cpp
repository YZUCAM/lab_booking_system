#include "orderMant.h"

OrderMant::OrderMant()
{
     ifstream ifs;
     ifs.open(ORDER_FILE, ios::in);

     string date;
     string interval;
     string stuID;
     string stuName;
     string roomID;
     string status;
     
     this->m_size = 0;

     while (ifs >> date && ifs >> interval && ifs 
            >> stuID && ifs >> stuName && ifs >> roomID && ifs >> status)
     {
         // cout << date << endl;
         // cout << interval << endl;
         // cout << stuID << endl;
         // cout << stuName << endl;
         // cout << roomID << endl;
         // cout << status << endl;
         //date
         string key, value;
         map<string, string> m;

         int pos = date.find(":");
         if (pos != -1)
         {
            key = date.substr(0, pos);
            value = date.substr(pos+1, date.size() - pos -1);
            m.insert(make_pair(key, value));
         }

         pos = interval.find(":");
         if (pos != -1)
         {
            key = interval.substr(0, pos);
            value = interval.substr(pos+1, interval.size() - pos -1);
            m.insert(make_pair(key, value));
         }
         
         pos = stuID.find(":");
         if (pos != -1)
         {
            key = stuID.substr(0, pos);
            value = stuID.substr(pos+1, stuID.size() - pos -1);
            m.insert(make_pair(key, value));
         }

         pos = stuName.find(":");
         if (pos != -1)
         {
            key = stuName.substr(0, pos);
            value = stuName.substr(pos+1, stuName.size() - pos -1);
            m.insert(make_pair(key, value));
         }

         pos = roomID.find(":");
         if (pos != -1)
         {
            key = roomID.substr(0, pos);
            value = roomID.substr(pos+1, roomID.size() - pos -1);
            m.insert(make_pair(key, value));
         }

         pos = status.find(":");
         if (pos != -1)
         {
            key = status.substr(0, pos);
            value = status.substr(pos+1, status.size() - pos -1);
            m.insert(make_pair(key, value));
         }
         this->m_orderDict.insert(make_pair(this->m_size, m));
         this->m_size++;
     }
     ifs.close(); 
}

void OrderMant::updateOrder()
{
   if (this->m_size == 0 )
   {
      return; // 0 order record
   }
   //Date:1 Period:1 Student_ID:1 Student_name:Jason Room_No:3 Status:1
   ofstream ofs(ORDER_FILE, ios:: out | ios::trunc);
   for (int i = 0; i < this->m_size; i++)
   {
      ofs << "Date:" << this->m_orderDict[i]["Date"] << " ";
      ofs << "Period:" << this->m_orderDict[i]["Period"] << " ";
      ofs << "Student_ID:" << this->m_orderDict[i]["Student_ID"] << " ";
      ofs << "Student_name:" << this->m_orderDict[i]["Student_name"] << " ";
      ofs << "Room_No:" << this->m_orderDict[i]["Room_No"] << " ";
      ofs << "Status:" << this->m_orderDict[i]["Status"] << " ";
   }
   ofs.close();
   
}