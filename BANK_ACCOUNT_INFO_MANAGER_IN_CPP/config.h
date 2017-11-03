#ifndef INITS_H_
#define INITS_H_

#include <iostream>
#include <cstdlib>
#include <Windows.h>
using namespace std;
namespace Config
{
  // config variables
  string coder = "Gurkirat Singh";
  string submitted_to = "Mrs. Seema Sehgal";
  string institution = "MDU";

  // animation
  int sleep_time = 300;  // in millisecs
  int loading_iteration = 4;
  char loading_chars[] = {'|', '/', '-', '\\'};

  void info()
  {
    system("cls");
    cout<<"\t\t\t====================================================="<<endl;
    cout<<"\t\t\t=======  BANK ACCOUNT INFO MANAGEMENT PROGRAM  ======"<<endl;
    cout<<"\t\t\t====================================================="<<endl<<endl;
    cout<<"Coded By : "<<coder<<endl;
    cout<<"Submitted To : "<<submitted_to<<endl;
    cout<<"Institution : "<<institution<<endl<<endl<<endl;

    for(int i = 0; i < loading_iteration; i++)
    {
      for (int x = 0; x < 4; x++)
      {

        cout<<"\t\t\tLoading . . "<<loading_chars[x]<<"\r"<<flush;
        Sleep(sleep_time);
      }
    }
  }

  int menu()
  {
    int option;
    system("cls");
    cout<<"\t\t\t====================="<<endl;
    cout<<"\t\t\t=======  MENU  ======"<<endl;
    cout<<"\t\t\t====================="<<endl<<endl;
    cout<<"1. New Account\t\t2. Delete Account"<<endl;
    cout<<"3. Modify Account\t4. Search Account"<<endl;
    cout<<"5. List All Account\t6. Quit"<<endl;
    cout<<"> ";
    cin>>option;
    cin.ignore();
    return option;
  }

  void pause()
  {
    cout<<"\n\n";
    system("pause");
  }
}
#endif // Inits
