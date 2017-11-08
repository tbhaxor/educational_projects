#ifndef ACTIONS_H
#define ACTIONS_H

// including header files and liberaries
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include "bank.h"
#include "config.h"
#include <iomanip>
using namespace std;

// namespace for spliting strings
namespace Split
{
  vector<string> split(const string& str, const char& ch)
  {
      string next;
      vector<string> result;

      // For each character in the string
      for (string::const_iterator it = str.begin(); it != str.end(); it++) {
          // If we've hit the terminal character
          if (*it == ch) {
              // If we have some characters accumulated
              if (!next.empty()) {
                  // Add them to the result vector
                  result.push_back(next);
                  next.clear();
              }
          } else {
              // Accumulate the next character into the sequence
              next += *it;
          }
      }
      if (!next.empty())
           result.push_back(next);
      return result;
  }
} /* Split */

namespace Actions
{

  void add_new()
  {
    Bank acc;     // declaring Bank class instance
    system(CLEAR);    // clearing output screen
    cout<<"\t\t\t __________________________________________________ "<<endl;
    cout<<"\t\t\t|                                                  |"<<endl;
    cout<<"\t\t\t|            Add New Account Details               |"<<endl;
    cout<<"\t\t\t|__________________________________________________|"<<endl<<endl<<endl;
    acc.get_details();   // getting details from user
    ofstream file1;     // declaring output file stream instance
    file1.open(MAIN_FILE, ios::binary|ios::app);   // opening binary file in append mode
    file1.write(reinterpret_cast<char *> (&acc), sizeof(Bank));  // writing obejct in the db of size = cluster size = size of Bank class
    file1.close();    // closing file stream
  }

  void show_all()
  {
    system(CLEAR);    // clearing output screen
    cout<<"\t\t\t ___________________________________________________ "<<endl;
    cout<<"\t\t\t|                                                   |"<<endl;
    cout<<"\t\t\t|            Show All Account Details               |"<<endl;
    cout<<"\t\t\t|___________________________________________________|"<<endl<<endl<<endl;
    ifstream file;      // declaring instance for input file stream
    file.open(MAIN_FILE, ios::binary);   // opening file
    if(!file)   // checking if file exits or not
    {
      cout<<"[!] Database File Doesn't Exists";
    }
    else
    {
      Bank acc;     // declaring Bank class instance
      file.seekg(0, ios::beg);   // moving file get cursor to begining
      while(file.read(reinterpret_cast<char *> (&acc), sizeof(Bank)))  // reading object from file of cluster size = class size
      {
        acc.show_details();    // show_details from Class instance
      }
      file.close();   // closing file stream
    }
  }

  void del_ete()
  {
    system(CLEAR);    // clearing output screen
    int ac;
    cout<<"\t\t\t ___________________________________________________ "<<endl;
    cout<<"\t\t\t|                                                   |"<<endl;
    cout<<"\t\t\t|            Show All Account Details               |"<<endl;
    cout<<"\t\t\t|___________________________________________________|"<<endl<<endl<<endl;
    cout<<"enter account to delete : ";
    cin>>ac;
    cin.ignore();               // ignoring inpot stream buffer
    ifstream file;      // declaring instance for input file stream
    ofstream f;      // declaring instance for output file stream
    file.open(MAIN_FILE, ios::binary);    // opening file
    f.open(TEMP_FILE, ios::binary);   // open file in overwrite mode
    if(!file)    // checking if DB exits or not
    {
      cout<<"[!] Database File Doesn't Exists";
    }
    else
    {
      Bank acc;     // declaring Bank class instance
      file.seekg(0, ios::beg);    // moving input file stream cursor to begining of the file
      while(file.read(reinterpret_cast<char *> (&acc), sizeof(Bank)))  // reading object from file of cluster size = class size
      {
        if(ac!=acc.is_acc_no())   // checking if account number in DB matches to what user entered now
        {
          f.write(reinterpret_cast<char *> (&acc), sizeof(Bank));   // if not matches than write to new temp file
        }
      }
      // closing file streams
      f.close();
      file.close();

      remove(MAIN_FILE); // removing original DB
      rename(TEMP_FILE, MAIN_FILE);    // renaming temp db as original db
    }
  }

