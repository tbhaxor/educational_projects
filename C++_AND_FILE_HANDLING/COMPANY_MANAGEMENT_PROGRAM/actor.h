#ifndef ACTOR_H
#define ACTOR_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "config.h"
#include "company.h"
#include "employee.h"
using namespace std;

namespace Actions
{
  void add_dept()
  {
    system(CLEAR);
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##            Add New Department        ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    Company cp;
    ofstream file;
    file.open(DEPT_FILE, ios::binary|ios::app);
    cp.get_details();
    file.write((char*)(&cp), sizeof(Company));
    file.close();
  }
  void add_emp()
  {
    char* name;
    int dep_id;
    system(CLEAR);
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##           Add New Employee           ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    Company cp;
    Employee ep;
    ofstream file;
    ifstream comp;
    file.open(EMP_FILE, ios::binary|ios::app);
    comp.open(DEPT_FILE, ios::binary);
    cout<<"enter department id : ";
    cin>>dep_id;
    cin.ignore();
    if(!comp)
    {
      cout<<"[!] Departments file not found";
    }
    else
    {
      comp.seekg(0, ios::beg);
      while(comp.read((char*)(&cp), sizeof(Company)))
      {
        if (cp.get_id() == dep_id)
        {
          name = cp.get_name();
        }
      }
    }
    ep.get_details(name);
    file.write((char*)(&ep), sizeof(Employee));
    file.close();
    comp.close();
  }

  void show_all()
  {
    system(CLEAR);
    char opt;
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##          Listing All Details         ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    cout<<"what you wana list ? (D)epartment Details\t\t(E)mployee Details\n> ";
    cin>>opt;
    cin.ignore();
    Company cp;
    Employee ep;
    ifstream file;
    if(opt == 'd' or opt == 'D')
    {
      file.open(DEPT_FILE, ios::binary);
      if(!file)
      {
        cout<<"[!] Departments file not found";
      }
      else
      {
        file.seekg(0, ios::beg);
        cout<<"============================================================"<<endl;
        cout<<setw(10)<<"ID"<<setw(30)<<"Departments"<<endl;
        cout<<"============================================================"<<endl;
        while(file.read((char*)(&cp), sizeof(Company)))
        {
          cp.show_details();
        }
      }
      file.close();
    }
    else if(opt == 'e' or opt == 'E')
    {
      file.open(EMP_FILE, ios::binary);
      if(!file)
      {
        cout<<"[!] DB File Not Found";
      }
      else
      {
        file.seekg(0, ios::beg);
        while(file.read((char*)(&cp), sizeof(Company)))
        {
          ep.show_details();
        }
      }
      file.close();
    }
  }
  void del_emp()
  {
    int id;
    Company cp;
    system(CLEAR);
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##       Deleting Employee Details      ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    ifstream file;
    ofstream temp;
    file.open("MAIN_FILE", ios::binary);
    temp.open(TEMP_FILE, ios::binary);
    if(!file)
    {
      cout<<"[!] DB File Not Found";
    }
    else
    {
      cout<<"enter employee id : ";
      cin>>id;
      cin.ignore();
      file.seekg(0, ios::beg);
      while(file.read((char*)(&cp), sizeof(Company)))
      {
      }
    }
    file.close();
    temp.close();
    remove("MAIN_FILE");
    rename(TEMP_FILE, "MAIN_FILE");
  }

  void del_dept()
  {
    int id;
    Company cp;
    system(CLEAR);
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##       Deleting Department Details    ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    ifstream file;
    ofstream temp;
    file.open("MAIN_FILE", ios::binary);
    temp.open(TEMP_FILE, ios::binary);
    if(!file)
    {
      cout<<"[!] DB File Not Found";
    }
    else
    {
      cout<<"enter department id : ";
      cin>>id;
      cin.ignore();
      file.seekg(0, ios::beg);
      while(file.read((char*)(&cp), sizeof(Company)))
      {
      }
    }
    file.close();
    temp.close();
    remove("MAIN_FILE");
    rename(TEMP_FILE, "MAIN_FILE");
  }


} /* Actions */

#endif
