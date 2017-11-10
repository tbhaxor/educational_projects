// including header files and lliberaries
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
  // invoking info function
  info();
  while(true)
  {
    switch (menu())
    {
      // invoking functions according to case selection
      case 1:
        add_dept();
      break;
      case 2:
        add_emp();
      break;
      case 3:
        del_emp();
      break;
      case 4:
        del_dept();
      break;
      case 5:
        mod_emp();
      break;
      case 6:
        mod_dept();
      break;
      case 7:
        search_dept();
      break;
      case 8:
      search_emp();
      break;
      case 9:
        show_all();
      break;
      case 0:
        return 0;
      default:
      cout<<"[!] Invalid Selection";
    }
    pause(); // pausing output screen
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
  system(CLEAR); // clearing output screen
  cout<<"\t\t\t##########################################"<<endl;
  cout<<"\t\t\t##                                      ##"<<endl;
  cout<<"\t\t\t##                 MENU                 ##"<<endl;
  cout<<"\t\t\t##                                      ##"<<endl;
  cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
  cout<<"1. Add New Department"<<endl;
  cout<<"2. Add New Employee"<<endl;
  cout<<"3. Delete Employee"<<endl;
  cout<<"4. Delete Department"<<endl;
  cout<<"5. Modify Employee Details"<<endl;
  cout<<"6. Modify Department Details"<<endl;
  cout<<"7. Search Department"<<endl;
  cout<<"8. Search Employee"<<endl;
  cout<<"9. List All"<<endl;
  cout<<"0. Quit"<<endl;
  cout<<"> ";
  cin>>opt; //  getting selection
  cin.ignore();   // ignoring input stream buffer
  return opt;
}

// defining info function
void info()
{
  system(CLEAR); // clearing output screen
  cout<<"\t\t\t##########################################"<<endl;
  cout<<"\t\t\t##                                      ##"<<endl;
  cout<<"\t\t\t##      Company Management Program      ##"<<endl;
  cout<<"\t\t\t##                                      ##"<<endl;
  cout<<"\t\t\t##########################################"<<endl<<endl<<endl;
  cout<<"Coded By : "<<CODER<<endl;
  cout<<"Submitted To : "<<SUBMITTED_TO<<endl;
  cout<<"Institution : "<<INSTITUTION<<endl;
  pause();   // pausing the output screen
}