  void search()
  {
    bool found = false;
    system(CLEAR);    // clearing output screen
    int ac;
    cout<<"\t\t\t ___________________________________________________ "<<endl;
    cout<<"\t\t\t|                                                   |"<<endl;
    cout<<"\t\t\t|              Search Account Details               |"<<endl;
    cout<<"\t\t\t|___________________________________________________|"<<endl<<endl<<endl;
    cout<<"enter account number : ";
    cin>>ac;
    cin.ignore();               // ignoring inpot stream buffer
    cout<<"\n\n\n";
    ifstream file;      // declaring instance for input file stream
    file.open(MAIN_FILE, ios::binary);   // opening file
    if(!file)   // checking if file Exists or not
    {
      cout<<"[!] Database File Doesn't Exists";
    }
    else
    {
      Bank acc;     // declaring Bank class instance
      file.seekg(0, ios::beg);    // moving input file stream cursor to begining of the file
      while(file.read(reinterpret_cast<char *>(&acc), sizeof(Bank)))   // reading object from file of cluster size = class size
      {
        if(acc.is_acc_no() == ac)   // checking if account number in db is equal to account number entered here
        {
          found = true;                 // setting found equal to true
          acc.show_details();    // showing Details
        }
      }
    }
    if(!found)   // checking if account exists or not
    {
      cout<<"[!] Account Details for "<<ac<<" not found";
    }
    file.close();      // closing file stream
  }

  void show_trans()
  {
    system(CLEAR);    // clearing output screen
    cout<<"\t\t\t ________________________________________________________ "<<endl;
    cout<<"\t\t\t|                                                        |"<<endl;
    cout<<"\t\t\t|              Viewing All Transactions Logs             |"<<endl;
    cout<<"\t\t\t|________________________________________________________|"<<endl<<endl<<endl;
    cout<<"d / D -  Debit\nc / C -  Credit\n\n";
    cout<<"=====================================================================================\n";
    cout<<setw(20)<<"Account Number"<<setw(30)<<"Transaction Type"<<setw(20)<<"Amount";   // setw used to format text on output screen
    cout<<"\n=====================================================================================\n";
    string data;
    ifstream file;      // declaring instance for input file stream
    file.open(TRANSACTION);
    if(!file)
    {
      cout<<"[!] Transactions logs are not found";
    }
    else
    {
      while(file>>data && data!="\n")
      {
        vector<string> logs = Split::split(data, ',');   // spliting data
        cout<<setw(13)<<logs[0]<<setw(30)<<logs[2]<<setw(25)<<logs[1]<<endl;  // setw used to format text on output screen
      }
    }
    file.close();
  }

  void create_trans()
  {
    system(CLEAR);    // clearing output screen
    int ac;
    float amt;
    char opt;
    ifstream file;      // declaring instance for input file stream
    ofstream f,g;       // declaring instance for output file stream
    f.open(TRANSACTION, ios::app);    // opening file in append mode
    file.open(MAIN_FILE, ios::binary);      // opening file
    g.open(TEMP_FILE, ios::binary);   // opening file in overwrite mode;
    cout<<"\t\t\t ___________________________________________________ "<<endl;
    cout<<"\t\t\t|                                                   |"<<endl;
    cout<<"\t\t\t|              Deposit / Withdraw Money             |"<<endl;
    cout<<"\t\t\t|___________________________________________________|"<<endl<<endl<<endl;
    cout<<"enter account number : ";
    cin>>ac;
    cout<<"enter ammount : ";
    cin>>amt;
    cin.ignore();               // ignoring inpot stream buffer
    cout<<"What You Wana Do -> (C)redit\t(D)ebit\n";
    cin>>opt;

    if(opt == 'c' or opt == 'C')    // checking if user wants to Deposit money or not
    {
      if(!file)
      {
        cout<<"[!] Database File Doesn't Exists";
      }
      else
      {
        Bank acc;     // declaring Bank class instance
        file.seekg(0, ios::beg);    // moving input file stream cursor to begining of the file
        while(file.read(reinterpret_cast<char *> (&acc), sizeof(Bank)))  // reading object from file of cluster size = class size
        {
          if(acc.is_acc_no() == ac)
          {
              // writing data to text file
              f<<ac;
              f<<",";
              f<<amt;
              f<<",c\n";

              // updating Balance in users db
              acc.credit(amt);
          }
          g.write(reinterpret_cast<char *>(&acc), sizeof(Bank));   // writing data to temp file
        }
      }
    }
    else if(opt == 'd' or opt == 'D')   // checking if user wants to Withdraw the money or not
    {
      if(!file)   // checking if users db exits or not
      {
        cout<<"[!] Database File Doesn't Exists";
      }
      else
      {
        Bank acc;     // declaring Bank class instance
        file.seekg(0, ios::beg);    // moving input file stream cursor to begining of the file
        while(file.read(reinterpret_cast<char *> (&acc), sizeof(Bank)))  // reading object from file of cluster size = class size
        {
          if(acc.is_acc_no() == ac)   // checking if account exits in db or not
          {
            if(amt <= acc.get_curr_bal())   // validating Balance
            {
              // writing data to text file
              f<<ac;
              f<<",";
              f<<amt;
              f<<",d\n";

              // updating Balance in users db
              acc.debit(amt);
            }
            else
            {
              cout<<"[!] Insuffucient Balance";
            }
          }
          g.write(reinterpret_cast<char *>(&acc), sizeof(Bank));  // writing data to temp file
        }
      }
    }

    // closing file streams
    f.close();
    file.close();
    remove(MAIN_FILE);        // removing original file
    rename(TEMP_FILE, MAIN_FILE);   // renaming temp file to original file
  }

