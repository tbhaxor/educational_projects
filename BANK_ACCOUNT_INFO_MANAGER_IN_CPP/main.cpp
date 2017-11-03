// including standard header file an liberar
#include <iostream>
#include <fstream>
using namespace std;


// including local header files and liberaries
#include "config.h"
using namespace Config;
#include "bank.h"

int main()
{
  // info();
  Bank account;
  fstream FILE_1, FILE_2;
  while(true)
  {
    switch (menu())
    {
      case 1:
        system("cls");
        cout<<"\t\t\t================================"<<endl;
        cout<<"\t\t\t=======  Add New Account  ======"<<endl;
        cout<<"\t\t\t================================"<<endl<<endl;
        account.get();
        break;

      case 5:
        system("cls");
        cout<<"\t\t\t====================================="<<endl;
        cout<<"\t\t\t=======  Viewing All Accounts  ======"<<endl;
        cout<<"\t\t\t====================================="<<endl<<endl;
        account.put();
        break;

      case 6:
        return 0;
      default:
        cout<<"[!] Info - Option not valid";
    }
    pause();
  }
}
