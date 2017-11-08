#include "book.h"
#include <iostream>
using namespace std;

// ---------------------
//  Method to get current book id
// ---------------------
int Book::get_book_id()
{
  return this->book_id;
}

// ---------------------
//  Method to print book details
// ---------------------
void Book::showdata()
{
  cout<<"Book ID : "<<this->book_id<<"\t\tPrice : "<<this->price<<endl;
  cout<<"Name : "<<this->name<<endl;
  cout<<"Author : "<<this->author<<endl;
  cout<<"Quantity : "<<this->quantity<<endl;
  cout<<"-------------------------------------------------------------\n\n";
}

// ---------------------
//  Method to get new book details
// ---------------------
void Book::getdata()
{
  cout<<"enter book id : ";
  cin>>this->book_id;
  cin.ignore();
  cout<<"enter book name : ";
  cin.getline(this->name, 30);
  cout<<"enter author name : ";
  cin.getline(this->author, 30);
  cout<<"enter quantity : ";
  cin>>this->quantity;
  cin.ignore();
  cout<<"enter price : ";
  cin>>this->price;
  cin.ignore();
}


// ---------------------
//  Method to modify book details
// ---------------------
void Book::modify()
{
  int opt;
  cout<<"What you wana modify ?"<<endl;
  cout<<"1. Name"<<endl;
  cout<<"2. Author"<<endl;
  cout<<"3. Quantity"<<endl;
  cout<<"4. Price"<<endl;
  cin>>opt;
  cin.ignore();
  switch (opt) {
    case 1:
      cout<<"enter new book name : ";
      cin.getline(this->name, 30);
    break;
    case 2:
      cout<<"enter new author name : ";
      cin.getline(this->author, 30);
    break;
    case 3:
      cout<<"enter new quantity : ";
      cin>>this->quantity;
      cin.ignore();
    break;
    case 4:
      cout<<"enter new price : ";
      cin>>this->price;
      cin.ignore();
    break;
  }
}