  void part_trans()
  {
    system(CLEAR);    // clearing output screen
    cout<<"\t\t\t ________________________________________________________ "<<endl;
    cout<<"\t\t\t|                                                        |"<<endl;
    cout<<"\t\t\t|          Viewing Particular Transactions Logs          |"<<endl;
    cout<<"\t\t\t|________________________________________________________|"<<endl<<endl<<endl;
    string ac;
    cout<<"enter account number : ";
    getline(cin, ac);   // getting details in ac via cin (console input)
    cout<<"\n\n\nd / D -  Debit\nc / C -  Credit\n\n";
    cout<<"=====================================================================================\n";
    cout<<setw(20)<<"Account Number"<<setw(30)<<"Transaction Type"<<setw(20)<<"Amount";    // setw used to format text on output screen
    cout<<"\n=====================================================================================\n";
    ifstream file;      // declaring instance for input file stream
    file.open(TRANSACTION);   // opening text file
    if(!file)   // checking if file exits or not
    {
      cout<<"[!] Transactions logs are not found";
    }
    else
    {
      while(file>>data && data!="\n")  // reading data line by line and is not equal to \n
      {
        vector<string> logs = Split::split(data, ','); // spliting data into vector
        if(logs[0]==ac) // checking if account
          cout<<setw(13)<<logs[0]<<setw(30)<<logs[2]<<setw(25)<<logs[1]<<endl;  // setw used to format text on output screen
      }
    }
    file.close();    // closing file stream
  }

  void modify()
  {
    system(CLEAR);    // clearing output screen
    cout<<"\t\t\t ________________________________________________________ "<<endl;
    cout<<"\t\t\t|                                                        |"<<endl;
    cout<<"\t\t\t|                 Modify Account Details                 |"<<endl;
    cout<<"\t\t\t|________________________________________________________|"<<endl<<endl<<endl;
    int ac;
    cout<<"enter account number : ";
    cin>>ac;
    cin.ignore();               // ignoring inpot stream buffer
    Bank bk;     // declaring Bank class instance
    ofstream f;
    ifstream file;      // declaring instance for input file stream
    file.open(MAIN_FILE, ios::binary);  // opening file
    f.open(TEMP_FILE, ios::binary);   // opening file in overwrite mode
    if(!file) // checking if db file exists or not
    {
      cout<<"[!] Database File Doesn't Exists";
    }
    else
    {
      file.seekg(0, ios::beg);    // moving input file stream cursor to begining of the file
      while(file.read(reinterpret_cast<char *> (&acc), sizeof(Bank)))  // reading object from file of cluster size = class size
      {
        if(bk.is_acc_no() == ac)   // checking if account entered here is equal to account in db
        {
          bk.modify();   // modifying Details
        }
        f.write(reinterpret_cast<char *>(&bk), sizeof(Bank));   // writing data to temp file
      }
    }

    // closing file streams
    f.close();
    file.close();
    remove(MAIN_FILE);        // removing original file
    rename(TEMP_FILE, MAIN_FILE);   // renaming temp file to original file
  }
} /* Actor */

#endif
