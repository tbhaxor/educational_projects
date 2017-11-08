#include <iostream>
#include "bank.h"
using namespace std;

// defining constructor
Bank::Bank()
{
  this->acc_type = '\0';
  this->name[0] = this->email[0] = '\0';
  this->acc_number = this->phone_number = 0;
  this->balance = 0.0F;
}

// defining member functions
void Bank::get_details()
{
  cout<<"enter account number : ";
  cin>>this->acc_number;
  cin.ignore();             // ignoring input stream buffer
  cout<<"enter account holders name : ";
  cin.getline(this->name, 30);
  cout<<"enter account holders email : ";
  cin.getline(this->email, 30);
  cout<<"enter account type (c/s) : ";
  cin>>this->acc_type;
  cin.ignore();             // ignoring input stream buffer
  cout<<"enter account holders phone number: ";
  cin>>this->phone_number;
  cin.ignore();             // ignoring input stream buffer
  cout<<"enter initial balance : ";
  cin>>this->balance;
  cin.ignore();             // ignoring input stream buffer
}

void Bank::show_details()
{
  cout<<"Account Number : "<<this->acc_number<<"\t\t\t"<<"Account Type : "<<this->acc_type<<endl;
  cout<<"Account Holder Name : "<<this->name<<endl;
  cout<<"Account Holder Email : "<<this->email<<endl;
  cout<<"Account Holder Phone Number : "<<this->phone_number<<"\t\t\tBalance : "<<this->balance<<endl;
  cout<<"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
}

int Bank::is_acc_no()
{
  return this->acc_number;   // returning account number on the current position
}

float Bank::get_curr_bal()
{
  return this->balance;   // returning balance on the current position
}

void Bank::credit(float ammount)
{
  this->balance += ammount;      // incrementing balance on credit
}

void Bank::debit(float ammount)
{
  this->balance -= ammount;    // decreasing balance on debits
}

void Bank::modify()
{
  int opt;
  cout<<"What do you want to change ?"<<endl;
  cout<<"1. Name\t\t2. Email\t\t3. Phone Number\n> ";
  cin>>opt;
  cin.ignore();   // ignoring input stream buffer
  switch (opt)
  {
    case 1:
      cout<<"enter new name : ";
      cin.getline(this->name, 30);            // overwriting existing values
    break;
    case 2:
      cout<<"enter new email : ";
      cin.getline(this->email, 30);            // overwriting existing values
    break;
    case 3:
      cout<<"enter new phone number : ";
      cin>>this->phone_number;            // overwriting existing values
      cin.ignore();   // ignoring input stream buffer
    break;
  }
}
