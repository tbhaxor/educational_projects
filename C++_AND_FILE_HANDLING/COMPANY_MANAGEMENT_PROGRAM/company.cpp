#include <iostream>
#include <iomanip>
#include "company.h"
using namespace std;

Company::Company()
{
  this->id = 0;
  this->name[0] = '\0';
}

void Company::get_details()
{
  cout<<"enter department id :";
  cin>>this->id;
  cin.ignore();
  cout<<"enter department name : ";
  cin.getline(this->name, 30);
}

void Company::show_details()
{
  cout<<setw(10)<<this->id<<setw(30)<<this->name<<endl;
}

char* Company::get_name()
{
  return this->name;
}

int Company::get_id()
{
  return this->id;
}
