// incling header files and lliberaries
#include <iostream>
#include <cstdlib>
#include "actor.h"
#include "config.h"
using namespace std;
using namespace Actions;

// function prototyping
int menu();
void pause();
void info();

int main()
{
  info();
  while(true)
  {
    switch (menu())
    {
      case 1:

      break;
      case 2:

      break;
      case 3:

      break;
      case 4:

      break;
      case 5:

      break;
      case 6:

      break;
      case 7:

      break;
      case 8:

      break;
      case 9:
        return 0;
      default:
      cout<<"[!] Invalid Selection";
    }
    pause();
  }
  return 0;
}

// defining pause function
void pause()
{
  cout<<"\n\n[!] Press Enter To Continue";
  cin.get();
}

// defining menu function
int menu()
{
  int opt;
  system(CLEAR);
  cout<<"\t\t\t##########################################"<<endl;
  cout<<"\t\t\t##                                      ##"<<endl;
  cout<<"\t\t\t##                 MENU                 ##"<<endl;
  cout<<"\t\t\t##                                      ##"<<endl;
  cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
  cout<<"1. Add New Employee"<<endl;
  cout<<"2. Delete Employe"<<endl;
  cout<<"3. Delete Department"<<endl;
  cout<<"4. Modify Employee Details"<<endl;
  cout<<"5. Modify Department Details"<<endl;
  cout<<"6. Search Department"<<endl;
  cout<<"7. Search Employee"<<endl;
  cout<<"8. List All"<<endl;
  cout<<"9. Quit"<<endl;
  cout<<"> ";
  cin>>opt;
  cin.ignore();
  return opt;
}

// defining info function
void info()
{
  system(CLEAR);
  cout<<"\t\t\t##########################################"<<endl;
  cout<<"\t\t\t##                                      ##"<<endl;
  cout<<"\t\t\t##      Company Management Program      ##"<<endl;
  cout<<"\t\t\t##                                      ##"<<endl;
  cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
  cout<<"Coded By : "<<CODER<<endl;
  cout<<"Submitted To : "<<SUBMITTED_TO<<endl;
  cout<<"Institution : "<<INSTITUTION<<endl;
  pause();
}
