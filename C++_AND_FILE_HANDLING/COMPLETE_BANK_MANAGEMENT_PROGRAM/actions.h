#ifndef ACTIONS_H
#define ACTIONS_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include "bank.h"
#include "config.h"
#include <iomanip>
using namespace std;

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
    Bank acc;
    system(CLEAR);
    cout<<"\t\t\t __________________________________________________ "<<endl;
    cout<<"\t\t\t|                                                  |"<<endl;
    cout<<"\t\t\t|            Add New Account Details               |"<<endl;
    cout<<"\t\t\t|__________________________________________________|"<<endl<<endl<<endl;
    acc.get_details();
    ofstream file1, file2;
    file1.open(MAIN_FILE, ios::binary|ios::app);
    file1.write(reinterpret_cast<char *> (&acc), sizeof(Bank));
    file1.close();
  }

  void show_all()
  {
    system(CLEAR);
    cout<<"\t\t\t ___________________________________________________ "<<endl;
    cout<<"\t\t\t|                                                   |"<<endl;
    cout<<"\t\t\t|            Show All Account Details               |"<<endl;
    cout<<"\t\t\t|___________________________________________________|"<<endl<<endl<<endl;
    ifstream file;
    file.open(MAIN_FILE, ios::binary);
    if(!file)
    {
      cout<<"[!] Database File Doesn't Exists";
    }
    else
    {
      Bank acc;
      file.seekg(0, ios::beg);
      while(file.read(reinterpret_cast<char *> (&acc), sizeof(Bank)))
      {
        acc.show_details();
      }
      file.close();
    }
  }

  void del_ete()
  {
    system(CLEAR);
    int ac;
    cout<<"\t\t\t ___________________________________________________ "<<endl;
    cout<<"\t\t\t|                                                   |"<<endl;
    cout<<"\t\t\t|            Show All Account Details               |"<<endl;
    cout<<"\t\t\t|___________________________________________________|"<<endl<<endl<<endl;
    cout<<"enter account to delete : ";
    cin>>ac;
    cin.ignore();
    ifstream file;
    ofstream f;
    file.open(MAIN_FILE, ios::binary);
    f.open(TEMP_FILE, ios::binary);
    if(!file)
    {
      cout<<"[!] Database File Doesn't Exists";
    }
    else
    {
      Bank acc;
      file.seekg(0, ios::beg);
      while(file.read(reinterpret_cast<char *> (&acc), sizeof(Bank)))
      {
        if(ac!=acc.is_acc_no())
        {
          f.write(reinterpret_cast<char *> (&acc), sizeof(Bank));
        }
      }
      f.close();
      file.close();
      remove(MAIN_FILE);
      rename(TEMP_FILE, MAIN_FILE);
    }
  }

  void search()
  {
    bool found = false;
    system(CLEAR);
    int ac;
    cout<<"\t\t\t ___________________________________________________ "<<endl;
    cout<<"\t\t\t|                                                   |"<<endl;
    cout<<"\t\t\t|              Search Account Details               |"<<endl;
    cout<<"\t\t\t|___________________________________________________|"<<endl<<endl<<endl;
    cout<<"enter account number : ";
    cin>>ac;
    cin.ignore();
    cout<<"\n\n\n";
    ifstream file;
    file.open(MAIN_FILE, ios::binary);
    if(!file)
    {
      cout<<"[!] Database File Doesn't Exists";
    }
    else
    {
      Bank acc;
      file.seekg(0, ios::beg);
      while(file.read(reinterpret_cast<char *>(&acc), sizeof(Bank)))
      {
        if(acc.is_acc_no() == ac)
        {
          found = true;
          acc.show_details();
        }
      }
    }
    if(!found)
    {
      cout<<"[!] Account Details for "<<ac<<" not found";
    }
    file.close();
  }

  void show_trans()
  {
    system(CLEAR);
    cout<<"\t\t\t ________________________________________________________ "<<endl;
    cout<<"\t\t\t|                                                        |"<<endl;
    cout<<"\t\t\t|              Viewing All Transactions Logs             |"<<endl;
    cout<<"\t\t\t|________________________________________________________|"<<endl<<endl<<endl;
    cout<<"d / D -  Debit\nc / C -  Credit\n\n";
    cout<<"=====================================================================================\n";
    cout<<setw(20)<<"Account Number"<<setw(30)<<"Transaction Type"<<setw(20)<<"Amount";
    cout<<"\n=====================================================================================\n";
    string data;
    ifstream file;
    file.open(TRANSACTION);
    if(!file)
    {
      cout<<"[!] Transactions logs are not found";
    }
    else
    {
      while(file>>data && data!="\n")
      {
        vector<string> logs = Split::split(data, ',');
        cout<<setw(13)<<logs[0]<<setw(30)<<logs[2]<<setw(25)<<logs[1]<<endl;
      }
    }
    file.close();
  }

  void create_trans()
  {
    system(CLEAR);
    int ac;
    float amt;
    char opt;
    string data;
    ifstream file;
    ofstream f,g;
    f.open(TRANSACTION, ios::app);
    file.open(MAIN_FILE, ios::binary);
    g.open(TEMP_FILE, ios::binary);
    cout<<"\t\t\t ___________________________________________________ "<<endl;
    cout<<"\t\t\t|                                                   |"<<endl;
    cout<<"\t\t\t|              Deposit / Withdraw Money             |"<<endl;
    cout<<"\t\t\t|___________________________________________________|"<<endl<<endl<<endl;
    cout<<"enter account number : ";
    cin>>ac;
    cout<<"enter ammount : ";
    cin>>amt;
    cin.ignore();
    cout<<"What You Wana Do -> (C)redit\t(D)ebit\n";
    cin>>opt;

    if(opt == 'c' or opt == 'C')
    {
      if(!file)
      {
        cout<<"[!] Database File Doesn't Exists";
      }
      else
      {
        Bank acc;
        file.seekg(0, ios::beg);
        while(file.read(reinterpret_cast<char *>(&acc), sizeof(Bank)))
        {
          if(acc.is_acc_no() == ac)
          {
              f<<ac;
              f<<",";
              f<<amt;
              f<<",c\n";
              acc.credit(amt);
          }
          g.write(reinterpret_cast<char *>(&acc), sizeof(Bank));
        }
      }
    }
    else if(opt == 'd' or opt == 'D')
    {
      if(!file)
      {
        cout<<"[!] Database File Doesn't Exists";
      }
      else
      {
        Bank acc;
        file.seekg(0, ios::beg);
        while(file.read(reinterpret_cast<char *>(&acc), sizeof(Bank)))
        {
          if(acc.is_acc_no() == ac)
          {
            if(amt <= acc.get_curr_bal())
            {
              f<<ac;
              f<<",";
              f<<amt;
              f<<",d\n";
              acc.debit(amt);
            }
            else
            {
              cout<<"[!] Insuffucuent Balance";
            }
          }
          g.write(reinterpret_cast<char *>(&acc), sizeof(Bank));
        }
      }
    }
    f.close();
    file.close();
    g.close();
    remove(MAIN_FILE);
    rename(TEMP_FILE, MAIN_FILE);
  }

  void part_trans()
  {
    system(CLEAR);
    cout<<"\t\t\t ________________________________________________________ "<<endl;
    cout<<"\t\t\t|                                                        |"<<endl;
    cout<<"\t\t\t|          Viewing Particular Transactions Logs          |"<<endl;
    cout<<"\t\t\t|________________________________________________________|"<<endl<<endl<<endl;
    string ac;
    cout<<"enter account number : ";
    getline(cin, ac);
    cout<<"\n\n\nd / D -  Debit\nc / C -  Credit\n\n";
    cout<<"=====================================================================================\n";
    cout<<setw(20)<<"Account Number"<<setw(30)<<"Transaction Type"<<setw(20)<<"Amount";
    cout<<"\n=====================================================================================\n";
    string data;
    ifstream file;
    file.open(TRANSACTION);
    if(!file)
    {
      cout<<"[!] Transactions logs are not found";
    }
    else
    {
      while(file>>data && data!="\n")
      {
        vector<string> logs = Split::split(data, ',');
        if(logs[0]==ac)
          cout<<setw(13)<<logs[0]<<setw(30)<<logs[2]<<setw(25)<<logs[1]<<endl;
      }
    }
    file.close();
  }
} /* Actor */

#endif
