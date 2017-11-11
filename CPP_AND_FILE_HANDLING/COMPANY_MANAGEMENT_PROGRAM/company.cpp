// including header files and liberaries
#include <iostream>
#include <iomanip>
#include "company.h"
using namespace std;

// defining Class Constructor
Company::Company()
{
  this->id = 0;
  this->name[0] = '\0';
}

// defining get_details method
void Company::get_details()
{
  cout<<"enter department id :";
  cin>>this->id;
  cin.ignore();   // ignoring input stream buffer
  cout<<"enter department name : ";
  cin.getline(this->name, 30);
}

// defining show_details method
void Company::show_details()
{
  cout<<setw(10)<<this->id<<setw(30)<<this->name<<endl;
}

// defining get_id method
int Company::get_id()
{
  return this->id;
}


// defining modify method
void Company::modify()
{
  cout<<"enter new department name : ";
  cin.getline(this->name, 30);
}
