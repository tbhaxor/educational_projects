#include <iostream>
#include <fstream>
#include <iomanip>
#include "book.h"
#include "config.h"
using namespace std;

// ---------------------
//    PROTOTYPES
// ---------------------
void intro();
int menu();
void add_new();
void list_all();
void delete_book();
void mod_book();

int main()
{
  intro();
  while(true)
  {
      switch(menu())
      {
        case 5:
          return 0; // exit
        break;
        case 1:
          add_new();
        break;
        case 2:
          list_all();
        break;
        case 4:
          delete_book();
        break;
        case 3:
          mod_book();
        break;
        default:
        cout<<"[x] Wrong Input...";  // if 1-5 is not entered
      }
      cout<<"\n\n[!] Press Enter To Continue...";
      cin.get();
  }
}

// ---------------------
//    Defining Menu
// ---------------------
int menu()
{
  short opt;
  system(CLEAR);
  cout<<"\t\t\t========================"<<endl;
  cout<<"\t\t\t========  MENU  ========"<<endl;
  cout<<"\t\t\t========================"<<endl<<endl;
  cout<<"1. Add new book"<<endl;
  cout<<"2. List all books"<<endl;
  cout<<"3. Modify Book"<<endl;
  cout<<"4. Delete Book"<<endl;
  cout<<"5. Exit"<<endl;
  cout<<"> ";
  cin>>opt;
  cin.ignore();  // ignore stream buffer
  return opt;
}

// ---------------------
//    Defining Intro
// ---------------------
void intro()
{
  system(CLEAR);
  cout<<"\t\t\t==============================================="<<endl;
  cout<<"\t\t\t========  Bookshop Management Program  ========"<<endl;
  cout<<"\t\t\t==============================================="<<endl<<endl;
  cout<<"Coded By : "<<CODER<<endl;
  cout<<"Submitted To : "<<SUBMITTED_TO<<endl;
  cout<<"Institution : "<<INSTITUTION<<endl;
  cout<<"\n\n[!] Info - Press Enter To Continue . . .";
  cin.get();   // alternate for pause
}

// ---------------------
//  Function to add new book details
// ---------------------
void add_new()
{
  system(CLEAR);
  cout<<"\t\t\t================================"<<endl;
  cout<<"\t\t\t========  Add New Book  ========"<<endl;
  cout<<"\t\t\t================================"<<endl<<endl;
  Book bk; // declaration of Book instance
  ofstream file;   // outstream
  file.open(ORIGINAL, ios::binary|ios::app);  // opening file as binary in append mode
  bk.getdata(); // getting data
  file.write(reinterpret_cast<char *> (&bk), sizeof(Book));  // writing data to file object
  file.close();   // closing and saving file
}

// ---------------------
//  Function to list all book details
// ---------------------
void list_all()
{
  system(CLEAR);
  cout<<"\t\t\t============================================"<<endl;
  cout<<"\t\t\t========  Listing All Book Details  ========"<<endl;
  cout<<"\t\t\t============================================"<<endl<<endl<<endl;
  Book bk; // declaration of Book instance
  ifstream file;  // input stream
  file.open(ORIGINAL, ios::binary);  // opening file as binary in read mode
  if(!file)   // checking whether file exists or not
  {
    cout<<"[x] File doesnt exists . . .";
  }
  else
  {
    file.seekg(0, ios::beg);   // taking file cursor to begining
    while(file.read(reinterpret_cast<char *> (&bk), sizeof(Book))) // iterattion body will be looped till all data read
    {
      bk.showdata(); // showing data
    }
  }
  file.close();
}

// ---------------------
//  Function to delete book details
// ---------------------
void delete_book()
{
  int book_id;
  system(CLEAR);
  cout<<"\t\t\t======================================="<<endl;
  cout<<"\t\t\t========  Delete Book Details  ========"<<endl;
  cout<<"\t\t\t======================================="<<endl<<endl<<endl;
  cout<<"enter book id : ";
  cin>>book_id; // getting book id to delete
  Book bk;
  ifstream file;
  ofstream fil_;

  file.open(ORIGINAL, ios::binary);
  if(!file)
  {
    cout<<"[x] File doesnt exists . . .";
  }
  else
  {
    fil_.open(TEMP, ios::binary);
    file.seekg(0, ios::beg);
    while(file.read(reinterpret_cast<char *> (&bk), sizeof(Book)))
    {
      if(book_id != bk.get_book_id())   // if doesnt match id then write to temp file
        fil_.write(reinterpret_cast<char *> (&bk), sizeof(Book));
    }
  fil_.close();
  file.close();
  remove(ORIGINAL);
  rename(TEMP, ORIGINAL);
  }
}

// ---------------------
//  Function to modify book details
// ---------------------
void mod_book()
{
  int book_id;
  system(CLEAR);
  cout<<"\t\t\t======================================="<<endl;
  cout<<"\t\t\t========  Modify Book Details  ========"<<endl;
  cout<<"\t\t\t======================================="<<endl<<endl<<endl;
  cout<<"enter book id : ";
  cin>>book_id; // getting book id to delete
  Book bk;
  ifstream file;
  ofstream fil_;

  file.open(ORIGINAL, ios::binary);
  if(!file)
  {
    cout<<"[x] File doesnt exists . . .";
  }
  else
  {
    fil_.open(TEMP, ios::binary);
    file.seekg(0, ios::beg);
    while(file.read(reinterpret_cast<char *> (&bk), sizeof(Book)))
    {
      if(book_id != bk.get_book_id())   // if doesnt match id then write to temp file
        fil_.write(reinterpret_cast<char *> (&bk), sizeof(Book));
      else
      {
        bk.modify(); // if id exists then modify and add to file
        fil_.write(reinterpret_cast<char *> (&bk), sizeof(Book));
      }
    }
  fil_.close();
  file.close();
  remove(ORIGINAL); // Deleted ORIGINAL
  rename(TEMP, ORIGINAL);  // renamed temp file as ORIGINAL file
  }
}
