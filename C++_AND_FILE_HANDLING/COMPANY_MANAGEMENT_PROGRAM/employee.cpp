#include <iostream>
#include "employee.h"
using namespace std;

void Employee::get_details()
{
  cout<<"enter employee name : ";
  cin.getline(this->name, 30);
}

void Employee::show_details()
{
  cout<<"Employee Name : "<<this->name<<endl;
}
