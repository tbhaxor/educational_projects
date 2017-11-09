#include <iostream>
#include "company.h"
using namespace std;

void Company::get()
{
  get_details();
  cout<<"enter department name : ";
  cin.getline(this->name, 30);
}

void Company::show()
{
  show_details();
  cout<<"Department Name : "<<this->name<<endl;
}
