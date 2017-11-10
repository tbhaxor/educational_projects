#ifndef ACTOR_H
#define ACTOR_H

// including
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
    system(CLEAR);
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##           Add New Employee           ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    Company cp;
    Employee ep;
    ofstream file;
    file.open(EMP_FILE, ios::binary|ios::app);
    ep.get_details();
    file.write((char*)(&ep), sizeof(Employee));
    file.close();
  }

  void show_all()
  {
    char opt;
    system(CLEAR);
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##          Listing All Details         ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    cout<<"what you wana list ? (D)epartment Details\t\t(E)mployee Details\n> ";
    cin>>opt;
    cin.ignore();   // ignoring input stream buffer
    Company cp;
    Employee ep;
    ifstream file;
    if(opt == 'd' or opt == 'D')
    {
      system(CLEAR);
      cout<<"\t\t\t##########################################"<<endl;
      cout<<"\t\t\t##                                      ##"<<endl;
      cout<<"\t\t\t##         Listing All Departments      ##"<<endl;
      cout<<"\t\t\t##                                      ##"<<endl;
      cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
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
      system(CLEAR);
      cout<<"\t\t\t##########################################"<<endl;
      cout<<"\t\t\t##                                      ##"<<endl;
      cout<<"\t\t\t##     Listing All Employee Details     ##"<<endl;
      cout<<"\t\t\t##                                      ##"<<endl;
      cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
      file.open(EMP_FILE, ios::binary);
      if(!file)
      {
        cout<<"[!] DB File Not Found";
      }
      else
      {
        file.seekg(0, ios::beg);
        while(file.read((char*)(&ep), sizeof(Employee)))
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
    Employee ep;
    system(CLEAR);
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##       Deleting Employee Details      ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    ifstream file;
    ofstream temp;
    file.open(EMP_FILE, ios::binary);
    temp.open(TEMP_FILE, ios::binary);
    if(!file)
    {
      cout<<"[!] DB File Not Found";
    }
    else
    {
      cout<<"enter employee id : ";
      cin>>id;
      cin.ignore();   // ignoring input stream buffer
      file.seekg(0, ios::beg);
      while(file.read((char*)(&ep), sizeof(Employee)))
      {
        if(ep.get_id() != id)
        {
          temp.write((char*)(&ep), sizeof(Employee));
        }
      }
    }
    file.close();
    temp.close();
    remove(EMP_FILE);
    rename(TEMP_FILE, EMP_FILE);
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
    file.open(DEPT_FILE, ios::binary);
    temp.open(TEMP_FILE, ios::binary);
    if(!file)
    {
      cout<<"[!] DB File Not Found";
    }
    else
    {
      cout<<"enter department id : ";
      cin>>id;
      cin.ignore();   // ignoring input stream buffer
      file.seekg(0, ios::beg);
      while(file.read((char*)(&cp), sizeof(Company)))
      {
        if(cp.get_id() != id)
        {
          temp.write((char*)(&cp), sizeof(Company));
        }
      }
    }
    file.close();
    temp.close();
    remove(DEPT_FILE);
    rename(TEMP_FILE, DEPT_FILE);
  }

  void search_dept()
  {
    system(CLEAR);
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##     Searching Department Details     ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    bool found = false;
    ifstream file;
    file.open(DEPT_FILE, ios::binary);
    if(!file)
    {
      cout<<"[!] DB File Not Found";
    }
    else
    {
      int id;
      cout<<"enter department id : ";
      cin>>id;
      cin.ignore();   // ignoring input stream buffer
      file.seekg(0, ios::beg);
      cout<<"============================================================"<<endl;
      cout<<setw(10)<<"ID"<<setw(30)<<"Departments"<<endl;
      cout<<"============================================================"<<endl;
      Company cp;
      while(file.read((char*)(&cp), sizeof(Company)))
      {
        if(cp.get_id() == id)
        {
          cp.show_details();
          found = true;
        }
      }
    }
    file.close();
    if(!found)
    {
      cout<<"[!] Department Not Found";
    }
  }

  void search_emp()
  {
    system(CLEAR);
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##      Searching Employee Details      ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    bool found = false;
    ifstream file;
    file.open(EMP_FILE, ios::binary);
    if(!file)
    {
      cout<<"[!] DB File Not Found";
    }
    else
    {
      int id;
      cout<<"enter employee id : ";
      cin>>id;
      cin.ignore();   // ignoring input stream buffer
      cout<<"\n\n";
      file.seekg(0, ios::beg);
      Employee ep;
      while(file.read((char*)(&ep), sizeof(Employee)))
      {
        if(ep.get_id() == id)
        {
          ep.show_details();
          found = true;
        }
      }
    }
    file.close();
    if(!found)
    {
      cout<<"[!] Employee Not Found";
    }
  }

  void mod_dept()
  {
    system(CLEAR);
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##     Modifying Department Details     ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    bool found = false;
    ifstream file;
    ofstream temp;
    file.open(DEPT_FILE, ios::binary);
    temp.open(TEMP_FILE, ios::binary);
    if(!file)
    {
      cout<<"[!] DB File Not Found";
    }
    else
    {
      int id;
      cout<<"enter department id : ";
      cin>>id;
      cout<<"\n\n";
      cin.ignore();   // ignoring input stream buffer
      file.seekg(0, ios::beg);
      Company cp;
      while(file.read((char*)(&cp), sizeof(Company)))
      {
        if(cp.get_id() == id)
        {
          cp.modify();
          found = true;
        }
        temp.write((char*)(&cp), sizeof(Company));
      }
    }
    file.close();
    temp.close();
    remove(DEPT_FILE);
    rename(TEMP_FILE, DEPT_FILE);
    if(!found)
    {
      cout<<"[!] Department Not Found";
    }
  }

  void mod_emp()
  {
    system(CLEAR);
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##      Modifying Employee Details      ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    bool found = false;
    ifstream file;
    ofstream temp;
    file.open(EMP_FILE, ios::binary);
    temp.open(TEMP_FILE, ios::binary);
    if(!file)
    {
      cout<<"[!] DB File Not Found";
    }
    else
    {
      int id;
      cout<<"enter employee id : ";
      cin>>id;
      cin.ignore();   // ignoring input stream buffer
      cout<<"\n\n";
      file.seekg(0, ios::beg);
      Employee ep;
      while(file.read((char*)(&ep), sizeof(Employee)))
      {
        if(ep.get_id() == id)
        {
          ep.modify();
          found = true;
        }
        temp.write((char*)(&ep), sizeof(Employee));
      }
    }
    file.close();
    temp.close();
    remove(EMP_FILE);
    rename(TEMP_FILE, EMP_FILE);
    if(!found)
    {
      cout<<"[!] Employee Not Found";
    }
  }

} /* Actions */

#endif
