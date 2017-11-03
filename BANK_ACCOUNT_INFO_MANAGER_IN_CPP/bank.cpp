#include "bank.h"
#include <iostream>
using namespace std;

Bank::Bank()
{
  this->acc_no = 0;
  this->name[0] = '\0';
  this->balance = 0.0F;
  this->type = '\0';
}

Bank::~Bank()
{
  this->acc_no = 0;
  this->name[0] = '\0';
  this->balance = 0.0F;
  this->type = '\0';
}

void Bank::get()
{
  cout<<"enter account number : ";
  cin>>this->acc_no;
  cin.ignore();
  cout<<"enter account holder's name : ";
  cin.getline(this->name, 50);
  cout<<"enter balance : ";
  cin>>this->balance;
  cin.ignore();
  cout<<"enter type of account (C - Current or S - Saving) : ";
  cin>>this->type;
}

void Bank::put()
{
  cout<<"Account Number : "<<this->acc_no<<"\t\tAccount Type : "<<this->type<<endl;
  cout<<"Account Holder Name : "<<this->name<<endl;
  cout<<"Current Balance : "<<this->balance<<endl;
  cout<<"--------------------------------------------------------"<<endl;
}

int Bank::is_acc_no()
{
  return this->acc_no;
}
