// including standard header file an liberar
#include <iostream>
#include <fstream>
using namespace std;

#define MAIN_FILE "ACCOUNTS.DAT"
#define TEMP_FILE "TEMP.DAT"

// including local header files and liberaries
#include "config.h"
using namespace Config;
#include "bank.h"

int main()
{
  // info();
  Bank ac;
  ofstream outFile;
  ifstream inFile;
  int ex;
  while(true)
  {
    bool flag = false;
    switch (menu())
    {
      case 1:
        system("cls");
        cout<<"\t\t\t================================"<<endl;
        cout<<"\t\t\t=======  Add New Account  ======"<<endl;
        cout<<"\t\t\t================================"<<endl<<endl;
        ac.get();
        outFile.open(MAIN_FILE,ios::binary|ios::app);
        outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank));
        outFile.close();
      break;

      case 2:
        system("cls");
        cout<<"\t\t\t================================"<<endl;
        cout<<"\t\t\t=======  Delete Account  ======"<<endl;
        cout<<"\t\t\t================================"<<endl<<endl;
        cout<<"enter account number you want to delete : ";
        cin>>ex;
        outFile.open(TEMP_FILE, ios::binary|ios::app);
        inFile.open(MAIN_FILE, ios::binary);
        if(!inFile)
        {
          cout<<"[x] Error - File doesnt exists";
        }
        else
        {
          inFile.seekg(0,ios::beg);
          while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank)))
          {
            if(ac.is_acc_no() == ex)
            {
              flag = true;
            }
            else
            {
              outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank));
            }
          }
        }
        outFile.close();
        inFile.close();
        if(flag)
        {
          remove(TEMP_FILE);
          rename(TEMP_FILE, MAIN_FILE);
          cout<<"[!] Info - Account Deleted";
        }
        else
        cout<<"[!] Info - Account Not Found";

      break;
      case 5:
        system("cls");
        cout<<"\t\t\t====================================="<<endl;
        cout<<"\t\t\t=======  Viewing All Accounts  ======"<<endl;
        cout<<"\t\t\t====================================="<<endl<<endl;
        inFile.open(MAIN_FILE, ios::binary);
        if(!inFile)
        {
          cout<<"[x] Error - File doesnt exists";
        }
        else
        {
          while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank)))
          {
            ac.put();
          }
          inFile.close();
        }
      break;

      case 6:
        return 0;
        break;

      default:
        cout<<"[!] Info - Option not valid";
        break;
    }
    pause();
  }
}
