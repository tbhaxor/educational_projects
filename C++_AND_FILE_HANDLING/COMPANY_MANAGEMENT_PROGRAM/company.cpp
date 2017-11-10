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
  cin.ignore();   // ignoring input stream buffer
  cout<<"enter department name : ";
  cin.getline(this->name, 30);
}

void Company::show_details()
{
  cout<<setw(10)<<this->id<<setw(30)<<this->name<<endl;
}


int Company::get_id()
{
  return this->id;
}

void Company::modify()
{
  cout<<"enter new department name : ";
  cin.getline(this->name, 30);
}
