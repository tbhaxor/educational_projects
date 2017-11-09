#include <iostream>
#include "employee.h"
using namespace std;

Employee::Employee()
{
  this->name[0] = this->post[0] = this->address[0] = this->join_date[0] =  '\0';
  this->id = this->department =0;
  this->salary = 0.0F;
}
void Employee::get_details()
{
  cout<<"enter department id : ";
  cin>>this->department;
  cin.ignore();
  cout<<"enter employee id : ";
  cin>>this->id;
  cin.ignore();
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
  cin.ignore();
}

void Employee::show_details()
{
  cout<<"Employee ID : "<<this->id<<"\t\t\tEmployee Name : "<<this->name<<endl;
  cout<<"Employee Date of Joining : "<<this->join_date<<endl;
  cout<<"Employee Post : "<<this->post<<"\t\t\tDepartment Name : "<<this->department<<endl;
  cout<<"Employee Residential Address : "<<this->address<<endl;
  cout<<"Employee Salary : "<<this->salary<<endl;
  cout<<"-----------------------------------------------------------------------"<<endl;
}

int Employee::get_id()
{
  return this->id;
}
