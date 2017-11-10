#ifndef ACTOR_H
#define ACTOR_H

// including header files and liberaries
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
  // defining add_dept function
  void add_dept()
  {
    system(CLEAR);   // clearing output screen
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##            Add New Department        ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    Company cp;   // declaring Company class instance
    ofstream file;   // declaring output file stream instance
    file.open(DEPT_FILE, ios::binary|ios::app);   // opening department db file as output stream in append mode
    cp.get_details();   // getting department details
    file.write((char*)(&cp), sizeof(Company));  // writing data to department db file
    file.close();  // closing output file stream
  }

  // defining add_emp function
  void add_emp()
  {
    system(CLEAR);   // clearing output screen
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##           Add New Employee           ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    Company cp;   // declaring Company class instance
    Employee ep;   // defining employee class instance
    ofstream file;   // declaring output file stream instance
    file.open(EMP_FILE, ios::binary|ios::app);   // opening department db file as output stream in append mode
    ep.get_details();   // getting employee details
    file.write((char*)(&ep), sizeof(Employee));     // writing data to employee db file
    file.close();   // closing output file stream
  }

  // defining show_all function
  void show_all()
  {
    char opt;
    system(CLEAR);   // clearing output screen
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##          Listing All Details         ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    cout<<"what you wana list ? (D)epartment Details\t\t(E)mployee Details\n> ";
    cin>>opt;    // getting option
    cin.ignore();   // ignoring input stream buffer
    Company cp;   // declaring Company class instance
    Employee ep;   // defining employee class instance
    ifstream file;   // declaring input file stream instance
    if(opt == 'd' or opt == 'D')   // if user want to list department details
    {
      system(CLEAR);   // clearing output screen
      cout<<"\t\t\t##########################################"<<endl;
      cout<<"\t\t\t##                                      ##"<<endl;
      cout<<"\t\t\t##         Listing All Departments      ##"<<endl;
      cout<<"\t\t\t##                                      ##"<<endl;
      cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
      file.open(DEPT_FILE, ios::binary);   // opening department db file as input file stream
      if(!file)  //checking if department db file exists or not
      {
        cout<<"[!] Departments file not found";
      }
      else
      {
        file.seekg(0, ios::beg); // moving input file stream cursor to the begining of file
        cout<<"============================================================"<<endl;
        cout<<setw(10)<<"ID"<<setw(30)<<"Departments"<<endl;   // setw is used for output formatting
        cout<<"============================================================"<<endl;
        while(file.read((char*)(&cp), sizeof(Company)))  // reading db file until its end with cluster size = Employee
        {
          cp.show_details();  // showing department details
        }
      }
      file.close();  // closing input file stream
    }
    else if(opt == 'e' or opt == 'E')  // if user wants to show employee details
    {
      system(CLEAR);   // clearing output screen
      cout<<"\t\t\t##########################################"<<endl;
      cout<<"\t\t\t##                                      ##"<<endl;
      cout<<"\t\t\t##     Listing All Employee Details     ##"<<endl;
      cout<<"\t\t\t##                                      ##"<<endl;
      cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
      file.open(EMP_FILE, ios::binary);   // opening employee db file as input file stream
      if(!file)   // checking output
      {
        cout<<"[!] DB File Not Found";
      }
      else
      {
        file.seekg(0, ios::beg); // moving input file stream cursor to the begining of file
        while(file.read((char*)(&ep), sizeof(Employee)))   // reading db file until its end with cluster size = Employee
        {
          ep.show_details();   //sshowing employee details
        }
      }
      file.close();   // closing input file stream
    }
  }

  // defining del_emp function
  void del_emp()
  {
    int id;
    Employee ep;   // defining employee class instance
    system(CLEAR);   // clearing output screen
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##       Deleting Employee Details      ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    ifstream file;   // declaring input file stream instance
    ofstream temp;   // declaring output file stream instance
    file.open(EMP_FILE, ios::binary);    // opening employee db file as input file stream
    temp.open(TEMP_FILE, ios::binary);   // open temperary file as output file stream in overwrite mode
    if(!file) // checking if employee db file exists
    {
      cout<<"[!] DB File Not Found";
    }
    else
    {
      cout<<"enter employee id : ";
      cin>>id;   // getting id
      cin.ignore();   // ignoring input stream buffer
      file.seekg(0, ios::beg); // moving input file stream cursor to the begining of file
      while(file.read((char*)(&ep), sizeof(Employee)))   // reading db file until its end with cluster size = Employee
      {
        if(ep.get_id() != id)   // checking if employee db file id is not what user has entered
        {
          temp.write((char*)(&ep), sizeof(Employee));    // writing data to temperary file
        }
      }
    }
    file.close();    // closing input file stream
    temp.close();    // closing output file stream
    remove(EMP_FILE);  // deleting original employee database
    rename(TEMP_FILE, EMP_FILE);  // renaming new temperary database to original employee database
  }

  // defining del_dept function
  void del_dept()
  {
    int id;
    Company cp;   // declaring Company class instance
    system(CLEAR);   // clearing output screen
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##       Deleting Department Details    ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    ifstream file;   // declaring input file stream instance
    ofstream temp;   // declaring output file stream instance
    file.open(DEPT_FILE, ios::binary);   // opening department db as input stream
    temp.open(TEMP_FILE, ios::binary);   // opening temperary file as output stream in overwrite mode
    if(!file)  // checking department db file
    {
      cout<<"[!] DB File Not Found";
    }
    else
    {
      cout<<"enter department id : ";
      cin>>id;   // getting id
      cin.ignore();   // ignoring input stream buffer
      file.seekg(0, ios::beg); // moving input file stream cursor to the begining of file
      while(file.read((char*)(&cp), sizeof(Company)))  // reading db file until its end with cluster size = Employee
      {
        if(cp.get_id() != id)  // checking if department db id is not what user has entered
        {
          temp.write((char*)(&cp), sizeof(Company));  // writing data to temperary database
        }
      }
    }
    file.close();     // closing input  file stream
    temp.close();     // closing output file stream
    remove(DEPT_FILE);   // removing original departments db
    rename(TEMP_FILE, DEPT_FILE);   // renaming old departments db with new
  }

  // defining search_dept function
  void search_dept()
  {
    system(CLEAR);   // clearing output screen
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##     Searching Department Details     ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    bool found = false; // declaring flag variable
    ifstream file;   // declaring input file stream instance
    file.open(DEPT_FILE, ios::binary);  // opening department db file os input stream
    if(!file)   // checking if department db exists
    {
      cout<<"[!] DB File Not Found";
    }
    else
    {
      int id;
      cout<<"enter department id : ";
      cin>>id;    // getting department id
      cin.ignore();   // ignoring input stream buffer
      file.seekg(0, ios::beg); // moving input file stream cursor to the begining of file
      cout<<"============================================================"<<endl;
      cout<<setw(10)<<"ID"<<setw(30)<<"Departments"<<endl;    // setw is used here for output formatting
      cout<<"============================================================"<<endl;
      Company cp;   // declaring Company class instance
      while(file.read((char*)(&cp), sizeof(Company)))  // reading db file until its end with cluster size = Employee
      {
        if(cp.get_id() == id)  // checking if db employee id is id that user has entered or not
        {
          cp.show_details();   // showing Department Details
          found = true;   // setting found = true
        }
      }
    }
    file.close();   // closing input file stream
    if(!found)   // checking if user input found or not
    {
      cout<<"[!] Department Not Found";
    }
  }

  // defining search_emp function
  void search_emp()
  {
    system(CLEAR);   // clearing output screen
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##      Searching Employee Details      ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    bool found = false;   // declaring flag variable
    ifstream file;   // declaring input file stream instance
    file.open(EMP_FILE, ios::binary); // opening employee db file as input stream
    if(!file)  // checking if employee db exists or not
    {
      cout<<"[!] DB File Not Found";
    }
    else
    {
      int id;
      cout<<"enter employee id : ";
      cin>>id; // getting id
      cin.ignore();   // ignoring input stream buffer
      cout<<"\n\n";
      file.seekg(0, ios::beg); // moving input file stream cursor to the begining of file
      Employee ep;   // defining employee class instance
      while(file.read((char*)(&ep), sizeof(Employee)))   // reading db file until its end with cluster size = Employee
      {
        if(ep.get_id() == id)   // checking if db employee id is id that user has entered or not
        {
          ep.show_details();    // showing details of employee
          found = true;   // setting found = true
        }
      }
    }
    file.close();    // closing input file stream
    if(!found)   // checking if user input found or not
    {
      cout<<"[!] Employee Not Found";
    }
  }

  // defining mod_dept function
  void mod_dept()
  {
    system(CLEAR);   // clearing output screen
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##     Modifying Department Details     ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    bool found = false;  // declaring flag variable
    ifstream file;   // declaring input file stream instance
    ofstream temp;   // declaring output file stream instance
    file.open(DEPT_FILE, ios::binary);     // opening employee db in input stram
    temp.open(TEMP_FILE, ios::binary);    // opening temperary db in output stram with overwrite mode
    if(!file)  // checking if file exists or not
    {
      cout<<"[!] DB File Not Found";
    }
    else
    {
      int id;
      cout<<"enter department id : ";
      cin>>id;   // getting id
      cout<<"\n\n";
      cin.ignore();   // ignoring input stream buffer
      file.seekg(0, ios::beg); // moving input file stream cursor to the begining of file
      Company cp;   // declaring Company class instance
      while(file.read((char*)(&cp), sizeof(Company)))  // reading db file until its end with cluster size = Employee
      {
        if(cp.get_id() == id)  // checking if db employee id is id that user has entered or not
        {
          cp.modify();   // modifying departments details
          found = true;   // setting found = true
        }
        temp.write((char*)(&cp), sizeof(Company));  // writing data to output stream
      }
    }
    file.close();   // closing input file stream
    temp.close();   // closing output file stream
    remove(DEPT_FILE);   // removing original departments db
    rename(TEMP_FILE, DEPT_FILE);   // renaming old departments db with new
    if(!found)   // checking if user input found or not
    {
      cout<<"[!] Department Not Found";
    }
  }

  // defining mod_emp function
  void mod_emp()
  {
    system(CLEAR);   // clearing output screen
    cout<<"\t\t\t##########################################"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##      Modifying Employee Details      ##"<<endl;
    cout<<"\t\t\t##                                      ##"<<endl;
    cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
    bool found = false;   // declaring flag
    ifstream file;   // declaring input file stream instance
    ofstream temp;   // declaring output file stream instance
    file.open(EMP_FILE, ios::binary);   // opening employee db in input stram
    temp.open(TEMP_FILE, ios::binary);   // opening temperary file in output stream with overwrite mode
    if(!file)   // checking if file exits or not
    {
      cout<<"[!] DB File Not Found";
    }
    else
    {
      int id;
      cout<<"enter employee id : ";
      cin>>id;   // getting id
      cin.ignore();   // ignoring input stream buffer
      cout<<"\n\n";
      file.seekg(0, ios::beg); // moving input file stream cursor to the begining of file
      Employee ep;   // defining employee class instance
      while(file.read((char*)(&ep), sizeof(Employee)))   // reading db file until its end with cluster size = Employee
      {
        if(ep.get_id() == id)   // checking if db employee id is id that user has entered or not
        {
          ep.modify();   // modifying selection
          found = true;   // setting found = true
        }
        temp.write((char*)(&ep), sizeof(Employee));   // writing data to output file
      }
    }
    file.close();  // closing input file stream
    temp.close();  // closing output file stream
    remove(EMP_FILE);  // deleting original employee database
    rename(TEMP_FILE, EMP_FILE);  // renaming new temperary database to original employee database
    if(!found)   // checking if user input found or not
    {
      cout<<"[!] Employee Not Found";
    }
  }

} /* Actions */

#endif
