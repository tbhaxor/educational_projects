// including all headers and liberaries
#include <iostream>
#include "employee.h"
using namespace std;

// defining Employee Class Constructor
Employee::Employee()
{
  this->name[0] = this->post[0] = this->address[0] = this->join_date[0] =  '\0';
  this->id = this->department =0;
  this->salary = 0.0F;
}

// defining get_details method
void Employee::get_details()
{
  cout<<"enter department id : ";
  cin>>this->department;
  cin.ignore();   // ignoring input stream buffer
  cout<<"enter employee id : ";
  cin>>this->id;
  cin.ignore();   // ignoring input stream buffer
  cout<<"enter employee name : ";
  cin.getline(this->name, 30);
  cout<<"enter date of joining (dd/mm/yy): ";
  cin.getline(this->join_date, 10);
  cout<<"enter post assigned : ";
  cin.getline(this->post, 30);
  cout<<"enter residential address : ";
  cin.getline(this->address, 30);
  cout<<"enter salary : ";
  cin>>this->salary;
  cin.ignore();   // ignoring input stream buffer
}

// defining show_details method
void Employee::show_details()
{
  cout<<"Employee ID : "<<this->id<<"\t\t\tEmployee Name : "<<this->name<<endl;
  cout<<"Employee Date of Joining : "<<this->join_date<<endl;
  cout<<"Employee Post : "<<this->post<<"\t\t\tDepartment Name : "<<this->department<<endl;
  cout<<"Employee Residential Address : "<<this->address<<endl;
  cout<<"Employee Salary : "<<this->salary<<endl;
  cout<<"-----------------------------------------------------------------------"<<endl;
}

// defining get_id method
int Employee::get_id()
{
  return this->id;
}

// defining modify method
void Employee::modify()
{
  int opt;
  cout<<"what you want to Modify ?"<<endl;
  cout<<"1. Name"<<endl;
  cout<<"2. Post"<<endl;
  cout<<"3. Department"<<endl;
  cout<<"4. Address"<<endl;
  cout<<"5. Salary"<<endl;
  cin>>opt;
  cin.ignore();   // ignoring input stream buffer
  switch (opt)
  {
    case 1:
      cout<<"enter new name : ";
      cin.getline(this->name, 20);
    break;
    case 2:
      cout<<"enter new post : ";
      cin.getline(this->post, 20);
    break;
    case 3:
      cout<<"enter new department : ";
      cin>>this->department;
      cin.ignore();   // ignoring input stream buffer
    break;
    case 4:
      cout<<"enter new address : ";
      cin.getline(this->address, 35);
    break;
    case 5:
      cout<<"enter new salary : ";
      cin>>this->salary;
      cin.ignore();   // ignoring input stream buffer
    break;
  }
}
